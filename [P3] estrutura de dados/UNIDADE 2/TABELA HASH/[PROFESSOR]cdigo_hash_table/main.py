# -*- coding: utf-8 -*-
from hash_table import Hash_table

class Aluno:
    def __init__(self, nome, matricula):
        self.nome = nome
        self.matricula = matricula
   
    def to_string(self):
        return self.nome + " - " + str(self.matricula)

a1 = Aluno("Maria", 12)
a2 = Aluno("João", 6)
a3 = Aluno("José", 24)
a4 = Aluno("Lucas", 36)
a5 = Aluno("Matheus", 3)
a6 = Aluno("Simão", 7)


ht = Hash_table(10)
ht.insert(a1.nome, a1)
ht.insert(a2.nome, a2)
ht.insert(a3.nome, a3)
ht.insert(a4.nome, a4)
ht.insert(a5.nome, a5)
ht.insert(a6.nome, a6)


ht.print()
#aluno = ht.get()
#print(aluno.to_string())
