#Crie um programa para gerar uma matriz de dimensões 3x3 preenchida com valores informados pelo usuário. Além disso, o programa deverá solicitar que o usuário digite um valor e irá verificar se ele pertence à matriz.

matriz = []

for i in range(3):
    for j in range(3):
        matriz.append(int(input("Digite um número:")))