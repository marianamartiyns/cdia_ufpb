# Escreva um programa em Python que simula o lançamento de um dado N vezes e imprime o percentual de surgimento de cada face do dado. O valor N é introduzido pelo usuário,sendo que zero encerra o programa. Seu Programa deverá utilizar uma lista para armazenar os números de aparecimento de cada face.

import random

faces = []
c1 = c2 = c3 = c4 = c5 = c6 = 0

n = int(input("Digite a quantidade que vezes que o dado será lançado: "))

for i in range(n):
    
    face = random.randint(1,6)
    faces.append(face)
    
    if face == 1:
        c1+= 1
        
    if face == 2:
        c2+=1
        
    if face == 3:
        c3+=1
        
    if face == 4:
        c4+= 1
        
    if face == 5:
        c5+= 1
        
    if face == 6:
        c6+= 1
        
print(f"O dado foi lançado {n} vezes e suas faces foram {faces}.")
print(f"A face 1 caiu {c1} vezes. Percentual = {c1/n*100}")
print(f"A face 2 caiu {c2} vezes. Percentual = {c2/n*100}")
print(f"A face 3 caiu {c3} vezes. Percentual = {c3/n*100}")
print(f"A face 4 caiu {c4} vezes. Percentual = {c4/n*100}")
print(f"A face 5 caiu {c5} vezes. Percentual = {c5/n*100}")
print(f"A face 6 caiu {c6} vezes. Percentual = {c6/n*100}")
        

    