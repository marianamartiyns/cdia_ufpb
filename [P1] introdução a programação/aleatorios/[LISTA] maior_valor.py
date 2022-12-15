# Programa que retorne o maior valor

maior = 0
numeros = []

print (" == Prencha a lista com números e o programa irá retornar o maior valor entre eles == ")
tam = int(input("Quantos números pretende adicionar? "))

for i in range(tam):
    
    numeros.append(int(input("Adicione um número: ")))

    if numeros[i] >= maior:
        maior = numeros [i]
    
print(f"A lista final ficou: {numeros}.")
print(f"E o maior número entre eles é {maior}.")



