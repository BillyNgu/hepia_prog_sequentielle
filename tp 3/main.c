#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "fraction.h"

void main()
{
    struct fraction frac;
    struct fraction frac2;
    struct fraction res;
    int choice = 0;
    int power;

    printf("Veuillez entrer la fraction, numérateur et dénominateur : ");
    scanf("%d%d", &frac.num, &frac.dem);
    printf("Veuillez entrer la 2e fraction : ");
    scanf("%d%d", &frac2.num, &frac2.dem);

    while (frac.dem == 0 || frac2.dem == 0)
    {
        if (frac.dem == 0)
        {
            printf("Votre dénominateur ne peut pas être nul.");
            scanf("%d", &frac.dem);
        }
        else
        {
            printf("Votre dénominateur ne peut pas être nul.");
            scanf("%d", &frac2.dem);
        }
    }

    printf("Veuillez choisir une opération : \n");
    printf("1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n5. Afficher son négatif\n6. Afficher sa valeur décimale\n7. Mettre à la puissance entière\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        show_fraction(fraction_add(frac, frac2));
        break;

    case 2:
        show_fraction(fraction_sub(frac, frac2));
        break;

    case 3:
        show_fraction(fraction_mul(frac, frac2));
        break;

    case 4:
        show_fraction(fraction_div(frac, frac2));
        break;

    case 5:
        show_fraction(fraction_neg(frac));
        break;

    case 6:
        printf("%f\n", fraction_to_double(frac));
        break;
    case 7:
        printf("Entrez la puissance : ");
        scanf("%d", &power);
        show_fraction(fraction_pow(frac, power));
        break;

    default:
        break;
    }
}
