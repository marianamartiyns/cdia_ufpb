#Escreva um programa que receba cinco valores do usuário e os armazene em uma lista.

lista = []

for i in range(5):
    lista.append(int(input("Digite um valor: ")))
    
print(lista)