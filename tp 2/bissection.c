#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double g(double x) // function g(x) = x^4 + x^3 + x^2 - 1
{
    return pow(x, 4) + pow(x, 3) + pow(x, 2) - 1;
}

bool sign(double a) // check the sign of the value
{
    return (a < 0);
}

int bissect(double a1, double b1, double epsilon, double *zero)
{
    double c1 = 0;
    int i = 0; // iteration counter
    while (b1 - a1 > epsilon)
    {
        c1 = (b1 + a1) / 2;
        i++;

        if (sign(g(c1)) != sign(g(a1)))
        {
            b1 = c1;
        }
        else
        {
            a1 = c1;
        }

        *zero = c1;
    }
    return i;
}

int main()
{
    double a, b, e, z;
    int iter;

    printf("a doit être inférieur à b.\n");
    printf("Veuillez entrer la première valeur a : ");
    scanf("%lf", &a);
    printf("Entrez b maintenant : ");
    scanf("%lf", &b);
    printf("Entrez epsilon : ");
    scanf("%lf", &e);

    if (a > b || e < 0 || sign(g(a)) == sign(g(b)))
    {
        printf("Les signes ne sont pas différents.\n");
    }

    iter = bissect(a, b, e, &z);
    printf("Votre zéro se trouve en %lf. Il a fallu %d itérations.\n", z, iter);
}
