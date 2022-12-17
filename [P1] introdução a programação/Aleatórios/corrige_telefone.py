# INCOMPLETO

# Faça um programa em Python que leia um número de telefone e corrija o número no caso deste conter somente 8 dígitos, adicionando o '9' na frente. O usuário pode informar o número com ou sem o traço separador. Corrija caso ele informe o número sem o traço separador. ex:

# Informe seu número de telefone: 88715498
# Telefone corrigido: 98871-5498


num =(input("Digite um número de telefone (XXXXX-XXXX): "))

for i in range(len(num)):
    
    lista =[]
    lista.append(num.split())


if len(num) <= 8:
    
    num[-9] == '9'
    
print(num)
print(lista)

