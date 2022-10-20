# POTÊNCIAÇÃO COM FOR

b = int(input("Digite um valor para a BASE: "))
e = int(input("Digite um valor para o EXPOENTE: "))

result = 1
    
for c in range(e):
    
    result *= b
    
print(f"\n{b} ** {e} = {result}")