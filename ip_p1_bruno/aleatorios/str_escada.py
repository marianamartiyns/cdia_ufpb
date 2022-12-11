# Escreva um programa em Python que receba uma string e a imprima na vertical e em formato de escada.

string = input("\nDigite algo: ")

#vertical
for i in range(len(string)):
    
    print(string[i])

#pular linha
print()
   
#escada
for i in range(len(string)):
        
    espaco = int((len(string) - 1) // 2)
    print(''*espaco+string[:i+1])