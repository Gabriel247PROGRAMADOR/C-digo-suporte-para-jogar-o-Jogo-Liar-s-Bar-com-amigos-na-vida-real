#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define GREEK_CHARSET 16

// MS-DOS COLORS
void textcolor(int color)
{
    // BLACK=0, BLUE=1; GREEN=2; CYAN=3; RED=4; MAGENTA=5; BROWN=6; LIGHTGRAY=7; DARKGRAY=8;
    // LIGHTBLUE=9; LIGHTGREEN=10; LIGHTCYAN=11, LIGHTRED=12; LIGHTMAGENTA=13; YELLOW=14; WHITE=15
    static int __BACKGROUND;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            color + (__BACKGROUND << 4));
}

void textoSequencial(const char *str, unsigned int delay)
{
    while (*str)
    {
        putchar(*str++);
        fflush(stdout);
        usleep(delay);
    }
}

int GeradorRandomico(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    srand(time(NULL));
    int min, max;
    int qtdJogadores;
    int quemAtira;
    int Nipe;

    // Nome JOGADORES
    char jog1[12];
    char jog2[12];
    char jog3[12];
    char jog4[12];

    // Gatilhos JOGADORES
    int gat1 = 0;
    int gat2 = 0;
    int gat3 = 0;
    int gat4 = 0;

    // Bala ARMA (onde está a bala no tambor de cada pistola de cada jogador)
    int bala1;
    int bala2;
    int bala3;
    int bala4;

    int aleCamara()
    {
        min = 1;
        max = 6;
        // Bala ARMA (onde está a bala no tambor de cada pistola de cada jogador)
        bala1 = GeradorRandomico(min, max);
        bala2 = GeradorRandomico(min, max);
        bala3 = GeradorRandomico(min, max);
        bala4 = GeradorRandomico(min, max);
    }

    int aleRodada()
    {
        min = 1;
        max = 3;
        Nipe = GeradorRandomico(min, max);

        textcolor(9);

        if (Nipe == 1)
        {
            textoSequencial("<<<------------------- Rodada (COPAS) ------------------->>>", 10000);
        }
        else if (Nipe == 2)
        {
            textoSequencial("<<<------------------ Rodada (ESPADAS) ------------------>>>", 10000);
        }
        else if (Nipe == 3)
        {
            textoSequencial("<<<------------------- Rodada (PAUS) -------------------->>>", 10000);
        }
    }

    int darNomes()
    {
        if (qtdJogadores > 1 && qtdJogadores < 5)
        {
            textoSequencial("\n< NOMES { MAX 12 CARACTERES }: >", 5000);
        }
        if (qtdJogadores == 2)
        {
            textoSequencial("\n\nJOGADOR 1: ", 2000);
            fflush(stdin);
            gets(jog1);
            textoSequencial("\nJOGAROR 2: ", 2000);
            fflush(stdin);
            gets(jog2);
        }
        else if (qtdJogadores == 3)
        {
            textoSequencial("\n\nJOGADOR 1: ", 2000);
            fflush(stdin);
            gets(jog1);
            textoSequencial("\nJOGAROR 2: ", 2000);
            fflush(stdin);
            gets(jog2);
            textoSequencial("\nJOGAROR 3: ", 2000);
            fflush(stdin);
            gets(jog3);
        }
        else if(qtdJogadores == 4)
        {

            textoSequencial("\n\nJOGADOR 1: ", 2000);
            fflush(stdin);
            gets(jog1);

            textoSequencial("\nJOGAROR 2: ", 2000);
            fflush(stdin);
            gets(jog2);

            textoSequencial("\nJOGAROR 3: ", 2000);
            fflush(stdin);
            gets(jog3);

            textoSequencial("\nJOGAROR 4: ", 2000);
            fflush(stdin);
            gets(jog4);

        }
        else
        {
            textcolor(12);
            textoSequencial("\nNúmero invalido!!!", 100000);
            textcolor(7);
            textoSequencial("\n\nQuantos vão jogar? \n: ", 5000);
            scanf("%d", &qtdJogadores);
            darNomes();
        }
    }

    int menu()
    {
        system("cls");
        if (qtdJogadores == 2)
        {
            textcolor(15);
            textoSequencial("JOGADOR 1: ", 1000);
            printf("%-12s ", jog1);
            textoSequencial("---- ", 1000);
            if (gat1 > 2)
            {
                textcolor(14);
            }
            if (gat1 == bala1)
            {
                textcolor(6);
            }
            printf("(%d", gat1);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if (gat1 == bala1)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }
            textcolor(15);
            textoSequencial("JOGADOR 2: ", 1000);
            printf("%-12s ", jog2);
            textoSequencial("---- ", 1000);
            if (gat2 > 2)
            {
                textcolor(14);
            }
            if (gat2 == bala2)
            {
                textcolor(6);
            }
            printf("(%d", gat2);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if (gat2 == bala2)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }
        }
        else if (qtdJogadores == 3)
        {
            textcolor(15);
            textoSequencial("JOGADOR 1: ", 1000);
            printf("%-12s ", jog1);
            textoSequencial("---- ", 1000);
            if (gat1 > 2)
            {
                textcolor(14);
            }
            if (gat1 == bala1)
            {
                textcolor(6);
            }
            printf("(%d", gat1);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if (gat1 == bala1)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }
            textcolor(15);
            textoSequencial("JOGADOR 2: ", 1000);
            printf("%-12s ", jog2);
            textoSequencial("---- ", 1000);
            if (gat2 > 2)
            {
                textcolor(14);
            }
            if (gat2 == bala2)
            {
                textcolor(6);
            }
            printf("(%d", gat2);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat2 == bala2)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

            textcolor(15);
            textoSequencial("JOGADOR 3: ", 1000);
            printf("%-12s ", jog3);
            textoSequencial("---- ", 1000);
            if(gat3 > 2)
            {
                textcolor(14);
            }
            if(gat3 == bala3)
            {
                textcolor(6);
            }
            printf("(%d", gat3);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat3 == bala3)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

        }
        else if(qtdJogadores == 4)
        {

            textcolor(15);
            textoSequencial("JOGADOR 1: ", 1000);
            printf("%-12s ", jog1);
            textoSequencial("---- ", 1000);
            if(gat1 > 2)
            {
                textcolor(14);
            }
            if(gat1 == bala1)
            {
                textcolor(6);
            }
            printf("(%d", gat1);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat1 == bala1)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

            textcolor(15);
            textoSequencial("JOGADOR 2: ", 1000);
            printf("%-12s ", jog2);
            textoSequencial("---- ", 1000);
            if(gat2 > 2)
            {
                textcolor(14);
            }
            if(gat2 == bala2)
            {
                textcolor(6);
            }
            printf("(%d", gat2);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat2 == bala2)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

            textcolor(15);
            textoSequencial("JOGADOR 3: ", 1000);
            printf("%-12s ", jog3);
            textoSequencial("---- ", 1000);
            if(gat3 > 2)
            {
                textcolor(14);
            }
            if(gat3 == bala3)
            {
                textcolor(6);
            }
            printf("(%d", gat3);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat3 == bala3)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

            textcolor(15);
            textoSequencial("JOGADOR 4: ", 1000);
            printf("%-12s ", jog4);
            textoSequencial("---- ", 1000);
            if(gat4 > 2)
            {
                textcolor(14);
            }
            if(gat4 == bala4)
            {
                textcolor(6);
            }
            printf("(%d", gat4);
            textoSequencial("/6) CÂMARAS RESTANTES", 1000);
            if(gat4 == bala4)
            {
                textcolor(12);
                textoSequencial(" {MORTO}\n", 1000);
            }
            else
            {
                textcolor(10);
                textoSequencial(" {VIVO}\n", 1000);
            }

        }

        aleRodada();

        textcolor(3);
        textoSequencial("\n\n\n Quem vai atirar em si?\n: ", 3000);
        scanf("%d", &quemAtira);

        textcolor(12);

        switch(quemAtira)
        {

        case 1:
            if(bala1 == gat1)
            {
                textoSequencial("\n\nJOGADOR FORA DE JOGO!!!", 100000);
            }
            else
            {
                gat1 ++;
            }
            break;

        case 2:
            if(bala2 == gat2)
            {
                textoSequencial("\n\nJOGADOR FORA DE JOGO!!!", 100000);
            }
            else
            {
                gat2 ++;
            }
            break;

        case 3:
            if(bala3 == gat3 || qtdJogadores < 3)
            {
                textoSequencial("\n\nJOGADOR FORA DE JOGO!!!", 100000);
            }
            else
            {
                gat3 ++;
            }
            break;

        case 4:
            if(bala4 == gat4 || qtdJogadores < 4)
            {
                textoSequencial("\n\nJOGADOR FORA DE JOGO!!!", 100000);
            }
            else
            {
                gat4 ++;
            }
            break;
        case 999:
            aleCamara();

            gat1 = 0;
            gat2 = 0;
            gat3 = 0;
            gat4 = 0;

            textoSequencial("\nINICIANDO JOGO...", 70000);

            menu();

            break;

        default:
            textoSequencial("\n\nNúmero invalido!!!", 100000);

        }

        menu();

    }

    //---------------------------------------------------
    //CÓDIGO

    textcolor(7);
    textoSequencial("Quantos vão jogar? \n: ", 5000);
    scanf("%d", &qtdJogadores);

    darNomes();

    aleCamara();

    textoSequencial("\nINICIANDO JOGO...", 70000);

    menu();


}








