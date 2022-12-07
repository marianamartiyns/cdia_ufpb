def soma(x,y,z):
    result = (x + y + z)
    return result

print("== SOMA DE 3 VARIAVEIS ==")

num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))
num3 = int(input("Digite o terceiro número: "))

print(f"A soma de {num1} + {num2} + {num3} = {soma(num1, num2, num3)}.")