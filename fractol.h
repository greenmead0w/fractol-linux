#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h> //(?)
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "fractol_libft/libft.h" //ft_printf, ft_strncmp
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 800
#define HEIGHT 800
#define NAME "Fractal"


// Image struct
typedef struct s_image
{
    void *img_ptr;
    char *img_data;
    int     bpp;
    int     line_length;
    int     endian;
}               t_image;

// Fractal struct
typedef struct s_fractal
{
    void *mlx_connection;
    void *mlx_window;
    t_image image;
    //TO DO: hooks variables to be added:
    double threshold;
    int max_iteration;
}               t_fractal;

//complex number struct
typedef struct s_complex
{
    double real; // real value
    double imaginary; // imaginary value
}               t_complex;

//initialize.c
void initialize(t_fractal *fractal);

//render.c
//double rescale(double unscaled_num, double new_min, double new_max, double old_max);
void render_fractal(t_fractal *fractal);

//events.c
int key_press(int key, t_fractal *fractal);
int close_window(t_fractal *fractal);
int mouse(int button, int x, int y, t_fractal *fractal);


//color palette:
// Psychedelic colors
#define MAGENTA_BURST 0xFF00FF  
#define LIME_SHECK    0x00FF00  
#define CYAN_FLARE    0x00FFFF 
#define FIRE_ORANGE   0xFF4500  
#define ELECTRIC_BLUE 0x0000FF  
#define NEON_PINK     0xFF1493 

// Standard colors
#define BLACK   0x000000
#define WHITE   0xFFFFFF  



#endif