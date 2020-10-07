#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct fraction
{
    int num;
    int dem;
};

struct fraction fraction_add(struct fraction a, struct fraction b); // additionne les fractions

struct fraction fraction_sub(struct fraction a, struct fraction b); // soustrait les fractions

struct fraction fraction_mul(struct fraction a, struct fraction b); // multiplie les fractions

struct fraction fraction_div(struct fraction a, struct fraction b); // divise les fractions

struct fraction fraction_neg(struct fraction a); // donne l'inverse de la fraction

double fraction_to_double(struct fraction a); // fraction en décimal

struct fraction fraction_pow(struct fraction a, int power); // met une fraction à la puissance entière

void show_fraction(struct fraction a); // affiche une fraction