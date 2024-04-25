#include "fractol.h"



int main (int argc, char **argv)
{

    t_fractal fractal;
    //what happens for julia if argv[2] is not a number? need to think about ways to break this
    if ((argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0))
        || (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0)) )
    {
        //ready to execute the program
        printf("valid input\n");
        initialize(&fractal);
        render_fractal(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        printf("this is the error message\n");
        //ft_printf("valid input must be "./fractol mandelbrot or ./fractol julia <real value> <imaginary value>)
        //exit(EXIT_FAILURE); //(?)
    }
    printf("max iteration is: %i\n", fractal.max_iteration);
}