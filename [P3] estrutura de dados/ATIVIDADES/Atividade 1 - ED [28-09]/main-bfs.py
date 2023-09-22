# Busca em Largura (fila)

import queue
from collections import deque

class Graph:
    
    def __init__(self, n):
        self.num_vertices = n  # Número de vértices no grafo
        self.matrix = [[0 for _ in range(n)] for _ in range(n)] # Matriz de Adjacência
        self.list = [[] for _ in range(n)]  # Lista de Adjacência

    def print(self):
        print(self.matrix) # Imprime a Matriz de Adjacência
        print(self.list) # Imprime a Lista de Adjacência

    def bfs(self, s, t):
        if s < 0 or s >= self.num_vertices or t < 0 or t >= self.num_vertices:
            return "Vértices fora do intervalo"

        visited = [False] * self.num_vertices
        parent = [-1] * self.num_vertices
        queue = queue.Queue()
        queue.put(s)
        visited[s] = True

        while not queue.empty():
            current = queue.get()
            if current == t:
                break
            for neighbor in self.list[current]:
                if not visited[neighbor]:
                    queue.put(neighbor)
                    visited[neighbor] = True
                    parent[neighbor] = current

        if not visited[t]:
            return "Não há caminho entre os vértices"

        path = []
        while t != -1:
            path.insert(0, t)
            t = parent[t]

        return path
