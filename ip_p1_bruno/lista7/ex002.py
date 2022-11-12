m = [[None] * 3 for i in range (0,3)]

for i in range(3):
    for j in range(3):
        m[i][j] = input("Digite um elemento para matriz: ")

#matriz original
print("\nMatriz sem alteração:")
for i in range(3):
    print(m[i])

print("\nDestacando as Variavéis: ")
print(f"Segunda linha: {m[1][0]}, {m[1][1]}, {m[1][2]}.")
print(f"Segunda Coluna: {m[0][1]}, {m[1][1]}, {m[2][1]}.") 

# Salvando as variaveis da linha anterior para mudar as colunas.
x = m[1][0] 
y = m[1][2]
 
# Trocando a Linha pela Coluna    
m[1][0] = m[0][1]
#m[1][1] = m[1][1]
m[1][2] = m[2][1]


# Trocando a Coluna pela Linha.    
m[0][1] = x
#m[1][1] = m[1][1]
m[2][1] = y

print("\nMatriz com os elementos da 2ª linha e 2ª coluna trocados: ")
for i in range(3):
    print(m[i])