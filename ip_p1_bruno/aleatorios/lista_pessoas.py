'''Faça um programa que tenha o seguinte menu:

1 - Incluir pessoa 
2 - Listar pessoas 
3 - Remover pessoa 

<'S' ou 's'> - Sair 

Quando o usuário selecionar a opção 1, o programa pede o nome da pessoa para ser adicionado. 
Quando o usuário digitar a opção 2, o programa lista todas as pessoas cadastradas. Quando o usuário selecionar a opção 3, o programa pede o nome da pessoa que deseja remover. O programa termina quando o usuário digitar o'caractere 'S', maiúsculo ou minúsculo.'''

lista_pessoas = []

print('''
      === Menu de opções ===
      Digite [1] para Incluir um pessoa
      Digite [2] para Listar pessoas
      Digite [3] para Remover uma pessoa
      
      < Selecione 'S' para Sair > 
      ''')

opcao = input("Escolha uma das opções acima: ").upper()

while opcao != 'sS':
    
    if opcao == '1':
        lista_pessoas.append(input("Digite o nome da pessoa que deseja incluir: "))
        
    if opcao == '2':
        print(lista_pessoas)
        
    if opcao == '3':
        lista_pessoas.remove(input("Digite o nome da pessoa que deseja remover: "))
        
    else:
        print("Número Invalído.")
        
print("Programa Encerrado")