#INCOMPLETO

# Crie um programa para gerar uma matriz de dimensões 3x3 preenchida com valores informados pelo usuário. Além disso, o programa deverá solicitar que o usuário digite um valor e irá verificar se ele pertence à matriz.

matriz = []

for i in range(3):
    linha = []
    for j in range(3):
        linha.append(int(input("Digite um número: ")))
        
    matriz.append(linha)
    
print("A matriz está definida!")

num = int(input("Digite um número para verificar se ele está na matriz: "))

for i in range(3):
    for j in range(3): 
        
        if (num == matriz[i][j]):
            print("Esse número pertence a matriz!")
                    
        else:
            print("Esse número não pertence a matriz!")