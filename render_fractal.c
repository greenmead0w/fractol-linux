#include "fractol.h"

//doubts if better to create a math.c file

/*mandelbrot function:
 z= z² + c
*/

//prints color in image buffer(not window)
static void my_pixel_put( int x, int y, t_image *image, int color)
{
    int offset; // from pixel to bytes
    offset = (y * image->line_length) + (x * (image->bpp / 8));
    *(unsigned int   *)(image->img_data + offset) = color;
}

static t_complex sum_cn(t_complex x, t_complex y)
{
    t_complex result;
    result.real = x.real + y.real;
    result.imaginary = x.imaginary + y.imaginary;
    return result;
}

// check apuntes on how to operate
static t_complex square_cn(t_complex x)
{
    t_complex result;
    result.real = (x.real * x.real) - (x.imaginary * x.imaginary);
    result.imaginary = 2 * x.real * x.imaginary;
    return result;

}

static double rescale(double unscaled_num, double new_min, double new_max, double old_max)
{
    double old_min = 0;
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
    
} 

static void set_type(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (ft_strncmp(fractal->type, "julia", 5) == 0)
    {
        c->real = fractal->j_real;
        c->imaginary = fractal->j_imaginary;
    }
    else
    {
        c->real = z->real;
        c->imaginary = z->imaginary;
    }
}

static void pixel_op(int pixel_x, int pixel_y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    // for zooming 
    //double x_min = -2.0 * fractal->zoom_level;
   // double x_max = +2.0 * fractal->zoom_level;
    //double y_min = +2.0 * fractal->zoom_level;
    //double y_max = -2.0 * fractal->zoom_level;
    z.real = rescale(pixel_x, fractal->range_min, fractal->range_max, WIDTH) + fractal->shift_x;       
    z.imaginary = rescale(pixel_y, fractal->range_max, fractal->range_min, HEIGHT) + fractal->shift_y ; //(0,0) pixels == (-2, +2) mandelbrot scale
    set_type(&z, &c, fractal);
    while( i < fractal->max_iteration)
    {
        //do mandelbrot equation
        z = sum_cn(square_cn(z), c);
        if((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->threshold) // pytaghorean theorem, check docs
        {
            color = rescale(i, BLACK, WHITE, fractal->max_iteration);
            my_pixel_put(pixel_x, pixel_y, &fractal->image, color );
            return;
        }
        i++;
    }
    my_pixel_put(pixel_x, pixel_y, &fractal->image, BLACK);

}

void render_fractal(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y <= HEIGHT)
    {
        x = 0;
            while (x <= WIDTH)
            {
                pixel_op(x, y, fractal);
                x++;
            }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img_ptr, 0, 0);
}
