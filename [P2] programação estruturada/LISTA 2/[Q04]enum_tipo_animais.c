#include <stdio.h>
#include <locale.h>

typedef enum {CACHORRO, GATO, PASSARO}tipo_animais;

typedef struct{
    tipo_animais animais;
    char nome[40];
}animal;

int main(){

    setlocale(LC_ALL, "Portuguese");
	animal a1;

	printf("nome do bicho: ");
	scanf("%s", a1.nome);

	printf("tipo do animal: ");
	scanf("%d", a1.animais);
	return 0;
}
