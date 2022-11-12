h = [None] * 10
s = [None] * 10

for i in range(10):
        h[i] = float(input("Altura: ")) 
        s[i] = input("Sexo: ")

maior = menor = 0

for i in range(h):
    
    if h[i] > h[i+1]:
        maior = h[i]
        
    if h[i] < h[i-1]:
        menor = h[i]
   
print(h, maior, menor)
print(s)


