def troca(quero_trocar, trocar_por, frase):
    
    nova = []
    for c in frase:
        if c == quero_trocar:
            nova.append(trocar_por)
        else:
            nova.append(c)

    return ''.join(nova)

print("\n== TROCA INICIAL ==")

frase = frase = input("Digite uma frase: ")
caractere = input("Digite um caractere para substituir: ")

print(troca(frase[0], caractere, frase))
