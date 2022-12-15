print("\n== Comparação de Strings ==") # sem considerar os espaços

str1 = input('Digite uma frase: ')
str2 = input('Digite a segunda frase: ')

esp1 = str1.count(" ")
esp2 = str2.count(" ")

compr1 = len(str1) - esp1
compr2 = len(str2) - esp2

if compr1 == compr2:
    print(f"A '{str1}' e '{str2}' possuem o mesmo comprimento.")
    
else:
    print(f"As palavras '{str1}' e '{str2}' não possuem o mesmo comprimento.")