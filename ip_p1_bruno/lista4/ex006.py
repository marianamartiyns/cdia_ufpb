# Simulação de um Sistemas de Vendas

t = 0
 
print('''
      TABELA DE CÓDIGOS: 
      PRODUTO [1] - 5,50
      PRODUTO [2] - 2,30
      PRODUTO [3] - 4,75
      PRODUTO [4] - 6,80
      PRODUTO [5] - 9,30''')

print("\nDigite [0] para ver o total das compras.")

prod = int(input("\nDigite o código do produto? "))
quant = int(input("Digite a quantidade desejada: "))


while prod != 0:
        
    if prod == 1:
        t = quant * 5.50
        
    elif prod == 2:
        t = quant * 2.30
        
    elif prod == 3: 
        t = quant * 4.75
        
    elif prod == 4:
        t = quant * 6.80
        
    elif prod == 5:
        t = quant * 9.30

    prod = int(input("\nDigite o código do produto? "))
    quant = int(input("Digite a quantidade desejada: "))
    
    total =+ t
      
print(total)