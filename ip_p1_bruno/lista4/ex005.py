# Leitura dos Dados Referente a uma Dívida e Cálculo dos Meses até a Mesma ser Quitada.

divida = float(input("\nQual o Valor Inicial da sua Dívida? ")) # Valor Inicial

jurm = float(input("Qual é o Juros Mensal? (ex: 3% = 0.03): ")) # Juros por Mês

parcela = float(input("Quanto será pago por mês? ")) # Pagamento por Mês

meses = divida / parcela
saldo = divida
juros = total = c = 0


if (divida * jurm) > parcela:
    print("Valor Não Compatível")
    
else: 
    while meses != juros:
        parcela = parcela + (parcela + juros)
        total = total + parcela
        c += 1
    
    saldo = saldo + juros

print(f"A divida poderá ser paga em {meses} meses, com um total pago de {saldo} e o total de juros de {c}")




