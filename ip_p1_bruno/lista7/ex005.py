h = [None] * 10
s = [None] * 10

for i in range(10):
    
    h[i] = float(input("Altura (ex: 1.91): ")) 
    s[i] = input("Sexo ('F' ou 'M'): ")
    
    maior = menor = h[i]

    if h[i] > maior:
        maior = h


    if h[i] < menor:
        menor = h
        
    
        



print(h)
print(s)
print(maior, menor)
print(shm)


