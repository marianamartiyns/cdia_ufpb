#include <stdio.h>
#include <stdlib.h>

typedef enum {JUNIOR, PLENO, SENIOR}nivel;

typedef struct{
    float salario_bruto, vale_refeicao, vale_transporte;
}CLT

typedef struct{
    float valor_hora, num_hora_trb, valor_beneficio;
}PJ

typedef union{
    CLT func;
    PJ func
}contrato

typedef struct{


}funcionario
