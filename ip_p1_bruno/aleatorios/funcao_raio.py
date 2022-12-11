def area_circulo(n):
    
    area = 3.14 * (n ** 2)
    
    return area

print("\n == Calculo da Area do Circulo a partir do Raio ==")
print("(Considerando pi = 3.14)")

raio = float(input("Digite o raio: "))
print(f"O Circulo de Raio {raio} tem uma Área de: {area_circulo(raio)}.")