/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display a number
*/

void my_put_nbr(int nb)
{
    int mod;
    if (nb < 0) {
        if (nb == -2147483648)
            my_putstr("-2147483648");
        else {
            my_putchar('-');
            nb = -nb;
        }
    }
    if (nb >= 0){
        if (nb >= 10){
            mod = nb % 10;
            nb = (nb - mod) / 10;
            my_put_nbr(nb);
            my_putchar(48 + mod);
        }
        else
            my_putchar(48 + nb % 10);
    }
    return (0);
}
