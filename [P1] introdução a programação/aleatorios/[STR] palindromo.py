# Faça um programa que leia uma string e diga se esta é ou não um palíndromo.

expressao = input('Escreva uma expressão: ').upper().replace(' ', '')

expInv = expressao[::-1]

if expressao == expInv:
    print(f'É palíndromo, pois, {expressao} --> {expInv}.')
    
else:
    print('Não é palíndromo.')