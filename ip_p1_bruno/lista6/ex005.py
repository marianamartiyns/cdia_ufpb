# ELEIÇÃO

print("ELEIÇÃO")
c1 = c2 = c3 = 0
total_ele = int(input("\nDigite o total de eleitores: "))

print(''' 
      NÚMEROS DOS CANDIDATOS:
      Candidato 1 : [10]
      Candidato 2 : [20]
      Candidato 3 : [30]''')

for c in range(total_ele):
    
    voto = int(input("\nDigite o seu Voto: "))

    if voto == 10:
        c1 += 1
        
    if voto == 20:
        c2 += 1
        
    if voto == 30:
        c3 += 1
        
    if voto != 10 and voto != 20 and voto != 30:
        print("Número Invalído. O voto será considerado como NULO.")

    
print(f'''
O Candidato 1 recebeu {c1} voto(s).
O Candidato 2 recebeu {c2} voto(s).
O Candidato 3 recebeu {c3} voto(s).''')