sexo = input("Digite seu sexo (F para Feminino ou M para Masculino): ")
h = float(input("Digite sua altura (ex. : 1.70): "))

if sexo == 'Ff':
    peso = (62.1 * h) - 44.7
else:
    peso = (72.7 * h) - 58
    
print(f"O peso ideal para uma pessoa com altura de {h:.2f} é {peso:.2f}.")