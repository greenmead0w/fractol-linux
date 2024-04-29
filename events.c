#include "fractol.h"


// If using return (0) -- there's a leak
int close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_press(int key, t_fractal *fractal)
{
    if (key == XK_Escape)
        close_window(fractal);
    else if (key == XK_plus)
        fractal->max_iteration +=10;
    else if (key == XK_minus)
        fractal->max_iteration = fractal->max_iteration - 10;
    else if (key == XK_Left)
		fractal->shift_x -= (0.25 * fractal->range_max);		
	else if (key == XK_Right)
		fractal->shift_x += (0.25 * fractal->range_max);	
	else if (key == XK_Up)
		fractal-> shift_y -= (0.25 * fractal->range_min);	
	else if (key == XK_Down)
		fractal->shift_y += (0.25 * fractal->range_min) ;	
    render_fractal(fractal); 
    return (0);

}

//int (*f)(int button, int x, int y, void *param)
// NOT WORKING AS EXPECTED: NEED TO TRY TUTORIAL FIRST AND SEE IF IT WORKS OR PLUG IN RATON OR SEE WHAT GETS PRINTED WHEN CLICING MOUSE
int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
   (void)x;
   (void)y;

	if (button == ZOOM_IN)
    {
		fractal->range_max *= 0.95;
        fractal->range_min *= 0.95;
    }
	else if (button == ZOOM_OUT)
    {
		fractal->range_max *= 1.05;
        fractal->range_min *= 1.05;
    }
	render_fractal(fractal);
    return (0);
}