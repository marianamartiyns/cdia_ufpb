#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    float valor_finan, taxa_juros, juros, valor_prestacao, pot, coef, prestacao;
    int quant_prestacao;

    printf("\nDigite o valor do Financiamento: ");
    scanf("%f", &valor_finan);

    printf("\nDigite a quantidade de prestações: ");
    scanf("%d", &quant_prestacao);

    printf("\nDigite o percentual do juros(%): ");
    scanf("%f", &taxa_juros);

    juros = taxa_juros / 100;
    pot = pow(1 + juros, quant_prestacao);
    coef = (pot - 1)/(juros * pot);
    prestacao = valor_finan / coef;

    printf("\nCom a taxa de juros em %.0f%", taxa_juros);
    printf("\nO financiamento no valor de R$ %.2f, será quitado após %d parcelas no valor de R$ %.2f.\n",valor_finan, quant_prestacao, prestacao);

    return 0;
}
