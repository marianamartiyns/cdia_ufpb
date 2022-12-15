
print("\n == VERIFICAÇÃO: SE UM NÚMERO É PRIMO OU NÃO. ==")
n = int(input("Digite um número: "))
d = 0

if n == 0 or n == 1:
    
    print(f"\nO Número {n} NÃO é primo.")
    
if n == 2:
    
    # Caso Particular 
    print(f"\nO Número {n} É primo.")

else:     
    for c in range(1, n+1):
        if n % c == 0:
            d += 1
        
    if d > 2:
        print(f"\nO número {n} NÃO É primo.")

    elif d == 2:
        print(f"\nO número {n} É primo.")