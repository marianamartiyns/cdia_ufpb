print("\n== Frase sem Espaços ==")

frase = input("Digite uma frase: ").split()

for i in range(len(frase)):
    
    if frase[i] != " ":
        
        sem_esp = frase
      
for i in range(len(sem_esp)):
    print(sem_esp[i], end = "")