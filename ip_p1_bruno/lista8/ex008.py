import random

lista_palavras = ["SORTE", "PYTHON", "PROGRAMAÇÃO", "JAVA", "BRUNO", "MONITOR"]

print("\n == JOGO DA FORCA == ")

palavra = random.choice(lista_palavras)
print("\nA palavra foi sorteada!")
print ( "_ " * len(palavra))

erros = 0
pcerta = ''

while erros < 6:
    
    letra = input('\nDigite uma letra: ').upper()
    
    if letra in palavra:
        pcerta += letra

        linha = 0
        for l in palavra:
            if l in pcerta:
                print(l, end=' ')
            else:
                print('_', end=' ')
                linha += 1

        if linha == 0 and erros == 0:
            print('\nExcepcional! Você acertou a palavra sem cometer erros!')
            break
        elif linha == 0 and (1 <= erros < 6):
            print('\nVocê acertou a palavra. Parabéns!')
            break
    else:
        erros += 1
        print(f'\nVocê errou a {erros}° vez.')
else:
    print(f'\nInfelizmente você perdeu o jogo. A resposta certa é {palavra}.')
