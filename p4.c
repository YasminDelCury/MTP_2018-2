#include <stdio.h>

int ack(int m, int n)
{
	if(m>0)
	{
		if(n==0)
	{
		return ack(m-1, 1);
	}
	else if(n>0)
	{
		return ack(m-1, ack(m, n-1));
	}
	}
	if(m==0)
	{
		return n+1;
	}
}

int main()
{
	int m, n;
	printf("\nDigite os valores de m e  n desejados, nessa ordem:");
	scanf("%d%d", &m, &n);
	printf("\n Resultado: %d", ack(m,n));
	return 0;
}
