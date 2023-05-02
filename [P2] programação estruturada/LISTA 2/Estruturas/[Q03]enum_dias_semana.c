#include <stdio.h>
#include <locale.h>

enum dia_semana{SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO, DOMINGO};

int main(){

    setlocale(LC_ALL, "Portuguese");
	enum dia_semana d = TERCA;

	printf("\nTERÇA == %d\n",d);
	return 0;
}
