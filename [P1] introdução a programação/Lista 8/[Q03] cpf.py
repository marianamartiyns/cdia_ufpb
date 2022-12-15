print("\n== Validação do CPF ==")

cpf = input("Digite um CPF(no formato: xxx.xxx.xxx-xx): ")
tam_cpf = len(cpf)

if tam_cpf == 14:
    if '.' in cpf[3]:
        if '.' in cpf[7]:
            if '-' in cpf[11]:

                print(f"O CPF {cpf} é um CPF válido.")
else:
    print(f'\nO CPF {cpf} é um CPF inválido.')