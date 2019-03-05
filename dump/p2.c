#include <stdio.h>
int main()
{
	int n, i, j=0;
	printf(" Enter an integer n(>2): ");
	scanf("%d", &n);
	
	if(n>2)
	{
		if(n%2 == 0)
			{
				printf("No. is not prime\n"); 
				j++;
			}
		else
		{
			for(i=3; i< (n/2); i+2)
			{
				if(n%i == 0)
				{
					printf("No. is not prime\n");
					j++;
					break;
				}
			}
		}
	

		if(j == 0)
		printf("No. is prime\n");
	}
	

	else if (n ==2)
		printf("No. is prime");
	else
		printf("No. is neither prime nor composite");

	return 0;
}
