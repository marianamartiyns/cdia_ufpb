h = []
s = []

maior = menor = 0

print("DIGITE A ALTURA E SEXO DE 5 PESSOAS P VER AS MÉDIAS\n")

for i in range(5):
    
    h.append(float(input("Digite a altura (ex: 1.50): ")))
    s.append(input("Digite o sexo da pessoa (ex: F ou M): ").upper())

    if h[i] >= maior:
        maior = h[i]
        sexo_alta = s[i]
        
    elif h[i] <= menor:
        menor = h[i]
        sexo_baixa = s[i]

    
print(h)
print(s)
print(f"Maior altura: {maior} do sexo {sexo_alta}e menor {menor} e do sexo {sexo_baixa}")
