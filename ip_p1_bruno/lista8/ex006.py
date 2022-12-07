def str_escada(n):

    for i in range(len(n)): 
        print(n[:i+1])
  
print("== STRING EM FORMATO DE ESCADA ==")  
nome = input("Digite uma palavra/frase: ").upper() 
str_escada(nome)
