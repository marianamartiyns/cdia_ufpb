# Simulação de um Sistemas de Vendas
 
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

soma = total = t = 0

while quant != 0:
     
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
   
    elif prod == 0:
        break
    
    else:
        t = 0
        print("Código Invalído!")


    prod = int(input("\nDigite o código do produto? "))
    quant = int(input("Digite a quantidade desejada: "))
    
    total = total + t
      
print(f"\nO Total da Compra foi: R$ {total:.2f}.")