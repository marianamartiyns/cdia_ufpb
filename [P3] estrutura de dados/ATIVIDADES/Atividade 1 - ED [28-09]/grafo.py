import queue

class Graph:
    def __init__(self, n):
        self.num_vertices = n  # Número de vértices no grafo
        self.matrix = [[0 for _ in range(n)] for _ in range(n)]  # Matriz de Adjacência
        self.list = [[] for _ in range(n)]  # Lista de Adjacência

    def print(self):
        print(self.matrix) # Imprime a Matriz de Adjacência
        print(self.list) # Imprime a Lista de Adjacência

