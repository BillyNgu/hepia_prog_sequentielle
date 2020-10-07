#include <stdio.h>  /* printf(), scanf() */
#include <stdlib.h> /* srand(), rand() */
#include <time.h>   /* time() */
#include <math.h>   /* log() */

int main()
{
    printf("Veuillez entrer une valeur MAX : ");
    int m;     // max value
    int tryNb; // value user will input
    int c = 0; // count

    scanf("%d", &m); // asks user to put the max value

    srand(time(NULL)); // rng seed

    int r = 0;
    r = rand() % m + 1;
    //printf("rng %d\n", r);
    printf("le nombre de coups optimal est de %d.\n", m / 2);
    while (tryNb != r) // as long as user didn't find the number
    {
        printf("Veuillez entrer une valeur : ");
        scanf("%d", &tryNb);
        c++;
        if (tryNb > r)
        {
            printf("Plus petit !\n");
        }
        else
        {
            printf("Plus grand !\n");
        }
        if (tryNb == r)
        {
            printf("Félicitations !\nVous avez mis %d coups.\n", c);
        }

        if (tryNb > m || tryNb < 1)
        {
            printf("Veuillez entrer une valeur entre 1 et %d.\n", m);
        }
    }

    return 0;
}
