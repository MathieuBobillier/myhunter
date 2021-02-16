/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-mathieu.bobillier
** File description:
** my_hunter.c
*/

#include "my.h"

void animation(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 10;
    rect.left += 191;
    if (rect.left == 573)
        rect.left = 0;
    rect.height = 191;
    rect.width = 191;
    sfSprite_setTextureRect(sprite, rect);
}

int shoot_the_dragon(sfSprite *sprite, sfWindow *Window, int score)
{
    sfVector2f capteur = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(Window);
    if (mouse.x >= capteur.x && mouse.x <= (capteur.x + 191) &&
        mouse.y >= capteur.y && mouse.y <= (capteur.y + 191))
    {
        score = score + 1;
        int x = 0;
        int y = 0;
        srand(time(NULL));
        y = (rand() % (409 + 1 - 0)) + 0;
        sfVector2f my_pos = {x, y};
        sfSprite_setPosition(sprite, my_pos);
    }
    return (score);
}

int life(sfSprite *sprite, int life2)
{
    sfVector2f capteur = sfSprite_getPosition(sprite);
    if (capteur.x >= 800)
    {
        life2 -= 1;
        int y = 0;
        int x = 0;
        srand(time(NULL));
        y = (rand() % (409 + 1 - 0)) + 0;
        sfVector2f my_pos = {x, y};
        sfSprite_setPosition(sprite, my_pos);
    }
    return (life2);
}

int clicstart(sfSprite *sprite, sfWindow *Window, int gamestart)
{
    sfVector2f capteur = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(Window);
    if (mouse.x >= capteur.x && mouse.x <= (capteur.x + 300) &&
        mouse.y >= capteur.y && mouse.y <= (capteur.y + 263))
    {
        gamestart++;
    }
}

int main(int argc, char **argv)
{
    int score = 0;
    int gamestart = 0;
    int life2 = 4;
    sfClock *clock;
    sfTime time;
    float seconds;
    clock = sfClock_create();

    sfVideoMode mode = {800, 600, 32};
    char *name = "Window";
    sfRenderWindow *window = sfRenderWindow_create(mode, name, sfClose, NULL);
    sfEvent event;
    if (argc == 2 && argv[1][1] == 'h')
    {
        description();
        return (0);
    }

    sfSprite *sprite = sfSprite_create();
    char *txt3 = "./image/alldragons.png";
    sfTexture *texture = sfTexture_createFromFile(txt3, NULL);
    sfVector2f my_pos = {0, 0};
    sfVector2f scale = {0.525, 0.595};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, my_pos);
    sfSprite_setScale(sprite, scale);

    sfSprite *background = sfSprite_create();
    char *txt2 = "./image/volcano.jpg";
    sfTexture *bg_texture = sfTexture_createFromFile(txt2, NULL);
    sfVector2f bg_pos = {0, 0};

    sfSprite_setTexture(background, bg_texture, sfFalse);
    sfSprite_setPosition(background, bg_pos);
    sfSprite_setScale(background, scale);
    sfSprite *menu_background = sfSprite_create();
    char *txt = "./image/bouton.png";
    sfTexture *background_texture = sfTexture_createFromFile(txt, NULL);
    sfVector2f my_pos2 = {233, 300};

    sfSprite_setPosition(menu_background, my_pos2);
    sfSprite_setTexture(menu_background, background_texture, sfFalse);

    while (sfRenderWindow_isOpen(window))
    {
        if (gamestart == 0)
        {
            sfRenderWindow_drawSprite(window, background, NULL);
            sfRenderWindow_drawSprite(window, menu_background, NULL);
        }
        else
        {
            seconds = time.microseconds / 1000000.0;
            time = sfClock_getElapsedTime(clock);
            if (seconds > 0.15)
            {
                sfClock_restart(clock);
                animation(sprite);
                avancer(sprite);
            }
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, background, NULL);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        life2 = life(sprite, life2);
        if (life2 <= 0)
        {
            sfRenderWindow_close(window);
            my_putstr("Dragons tués: ");
            my_put_nbr(score);
            life2 = 0;
            sfRenderWindow_drawSprite(window, menu_background, NULL);
        }

        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
            {
                score = shoot_the_dragon(sprite, window, score);
                gamestart++;
            }
        }
        sfRenderWindow_display(window);
    }
    return (0);
}