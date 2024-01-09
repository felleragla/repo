/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** files
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "hunter.h"
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

void mos(hunter *get)
{
    while (sfRenderWindow_pollEvent(get->window, &get->event)) {
        if (get->event.type == sfEvtClosed)
        sfRenderWindow_close(get->window);
        }
}

int initialize(hunter *get)
{
    get->mode.height = 600;
    get->mode.width = 800;
    get->mode.bitsPerPixel = 16;
    get->window = sfRenderWindow_create(get->mode,
    "SFML Window", sfDefaultStyle, NULL);
    get->texture0 = sfTexture_createFromFile("game.png", NULL);
    get->texture1 = sfTexture_createFromFile("bird.png", NULL);
    get->juice = sfMusic_createFromFile("audio.ogg");
    sfMusic_setLoop(get->juice, sfTrue);
    get->sprite1 = sfSprite_create();
    get->sprite0 = sfSprite_create();
    return (0);
}

int main(int ac, char **av)
{
    hunter *get = malloc(sizeof(hunter) *3);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        tuer();
    } else if (ac == 1) {
    initialize(get);
    initial(get);
    sfSprite_setTexture(get->sprite1, get->texture1, sfTrue);
    sfSprite_setTexture(get->sprite0, get->texture0, sfTrue);
    sfMusic_play(get->juice);
    while (sfRenderWindow_isOpen(get->window)) {
        mos(get);    
    sfRenderWindow_clear(get->window, sfBlack);
    play(get);
    }
    sfMusic_stop(get->juice);
    available(get);
    } else {
        return 84;
    }
}
