d = float(input("Digite a distância em KM da sua Viagem: "))

if d > 200:
    custo = d * 0.45
    
else:
    custo = d * 0.50
    
print(f"Sua viagem terá {d}, por isso seu custo será {custo:.2f}") 