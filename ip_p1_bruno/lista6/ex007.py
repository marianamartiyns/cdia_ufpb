# VERIFICAÇÃO SE UM NÚMERO É PRIMO

n = int(input("Digite um número: "))

d = 0

if n == 0 or n == 1:
    
    print(f"\nO Número {n} NÃO é primo.")
    
if n == 2:
    
    # Caso Particular 
    print(f"\nO Número {n} É primo.")

else:     
    for c in range(1, n):
        
        if n % c == 0:
            
            d += 1
            
            if d > 1:
                break
    
        
    if d > 1:
        
        print(f"\nO número {n} NÃO É primo.")
        
    # TA DANDO ERRO QUANDO COLOCA 1. PARECE QUE É E NAO É.
    else:
        if d != 1:
            print(f"\nO número {n} É primo.")
  

 