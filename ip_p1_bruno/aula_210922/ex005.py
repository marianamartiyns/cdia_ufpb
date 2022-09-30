'''7. Escreva um programa que receba as 3 notas obtidas porum aluno, calcule a média aritmética de aproveitamento e apresente o conceito e a situação do aluno (APROVADO ou REPROVADO).
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