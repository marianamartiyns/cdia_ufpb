# print - n1 // n2
# print - n1 % n2 == n1 - (n2 * (n1 % n2))

n1 = int(input("Digite um número: "))
n2 = int(input("Digite outro número: "))

while True:
    p1 = n1 // n2
    
    if n1 // n2 == 0:
        p2 = n1 - (n2 * (n1 % n2))
    else:
        p2 = 0

    print(f"A divisão inteira de {n1} por {n2} é {p1}. Já o seu resto é {p2}.")
    break
