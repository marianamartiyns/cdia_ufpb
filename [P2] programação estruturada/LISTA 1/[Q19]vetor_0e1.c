#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int a[8] = {10, 20, 30, 40, 50, 60, 70, 80};

	int b = a + 2;

	printf("%d", b);


}
