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

int main() {
	
	float fd, bd, cd, dx;
	float equation[50], x0;
    int i, degree;

    printf("Degree of Equation :");
    scanf("%d", &degree);

    for(i = degree; i >= 0; i--)
    {
        printf("x^%d Coefficient of the Term : ", i);
        scanf("%f", &equation[i]);
    }
	
	printf("Enter Delta  (dx): ");
	scanf("%f",&dx);
	
	printf("Enter x0: ");
	scanf("%f",&x0);
	
	// Forward Derivation
	fd = (FunctionResult(equation, degree, x0+dx) - FunctionResult(equation, degree, x0))/dx;
	
	// Backward Derivation
	bd = (FunctionResult(equation, degree, x0) - FunctionResult(equation, degree, x0-dx))/dx;
	
	// Central Derivation
	cd = (FunctionResult(equation, degree, x0+dx) - FunctionResult(equation, degree, x0-dx))/(2*dx);
	// or cd = (fd+bd)/2;
	
	printf("Backward \t Forward \t Central\n");
	printf("%f\t%f\t%f\n", bd, fd, cd);
	system("pause");
	return 0;
}
