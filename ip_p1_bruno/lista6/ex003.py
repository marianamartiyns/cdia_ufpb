# MÉDIA DE UMA TURMA

n  = t = 1
idades = 0

print('\nDigite [0] para o fim do programa.')

while id != 0:
    
    for c in range(n):
        
        id = int(input("Digite sua Idade: "))
        
        idades += id
        #quando digita 0 o contdor aumenta 1 e a divisao fica errada
        t += n
        
        while t != 0:
            media = idades / (t - 1)
        
if 0 < media <= 25:
    print(f"De acordo com a média da turma, {media}, a turma é JOVEM.")
    
elif  26 < media <= 60:
    print(f"De acordo com a média da turma, {media}, a turma é ADULTA.")
    
elif  media > 60:
    print(f"De acordo com a média da turma, {media}, a turma é VELHA.")
        