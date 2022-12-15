def str_escada(n):

    for i in range(len(n)): 
        print(n[:i+1])
  
print("\n== String em Formato de Escada ==")  
nome = input("Digite uma palavra/frase: ").upper() 
str_escada(nome)
