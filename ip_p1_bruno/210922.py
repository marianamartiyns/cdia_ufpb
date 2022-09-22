'''
Introdução a Programação - Bruno Pessoa
Estruturas de Decisão (12/09/2022 - 21/09/2022)

1. i2 e i5
2. A = 4, B = 13, C = 3

3. Elabore um programa em Python que troque o valor de duas variáveis inteiras.

n1 = int(input("Digite a Primeira Variável: "))
n2 = int(input("Digite a Segunda Variável: "))
n3 = n2 + n1
n2 = n1

print(f"Com a troca de Variáveis V1 ficou {n1} e V2 ficou {n2} e a N3 ficou {n3}")


4. Escreva um programa que leia um número inteiro e imprima se esse número é par ou ímpar.

n = int(input("Digite um número para verificar se ele é PAR ou ÍMPAR: "))

if n % 2 == 0:
    print(f"{n} é PAR.")
else:
    print(f"{n} é ÍMPAR.")
    
5. Escreva um programa para verificar se um número é menor, igual ou maior que zero.

n = float(input("Digite se um número para verificar se ele é MENOR, IGUAL ou MAIOR que Zero(0): "))

if n < 0:
    print(f"O número {n} é MENOR que zero.")
elif n == 0:
    print(f"O número {n} é IGUAL a zero.")
elif n > 0: 
    print(f"O número {n} é MAIOR que zero.")
    
6. Desenvolva um programa que receba o valordo salário bruto, calcule e apresente o valorde desconto do INSS e o valor do saláriolíquido (o salário bruto descontado do INSS),considerando que:
◦ Para um salário de até R$ 420, o desconto de INSS é de 8%;
◦ Para um salário acima de R$ 420 até R$ 1350, o desconto de INSS é de 9%;
◦ Para um salário acima de R$ 1350,00, o desconto de INSS é de 10%;

salario = float(input("Digite seu salário para calcula-lo com o desconto do INSS: "))

if salario < 420:
    desc = salario - (salario * 8/100)
elif salario < 1350:
    desc = salario - (salario * 9/100)
else:
    desc = salario - (salario * 10/100)
    
print(f"Seu salarío de {salario} com desconto ficou {desc}")

7. Escreva um programa que receba as 3 notas obtidas porum aluno, calcule a média aritmética de aproveitamento e apresente o conceito e a situação do aluno (APROVADO ou REPROVADO).
tabela: 
A a partir de 9,0
B De 7,5 a 9,0
C De 6,0 a 7,5
D De 4,0 a 6,0
E Abaixo de 4,0
'''

n1 = float(input("Digite a Primeira nota: "))
n2 = float(input("Digite a Segunda nota: "))
n3 = float(input("Digite a Terceira nota: "))

media = (n1+n2+n3)/3

if media > 9.0:
    print(f"Sua média foi {media:.1f}, sua classificação foi A, e você está APROVADO.")
elif 7.5 > media >= 9:
    print(f"Sua média foi {media:.1f}, sua classificação foi B, e você está APROVADO.")
elif 6 > media >= 7.5:
    print(f"Sua média foi {media:.1f}, sua classificação foi C, e você está APROVADO.")
elif  4 > media > 6:
    print(f"Sua média foi {media:.1f}, sua classificação foi D, e você está REPROVADO.")
else:
    print(f"Sua média foi {media:.1f}, sua classificação foi E, e você está REPROVADO.")