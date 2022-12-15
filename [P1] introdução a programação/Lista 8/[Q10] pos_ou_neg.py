def pos_neg(a):
    
    if a > 0:
        a = "Positivo"
        
    elif a <= 0:
        a = "Negativo"
        
    return a


print("\n== Positivo ou Negativo ==")
num = int(input("Digite um número: "))

print(f"O número {num} é {pos_neg(num)}.")