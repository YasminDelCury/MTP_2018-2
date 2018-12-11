/* Yasmin Delbany Cury */
/* 11811EEL010 */
/* P6.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct ponto
{
	float x;
	float y;
};

void gera_pontos(struct ponto *v, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		v[i].x=cos(i*2.0*M_PI/(n-1));
		v[i].y=sin(i*2.0*M_PI/(n-1));
	}
	
}

int main()
{
	int n,i;
	scanf("%d", &n);
	struct ponto *v = (struct ponto *)calloc(n, sizeof(struct ponto));
	gera_pontos(v,n);
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("(%.3f,%.3f) ", v[i].x, v[i].y);
	}
	free(v);
	return 0;
}
