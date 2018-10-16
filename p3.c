/* P3.c */
/* Yasmin Delbany Cury */
/* 11811EEL010 */

#include <stdio.h>

int potencia(int exp)
{
    int i=0, p=1;
    while(i<exp)
    {
        p=p*10;
        i++;
    }
    return p;
}


int main()
{
    int i=0, j=0, num=0, len=0, n=0;
    char bits[256];
	int aux[256];
    printf("\nDigite um texto com numeros:");
    scanf("%s", bits);
    printf("\n");
    for(i=0; bits[i]!='\0'; i++)
    {
        if(bits[i]<='9' && bits[i]>='0')
        {
        	aux[j]=bits[i]-'0';
        	j++;
		}
            
    }
    aux[j]='\0';
    j--;
	while(j>=0)
	{
		num=num + (aux[j])*potencia(n);
		n++;
		j--;
	}
	printf("\nNumero: %d", num);
	return 0;
}
