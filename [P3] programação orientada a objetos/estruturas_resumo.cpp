#include <iostream>
using namespace std;

int main(void){

/* RESUMO DO USO DAS ESTRUTURAS EM C++ */

/* IF - ELSE

    Pode ser seguido opcionalmente de else para especificar um bloco de código a ser executado quando a expressão é falsa.

*/
    int x = 10;

    if (x > 5) {
        cout << "x é maior que 5" << endl;
    } else {
        cout << "x não é maior que 5" << endl;
    }

/* SWITCH CASE - mesmo jeito que C*/

    int opcao = 2;
    switch (opcao) {
        case 1:
            cout << "Opção 1 selecionada" << endl;
            break;
        case 2:
            cout << "Opção 2 selecionada" << endl;
            break;
        default:
            cout << "Opção inválida" << endl;
    }


/* FOR - É comumente utilizado quando se conhece o número de iterações desejadas. */

    for (int i = 1; i <= 5; i++) { // Isso imprimirá: 1 2 3 4 5
    cout << i << " ";
    }

/* WHILE - É adequada quando o número de iterações não é conhecido previamente e depende de uma condição. */

    int contador = 1;
    while (contador <= 5) { // Isso imprimirá: 1 2 3 4 5
        cout << contador << " ";
        contador++;
    }

/* DO WHILE

    A estrutura do while é semelhante ao while, mas garante que o bloco de código seja executado pelo menos uma vez, pois a condição é verificada após a execução do bloco. 

*/

    int num = 0;
    do {
        cout << "Digite um número maior que zero: ";
        cin >> num;
    } while (num <= 0);



}