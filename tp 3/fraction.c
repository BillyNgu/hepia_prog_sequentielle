#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "fraction.h"

void show_fraction(struct fraction a) // affiche la fraction
{
    printf("%d/%d\n", a.num, a.dem);
}

struct fraction fraction_irr(struct fraction a); // rend la fraction irréductible

int pgdc(int a, int b) // plus grand diviseur commun
{
    int tmp_n = a;
    int tmp_m = b;
    while (tmp_n % tmp_m > 0)
    {
        int tmp = tmp_n;
        tmp_n = tmp_m;
        tmp_m = tmp % tmp_m;
    }
    return tmp_m;
}

int ppmc(int a, int b) // plus petit multiple commun
{
    int mul_m = a;
    int mul_n = b;

    while (mul_m != mul_n)
    {
        if (mul_m < mul_n)
        {
            mul_m += a;
        }
        else
        {
            mul_n += b;
        }
    }
    return mul_m;
}

struct fraction fraction_irr(struct fraction a)
{
    struct fraction res;
    int neg;
    int pgdc_c = 0;
    if (a.num < 0)
    {
        neg = a.num * -1;
        pgdc_c = pgdc(neg, a.dem);
        res.num = neg / pgdc_c * -1;
        res.dem = a.dem / pgdc_c;
    }
    else
    {
        pgdc_c = pgdc(a.num, a.dem);
        res.num = a.num / pgdc_c;
        res.dem = a.dem / pgdc_c;
    }

    return res;
}

struct fraction fraction_add(struct fraction a, struct fraction b)
{
    struct fraction res, irr;
    int x = 0;
    int y = 0;

    if (a.dem == b.dem)
    {
        res.dem = a.dem;
        res.num = a.num + b.num;
    }
    else
    {
        res.dem = ppmc(a.dem, b.dem);
        x = res.dem / a.dem;
        y = res.dem / b.dem;
        res.num = a.num * x + b.num * y;
    }
    irr = fraction_irr(res);
    return irr;
}

struct fraction fraction_sub(struct fraction a, struct fraction b)
{
    struct fraction res, irr;
    int x = 0;
    int y = 0;

    if (a.dem == b.dem)
    {
        res.dem = a.dem;
        res.num = a.num - b.num;
    }
    else
    {
        res.dem = ppmc(a.dem, b.dem);
        x = res.dem / a.dem;
        y = res.dem / b.dem;
        res.num = a.num * x - b.num * y;
    }
    irr = fraction_irr(res);
    return irr;
}

struct fraction fraction_mul(struct fraction a, struct fraction b)
{
    struct fraction res, irr;

    res.num = a.num * b.num;
    res.dem = a.dem * b.dem;

    irr = fraction_irr(res);

    return irr;
}

struct fraction fraction_div(struct fraction a, struct fraction b)
{
    struct fraction res, irr;

    res.num = a.num * b.dem;
    res.dem = a.dem * b.num;

    irr = fraction_irr(res);

    return irr;
}

struct fraction fraction_neg(struct fraction a)
{
    struct fraction res, irr;

    res.num = a.num;
    res.dem = a.dem;

    irr = fraction_irr(res);

    irr.num = irr.num * -1;

    return irr;
}

double fraction_to_double(struct fraction a)
{
    double res;
    double num, dem;

    num = a.num;
    dem = a.dem;
    res = num / dem;

    return res;
}

struct fraction fraction_pow(struct fraction a, int power)
{
    struct fraction res, irr;

    res.num = pow(a.num, power);
    res.dem = pow(a.dem, power);

    irr = fraction_irr(res);

    return irr;
}