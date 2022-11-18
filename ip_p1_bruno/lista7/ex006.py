med = d = 0

print("\n== Distância dos N pontos ==")
n = int(input("\nDigite a quantidade de pontos: "))

p1 = ()  
p2 = ()

for i in range(n):
    
    x = (input(f"\nDigite a coordenada x do ponto {i+1}: ") ,) 
    y = (input(f"Digite a coordenada y do ponto {i+1}: ") ,) 

    p1 += x
    p2 += y


for i in range(n):
    
    dist = []
    
    # Distância Euclidiana = √((x1 – x2)² + (y1 – y2)²)
    m = ((p1[i][0]) - (p1[i][i+1])) ** 2
    n = ((p2[i][0]) - (p2[i][i+1])) ** 2
    
    d = ( m + n ) ** (1/2)
    
    med += d
    dist.append(d)

    if i == 0:
        max = min = d
    
    if d >= max:
        max = d
        
    if d <= min:
        min = d


media = med / n

print(f"\nAs coordenadas X inseridas foram: {p1}")
print(f"As coordenadas Y inseridas foram: {p2}")
print(f"Distância entre os pontos {p1[i]}, {p2[i]} é {dist[i]}")
print(f"A distância maxíma foi {max} e a mínima foi {min}\n")
