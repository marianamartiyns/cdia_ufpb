# Leitura e Soma de Números Repetidamente até -1 ser Digitado.

print("\nDigite [-1] para interromper o programa.")
n = int(input("Digite um valor: "))

maior = menor = n
soma = 0 

while n != -1:
    
    if n != -1:
        
        if n > maior:
            maior = n

        if n < menor:
            menor = n
            
    soma = (soma + n) 
           
    print("\nDigite [-1] para interromper o programa.")
    n = int(input("Digite um valor: "))
     
    
print(f"\nO Maior e Menor número digitado foi, respectivamente, {maior} e {menor}, e a soma de todos os valores é: {soma}\n")