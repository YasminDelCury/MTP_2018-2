/* P5.c */
/* Yasmin Delbany Cury */
/* 11811EEL010 */



#include <stdio.h>

typedef
	unsigned long long int
	Bytes8;
typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual; }
	LCG;

void semente(LCG * r, Bytes8 seed) 
{
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r)
 {
		r->atual = (r->a * r->atual + r->c) % r->m;
		return r->atual;
 }
 
double lcg_rand_01(LCG * r)
 {
		return ((double) lcg_rand(r))/(r->rand_max);
 }
 
void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) 
{
	int i;
	printf("\nForam gerados 50 numeros: \n");
	for(i = 0; i < tam; i++)
	{
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
		printf("%.2f   ", vetor[i]);	
	}
	
}

 float soma(float *inicio_vetor, float *fim_vetor)
 {
 	while(fim_vetor > inicio_vetor)
 	{
 		return *fim_vetor + soma(inicio_vetor, fim_vetor -1);
	}
	if(fim_vetor== inicio_vetor)
	{
		return *inicio_vetor;
	}
 }
 
 float produto(float *inicio_vetor, float *fim_vetor)
 {
 	while(fim_vetor > inicio_vetor)
 	{
 		return *fim_vetor * produto(inicio_vetor, fim_vetor -1);
	}
	if(fim_vetor == inicio_vetor)
	{
		return *inicio_vetor;
	}
	 
 }

int main()
{
	LCG random;
    semente(&random,123456);
    float vet[50];
    float *inicio, *fim;
    int n;
    printf("\nDigite a opcao desejada :\n1- Soma\n2-Produto");
    scanf("%d", &n);
    gera_numeros(vet, 50, 0.5, 1.5, &random);
    inicio = vet;
    fim = &vet[49];
    switch(n)
    {
    	case 1:
    		printf("\nSoma = %.2f ",soma(inicio, fim) );
    		break;
    		
    	case 2:
    		printf("\nProduto = %.2f ", produto(inicio, fim));
			break;	
			
		default:
			printf("\nOpcao inexistente");
			break;
	}
    
    return 0;
}

