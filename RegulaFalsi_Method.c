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

int main() {
	
	float equation[50], a, b, fa, fb, epsilon, c, fc;
    int i, degree, step=1;

    printf("Degree of Equation :");
    scanf("%d", &degree);

    for(i = degree; i >= 0; i--)
    {
        printf("x^%d Coefficient of the Term : ", i);
        scanf("%f", &equation[i]);
    }

    printf("a value : ");
    scanf("%f", &a);

    printf("b value : ");
    scanf("%f", &b);
     
    printf("Epsilon : ");
    scanf("%f", &epsilon);

	fa = FunctionResult(equation, degree, a);
	fb = FunctionResult(equation, degree, b);
	
		if(fa * fb > 0){
			printf("Root not found.\n");
	}
	else {
		printf("\nStep \t a \t f(a) \t b \t f(b) \t c \t f(c)\n");
	do{	
		fa = FunctionResult(equation, degree, a);
		fb = FunctionResult(equation, degree, b);
		
   		 c = (b*fa-a*fb)/(fa-fb);
		fc = FunctionResult(equation, degree, c);
	if(fa*fc > 0){
		a=c;
	}
	else{
		b=c;
	}
	printf("%d\t %0.3f\t %0.3f\t %0.3f\t %0.3f\t %0.3f\t %0.3f\t\n", step, a, fa, b, fb, c, fc);
	step++;
	}while(epsilon < fabs(fc));
}
	printf("Root: %f\n",c);
    system("pause");
	
	return 0;
}
