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
	float equation[50], x0, fx0, epsilon, x1, fx1, x2, fx2, control=0.0, minrange, maxrange;
    int i, degree;

    printf("Degree of Equation :");
    scanf("%d", &degree);

    for(i = degree; i >= 0; i--)
    {
        printf("x^%d Coefficient of the Term : ", i);
        scanf("%f", &equation[i]);
    }

    printf("Epsilon : ");
    scanf("%f", &epsilon);
	
	printf("Enter min range: ");
	scanf("%f",&minrange);
	
	printf("Enter max range: ");
	scanf("%f",&maxrange);
	
	x0 = minrange;
	x1 = maxrange;
	
	do{	
	fx0 = FunctionResult(equation, degree, x0);
	fx1 = FunctionResult(equation, degree, x1);
	
	x2 = x0 - fx0 * ((x1-x0)/(fx1-fx0));
	fx2 = FunctionResult(equation, degree, x2);
	
	if(fx2 * fx0 > 0){
		control = x2 - x0;
		x0 = x2;
		fx0 = fx2;
	}
	else{
		control = x2 - x1; 
		x1 = x2;
		fx1 = fx2;
	}
	}while(epsilon < control);

	printf("Root: %f\n",x2);
    system("pause");
		
	return 0;
}
