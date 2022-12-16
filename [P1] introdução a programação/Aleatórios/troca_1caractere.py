print("\n== TROCA ESPAÇO ==")

frase = input("Digite uma frase: ").split()
caractere = input("Digite o caractere que irá substituir o espaço: ")

for i in range(len(frase)):
    nova_frase = frase[i].split()
    
    for i in range(len(nova_frase)):
        
        if nova_frase[i] != frase[0]:
            sem_a = nova_frase
      
for i in range(len(sem_a)):
    
    print(sem_a[i], end = caractere)
    
