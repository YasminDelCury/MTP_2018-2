/* P7.c */
/*Yasmin Delbany Cury*/
/* 11811EEL010 */



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
	int n,i, opcao;
	FILE *pont;
	struct ponto *v;
	char conteudo[700];
	printf("\n1- Gerar arquivo com pontos\n2 - Recuperar pontos de arquivo\nOpcao:");
	scanf("%d", &opcao);
	getchar();
	switch(opcao)
	{
		case 1:
			{
				printf("\n\nEscolha o numero de pontos desejados:");
			    scanf("%d", &n);
			    getchar();
				pont = fopen("pontos.dat", "wb");
				struct ponto *v = (struct ponto *)calloc(n, sizeof(struct ponto));
				gera_pontos(v, n);
				for(i=0;i<n;i++)
						{
							fprintf(pont, "\n %.3f , %.3f", v[i].x, v[i].y);
						}
				free(v);
				fclose(pont);
				printf("\nArquivo salvo com sucesso");
				break;
			}
			
		case 2:
			{

            pont = fopen("pontos.dat", "rb");
            fread(&conteudo, sizeof(char), 700 , pont);
            printf("\nO conteudo do arquivo e:\n %s \n", conteudo);
            fclose(pont);
            break;
			}
			
			
		default:
			printf("\nOpcao nao disponivel");
			break;
			


}
			
	
	
	return 0;
}
