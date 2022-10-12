# Leitura dos Dados Referente a uma Dívida e Cálculo dos Meses até a Mesma ser Quitada.

divida = float(input("Qual o Valor Inicial da sua Dívida? ")) # Valor Inicial

jurm = float(input("Qual é o Juros Mensal? (ex: 3% = 0.03) ")) # Juros por Mês

parcela = float(input("Quanto será pago por mês? ")) # Pagamento por Mês

total = c = 0 # c para contador
meses = divida / parcela


if (divida * jurm) > parcela:
    print("Valor Não Compatível")
    
else: 
    while meses != c:
        parcela = parcela + (parcela + jurm)
        total = total + parcela
        c = c + 1

    total_juros = total - divida

print(f"A dívida poderá ser paga em {meses:.1f} meses, com um total pago de R${total} sendo R${total_juros} o total de juros.")




