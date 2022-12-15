# Desenvolva um programa que recebe uma string e depois a exibe de forma invertida.

print("\n== Inversor de String ==")
frase = input('Digite uma frase: ').upper()

inv = frase[::-1]

print(f'\n{frase} ---> {inv}')