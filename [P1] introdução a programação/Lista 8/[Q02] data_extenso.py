print("\n== Data de Nascimento por Extenso ==")

lista_str = input("Digite a data de nascimento(dd/mm/aaaa): ").split("/")

mes = int(lista_str[1])

meses = ["Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]

print(f"A data inserida, por exterso, fica: {lista_str[0]} de {meses[mes-1]} de {lista_str[2]}.")