#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main () {

    setlocale(LC_ALL, " ");

    int valor_finan, quant_prestacao, taxa_juros, juros, valor_prestacao;

    printf("\nDigite o valor do Financiamento: ");
    scanf("%d", &valor_finan);
    printf("\nDigite a quantidade de prestações: ");
    scanf("%d", &quant_prestacao);
    printf("\nDigite o percentual do juros(%): ");
    scanf("%d", &taxa_juros);

    juros = taxa_juros / 100;
    valor_prestacao = (valor_finan * juros) / ( 1 - pow((1 + juros),-quant_prestacao));

    printf("\nO financiamento no valor de R$ %d, será quitado após %d parcelas no valor de R$ %d\nJa aplicada uma taxa de juros de %d .", valor_finan, quant_prestacao, valor_prestacao, taxa_juros);

    return 0;
}
