print("== Frase sem Espaços ==")

frase = input("Digite uma frase: ").split()
tamanho = len(frase)

for i in range(tamanho):
    
    if frase[i] != " ":
        a = frase
        
b = len(a)
for i in range(b):
    print(a[i], end = "")