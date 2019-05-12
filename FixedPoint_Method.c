#include<stdio.h>
#include<math.h>

// Write f(x) function
#define   f(x)   x*x-2*x-3

// Solve x = g(x) and define g(x)
#define   g(x)   3/(x-2)

// Write derivation of g(x)
#define gd(x) -3/((x-2)*(x-2))

int main()
{
	 int step=1, N, exist=1;
	 float x0, x1, epsilon;
	 
	 printf("Please be sure write the true define functions before the test\n\n");
	 
	 printf("Enter x0: ");
	 scanf("%f", &x0);
	 printf("Enter Epsilon: ");
	 scanf("%f", &epsilon);
	 
	 printf("x0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
	 	if(gd(x0)>=1){
	 		system("cls");
	 		exist = 0;
	 		break;
		 }
	 	
		  x1 = g(x0);
		  printf("%f\t%f\t%f\t%f\n", x0, f(x0), x1, f(x1));
		  
		  x0 = x1;
		  
	 }while( fabs(f(x1)) > epsilon);
	 
	 if(exist == 1){
	 	printf("\nRoot is %f\n", x1);
	 }
	 else{
	 	printf("Function is Divergent, No Root\n");
	 }
	 
	system("pause");
	 return 0;
}
