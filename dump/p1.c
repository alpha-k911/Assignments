#include <stdio.h>
#include <math.h>

int func(int, int);
void con(int, int);

int main()
{
	int A, B, n, d;
	printf("Enter any integer and its base(<10) : ");
	scanf("%d %d", &n, &A);
	printf("Enter the base(<10) to which you have to convert the no to : ");
	scanf("%d", &B);
	if (A>>10 || B>>10)
	printf("Invalid input you will get wrong result");
	d = func(n, A);
	con(d, B);
	return 0;
}

int func(int n, int b)
{
	int i, sum=0;
	for(i=0; i<n; i++)
	{
		sum=sum+((n%b)*pow(b, i));
		n=n/b;
		if (n==0)
		break;
	}
	return(sum);
}

void con(int x, int y)
{
 	int r;
	r=x%y;
	if(r==0)
	return;
	con(x/y, y);
	printf("%d", r);
}

