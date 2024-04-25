#include "fractol.h"

//might need to check for leaks
static void handle_error(t_fractal *fractal, int error_code)
{
    if (error_code == 1)
    {
        mlx_destroy_display(fractal->mlx_connection); 
        free(fractal->mlx_connection);
    }
    perror("Unsuccessful malloc");
}

static void data_init(t_fractal *fractal)
{
    fractal->threshold = 4;
    fractal->max_iteration = 42;
}

static void event_init(t_fractal *fractal)
{
    //keyboard
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_press, fractal);
    //mouse
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse, fractal);
    //close window
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_window, fractal);


}


void initialize(t_fractal *fractal)
{
    fractal ->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        handle_error(fractal, 0);
    fractal ->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, NAME);
    if(fractal->mlx_window == NULL)
        handle_error(fractal,  1);
    fractal ->image.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->image.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        handle_error(fractal, 1);
    }
    fractal->image.img_data = mlx_get_data_addr(fractal->image.img_ptr, &(fractal->image.bpp), &(fractal->image.line_length), &(fractal->image.endian));
    event_init(fractal);
    data_init(fractal);
}
