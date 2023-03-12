#import <stdio.h>
#import <locale.h>

int main(){

    setlocale(LC_ALL, " ");

    int num1, den1, num2, den2, result, result_mmc

    printf("Lembre-se que o denominador (segundo número) precisa ser diferente de 0!");

    do {
    printf("Digite a primeira fração (ex: 2/3 = 2 3): ");
    scanf("%d %d" &num1, &den1)}; while (den1 == 0);

    do{
    printf("Digite a segunda fração (ex: 8/9 = 8 9): ");
    scanf("%d %d" &num2, &den2)}; while (den2 == 0);

    if (den1 == den2){

        result = num1+num2
        printf("A soma das frações inseridas resultou: %d / %d.", result, den1);
    }

    else {

    mmc = x;
    while (mmc % y != 0)
        mmc = mmc + x;

    result_mmc = ((mmc / den1) * num1) +((mmc / den2) * num2))

    printf("A soma das frações inseridas resultou: %d / %d.", result_mmc, mmc); }

    return 0;
}
