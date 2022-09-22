'''
Introdução a Programação - Bruno Pessoa
Introdução à Linguagem Python (31/08/2022 - 12/09/2022)

1. Conversão de binário para decinal e Vice-versa:

a) 176   b) 202   c) 01110001   d) 10001110'''

f = float(input("Informe a Temperatura em Fahrenheit: "))
celsius = 5 * (f-32) / 9

print(f"A temperatura {f} em Fahrenheit, equivale á {celsius:.2f}º na escala do Celsius")