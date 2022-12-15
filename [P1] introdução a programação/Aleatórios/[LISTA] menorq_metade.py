# Programa que retorna todos os valores da lista menores do que a metade do maior número.

maior = menor = 0

lista = []

print ("\n == Prencha a lista com números e o programa irá retornar todos os valores menores que a metade do maior valor == ")
tam = int(input("\nQuantos números pretende adicionar? "))

for i in range(tam):
    
    lista.append(int(input("Adicione um número: ")))
    
    if lista[i] >= maior:
        maior = lista[i]

metade_maior = maior // 2

menores = []
for i in range(tam):
     
    if lista[i] <= metade_maior:
        menores.append(lista[i])
        
print(f"\nA lista ficou {lista}")
print(f"\nOs números menores que a metade do maior número ({maior} / 2 = {metade_maior}) são:\n {menores}.")
        


    