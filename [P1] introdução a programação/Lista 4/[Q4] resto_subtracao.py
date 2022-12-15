# Resto da Dívisão

print("\n== Resto da Divisão ==")
n1 = int(input("\nDigite um número: "))
n2 = int(input("\nDigite outro número: "))

r = 0
resto = n1

while resto >= n2:
    
    resto = resto - n2
    r = r + 1
    
print(f"\nA divisão inteira de {n1} por {n2} é {r}. Já o seu resto é {resto}.")
