#include <stdio.h>
#include <math.h>

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

float DerivateResult(float equation[], int N, float x){
	int i;
    float sum = 0.0, factor = 1;

    for(i=1; i <= N; i++)
    {
        sum += equation[i] * factor * i;
        factor *= x;
    }
    return sum;
}

int main() {
	float equation[50], x0, fx0, epsilon, fdx0, x1,control=0.0;
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
     
    printf("Epsilon : ");
    scanf("%f", &epsilon);
	
	printf("Step\tx0\tx1\n");
	
	do{	
	fx0 = FunctionResult(equation, degree, x0);
	fdx0 = DerivateResult(equation, degree, x0);
	x1 = x0 - (fx0/fdx0);
	control = x1-x0;
	printf("%d\t%0.3f\t%0.3f\n",step, x0, x1);
	x0 = x1;
	
	step++;
	}while(epsilon < fabs(control));

	printf("Root: %f\n",x0);
    system("pause");
		
	return 0;
}
