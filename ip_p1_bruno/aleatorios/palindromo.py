
expressao = input('Escreva uma expressão: ').upper().replace(' ', '')

expInv = expressao[::-1]

if expressao == expInv:
    print(f'É palíndromo, pois, {expressao} --> {expInv}.')
    
else:
    print('Não é palíndromo.')