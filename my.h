/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-mathieu.bobillier
** File description:
** my.h
*/

#ifndef MY_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Window.h>
#include <unistd.h>

void avancer(sfSprite *sprite);
int main(argc, argv);
int my_putstr(str);
int clicstart(sfSprite *sprite, sfWindow *Window, int gamestart);
int life(sfSprite *sprite, int life2);
int shoot_the_dragon(sfSprite *sprite, sfWindow *Window, int score);
#endif