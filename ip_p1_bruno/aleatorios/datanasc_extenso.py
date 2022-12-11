# Faça um programa que solicite a data de nascimento (dd/mm/aaaa) e imprima com o nome do mês por extenso.

print("\n== DATA DE NASCIMENTO POR EXTENSO ==")

lista_str = input("Digite a data de nascimento(dd/mm/aaaa): ").split("/")

mes = int(lista_str[1])

meses = ["Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]

meses[mes-1]

print(f"A data inserida, por exterso, fica: {lista_str[0]} de {meses[mes-1]} de {lista_str[2]}.")