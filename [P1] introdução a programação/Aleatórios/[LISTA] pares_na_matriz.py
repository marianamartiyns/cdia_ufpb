# Faça um programa que leia uma matriz 3x3 digitada pelo usuário, conte quantos números pares há na matriz e depois exiba na tela.

matriz = []
pares = []

for i in range(3):
    
    linha = []
    for j in range(3):  
        linha.append(int(input("Digite um número: ")))    
    matriz.append(linha)
    
for i in range(3):
    for j in range(3):
        if (matriz[i][j] % 2 == 0):
            pares.append(matriz[i][j])

print("\nA matriz ficou: ")
for i in range(0,3):   
    print(matriz[i])
    
print(f"\nOs números pares digitados na matriz foram: {pares}")