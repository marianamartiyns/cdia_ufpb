//INCOMPLETOOOO

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {

    setlocale(LC_ALL, "Portuguese");

    int c = 0, voto, votos_83, votos_93;
    char conf, next;
    //printf("\n== VOTAÇÃO ELEITORAL - SEGUNDO TURNO ==\nDigite [83] para votar no cadidato ALIBADÁ\nDigite [93] para votar no cadidato ALCAPONE\nDigite [00] para votar no 'BRANNCO'.");
    //printf("Voto: ");

    do{
    printf("\n== VOTAÇÃO INICIADA ==");
    printf("\n== VOTAÇÃO ELEITORAL - SEGUNDO TURNO ==\nDigite [83] para votar no cadidato ALIBADÁ\nDigite [93] para votar no cadidato ALCAPONE\nDigite [00] para votar no 'BRANNCO'.");
    printf("\nVoto: ");
    scanf("%d", &voto);

    switch (Voto){

            case 89:
                printf("Você votou no candidato ALIBABA! Confirma seu voto(S/N)? ");
                scanf("%c", &conf);

                if (conf == 's');
                    printf("Voto confirmado!")
                else{
                    printf("\nCorija seu Voto: ");
                    scanf("%d", &voto);

                    if (voto)
                }

                break;

            case 93:
                if (Confirma("Alcapone", &Sim) == 1)
                    ComputaVoto(&Alcapone);
                break;

            case 99:
                if (Confirma("Brancos", &Sim) == 1)
                    ComputaVoto(&Brancos);
                break;

            default:
                if (Confirma("Nulo", &Sim) == 1)
                    ComputaVoto(&Nulos);
                break;
            }
    }
    while (next != 's');
    printf("Outro eleitor (S/N)? ");
    scanf("%d", &next);

    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include <conio.h>

//Função para confirmação do voto
int Confirma(char *s, char *p){

    int r;
    char Conf;

    printf("Voce votou em %s! Confirma seu voto (SN)? ", s);
    fflush(stdin);
    scanf("%c", &Conf);

    if (toupper(Conf) == 'S'){
        *p = 's';
        r = 1;
    }

    else{
        *p = 'n';
        printf("\a Vote de novo: ");
        sound(1000);
        delay(80000);
        nosound();
        r = 0;
    }
    return r;
}

//Função para computar cada voto confirmado para o candidato
void ComputaVoto(int *p){
    *p = *p + 1;
}

//Função principal

main(){

    int Alibaba, Alcapone, Nulos, Brancos, Eleitores, Voto;
    char Sim, Cont;
    clrscr();
    Alibaba = Alcapone = Nulos = Brancos = 0;
    do{
        do{
            printf(" 89 - Alibaba \n 93 - Alcapone \n 99 - Branco \n");
            printf("Digite seu voto: ");
            scanf("%d", &Voto);

            switch (Voto){

            case 89:
                if (Confirma("Alibaba", &Sim) == 1)
                    ComputaVoto(&Alibaba);
                break;

            case 93:
                if (Confirma("Alcapone", &Sim) == 1)
                    ComputaVoto(&Alcapone);
                break;

            case 99:
                if (Confirma("Brancos", &Sim) == 1)
                    ComputaVoto(&Brancos);
                break;

            default:
                if (Confirma("Nulo", &Sim) == 1)
                    ComputaVoto(&Nulos);
                break;
            }
            clrscr();
        }
    while (Sim != 's');
    printf("Outro eleitor (S/N)? ");
    fflush(stdin);
    scanf("%c", &Cont);
    }

    while (toupper(Cont) == 'S');
    Eleitores = Alibaba + Alcapone + Brancos + Nulos;
    printf("Total de eleitores %d \n Alibaba %d \n Alcapone %d \n Brancos %d \n Nulos %d", Eleitores,Alibaba, Alcapone, Brancos, Nulos);
}
*/
