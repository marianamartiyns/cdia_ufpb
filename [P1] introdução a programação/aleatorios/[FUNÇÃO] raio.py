# Crie um função que tenha como parametro o raio de um circulo e retorne a área do mesmo.

def area_circulo(n):
    
    area = 3.14 * (n ** 2)
    
    return area

print("\n == Calculo da Área do Circulo a partir do Raio ==")
print("(Considerando pi = 3.14)")

raio = float(input("Digite o raio: "))
print(f"O Circulo de Raio {raio} tem uma Área de: {area_circulo(raio)}.")