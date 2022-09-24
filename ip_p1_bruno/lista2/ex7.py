# Entrada de dados
vp = float(input("\nDigite o Valor do Produto Comprado: "))
fp = float(input("Digite a Forma de Pagamento (1 - Dinheiro, 2 - Cheque): "))

# vp == Valor do Produto; 
# fp == Forma de Pagamento;
# vd == Valor com Desconto;

if fp == 1 and vp >= 100:
    vd = vp - (vp * 10/100)
    print(f"\nO produto com valor de R${vp}, ficou por R${vd} com o desconto de 10%!") 

elif fp == 1 and vp < 100:
    print(f"\nO total a pagar é R${vp}")
     
elif fp == 2:
    print(f"\nO total a pagar é R${vp}. ")
    
elif fp != 1 and fp !=2:
    print(f"\nForma de Pagamento Inválida.")
