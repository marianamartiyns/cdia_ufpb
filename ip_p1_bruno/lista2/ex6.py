n1 = float(input("Digite a Primeira nota: "))
n2 = float(input("Digite a Segunda nota: "))

media = (n1+n2)/2

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