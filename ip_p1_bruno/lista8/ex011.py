def conta_dig(n):
    
    c = 0
    while n != 0:
        
        n = n // 10
        c += 1
        
    return c

print("== Contador de Dígitos ==")
num = int(input("Digite um número: "))

print(f"O número {num} tem {conta_dig(num)} dígitos.")
