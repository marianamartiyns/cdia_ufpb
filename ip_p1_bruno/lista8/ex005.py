def conta_letra(n):
    
    for i in n:
        
        dic = {}
        tam = len(n)
        
        for n in range(len(n)):
            
            letras = n
            
            if i in letras:
                dic[i] += 1
            
            else:
                dic[i] = 1
            
            
    return dic

string = input("Digite Algo: ").lower()

for chave in conta_letra(string):
    print(f"{chave+1} : {conta_letra(string)[chave]}")
    
''''
dic['LETRAS'] = letras
dic['NUMEROS'] = numeros
print(dic)'''


'''
nome = sys.argv[1]
dic = {}

arq = open(nome, 'r', encoding='utf-8')
for lin in arq:
    lin = lin.strip().lower()
    palavras = lin.split()
    for p in palavras:
        if p in dic:
            dic[p] += 1
        else:
            dic[p] = 1

arq.close()

for chave in dic:
    print('{} = {}'.format(chave, dic[chave]))'''
    
    
    
'''for i in range(letras):
        
        d = {}
        if lista[i] not in d:
            d[lista[i]] = 1
        
        else:
            add = d[lista[i]] + 1
            d[lista[i]] = add

    if (frase != 1):
        print(d)'''
