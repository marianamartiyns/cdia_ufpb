# MÉDIA DE UMA TURMA

n = 1
idades = t = 0

print('\nDigite [0] para o fim do programa.')

while id != 0:
      
    for c in range(n):
        
        id = int(input("Digite sua Idade: "))
        
        idades += id
        t += n

t -= 1    
media = idades / t
    
 
if 0 < media <= 25:
    print(f"De acordo com a média da turma ({media}), a turma é JOVEM.")
    
elif  26 < media <= 60:
    print(f"De acordo com a média da turma ({media}), a turma é ADULTA.")
    
elif  media > 60:
    print(f"De acordo com a média da turma ({media}), a turma é VELHA.")
        