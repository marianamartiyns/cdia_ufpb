maior = menor = 0
n = 1

for i in range(n):
    while n != -1:
        print("\nDigite [-1] para interromper o programa")
        n = int(input("Digite um valor: "))
        
        if n == 1:
            maior = n
            menor = n
 
        if n > maior:
            maior = n
            
        if n < menor:
            menor = n
        
print(f"\nO Maior e Menor número digitado foi, respectivamente, {maior} e {menor}\n")