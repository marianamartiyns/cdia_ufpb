def repet(n):
    
    for i in range(n+1):
        
        a = str(i) + " "
        b = a * i
        print(b)
        
num = int(input("Digite um número: "))
repet(num)
