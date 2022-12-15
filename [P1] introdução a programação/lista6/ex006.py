
print("SEQUÊNCIA DE FIBONACCI")
n = int(input("Digite um número de termos p/ a sequência: "))

t1 = 0
t2 = 1

print(f"\n{t1} -> {t2}", end = '')
cont = 3

for c in range(2, n):
    
    t3 = t1 + t2
    print(f" -> {t3}", end = '')
    t1 = t2
    t2 = t3
 
    