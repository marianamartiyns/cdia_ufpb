
tab = [ " ","a","b","c","d","e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

lista = []
x = 0

print("\nDigite um [30] para Traduzir a mensagem.")

while (x != 30 ):
    
    x = int(input("Informe a letra codificada:"))
     
    if 0 <= x <= 26:
        lista.append(tab[x])
        
    elif x == 30:
        break
    
    else:
        print("Número Inválido!")

    
print("\n Código Traduzido")
print(lista)
