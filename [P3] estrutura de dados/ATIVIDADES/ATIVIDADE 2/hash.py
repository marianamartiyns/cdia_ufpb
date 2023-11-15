class Hash_table:

    def __init__(self, s):
        self.size = int(s * 1.25)
        self.T = [[[], []] for _ in range(self.size)]
        
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
        self.T[pos][0].append(key)  # Encadeamento para frente
        self.T[pos][1].append(value)  # Encadeamento para trás
    
    def get(self, key):
        pos = self.__hash(key)
        forward_list = self.T[pos][0]
        backward_list = self.T[pos][1]
        
        for i, value in enumerate(forward_list):
            if value == key:
                return backward_list[i], i
        return None, -1

    def delete(self, key):
        aluno, index = self.get(key)
        if aluno is not None:
            pos = self.__hash(key)
            self.T[pos][0].pop(index)  # Removendo da lista de encadeamento para frente
            self.T[pos][1].pop(index)  # Removendo da lista de encadeamento para trás
            
    def print(self):
        print("{")
        for i in range(self.size):
            backward_list = self.T[i][1]
            _str = ""
            for aluno in backward_list:
                _str += aluno.to_string() + " "
            print("[" + _str + "]")
        print("}")

class Aluno:
    
    def __init__(self, nome, matricula):
        self.nome = nome
        self.matricula = matricula
   
    def to_string(self):
        return self.nome + " - " + str(self.matricula)