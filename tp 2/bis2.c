#include <stdio.h>  /* printf(), scanf() */
#include <stdlib.h> /* srand(), rand() */
#include <stdbool.h>
#include <time.h> /* time() */
#include <math.h> /* log() */

//Notre belle fonction
double g(double x)
{
    double f = (x * x * x * x) + (x * x * x) + (x * x) - 1;
    return f;
}

bool verifcondition(double a1, double b1, double Epsilon)
{
    if (a1 < b1 && Epsilon > 0.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool verifsign(double a1)
{
    return (a1 < 0);
}

int bissection(double a1, double b1, double Epsilon, double *zero)
{
    double c1 = 0;
    int i = 0;
    while (b1 - a1 > Epsilon)
    {
        c1 = (b1 + a1) / 2;
        i++;
        if (verifsign(g(c1)) != verifsign(g(a1)))
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

void main()
{
    double a1;
    double b1;
    double Epsilon;
    double zero;
    int i;
    printf("Bonjour. La bissection, c'est bien. Entrez 3 nombres. a1 et b1 (a1 < b1) et Epsilon (> à 0): \n");
    scanf("%lf %lf %lf", &a1, &b1, &Epsilon);
    printf("test : %lf %lf %lf", a1, b1, Epsilon);

    if (verifcondition)
    {
        //Si on met pas le & on ne pourra pas récupérer la valeur du pointeur dans la fonction bissectrice
        i = bissection(a1, b1, Epsilon, &zero);
        printf("La bissection est de %lf et elle a été trouvée en %d tours de boucle. \n", zero, i);
    }
}
