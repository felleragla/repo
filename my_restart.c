/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** step
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./hunter.h"

void play(hunter *get)
{
    sfSprite_setTextureRect(get->sprite0, get->rect0);
    sfRenderWindow_drawSprite(get->window, get->sprite0, NULL);
    sfSprite_setTextureRect(get->sprite1, get->rect1);
    sfRenderWindow_drawSprite(get->window, get->sprite1, NULL);
    sfRenderWindow_display(get->window);
    move_rect(get, &get->rect1, 110, 330);
}

void available(hunter *get)
{
    sfRenderWindow_destroy(get->window);
    sfTexture_destroy(get->texture0);
    sfSprite_destroy(get->sprite0);
    sfTexture_destroy(get->texture1);
    sfSprite_destroy(get->sprite1);
    sfClock_destroy(get->clock);
}
