turno = (input("Digite o turno que você estuda, \n M (matutino)\n V (vespertino)\n N (noturno):\n "))

if turno == 'M':
    print("Bom Dia!")
elif turno == 'V':
    print("Boa Tarde!")
elif turno == 'N':
    print("Boa Noite!")
else: 
    print("Valor Inválido! :(")