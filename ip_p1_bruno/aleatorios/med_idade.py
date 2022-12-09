#Escreva um programa para ler a idade de 10 pessoas, calcular a média de idade do grupo e exibir apenas as idades das pessoas acima da média

idade = []
c = soma = 0
lista = []
    

for i in range(10):
    
    idade.append(int(input(f"\nDigite a idade da {i+1}ª pessoa: ")))
    
    
    soma += idade[i]
    media = soma / 10
    

for i in range(10):
    
    if idade[i] > media:
            lista.append(idade[i])

print(f"\nA média das idades foi: {media}.")
print(f"Idades maiores que a media: {lista}")