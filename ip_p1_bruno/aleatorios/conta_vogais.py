# Escreva um programa em Python para ler uma string de 30 caracteres e exibir a quantidade de vogais.


#removem espaços, linhas e símbolos de pontuação
'''texto = texto.replace(" ","")
texto = texto.replace("\n","")
texto = texto.replace(".","")
texto = texto.replace("!","")
texto = texto.replace("?","")
texto = texto.replace(",","")
texto = texto.replace(";","")

#removem acentos e cedilha
texto = texto.replace("á","a")
texto = texto.replace("à","a")
texto = texto.replace("ã","a")
texto = texto.replace("é","e")
texto = texto.replace("ê","e")
texto = texto.replace("í","i")
texto = texto.replace("ó","o")
texto = texto.replace("ô","o")
texto = texto.replace("ú","u")
texto = texto.replace("ç","c")'''

# ------------

'''
vogais = consoantes = 0

print ("\nConta Letras - Vogais e Consoantes\n")

texto = input("Digite algo para contar as vogais: ").lower()

for caracter in texto:
    
    if caracter in 'aeiou':
        vogais += 1
        
    else:
        consoantes += 1
            
        
print (f"Vogais: {vogais}")
print (f"Consoantes: {consoantes}")'''

#nao consigo fazer com função
'''def contador(string):
    
    vogais = consoantes = 0

    for caracter in string:
    
        if caracter in 'aeiou':
            vogais += 1
        
        else:
            consoantes += 1
            
        return vogais
        
print ("\nConta Letras - Vogais e Consoantes\n")
texto = input("Digite algo para contar as vogais: ").lower()
                  
print (f"Vogais: {contador(texto)}")'''
#print (f"Consoantes: {consoantes}")

c = 0
frase = input("\nDigite um frase: ").lower()

for i in range(len(frase)):
    
    if (frase[i] == 'a'):
        c+=1
        
    elif frase[i] =='e':
        c+= 1
        
    elif frase[i] == 'i':
        c+= 1
        
    elif frase[i] == 'o':
        c+= 1
        
    elif frase[i] == 'u':
        c+= 1
    
print(f"'{frase}' tem {c} vogais.")       







