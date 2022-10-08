#maior = menor = n = soma = 0
# o menor ta dando errad

n = soma = 0

while n != -1 :
    
    print("\nDigite [-1] para interromper o programa.")
    n = int(input("Digite um valor: "))
    
    if n != -1:
        
        maior = menor = n
        
        if n > maior:
            maior = n

        if n < menor:
            menor = n
            
        soma = (soma + n)
    
print(f"\nO Maior e Menor número digitado foi, respectivamente, {maior} e {menor}, e a soma dos valores é: {soma}\n")

'''a = int(input("Digite um número: "))
soma = 0
maior = menor = a

while a != -1:
    if a > maior:
        maior = a
    if a < menor:
        menor = a
    a = int(input("Digite outro número: "))
    soma = soma + a
    
print (maior, menor, soma)'''