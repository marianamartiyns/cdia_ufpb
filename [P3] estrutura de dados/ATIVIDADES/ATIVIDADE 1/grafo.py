from collections import deque

# Matriz de adjacencia
class MatrizAdjacencia:
    
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.matriz = [[0] * num_vertices for _ in range(num_vertices)]

    def adicionar_aresta(self, u, v):
        self.matriz[u][v] = 1
        self.matriz[v][u] = 1

    # BFS especifico para matriz
    def bfs(self, s, t):

        visited = [False] * self.num_vertices
        queue = []
        parent = [-1] * self.num_vertices
        queue.append(s)
        visited[s] = True

        while queue:
            u = queue.pop(0)
            for v in range(self.num_vertices):
                if not visited[v] and self.matriz[u][v]:
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u

        if not visited[t]:
            print("Não há caminho entre os vértices.")
            return

        path = []
        current = t
        while current != -1:
            path.insert(0, current)
            current = parent[current]

        print("Caminho entre os vértices:", " -> ".join(map(str, path)))

    # dfs para matriz
    def dfs(matrix, start_vertex):

        num_vertices = len(matrix)
        visited = [False] * num_vertices
        stack = []

        stack.append(start_vertex)

        while stack:
            vertex = stack.pop()
            if not visited[vertex]:
                print(vertex, end=' ') 
                visited[vertex] = True

                # Empilha todos os vizinhos não visitados
                for neighbor in range(num_vertices):
                    if matrix[vertex][neighbor] == 1 and not visited[neighbor]:
                        stack.append(neighbor)


# Lista de adjacencia 
class ListaAdjacencia:

    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.lista = [[] for _ in range(num_vertices)]

    def adicionar_aresta(self, u, v):
        self.lista[u].append(v)
        self.lista[v].append(u)

    # BFS especifico para Lista
    def bfs(self, s, t):

        visited = [False] * self.num_vertices
        queue = []
        parent = [-1] * self.num_vertices
        queue.append(s)
        visited[s] = True

        while queue:
            u = queue.pop(0)
            for v in self.lista[u]:
                if not visited[v]:
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u

        if not visited[t]:
            print("Não há caminho entre os vértices.")
            return

        path = []
        current = t
        while current != -1:
            path.insert(0, current)
            current = parent[current]

        print("Caminho entre os vértices:", " -> ".join(map(str, path)))


    # DFS especifico para Lista 
    def dfs(graph, start_vertex):
        visited = [False] * graph.vertices
        stack = deque()

        stack.append(start_vertex)

        while stack:
            vertex = stack.pop()
            if not visited[vertex]:
                print(vertex, end=' ')
                visited[vertex] = True

                # Empilha todos os vizinhos não visitados
                for neighbor in reversed(graph.adjacency_list[vertex]):
                    if not visited[neighbor]:
                        stack.append(neighbor)






