# TABUADA

n = int(input("Digite Algum Número para ver a sua Tabuada: "))

print(f"\n== Tabuada do {n} ==")

for c in range(1,11):
    
    result = n * c
    print(f"{n} x {c} = {result}")
