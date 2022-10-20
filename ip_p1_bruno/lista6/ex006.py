# SEQUÊNCIA DE FIBONACCI

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













'''ultimo = 1
penultimo = 1

if (n ==1) or ( n==2):
    
    print("1")
    
else:
    
    for count in range(2,n):
        termo = ultimo + penultimo
        penultimo = ultimo
        ultimo = termo 
        count += 1
        
    print(termo) '''   
    