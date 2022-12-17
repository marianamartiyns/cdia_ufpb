# Faça um programa que troque a inicial da frase por um caractere ao longo da frase:
# ex: A copa flopou geral == # cop# flopou ger#l

print("\n== TROCA STRING ==")

frase = str(input("Digite uma palavra: "))
caractere = str(input("Digite um caractere para substituir: "))

frase_final = ''

letra = frase[0]

for i in range (len(frase)):
    
    if frase[i] != letra:
        frase_final += frase[i]
        
    else:
        frase_final += caractere
        
print(frase_final)

