//Tema: Educativo.
//Grupo: João Eduardo, Luana Pinheiro e Giovanni Marchan.
//versão 0.1 - 28/10/2022 1:39AM

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define coluna 20
#define linha 10

void desenhaMapaNoEscuro(int pi, int pj, int ai, int aj)
{
    for(int i=0; i<linha; i++)
    {
        for(int j=0; j<coluna; j++)
        {
            if(i==pi && j==pj)
            {
                printf(" P");
            }
            else if(i>0 && j>0 && i<linha-1 && j<coluna-1)
            {
                if( i==pi+1 && j==pj || i==pi+1 && j==pj+1 || i==pi+1 && j==pj-1 ||
                        i==pi-1 && j==pj   || i==pi-1 && j==pj+1 || i==pi-1 && j==pj-1 ||
                        i==pi   && j==pj+1 || i==pi && j==pj-1)
                {
                    if (i == ai && j == aj)
                    {
                        printf(" ,");
                    }
                    else
                    {
                        printf(" .");
                    }
                }
                else
                {
                    printf("  ");
                }
            }
            else if(i==0 && pi==1 && j==pj || i==0 && pi==1 && j==pj-1 || i==0 && pi==1 && j==pj+1 ||
                    j==0 && pj==1 && i==pi || j==0 && pj==1 && i==pi-1 || j==0 && pj==1 && i==pi+1 ||
                    j==coluna-1 && pj==coluna-2 && i==pi || j==coluna-1 && pj==coluna-2 && i==pi-1 || j==coluna-1 && pj==coluna-2 && i==pi+1 ||
                    i==linha-1 && pi==linha-2 && j==pj || i==linha-1 && pi==linha-2 && j==pj-1 || i==linha-1 && pi==linha-2 && j==pj+1)
            {
                printf(" #");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void desenhaMapaComLuz(int pi, int pj)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i == 0 || j == 0 || j == coluna - 1 || i == linha - 1)
                printf(" #");
            else if (j == pj && i == pi)
                printf(" P");
            else
                printf(" .");
        }
        printf("\n");
    }
    printf("\n");

}


void desenhaMapa(int pi, int pj)
{
    int ai = 5, aj = 7;
    if(pi != ai && pj != aj || pi == ai && pj !=aj || pi != ai && pj ==aj )
        desenhaMapaNoEscuro(pi, pj, ai, aj);
    else
        desenhaMapaComLuz(pi, pj);
}

void main()
{
    int pi=1, pj=1;
    char comando;
    int movimentoRealizado;



    for( ; ; )
    {
        system("CLS");

        desenhaMapa(pi, pj);



        printf("Comando: w (cima)\td (direita)\ts (baixo)\ta (esquerda)\n");
        printf("Digite um comando: ");
        comando = getch();


        movimentoRealizado = 1;
        switch(comando)
        {
        case 'w':
            pi = pi - 1;
            if (pi < 1)
            {
                pi = 1;
                movimentoRealizado = 0;
            }
            break;

        case 's':
            pi += 1;
            if (pi >= linha - 1)
            {
                pi = linha - 2;
                movimentoRealizado = 0;
            }
            break;

        case 'a':
            pj -= 1;
            if (pj < 1)
            {
                pj = 1;
                movimentoRealizado = 0;
            }
            break;

        case 'd':
            pj += 1;
            if (pj >= coluna - 1)
            {
                pj = coluna - 2;
                movimentoRealizado = 0;
            }
            break;

        default:
            movimentoRealizado = 0;
            printf("Comando invalido!\n");
            printf("Pressione uma tecla para continuar!\n");
            system("PAUSE");
        }
    }
}
