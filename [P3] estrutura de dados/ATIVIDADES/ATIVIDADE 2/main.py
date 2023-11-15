from hash import Hash_table , Aluno

a1 = Aluno("Mariana", 12)
a2 = Aluno("Jeova", 6)
a3 = Aluno("felly", 24)
a4 = Aluno("carla", 36)
a5 = Aluno("cLAY", 3)
a6 = Aluno("brune", 7)

ht = Hash_table(10)
ht.insert(a1.nome, a1)
ht.insert(a2.nome, a2)
ht.insert(a3.nome, a3)
ht.insert(a4.nome, a4)
ht.insert(a5.nome, a5)
ht.insert(a6.nome, a6)

ht.print()

# Buscando um aluno pelo nome
aluno, _ = ht.get("Maria")
if aluno:
    print("Aluno encontrado:", aluno.to_string())
else:
    print("Aluno não encontrado")
