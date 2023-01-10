/*
    newton.c: ニュートン法
 */
#include <stdio.h>  // printf, fprintf, fgets, sscanf
#include <stdlib.h> // atof
#include <math.h>   // fabs

/*
    f(x) = x^2 - a
*/
double f(double x, double a)
{
    return pow(x, 2) - a;
}

/*
    f'(x) = 2x
*/
double df(double x)
{
    return 2 * x;
}

/*
    ニュートン法のアルゴリズム
    x0: 初期値
    a: f(x)の引数
    f: f(x)の関数ポインタ
    df: f'(x)の関数ポインタ
    eps: 許容誤差
*/
double newton(double x, double a, double (*f)(double, double), double (*df)(double), double eps)
{
    int n = 0;
    double x0, err;

    printf("# n, x, err\n");
    printf("%4d, % .15e\n", n, x);
    do
    {
        n++;
        x0 = x;
        x = x0 - f(x0, a) / df(x0);
        err = fabs(x - x0);
        printf("%4d, % .15e, % .15e\n", n, x, err);
    } while (err >= eps);
    return x;
}

int main(int argc, char *argv[])
{
    double x, x0, err, eps = 1.0e-10;
    char s[128];

    x = (atof(argv[1]) + 1.0) / 2.0;

    printf("\n# sqrt(%e) =  % .15e\n", atof(argv[1]), newton(x, atof(argv[1]), f, df, eps));
    return 0;
}
