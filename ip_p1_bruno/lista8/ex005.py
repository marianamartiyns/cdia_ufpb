def contador(n):

    lista = []
    lista.append(n)
    letras = len(n)

    '''for i in range(letras):
        
        d = {}
        if lista[i] not in d:
            d[lista[i]] = 1
        
        else:
            #add = d[lista[i]] + 1
            d[lista[i]] =+ 1
            #d[lista[i]] = add
'''
    return lista
    
print("== Contador de Strings ==")
frase = input("Digite uma frase: ").lower()

print(contador(frase))