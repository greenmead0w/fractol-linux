#include "fractol.h"

static double ascii_to_double(char *str, double fraction, int sign, int is_fraction ) 
{
    double result;

    result = 0.0;
    if (*str == '-') 
    {
        sign = -sign;
        str++;
    }
    while (*str) 
    {
        if (*str == '.') 
        {
            is_fraction = 1;
            str++;
        }
        result = result * 10 + (*str - '0');
        if (is_fraction)
            fraction /= 10.0;
        str++;
    }
    return sign * result * fraction;
}

static int check_digit(char *str) 
{
    int decimal_count;
    int i;

    decimal_count = 0;
    i = 0;
    if (str[0] == '-') 
        i++; 
    while (str[i] != '\0') 
    {
        if (!ft_isdigit(str[i]) && str[i] != '.') 
            return 0;
        if (str[i] == '.')
            decimal_count++;
        if (decimal_count > 1)
            return 0;
        i++;
    }
    return 1;
}

// need to change printfs
static int is_valid(int argc, char **argv) 
{
if (!((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0) || 
      (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))) 
    {
        printf("valid input must be ./fractol mandelbrot or ./fractol julia <real value> <imaginary value>\n");
        return 0;
    }
    if (argc == 4) 
    {
        if (!check_digit(argv[2]) || !check_digit(argv[3]))
        {
            printf("valid input for Julia only has numbers\n");
            return 7;
        } 
    }
    return 1;
}

int main (int argc, char **argv)
{
    t_fractal fractal;
	int 		valid;

	valid = is_valid(argc, argv);
	//if input is invalid
	if (valid != 1)
    	exit(EXIT_SUCCESS);
	else
    {
		fractal.type = argv[1];
        printf("valid input\n");
		if (argc == 4)
		{
			fractal.j_real = ascii_to_double(argv[2], 1.0, 1, 0);
        	fractal.j_imaginary = ascii_to_double(argv[3], 1.0, 1, 0);
        	printf("real number is: %f\n", fractal.j_real);
        	printf("imaginary number is: %f\n", fractal.j_imaginary);
		}
        initialize(&fractal);
        render_fractal(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
}