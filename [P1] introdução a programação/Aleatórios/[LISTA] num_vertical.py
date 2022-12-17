# Faça um programa que crie uma lista com os valores de 1 a 50 e depois imprima os elementos dessa lista na vertical usando outro laço.

lista = []

for i in range(1,51):
    lista.append(i)
    
for lista[i] in range(len(lista)):
    print(lista[i], end= '\n')