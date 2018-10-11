#include <stdio.h>

int main()
{
    int i=0;
    char bits[256];
    printf("\nDigite um texto com numeros:");
    scanf("%s", bits);
    printf("\n");
    for(i=0; bits[i]!='\0'; i++)
    {
        if(bits[i]<='9' && bits[i]>='0')
            printf("%c", bits[i]);
    }
    return 0;
}
