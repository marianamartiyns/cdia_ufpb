'''4. Escreva um programa que leia um número inteiro e imprima se esse número é par ou ímpar.'''

n = int(input("Digite um número para verificar se ele é PAR ou ÍMPAR: "))

if n % 2 == 0:
    print(f"{n} é PAR.")
else:
    print(f"{n} é ÍMPAR.")