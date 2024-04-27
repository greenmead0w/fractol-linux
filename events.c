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
    render_fractal(fractal); 
    return (0);

}

//int (*f)(int button, int x, int y, void *param)
// NOT WORKING AS EXPECTED: NEED TO TRY TUTORIAL FIRST AND SEE IF IT WORKS OR PLUG IN RATON OR SEE WHAT GETS PRINTED WHEN CLICING MOUSE
/*int mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == ZOOM_IN)
		fractal->zoom_level *= 0.95;
	if (button == ZOOM_OUT)
		fractal->zoom_level *= 1.05;
	render_fractal(fractal);
    return (0);
}*/