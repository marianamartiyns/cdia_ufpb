#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int d_nasc, m_nasc, a_nasc, d_atual, m_atual, a_atual, ano, mes, dia;

    printf("\nDigite a data do nascimento(ex:25/04/2004 = 25 04 2004): ");
    scanf("%d %d %d", &d_nasc, &m_nasc, &a_nasc);

    printf("\nDigite a data de hoje(ex:16/03/2023 = 16 03 2023): ");
    scanf("%d %d %d", &d_atual, &m_atual, &a_atual);

    ano = a_atual - a_nasc;
    mes = m_atual - m_nasc;
    dia = d_atual - d_nasc;

    if ((ano < 0) || ((ano == 0) && (mes < 0)) || ((ano == 0) && (mes== 0) && (dia < 0)))
        printf("\nData de Nascimento Invalída!\n");

    else{
        if (mes < 0){
            ano = ano - 1;
            mes = mes + 12;
        }

        if (dia < 0){
            if (mes > 0)
                mes = mes - 1;
        else
            ano = ano - 1;

        switch (m_nasc){

        case 2 :

        if (a_atual % 4 == 0)
            dia = dia + 29;

        else
            dia =+ 28;
            break;

        case 4: case 6: case 9: case 11:
            dia =+ 30;
            break;

        default: dia =+ 31;
        };
        }
    printf("\nA pessoa nascida em %d/%d/%d tem %d ano(s), %d mes(es) e %d dia(s).\n", d_nasc, m_nasc, a_nasc, ano, mes, dia);
    }

    return 0;
}
