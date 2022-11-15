'''
n = int(input("Digite a quantidade de pontos: "))
lista = []

for i in range(n):
    
    x = (input(f"\nDigite a coordenada x do ponto {i+1}: ") ,) 
    y = (input(f"Digite a coordenada y do ponto {i+1}: ") ,) 
    
    lista.append(x, y)
'''


n = int(input("Digite a quantidade de pontos: "))

p1 = ()  
p2 = ()

for i in range(n):
    
    x = (input(f"\nDigite a coordenada x do ponto {i+1}: ") ,) 
    y = (input(f"Digite a coordenada y do ponto {i+1}: ") ,) 

    p1 += x
    p2 += y

# Distância Euclidiana

for i in range(n):
    
    m = p1[i] - p1[i+1]
    n = p2[i] - p2[i+1]

    d = ( m + n ) ** (1/2)

for c in range(n):
    
    if d > max:
        max = d
        
    if d < min:
        min = d

    media = d / n

print(p1)
print(p2)
print(f"Distância entre os pontos {p1}, {p2} é {d}")
print(min, max, media)

#===============

'''
n = int(input("Digite a quantidade de pontos: "))

    
for i in range(n):
    
    p1 = (input(f"\nDigite a coordenada x do ponto {i+1}: "), ) * n
    p2 = (input(f"Digite a coordenada y do ponto {i+1}: "), ) * n

    for i in range(n):
      
        p1 = ()  
        p2 = ()
    
print(p1)
print(p2)'''