import random
x1 = x2 = x3 = x4 = x5 = x6 = 0
faces = []

n = int(input("Digite o nº de vezes que o dado será lançado: "))

for i in range(n):
    
    face = random.randint(1,6)
    faces.append(face)
    
    # ta faltando o percentual
    if face == 1:
        x1 += 1
    if face == 2:
        x2 += 1
    if face == 3:
        x3 += 1
    if face == 4:
        x4 += 1
    if face == 5:
        x5 += 1
    if face == 6:
        x6 += 1 
    

print(faces)