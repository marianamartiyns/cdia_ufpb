
divida = float(input("Qual o Valor Inicial da sua Dívida? ")) # Valor Inicial

jurm = float(input("Qual é o Juros Mensal? "))

pagm = float(input("Quanto será pago por mês? "))

mes = 1

saldo = divida
juros = 0

if(divida * jurm/100 > pagm):
    print("Erro, Valor Invalído")
    
else: 
    saldo = divida
    jurp = 0
    
    while saldo > pagm:
        jur = saldo * (jurm/100)
        saldo = saldo + jur - pagm
        jurp =+ jur
        mes =+ 1
        
saldo = divida + jurp

print(f"A divida podera ser paga em {mes} meses, com um total pago de {saldo} e o total de juros de {jurp}")




