/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct junior {
    sfRenderWindow *window;
    sfCircleShape *circle;
    sfVector2f position;
    sfCircleShape *circle2;
    sfVector2f position2;
    sfEvent event;
    sfSprite *map;
    sfSprite *planer;
    sfSprite *tower;
    sfTexture *mapTexture;
    sfTexture *planerTextures;
    sfTexture *towerTextures;
} feller;

int is_intersecting(sfCircleShape *c1, sfCircleShape *c2);
void my_radar(feller *window);
void create_window(feller *window);
void image(feller *window);
void radar_create(feller *radar);
void radar_update(feller *radar);
void radar_draw(feller *radar);
void radar_destroy(feller *radar);
void destroy(feller *window);
void set_all(feller );
void dest_all(feller *);