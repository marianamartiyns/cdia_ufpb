#import <stdio.h>
#import <locale.h>

int main() {

    setlocale(LC_ALL, " ");

    int valor, resto;

    printf("\nDigite um n�mero de 3 algarismos: ");
    scanf("%d", &valor);

    if (valor >= 0) {
        do {
            resto = valor % 10;
            printf("%d", resto);
            valor /= 10;
        }
        while (valor != 0); printf("\n");
    }
    else
    if (valor <1){
        valor = valor * -1;
        printf("-");

        do{
            resto = valor % 10;
            printf("%d", resto);
            valor /= 10;
        }
        while (valor != 0);
        printf("\n");
    }
    return 0;
}
