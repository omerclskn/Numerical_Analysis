#include <stdio.h>
#include <math.h>

// Write the equations with maximum diagonal and convert the equations in terms of variables.

/* 
	3x1 + x2 -2x3 = 9
	-x1 + 4x2 -3x3 = -8
	x1 - x2 + 4x3 = 1
*/

#define f1(x1,x2,x3)  (9-x2+2*x3)/3
#define f2(x1,x2,x3)  (-8+x1+3*x3)/4
#define f3(x1,x2,x3)  (1-x1+x2)/4


int main() {
	
	float epsilon;
	float x1, x2, x3;
	float dx1, dx2, dx3;
	float x10=1, x20=1, x30=1;
	int step=1;
	
	printf("Please be sure write the true define functions before the test\n\n");
	
	printf("Enter epsilon: ");
	scanf("%f", &epsilon);
	
	printf("\nStep\tx1\tdx1\tx2\tdx2\tx3\tdx3\n");
	
	do{

	x1 = f1(x10,x20,x30);
	x2 = f2(x1,x20,x30);
	x3 = f3(x1,x2,x30);
	
	dx1 = fabs(x10 - x1);
	dx2 = fabs(x20 - x2);
	dx3 = fabs(x30 - x3);
	
	
	printf("%d\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\n", step, x1, dx1, x2, dx2, x3, dx3);
	
	x10 = x1; 
	x20 = x2;
	x30 = x3;

	step++;
	}while(dx1 > epsilon && dx2 > epsilon && dx3 > epsilon);
	
	printf("\nx1 = %f\nx2 = %f\nx3 = %f\n\n",x1,x2,x3);
	
	system("pause");
	return 0;
}
