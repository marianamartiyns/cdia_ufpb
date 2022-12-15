# Entrada de dados
print("\n-- Código de Cálculo para IMC --")
print("\nF para Feminino\nM para Masculino\n")
sexo = input("Digite seu sexo: ")

h = float(input("Digite sua altura (ex. : 1.70): "))

if sexo == 'Ff':
    peso = (62.1 * h) - 44.7
else:
    peso = (72.7 * h) - 58
    
print(f"O peso ideal para uma pessoa com altura de {h:.2f} é {peso:.2f}.")