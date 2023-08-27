#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int soma_acumulada(int n){

    int acumulador = 0; // 1

    for (int i=0; i < n; i++) { // n
        acumulador += i; // n
    };

    return acumulador; // 1

}; // ordem de complexidade assintótica é O(n)



void exemplo2(int n){

    int a = 0; // 1

    for (int i =0; i < n ; i++){ // n

        for (int j = n; j > i; i--){ // (n²), O 2º loop for é aninhado dentro do primeiro loop e executa em média cerca de n/2 iterações (pois j varia de n para i, e a média é aproximadamente n/2). 

            a += i + j; // n(n+1)/2
        };

        exemplo1(n); // 1, não depende de n então podemos tratá-la como uma operação de tempo constante.
    };
}; // ordem de complexidade assintótica é O(n²)




int A[MAX_SIZE][MAX_SIZE];
int B[MAX_SIZE][MAX_SIZE];
int C[MAX_SIZE][MAX_SIZE];

void exemplo3 (int n){
    
    for( int i =0; i<n; i++){ //n 

        for (int j =0; j<n; j++){ //n²

            C[i][j] = 0; // 1

            for(int k = n-1; k>=0; k--){ //n³

                C[i][j] = A[i][k] * B[i][j]; // 1
            };
        };
    };
}; // ordem de complexidade assintótica é O(n³)



void ordena(int *V, int n) {

    int i, j, min, x;

    for(i=0; i< n-1; i++){ // n

        min = i; // 1

        for(j = i + 1; j <n; j++){ //n²

            if (V[j] < V[min]){ // if vale 0, por isso analisamos o que ta dentro dos () e nesse caso vale 1
                min = j; // 1
            };
        };

        // troca A[min] e A[i]:

        x = V[min]; // 1
        V[min] = V[i]; // 1
        V[i] = x; // 1
    
    };
}; // ordem de complexidade assintótica é O(n²)