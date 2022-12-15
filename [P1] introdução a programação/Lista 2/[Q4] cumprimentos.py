# Entrada de dados
print("\n (M) para matutino\n (V) para vespertino\n (N) para noturno")
turno = (input("Digite o turno que você estuda: ")).upper()

if turno == 'M':
    print("Bom Dia!")
elif turno == 'V':
    print("Boa Tarde!")
elif turno == 'N':
    print("Boa Noite!")
else: 
    print("Valor Inválido! :(")