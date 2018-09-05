/* P1.c */
/* Yasmin Delbany Cury */
/* 11811EEL010 */


#include <stdio.h>

int main()
{
    int estado=0, i=0;
    char bits[256];
    printf("Digite o numero em binario:");
    scanf("%s", &bits);
    while(bits[i]!='\0')
    {
        if(bits[i]=='0' && estado==0)
        {
            estado=0;
        }
        else
        {
        if(bits[i]=='1' && estado==0)
            estado=1;

            else
            {
                if(bits[i]=='1' && estado==1)
                    estado=0;
                else
                {
                    if(bits[i]=='0' && estado==1)
                        estado=2;
                    else
                    {
                        if(bits[i]=='1' && estado==2)
                            estado=2;
                        else
                        {
                            if(bits[i]=='0' && estado==2)
                                estado=1;
                        }
                    }
                }
            }

        }

        i++;
    }
    printf("\n %s", bits);
    if(estado==0)
    {
        printf("\ne multiplo de 3");
    }
    else
        printf("\nnao e ");

    return 0;
}