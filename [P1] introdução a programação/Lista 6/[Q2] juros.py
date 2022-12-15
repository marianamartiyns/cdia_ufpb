
print("\n== TOTAL DE GANHO COM JUROS EM DETERMINADO PERÍODO ==")
di = float(input("Digite o Depósito Inicial: ")) # Depósito Inicial
tj = float(input("Quanto é a Taxa de Juros? (ex: 3% = 0.03) ")) # Taxa de Juros

tg = juros = 0
dep = di - (di * tj) # Depósito

for c in range(1, 25):
    
    dep = dep - (dep * tj)
    
    print(f"Para o {c}º mês o Valor Ficará {dep:.2f}")
    
    tg += dep # Total Ganho
    juros += dep * tj
    
print(f"\nTotal Acumulado em 24 meses será: R${tg:.2f}, com um desconto total de juros de R${juros:.2f}.")