

vi = float(input("Qual o Valor Inicial da sua Dívida? "))
juros_mes = float(input("Qual é o Juros Mensal? "))
parc_vi = float(input("Quanto será pago por mês? "))

mes = 1

saldo = vi
juros = 0

while saldo > parc_vi:
    juros = saldo * (juros_mes/100)
    saldo = saldo + juros - parc_vi
    juros = jurp

#num_meses = vi / ? 
#total_pg = num_meses * ((juros * num_meses) + parc_vi )
#tot_juros = juros * num _meses