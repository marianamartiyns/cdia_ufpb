# Soma de todos os números ímpares múltiplos de 3 entre 1 e 500.

soma = 0
n = 1

while (n <= 500):
    if n % 3 == 0:
        soma = soma + n    
  
print(soma)