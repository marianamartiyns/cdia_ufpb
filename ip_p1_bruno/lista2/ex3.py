# Entrada de dados
print("\n-- Código do Cálculo Salarial --")
ganho = float(input("Digite o seu ganho por hora: "))
horas = int(input("Digite o número de horas trabalhadas no mês: "))

# Cálculo (Salário Bruto e Liquído, Imposto de Renda, Sindicato e INSS)
sal_bruto = ganho * horas
ir = sal_bruto * 0.11
inss = sal_bruto * 0.08
sind = sal_bruto * 0.05
sal_liq = sal_bruto - (ir + inss + sind)

print("________________________")
print(f"\nSalário Bruto: R$ {sal_bruto};\n Imposto de Renda: R$ {ir};\n INSS: R${inss};\n Sindicato: R$ {sind}.\n Com todos os descontos, o Salário Liquido ficou: R$ {sal_liq}.\n")
print("________________________")