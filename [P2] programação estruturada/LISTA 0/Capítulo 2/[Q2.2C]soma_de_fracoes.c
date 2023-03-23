#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int num1, den1, num2, den2, result, mmc, result_mmc, i, eq_num1, eq_num2, res_num;

    printf("\nLembre-se que o denominador (segundo número) precisa ser diferente de 0!\n");

    do {
    printf("\nDigite a primeira fração (ex: 2/3 = 2 3): ");
    scanf("%d %d",&num1, &den1);} while (den1 == 0);

    do{
    printf("\nDigite a segunda fração (ex: 8/9 = 8 9): ");
    scanf("%d %d",&num2, &den2);} while (den2 == 0);

    if (den1 == den2){

        result = num1 + num2;
        printf("\nA soma das frações inseridas resultou: %d / %d.\n", result, den1);

    }

    else {

    for(i=1; i<=den1 && i<=den2; i++){
      if(den1%i==0 && den2%i==0) {
         mmc = i;
      }
   }

    result_mmc = (den1*den2)/mmc;

    eq_num1 = num1 * (result_mmc / den1);
    eq_num2 = num2 * (result_mmc / den2);
    res_num = eq_num1 + eq_num2;

    printf("\nA soma das frações inseridas resultou: %d / %d.\n", res_num, result_mmc); }

    return 0;
}
