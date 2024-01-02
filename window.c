/*
** EPITECH PROJECT, 2023
** B-MUL-100-COT-1-1-myradar-feller.agla
** File description:
** window.c
*/

#ifdef __GNUC__
#define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#else
#define UNUSED(x) UNUSED_ ## x
#endif
#undef UNUSED
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "radar.h"

void create_window(feller *window)
{
    sfVideoMode mode = {1980, 1082, 32};

   window->window = sfRenderWindow_create(mode, "FELLER",
    sfResize | sfClose, NULL);
    window->mapTexture = sfTexture_createFromFile("map.jpg", NULL);
    window->planerTextures = sfTexture_createFromFile("plane.png", NULL);
    window->towerTextures = sfTexture_createFromFile("tower.png", NULL);
    window->map = sfSprite_create();
    window->planer = sfSprite_create();
    window->tower = sfSprite_create();
    sfSprite_setTexture(window->map, window->mapTexture, sfTrue);
    sfSprite_setTexture(window->planer, window->planerTextures, sfTrue);
    sfSprite_setTexture(window->tower, window->towerTextures, sfTrue);
    radar_create(window);
}

int main(void)
{
    feller window;

    create_window(&window);
    while (sfRenderWindow_isOpen(window.window)) {
        my_radar(&window);
        radar_update(&window);
        destroy(&window);
    printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n");
    }
}
