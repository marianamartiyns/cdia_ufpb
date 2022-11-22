max = min = med = c = soma = 0

coord_x = []
coord_y = []

print("\n== Distância dos N pontos ==")
n = int(input("\nDigite a quantidade de pontos: "))

#pontos = [None] * n

for i in range(n):
    
    coord_x.append(int(input(f"\nDigite a coordenada x do ponto {i+1}: ")))
    coord_y.append(int(input(f"Digite a coordenada y do ponto {i+1}: ")))
    
for i in range(n):
    for j in range(n):
        
        if j != i:
            # Distância Euclidiana = √((x1 – x2)² + (y1 – y2)²)
            if i == 0:
                dist = ((coord_x[j] - coord_x[i] ** 2) + (coord_y[j] - coord_y[i] ** 2) ** 1/2)
                max = min = dist
                
            else:
                dist = dist = ((coord_x[j] - coord_x[i] ** 2) + (coord_y[j] - coord_y[i] ** 2) ** 1/2)
                
                if dist > max:
                    max = dist
                    
                elif dist <= min:
                    min = dist
            
            c += 1
            soma += dist
                
pontos = ()
for i in range(n):
    
    pontos += ((coord_x[i], coord_y[i]),)
    
med = soma / c
    
print(f"\nAs coordenadas X inseridas foram: {coord_x}")
print(f"As coordenadas Y inseridas foram: {coord_y}")
print(f"As coordenadas dos {n} pontos ficaram {pontos}.")
print(f"A distância maxíma foi {max:.1f}, a mínima foi {min:.1f} e a média foi {med:.1f}.\n")
