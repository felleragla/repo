 /*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** files
*/
#include <stdio.h>
#include <stdlib.h>
#include "hunter.h"
#include <SFML/Graphics.h>
void initial(hunter *get)
{
    get->rect1 = (sfIntRect){0, 0, 110, 110};
    get->rect0 = (sfIntRect){0, 0, 800, 600};
}

void move_rect(hunter *data, sfIntRect *rect, int offset, int max_value)
{
    float seconds;

    data->clock = sfClock_create();
    data->time = sfClock_getElapsedTime(data->clock);
    seconds = sfTime_asMicroseconds(data->time);
    rect->left += offset;
    if (rect->left > 2000.f) {
        rect->left = -110.f;
    }
}

void tuer(void)
{
    mini_printf("USAGE\n");
    mini_printf("    ./my_hunter\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("    the game.png is sprite0\n");
    mini_printf("    the bird.png is sprite1\n");
}


