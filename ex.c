#include <SFML/Graphics.h>
#include <math.h>

int main() {
    sfVideoMode mode = {1980, 1019, 100};
    sfRenderWindow* window;
    sfEvent event;
    sfTexture* texture;
    sfSprite* avion;
    sfCircleShape *circle;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

    // Chargement de l'image de l'avion
    texture = sfTexture_createFromFile("plane.png", NULL);
    if (!texture) {
        // Gérer l'erreur si l'image ne peut pas être chargée
        return 1;
    }

    // Création du sprite de l'avion
    avion = sfSprite_create();
    sfSprite_setTexture(avion, texture, sfTrue);

    // Création du cercle
    sfVector2f position = {100, 100};
    float radius = 185;
    circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setOutlineColor(circle, sfWhite);

    sfVector2u textureSize = sfTexture_getSize(texture);
    float halfWidth = textureSize.x / 2.0f;
    float halfHeight = textureSize.y / 2.0f;


    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlue);

        // Dessine le cercle sur la fenêtre
        sfRenderWindow_drawCircleShape(window, circle, NULL);

        // Dessine l'avion à l'intérieur du cercle en ajustant la position
        sfVector2f avionPosition = sfCircleShape_getPosition(circle);
        sfVector2f avionOffset = {100, 100}; // Ajustez l'offset pour placer l'avion correctement
        sfVector2f avionFinalPosition = {avionPosition.x + avionOffset.x, avionPosition.y + avionOffset.y};
        sfSprite_setPosition(avion, avionFinalPosition);
        sfRenderWindow_drawSprite(window, avion, NULL);

        sfRenderWindow_display(window);
    }

    sfTexture_destroy(texture);
    sfSprite_destroy(avion);
    sfCircleShape_destroy(circle);
    sfRenderWindow_destroy(window);

    return 0;
}
