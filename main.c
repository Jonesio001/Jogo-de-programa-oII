//Tema: Educativo.
//Grupo: João Eduardo, Luana Pinheiro e Giovanni Marchan.
//versão 0.6 - 04/10/2022 14:00PM

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define coluna 18
#define linha 20

typedef struct
{
    int iInicio;
    int iFim;
    int jInicio;
    int jFim;
    int iPorta;
    int jPorta;
    int iInterruptor;
    int jInterruptor;
    int desbloqueado;
    int portaAberta;

} tipoComodo;

void criaComodo(tipoComodo*comodos)
{
    tipoComodo quarto1;
    quarto1.iInicio = 0;
    quarto1.iFim = 8;
    quarto1.jInicio = 0;
    quarto1.jFim = 7;
    quarto1.iPorta = 4;
    quarto1.jPorta = quarto1.jFim;
    quarto1.iInterruptor = 4;
    quarto1.jInterruptor = 4;
    quarto1.desbloqueado = 0;
    quarto1.portaAberta = 1;

    tipoComodo quarto2;
    quarto2.iInicio = quarto1.iInicio;
    quarto2.iFim = 8;
    quarto2.jInicio = 11;
    quarto2.jFim = coluna;
    quarto2.iPorta = 3;
    quarto2.jPorta = quarto2.jInicio;
    quarto2.iInterruptor = 7;
    quarto2.jInterruptor = 16;
    quarto2.desbloqueado = 0;
    quarto2.portaAberta = 0;

    tipoComodo quarto3;
    quarto3.iInicio = quarto2.iFim;
    quarto3.iFim = quarto3.iInicio+5;
    quarto3.jInicio = 12;
    quarto3.jFim = coluna;
    quarto3.iPorta = quarto3.iFim;
    quarto3.jPorta = quarto3.jInicio+3;
    quarto3.iInterruptor = 10;
    quarto3.jInterruptor = 17;
    quarto3.desbloqueado = 0;
    quarto3.portaAberta = 0;

    tipoComodo quarto4;
    quarto4.iInicio = 16;
    quarto4.iFim = quarto4.iInicio+4;
    quarto4.jInicio = 13;
    quarto4.jFim = coluna;
    quarto4.iPorta = quarto4.iInicio;
    quarto4.jPorta = quarto4.jInicio+2;
    quarto4.iInterruptor = 19;
    quarto4.jInterruptor = 17;
    quarto4.desbloqueado = 0;
    quarto4.portaAberta = 0;

    tipoComodo quarto5;
    quarto5.iInicio = 12;
    quarto5.iFim = linha;
    quarto5.jInicio = 0;
    quarto5.jFim = quarto5.jInicio+9;
    quarto5.iPorta = quarto5.iInicio+3;
    quarto5.jPorta = quarto5.jFim;
    quarto5.iInterruptor = 18;
    quarto5.jInterruptor = 3;
    quarto5.desbloqueado = 0;
    quarto5.portaAberta = 0;

    comodos[1] = quarto1;
    comodos[2] = quarto2;
    comodos[3] = quarto3;
    comodos[4] = quarto4;
    comodos[5] = quarto5;
}

void criaMapa(char*mapa, tipoComodo*comodos, int qtdcomodos)
{
    for (int i = 0; i <= linha; i++)
    {
        for (int j = 0; j <= coluna; j++)
        {
            for(int x=0; x<qtdcomodos; x++)
            {
                if(i>=comodos[x].iInicio && i <= comodos[x].iFim && j>=comodos[x].jInicio && j <= comodos[x].jFim)
                {
                    if (    i==comodos[x].iInicio && j!=comodos[x].jPorta || i==comodos[x].iInicio && j==comodos[x].jPorta && i!=comodos[x].iPorta ||
                            i==comodos[x].iFim    && j!=comodos[x].jPorta || i==comodos[x].iFim    && j==comodos[x].jPorta && i!=comodos[x].iPorta ||
                            j==comodos[x].jInicio && i!=comodos[x].iPorta || j==comodos[x].jInicio && i==comodos[x].iPorta && j!=comodos[x].jPorta ||
                            j==comodos[x].jFim    && i!=comodos[x].iPorta || j==comodos[x].jFim    && i==comodos[x].iPorta && j!=comodos[x].jPorta)
                    {
                        mapa[i*coluna+j] = '#';
                        break;
                    }
                    else if (j == comodos[x].jPorta && i == comodos[x].iPorta)
                    {
                        mapa[i*coluna+j] = '@';
                        break;
                    }
                    else if (j == comodos[x].jInterruptor && i == comodos[x].iInterruptor)
                    {
                        mapa[i*coluna+j] =',';
                        break;
                    }
                }
                else if (i == 0 || j == 0 || j == coluna || i == linha)
                    mapa[i*coluna+j] = '#';
                else
                    mapa[i*coluna+j] = '.';
            }
        }
    }

}

void desenhaMapa(int pi, int pj, char*mapa, tipoComodo*comodos, int qtdcomodos)
{
    for(int i=0; i<=linha; i++)
    {
        for(int j=0; j<=coluna; j++)
        {
            for(int x=1; x<qtdcomodos; x++)
            {
                if(i>=comodos[1].iInicio && i <= comodos[1].iFim && j>=comodos[1].jInicio && j <= comodos[1].jFim && comodos[1].desbloqueado ==1 ||
                   i>=comodos[2].iInicio && i <= comodos[2].iFim && j>=comodos[2].jInicio && j <= comodos[2].jFim && comodos[2].desbloqueado ==1 ||
                   i>=comodos[3].iInicio && i <= comodos[3].iFim && j>=comodos[3].jInicio && j <= comodos[3].jFim && comodos[3].desbloqueado ==1 ||
                   i>=comodos[4].iInicio && i <= comodos[4].iFim && j>=comodos[4].jInicio && j <= comodos[4].jFim && comodos[4].desbloqueado ==1 ||
                   i>=comodos[5].iInicio && i <= comodos[5].iFim && j>=comodos[5].jInicio && j <= comodos[5].jFim && comodos[5].desbloqueado ==1 )
                {
                    if(i==pi && j==pj) {
                        printf(" P");
                    } else {
                        printf(" %c", mapa[i*coluna+j]);
                    }
                        break;

                }
                else {
                    desenhaMapaNoEscuro(pi, pj, i, j, mapa, comodos);
                    break;
                }
            }

        }
        printf("\n");
    }
    printf("Comando: w (cima)\td (direita)\ts (baixo)\ta (esquerda)\n");
    printf("Digite um comando: ");
}

void desenhaMapaNoEscuro(int pi, int pj, int i, int j, char*mapa, tipoComodo*comodos)
{
    if(i==pi && j==pj)
        printf(" P");

    else if(mapa[i*coluna+j] != '#' && mapa[i*coluna+j] != '@')
    {
        if(i==pi+1 && j>=pj-1 && j<=pj+1 || i==pi-1 && j>=pj-1 && j<=pj+1 || i==pi && j<=pj+1 && j>=pj-1 && j!=pj)
        {
            if (mapa[i*coluna+j] == ',')
                printf(" ,");
            else
                printf(" .");
        }
        else
            printf("  ");
    }
    else if(mapa[i*coluna+j] == '#' && i==pi-1 && j>=pj-1 && j<=pj+1 || mapa[i*coluna+j] == '#' && j==pj-1 && i>=pi-1 && i<=pi+1 ||
            mapa[i*coluna+j] == '#' && i==pi+1 && j>=pj-1 && j<=pj+1 || mapa[i*coluna+j] == '#' && j==pj+1 && i>=pi-1 && i<=pi+1 )
        printf(" #");

    else if(mapa[i*coluna+j] == '@' && i==pi-1 && j>=pj-1 && j<=pj+1 || mapa[i*coluna+j] == '@' && j==pj-1 && i>=pi-1 && i<=pi+1 ||
            mapa[i*coluna+j] == '@' && i==pi+1 && j>=pj-1 && j<=pj+1 || mapa[i*coluna+j] == '@' && j==pj+1 && i>=pi-1 && i<=pi+1 )
        printf(" @");

    else
        printf("  ");
}

void movimentaPersonagem(char comando, int*pi, int*pj, tipoComodo*comodos, int qtdcomodos)
{
    switch(comando)
    {
    case 'w':
        *pi -= 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (*pi<1 ||
                    *pi == comodos[x].iInicio && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && *pj!=comodos[x].jPorta ||
                    *pi == comodos[x].iFim    && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && *pj!=comodos[x].jPorta
                    || *pj == comodos[x].jPorta  && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jInicio
                    || *pj == comodos[x].jPorta  && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jFim
                    || *pi == comodos[x].iPorta  && *pj == comodos[x].jPorta && comodos[x].portaAberta == 0)
                *pi += 1;

        }
        break;

    case 's':
        *pi += 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (*pi >= linha ||
                    *pi == comodos[x].iInicio && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && *pj!=comodos[x].jPorta ||
                    *pi == comodos[x].iFim    && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && *pj!=comodos[x].jPorta
                    || *pj == comodos[x].jPorta  && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jInicio
                    || *pj == comodos[x].jPorta  && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jFim
                    || *pi == comodos[x].iPorta  && *pj == comodos[x].jPorta && comodos[x].portaAberta == 0)
            {
                *pi -= 1;
            }
        }
        break;

    case 'a':
        *pj -= 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (*pj < 1 ||
                    *pj == comodos[x].jInicio && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && *pi!=comodos[x].iPorta ||
                    *pj == comodos[x].jFim    && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && *pi!=comodos[x].iPorta
                    || *pi == comodos[x].iPorta  && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iFim
                    || *pi == comodos[x].iPorta  && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iInicio
                    || *pi == comodos[x].iPorta  && *pj == comodos[x].jPorta && comodos[x].portaAberta == 0 )
            {
                *pj += 1;
            }
        }
        break;

    case 'd':
        *pj += 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (*pj >= coluna ||
                    *pj == comodos[x].jInicio && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && *pi!=comodos[x].iPorta ||
                    *pj == comodos[x].jFim    && *pi >= comodos[x].iInicio && *pi <= comodos[x].iFim && *pi!=comodos[x].iPorta
                    || *pi == comodos[x].iPorta  && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iFim
                    || *pi == comodos[x].iPorta  && *pj >= comodos[x].jInicio && *pj <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iInicio
                    || *pi == comodos[x].iPorta  && *pj == comodos[x].jPorta && comodos[x].portaAberta == 0
               )
            {
                *pj -= 1;
            }
        }
        break;

    default:
        printf("Comando invalido!\n");
        printf("Pressione uma tecla para continuar!\n");
        system("PAUSE");
    }
}

void criaDisjuntor(int*ai, int*aj, int pi, int pj)
{

    srand(time(NULL));

    for ( ; ; )
    {
        *ai = rand();
        if(*ai>0 && *ai <linha-1 && *ai != pi)
            break;
    }

    for ( ; ; )
    {
        *aj = rand();
        if(*aj>0 && *aj<coluna-1 && *aj!= pj)
            break;
    }

}

int fazPerguntas()
{
    char resposta;
    printf("Pergunta 1 \n");
    scanf("%c", &resposta);
    if (resposta == 'a')
    {
        return 1;
    }
    else
        return 0;
}


void main()
{
    int pi=3, pj=4;
    char comando;
    int ai = 4, aj = 4, proximo = 0, cont = 0;

    int qtdcomodos = 6;
    tipoComodo comodos[6];
    criaComodo(comodos);

    char mapa[linha][coluna];
    criaMapa(mapa, comodos, qtdcomodos);

    for( ; ; )
    {

        for(int x=0; x<qtdcomodos; x++)
        {
            if(pi == comodos[x].iInterruptor && pj == comodos[x].jInterruptor)
            {
                comodos[x].desbloqueado = 1;
                comodos[x+1].portaAberta = 1;
            }
        }

        system("CLS");
        desenhaMapa(pi, pj, mapa, comodos, qtdcomodos);
        movimentaPersonagem(getch(), &pi, &pj, comodos, qtdcomodos);

    }

}
