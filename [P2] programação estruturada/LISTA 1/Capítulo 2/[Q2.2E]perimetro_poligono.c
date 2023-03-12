#import <stdio.h>
#import <locale.h>

int main() {

    setlocale(LC_ALL, " ");

    int raio, quant_lados;

    printf("Digite a quantidade de lados do poligono: ");
    scanf("%d", &quant_lados);

    printf("Digite o tamanho do raio: ");
    scanf("%d", &raio);



    return 0;
}
