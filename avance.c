/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-mathieu.bobillier
** File description:
** avance.c
*/

#include "my.h"

void avancer(sfSprite *sprite)
{
    sfVector2f trajectoire = sfSprite_getPosition(sprite);
    trajectoire.x += 20;
    trajectoire.y += 0;
    sfSprite_setPosition(sprite, trajectoire);
}