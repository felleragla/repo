/*
** EPITECH PROJECT, 2023
** B-MUL-100-COT-1-1-myradar-feller.agla
** File description:
** circle.c
*/


#include"radar.h"
#include <math.h>

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlack);
}

void radar_create(feller *radar)
{
    radar->position.x = 100;
    radar->position.y = 100;
    radar->position2.x = 210;
    radar->position2.y = 100;
    radar->circle = create_circle(radar->position, 100);
    radar->circle2 = create_circle(radar->position2, 100);
}

int is_intersecting(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos1 = sfCircleShape_getPosition(c1);
    sfVector2f pos2 = sfCircleShape_getPosition(c2);
    float radius1 = sfCircleShape_getRadius(c1);
    float radius2 = sfCircleShape_getRadius(c2);
    float distance = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));

    if (distance <= radius1 + radius2) {
        return 1;
    } else {
        return 0;
    }
}
