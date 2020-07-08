#include <stdio.h>

int dotProduct(int A[], int B[], int* AB, int sizeA, int sizeB);

int main()
{
	int AB;
	int A[5]={1,2,3,4,5};
	int B[5]={6,7,8,9,10};
	dotProduct(A,B,&AB,5,5);

	return 0;
}

int dotProduct(int A[], int B[], int* AB, int sizeA, int sizeB)
{
	int i, temp;
	*AB = 0;
	if(A==NULL || B==NULL || sizeA<=0 || sizeB<=0 || sizeA!=sizeB)
		return (-1);
	else
	{
		for(i=0; i<=(sizeA-1); i++){
			temp=A[i]*B[i];
			printf("%d\n", temp);
			*AB = *AB + temp;
		}
		printf("%d\n", *AB);
		return 0;
	}
}
