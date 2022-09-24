# Entrada de dados

# tc == Tipo do Cartão;
# vp == Valor do Produto; 
# fp == Forma de Pagamento;
# vd == Valor com Desconto;

vp = float(input("\nDigite o Valor do Produto Comprado: "))
print("\n 1 - Dinheiro\n 2 - Cheque\n 3 - Cartão\n")
fp = float(input("Digite a Forma de Pagamento : "))

if  fp == 3: 
    print("\n 1 - Débito\n 2 - Crédito\n")
    tc = input("Escolha o Tipo de Cartão: ")
    
if tc == 2:
    parc = (input("\nDigite em quantas parcelas você gostaria de parcelar (2 ou 3): "))  
    
#

if fp == 1: #dinheiro
    
    if vp >= 100:
        vd = vp - (vp * 10/100)
        print(f"\nO produto com valor de R${vp}, ficou por R${vd} com o desconto de 10%!") 

    else:
        print(f"\nO total a pagar é R${vp}")
     
elif fp == 2: #cheque
    print(f"\nO total a pagar é R${vp}. ")
    
elif fp == 3: #cartão
    
    if tc == 1: #tipo do cartão == débito
        print(f"O total a pagar é R${vp}.")
    
    elif tc == 2: #tipo do cartão == crédito
        if parc == 2:
            v_parc = vp / 2
            print(f"O valor a pagar será R$ {v_parc} parcelado em 2 vezes.")
        elif parc == 3:
            v_parc = vp / 3
            print(f"O valor a pagar será R$ {v_parc} parcelado em 3 vezes.")