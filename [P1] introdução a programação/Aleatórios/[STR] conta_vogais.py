# Escreva um programa em Python para ler uma string e exibir a quantidade de vogais.

c = 0
frase = input("\nDigite um frase: ").lower()

for i in range(len(frase)):
    
    if (frase[i] == 'a'):
        c+=1
        
    elif frase[i] =='e':
        c+= 1
        
    elif frase[i] == 'i':
        c+= 1
        
    elif frase[i] == 'o':
        c+= 1
        
    elif frase[i] == 'u':
        c+= 1
    
print(f"'{frase}' tem {c} vogais.")       







