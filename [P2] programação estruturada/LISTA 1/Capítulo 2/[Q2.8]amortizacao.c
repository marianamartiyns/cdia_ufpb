#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#include <stdio.h>
#include <math.h>
/*
int main() {
    float valor_financiado, taxa_juros, prestacao;
    int num_prestacoes;

    printf("Digite o valor do financiamento: ");
    scanf("%f", &valor_financiado);

    printf("Digite a taxa de juros (em %%): ");
    scanf("%f", &taxa_juros);

    printf("Digite o número de prestações: ");
    scanf("%d", &num_prestacoes);

    taxa_juros = taxa_juros / 100.0; // Converte a taxa de juros para decimal

    prestacao = valor_financiado * (taxa_juros / (1 - pow(1 + taxa_juros, -num_prestacoes)));

    printf("O valor da prestação é: R$ %.2f\n", prestacao);

    return 0;
}
*/

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
    printf(juros);
    valor_prestacao = valor_finan * (juros / ( 1 - pow(1 + juros,-quant_prestacao)));

    printf("\nO financiamento no valor de R$ %d, será quitado após %d parcelas no valor de R$ %d\nJa aplicada uma taxa de juros de %d.", valor_finan, quant_prestacao, valor_prestacao, taxa_juros);

    return 0;
}
