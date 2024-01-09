/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** files
*/

#ifndef HUNTER_H
    #define HUNTER_H

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <time.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <SFML/Audio.h>

typedef struct hunter {
    sfEvent event;
    sfVideoMode mode;
    sfSprite *sprite0;
    sfRenderWindow *window;
    sfTexture *texture0;
    sfTexture *texture1;
    sfSprite *sprite1;
    sfMusic *juice;
    sfIntRect rect0;
    sfIntRect rect1;
    sfClock *clock;
    sfTime time;
    sfTime plane;
    float  butposX;
    float birdSpeed;
}hunter;

int initialize(hunter *get);
void initial(hunter *get);
void move_rect(hunter *data, sfIntRect *rect, int offset, int max_value);
void tuer(void);
int mini_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
void function(const char *format, va_list list_of_arg, int *c);
void play(hunter *get);
void available(hunter *get);

#endif
