total_ele = int(input("Digite o total de eleitores: "))

print(''' 
      NÚMEROS DOS CANDIDATOS:
      Candidato 1 : [10]
      Candidato 2 : [20]
      Candidato 3 : [30]''')

for c in range(total_ele):
    
    c1 = c2 = c3 = 0
    
    voto = int(input("\nDigite o seu Voto: "))
    
    # dando errado a contagem
    
    if voto == 10:
        c1 = c1 + 1
        
    if voto == 20:
        c2 = c2 + 1
        
    if voto == 30:
        c3 = c3 + 1
        
    #if voto != (10, 20, 30): ou else
        #print("Número Inválido!")
        
print(f'''
O Candidato 1 recebeu {c1} votos.
O Candidato 2 recebeu {c2} votos.
O Candidato 3 recebeu {c3} votos.''')