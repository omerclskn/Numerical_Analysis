#include <stdio.h>
#include <math.h>

// Write down the function here
#define f(x) 1/(2+x*x*x)

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
	
	float h, upper, lower, f0, sum=0;
    int n, counter=0;
	
	printf("Please be sure write the true define functions before the test\n\n");
	
	printf("Enter Lower Limit: ");
	scanf("%f", &lower);
	
	printf("Enter Upper Limit: ");
	scanf("%f", &upper);
	
	printf("Enter n number: ");
	scanf("%d", &n);
	
	h = fabs(upper-lower)/n;
	
	printf("\nx\tf(x)\n");
	do{
		f0 = f(lower);
		
		if(counter == 0 || counter == n){
		sum += f0;
		}
		else if(counter%2 == 1)
		{
			sum += 4*f0;
		}
		else{
			sum += 2*f0;
		}
		printf("%0.3f\t%f\n",lower,f0);
		lower += h;
		counter++;
		
	}while(lower<=upper);
	
	printf("\nResult: %f\n", sum*(h/3) );
	
    system("pause");
	return 0;
}
