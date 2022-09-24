# Entrada dos dados
ganho = float(input("Digite o seu ganho por hora: "))
horas = int(input("Digite o número de horas trabalhadas no mês: "))

# Cálculos dos Descontos e do Salário

sal_bruto = ganho * horas  #Salário Bruto
ir = sal_bruto * 0.11  #Imposto de Renda
inss = sal_bruto * 0.08 
sind = sal_bruto * 0.05  #Sindicato
sal_liq = sal_bruto - (ir + inss + sind)  #Salário Líquido

#Saída
print("________________________")
print(f"\n Salário Bruto: R$ {sal_bruto};\n Imposto de Renda: R$ {ir};\n INSS: R${inss};\n Sindicato: R$ {sind}.\n Com todos os descontos, o Salário Liquido ficou: R$ {sal_liq}.\n")
print("________________________")