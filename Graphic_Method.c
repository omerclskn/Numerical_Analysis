#include <stdio.h>

float FunctionResult(float equation[], int N, float x)
{
    int i;
    float sum = 0.0, factor = 1;

    for(i=0; i <= N; i++)
    {
        sum += equation[i] * factor;
        factor *= x;
    }
    return sum;
}

int main()
{
    float equation[50], x0, x1, f0, f1, dx, epsilon;
    int i, degree, step=1;

    printf("Degree of Equation :");
    scanf("%d", &degree);

    for(i = degree; i >= 0; i--)
    {
        printf("x^%d Coefficient of the Term : ", i);
        scanf("%f", &equation[i]);
    }

    printf("x0 value : ");
    scanf("%f", &x0);

    printf("Delta Value (dx) :");
    scanf("%f", &dx);

    printf("Epsilon : ");
    scanf("%f", &epsilon);
	
	printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");	
	
    while(epsilon < dx)
    {
    f0 = FunctionResult(equation, degree, x0);

    x1 = x0 + dx;
    f1 = FunctionResult(equation, degree, x1);
	printf("%d\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
	
    if(f0 * f1 < 0)
        dx /= 2.0;
    else
        x0 = x1;
        step++;
    }
    printf("\nRoot: %f\n", x0);
    system("pause");
    return 0;
}
