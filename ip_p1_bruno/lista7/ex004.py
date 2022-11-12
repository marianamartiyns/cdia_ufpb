import random
x1 = x2 = x3 = x4 = x5 = x6 = 0
faces = []

print("=== Simulador de Dados ====")
n = int(input("Digite o nº de vezes que o dado será lançado: "))

for i in range(n):
    
    face = random.randint(1,6)
    faces.append(face)
    
    if face == 1:
        x1 += 1
    elif face == 2:
        x2 += 1
    elif face == 3:
        x3 += 1
    elif face == 4:
        x4 += 1
    elif face == 5:
        x5 += 1
    else:
        x6 += 1 
 
        
print(f"\nOs números sorteados foram: {faces}.")    
print(f"""
    Número 1 saiu {x1} vezes. Seu percentual de surgimento foi: {x1/n*100:.0f}%.
    Número 2 saiu {x2} vezes. Seu percentual de surgimento foi: {x2/n*100:.0f}%.
    Número 3 saiu {x3} vezes. Seu percentual de surgimento foi: {x3/n*100:.0f}%.
    Número 4 saiu {x4} vezes. Seu percentual de surgimento foi: {x4/n*100:.0f}%.
    Número 5 saiu {x5} vezes. Seu percentual de surgimento foi: {x5/n*100:.0f}%.
    Número 6 saiu {x6} vezes. Seu percentual de surgimento foi: {x6/n*100:.0f}%.
    """)
