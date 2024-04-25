#include "fractol.h"


// somehow there's a memory leak!!
int close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    return (0);
}

int key_press(int key, t_fractal *fractal)
{
    if (key == XK_Escape)
        close_window(fractal);
    else if (key == XK_plus)
        fractal->max_iteration +=10;
    else if (key == XK_minus)
        fractal->max_iteration = fractal->max_iteration - 10;
    render_fractal(fractal);
    return (0);

}

//int (*f)(int button, int x, int y, void *param)

int mouse(int button, int x, int y, t_fractal *fractal)
{
    // zoom in
    if (button == 5)

    else if (button == 4)

    render_fractal(fractal);
    return (0);
}