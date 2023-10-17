class HashTable:
    
    def __init__(self, n):
        self.n = n
        self.table = [[] for _ in range(10)]

    def hash1(self, c):
        return c % 10

    def hash2(self, c):
        return c % (self.n // 10)

    def insert(self, c):
        index = self.hash1(c)
        self.table[index].append(c)

    def remove(self, c):
        index = self.hash1(c)
        self.table[index].remove(c)

    def search(self, c):
        index = self.hash1(c)
        for i in self.table[index]:
            if i == c:
                return True
        return False

ht = HashTable(100)

# Inserindo elementos
ht.insert(10)
ht.insert(20)
ht.insert(15)

# Procurando elementos
print("Procurando por 10:", ht.search(10))
print("Procurando por 20:", ht.search(20))
print("Procurando por 15:", ht.search(15))

# Removendo elementos
ht.remove(20)

# Procurando elementos após a remoção
print("Procurando por 20:", ht.search(20))
