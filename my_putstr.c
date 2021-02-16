/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-mathieu.bobillier
** File description:
** my_putstr.c
*/

int my_putstr(char const *str)
{
    int i;

    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (1);
}