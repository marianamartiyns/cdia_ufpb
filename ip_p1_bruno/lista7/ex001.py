v1 = [None]*5
v2 = [None]*5
v3 = [None]*10

print("- Programa que lê dois vetores e mostra um terceiro composto pelos outros( com elementos intercalados) -")

print("\nDigite as variavéis para o primeiro vetor.")
for i in range (5):
    v1[i] = input('Informe um Valor: ')
    
print("\nDigite as variavéis para o segundo vetor.")
for i in range (5):
    v2[i] = input('Informe um Valor: ')

v3 = [v1[0], v2[0], v1[1], v2[1], v1[2], v2[2], v1[3], v2[3], v1[4], v2[4]]

print(f"Considerando os vetores: {v1} e {v2}, temos V3 = {v3}")