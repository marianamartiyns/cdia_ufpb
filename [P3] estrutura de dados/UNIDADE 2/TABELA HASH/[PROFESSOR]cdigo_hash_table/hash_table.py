# -*- coding: utf-8 -*-


class Hash_table:
    def __init__(self, s):
        self.size = int(s* 1.25)
        self.T = [[] for _ in range(self.size)]
     
    def __hash_str(self, key_str):
        num = 0
        for c in key_str:
            num += ord(c)
        return num
    
    def __hash(self, key_str):
        key = self.__hash_str(key_str)
        return key % self.size
    
    def insert(self, key, value):
        pos = self.__hash(key)
        self.T[pos].append(value)
    
    def get(self, key):
        pos = self.__hash(key)
        L = self.T[pos]
        for value in L:
            if(value.matricula == key):
                return value
        return None
            
    def print(self):
        print("{")
        for i in range(self.size):
            alunos = self.T[i]
            _str = ""
            for aluno in alunos:
                _str += aluno.to_string() + " "
            print("[" + _str + "]")
        
        print("}")

