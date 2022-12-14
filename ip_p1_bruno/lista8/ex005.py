def conta_letra(n):
    
    dic = {}
    
    for i in range(len(n)):
        
        if n[i] not in dic:
            if n[i] != " ":
                dic[n[i]] = 1
        
        else:
            nova_letra = dic[n[i]] + 1
            dic[n[i]] = nova_letra
            
    return dic

print("\n== Conta Letras de uma String ==")
string = input("Digite uma frase: ").upper()
print(f"\nEm {string}. Temos: {conta_letra(string)}.")
