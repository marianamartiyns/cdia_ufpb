# TOTAL DE GANHO COM JUROS EM DETERMINADO PERÍODO

di = float(input("Digite o Depósito Inicial: ")) # Depósito Inicial
tj = float(input("Quanto é a Taxa de Juros? (ex: 3% = 0.03) ")) # Taxa de Juros

n = 0
for c in range(1, 25):
    
    valor = (di * tj)
    
    print(f"Para o mês {c} o Valor Ficará {valor}")
    
    n += valor
    
tg = n - tj
print(tg)