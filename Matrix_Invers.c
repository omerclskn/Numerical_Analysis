#include<stdio.h>

int main()
{
	int N,i,j,k;
	float count,m=2.0;
	
	printf("Enter Matrix Size: ");
	scanf("%d",&N);
	
	float Matrix[N][N*2];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Enter %d %d Coefficent: ",i,j);
			scanf("%f",&Matrix[i][j]);
		}
	}
	system("cls");
	printf("Original Matrix: \n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%0.3f ",Matrix[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(i==j)
			{
				Matrix[i][j+N] = 1;
			}
			else
			{
				Matrix[i][j+N] = 0;
			}
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(i!=j){
				
			count = Matrix[j][i]/Matrix[i][i];
			
			for(k=0;k<2*N;k++){
				Matrix[j][k] = Matrix[j][k] - count * Matrix[i][k];
				}
			}
			
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<2*N;j++){
			Matrix[i][j] = Matrix[i][j]/Matrix[i][i];
		}
	}
	
	printf("\nInverse Matrix :\n");
		 for(i=0;i<N;i++)
		 {
			  for(j=N;j<2*N;j++)
			  {
			   	printf("%0.3f  ",Matrix[i][j]);
			  }
			  printf("\n");
		 }
		printf("\n");
	system("pause");	
	return 0;
}
