'''6. Desenvolva um programa que receba o valordo salário bruto, calcule e apresente o valorde desconto do INSS e o valor do saláriolíquido (o salário bruto descontado do INSS),considerando que:
◦ Para um salário de até R$ 420, o desconto de INSS é de 8%;
◦ Para um salário acima de R$ 420 até R$ 1350, o desconto de INSS é de 9%;
◦ Para um salário acima de R$ 1350,00, o desconto de INSS é de 10%;'''

salario = float(input("Digite seu salário para calcula-lo com o desconto do INSS: "))

if salario < 420:
    desc = salario - (salario * 8/100)
elif salario < 1350:
    desc = salario - (salario * 9/100)
else:
    desc = salario - (salario * 10/100)
    
print(f"Seu salarío de {salario} com desconto ficou {desc}")