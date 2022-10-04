v1 = float(input("Digite um número: "))
v2 = float(input("Digite o 2° número: "))
resp = 0
print("==================")
print('''
      [ 1 ] somar 
      [ 2 ] multiplicar
      [ 3 ] maior
      [ 4 ] novos números
      [ 5 ] sair do programa''')

while resp != 5:
    resp =  (input(">>>>>> Qual é a sua opção: "))
    
    if resp == 1:
        r = v1 + v2
        print(f"A soma é {r}")
    elif resp == 2:
        r = v1 * v2
        print(f"A multiplição resulta em {r}")
    elif resp == 3:
        if v1 > v2:
            print(f"O maior é {v1}")
        else:
            print(f"O menor é {v2}")
    elif resp == 4:
        v1 = input("Digite o numero novo: ")
        v2 = input("Digite o numero novo: ")