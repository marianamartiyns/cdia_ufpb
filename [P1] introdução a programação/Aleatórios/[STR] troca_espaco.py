# Programa que troca o espaçamento por um caracter.

print("\n== TROCA ESPAÇO ==")

frase = input("Digite uma frase: ").split()
caractere = input("Digite o caractere que irá substituir o espaço: ")

for i in range(len(frase)):
       
    if frase[i] != " ":
        sem_esp = frase
      
for i in range(len(sem_esp)):
    
    print(sem_esp[i], end = caractere)