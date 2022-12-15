# Entrada dos dados
print("== Tipos de Triângulo ==")
l1 = float(input("Digite o Primeiro lado do Triângulo: "))
l2 = float(input("Digite o Segundo lado do Triângulo: "))
l3 = float(input("Digite o Terceiro lado do Triângulo: "))

if l1 == l2 == l3: # para triângulos equiláteros
    print(f"Os lados do Triângulo são iguais ({l1:.0f} = {l2:.0f} = {l3:.0f}), ou seja, o Triângulo é Equilátero.")
    
elif l1 == l2 or l2 == l3 or l1 == l3: # para triângulos isósceles
    print("Dois dos lados do triângulo são iguais, ou seja, o Triângulo é Isósceles.")

elif l1 != l2 != l3: # para triângulos escalenos
    print(f"O triângulo apresenta 3 lados diferentes ({l1:.0f}, {l2:.0f}, {l3:.0f}), ou seja, o Triângulo é Escaleno.")