
print("\nDigite 1 para Encerrar o Programa.")
frase = 0
lista = []

while frase != 1:
    
    frase = input("Digite uma frase: ")
    lista.append(frase)
    letras = len(frase)

    for i in range(letras):
        
        d = {}
        if lista[i] not in d:
            d[lista[i]] = 1
        
        else:
            add = d[lista[i]] + 1
            d[lista[i]] = add

    if (frase != 1):
        print(d)

