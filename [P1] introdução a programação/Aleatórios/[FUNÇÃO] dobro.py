# Escreva um programa para ler um valor inteiro e calcular seu dobro, utilizando a função dobra() que recebe um número por parâmetro e retorna seu dobro.

def dobro(n):
    
    result = n * 2
    
    return result

print("\n== Dobro de um número ==")
num = int(input("Digite um número: "))

print(f"{num} x 2 é {dobro(num)}.")