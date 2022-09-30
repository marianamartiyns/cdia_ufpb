'''5. Escreva um programa para verificar se um número é menor, igual ou maior que zero.'''

n = float(input("Digite se um número para verificar se ele é MENOR, IGUAL ou MAIOR que Zero(0): "))

if n < 0:
    print(f"O número {n} é MENOR que zero.")
elif n == 0:
    print(f"O número {n} é IGUAL a zero.")
elif n > 0: 
    print(f"O número {n} é MAIOR que zero.")