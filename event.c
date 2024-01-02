/*
** EPITECH PROJECT, 2023
** B-MUL-100-COT-1-1-myradar-feller.agla
** File description:
** event.c
*/

#include "radar.h"

void radar_update(feller *radar)
{
    sfVector2f new_position;
    new_position.x = 500;
    new_position.y = 600;
    //sfCircleShape_setPosition(radar->circle2, new_position);
    // if (is_intersecting(radar->circle, radar->circle2)) {
    //     printf("Intersection detected !\n");
    // }
}

// void my_radar(feller *window)
// {
//     sfEvent event;

//     while(sfRenderWindow_pollEvent(window->window, &event)) {
//         if (event.type == sfEvtClosed) {
//             sfRenderWindow_close(window->window);
//         }
//         if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
//             sfRenderWindow_close(window->window);
//         }
//     }
// }

void my_radar(feller *window)
{
    sfEvent event;

    /*if (window == NULL || window->window == NULL) {
        printf("Window is null.\n");
    }*/
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            //exit;
        }
        /*if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            sfRenderWindow_close(window->window);
        }*/
    }
    image(window);
}

void destroy(feller *window)
{
    sfCircleShape_destroy(window->circle);
    sfCircleShape_destroy(window->circle2);
    sfTexture_destroy(window->mapTexture);
    sfTexture_destroy(window->planerTextures);
    sfTexture_destroy(window->towerTextures);
    sfSprite_destroy(window->map);
    sfSprite_destroy(window->planer);
    sfSprite_destroy(window->tower);
    sfRenderWindow_destroy(window->window);
}

void image(feller *window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, window->map, NULL);
    sfRenderWindow_drawSprite(window->window, window->planer, NULL);
    sfRenderWindow_drawSprite(window->window, window->tower, NULL);
    //sfRenderWindow_drawCircleShape(window->window, window->circle, NULL);
    //sfRenderWindow_drawCircleShape(window->window, window->circle2, NULL);
    sfRenderWindow_display(window->window);
}