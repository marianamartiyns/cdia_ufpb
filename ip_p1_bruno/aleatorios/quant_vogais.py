
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
def contador(string):
    
    vogais = consoantes = 0

    for caracter in string:
    
        if caracter in 'aeiou':
            vogais += 1
        
        else:
            consoantes += 1
            
        return vogais
        
print ("\nConta Letras - Vogais e Consoantes\n")
texto = input("Digite algo para contar as vogais: ").lower()
                  
print (f"Vogais: {contador(texto)}")
#print (f"Consoantes: {consoantes}")





