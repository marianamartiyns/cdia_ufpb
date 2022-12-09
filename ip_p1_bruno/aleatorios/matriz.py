#Faça um programa que leia uma matriz 3x3 digitada pelo usuário, conte quantos números pares há na matriz e depois exiba na tela.

# Não consegui analisar os pares

matriz = []

print("\n== MATRIZ 3x3 ==")

for i in range(3):
    
    linha = []
    for j in range(3):
        
        linha.append(int(input("Digite um valor para a matriz: ")))
        
    matriz.append(linha)
    
pares = 0
for i in range(3):
    for j in range(3):
        if (matriz[i][j] % 2 == 0):
            pares += 1

        

print("\nA matriz ficou:")  
for i in range(3):
    print(matriz[i])
    
    