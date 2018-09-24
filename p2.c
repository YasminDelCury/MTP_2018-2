#include <stdio.h>


int potencia(int exp)
{
    int i=0, p=1;
    while(i<exp)
    {
        p=p*2;
        i++;
    }
    return p;
}

int bindec(char  bits[256])
{
    int i=0, soma=0, p=0,a;
    for(i; bits[i]!='\0'; i++);
    a=i;
    i=0;
    while(bits[i]!='\0')
    {
        bits[i]=bits[i]-48;
        a--;
        soma = soma + (bits[i] * potencia(a));
        i++;

    }
    return soma;
}

void decbin(int num, int bits2[256])
{
    int i=0;
    while(num>=1)
    {
        bits2[i]=num%2;
        num=num/2;
        i++;
    }
    while(i>0)
    {
        i--;
        printf("%d", bits2[i]);
    }
}



int main()
{
    int n=-1, h;
    char bits[256];
    int bits2[256];
    while(n<1 || n>8)
    {
        printf("\nEscolha uma das opcoes a seguir:");
        printf("\n (1) Binario para decimal");
        printf("\n (2) Binario para hexadecimal");
        printf("\n (3) Hexadecimal para decimal");
        printf("\n (4) Hexadecimal para binario");
        printf("\n (5) Decimal para binario");
        printf("\n (6) Decimal para hexadecimal");
        printf("\n (7) Octal para decimal");
        printf("\n (8) Decimal para octal\n");
        scanf("%d", &n);
    }
    switch (n)
    {
         case 1:
            printf("\n\nDigite o numero em binario:");
            scanf("%s", bits);
            printf("\nConversao: %d", bindec(bits));
            break;
         case 2:
            printf("\nDigite o numero em binario:");
            scanf("%s", bits);
            printf("Conversao: %x ", bindec(bits));
            break;
         case 3:
            printf("\nDigite o numero em hexadecimal:");
            scanf("%x", &h);
            printf("Conversao: %d", h);
            break;
         case 4:
            printf("\nDigite o numero em hexadecimal:");
            scanf("%x", &h);
            printf("\nConversao: ");
            decbin(h, bits2);
            break;
         case 5:
            printf("\nDigite o numero em decimal:");
            scanf("%d", &h);
            printf("\nConversao:");
            decbin(h, bits2);
            break;
         case 6:
            printf("\nDigite o numero em decimal:");
            scanf("%d", &h);
            printf("\nConversao: %x", h);
            break;
         case 7:
            printf("\nDigite o numero em octal:");
            scanf("%o", &h);
            printf("\nConversao: %d", h);
            break;
         case 8:
            printf("\nDigite o numero em decimal:");
            scanf("%d", &h);
            printf("\nConversao: %o", h);
            break;
        }
    return 0;
}




