from grafo import MatrizAdjacencia, ListaAdjacencia

def le_arq():

    # Lê o arquivo "pcv10.txt" e cria o grafo a partir dele
    with open("pcv10.txt", "r") as arquivo:

        num_vertices = int(arquivo.readline().strip())
        representacao_matriz = arquivo.readline().strip() == "Matriz"

        if representacao_matriz:
            grafo = MatrizAdjacencia(num_vertices)
        else:
            grafo = ListaAdjacencia(num_vertices)

        for linha in arquivo:
            u, v = map(int, linha.strip().split())
            grafo.adicionar_aresta(u, v)

if __name__ == "__main__":

    # Teste com o arquivo pcv10.txt
    print("Teste com pcv10.txt:")
    graph_pcv10 = le_arq("pcv10.txt")

    graph_pcv10.bfs(0, 5)  # busca em largura
    graph_pcv10.dfs(0)  # busca em profundidade

    # Teste com o arquivo pcv50.txt
    print("\nTeste com pcv50.txt:")
    graph_pcv50 = le_arq("pcv50.txt")

    graph_pcv50.bfs(0, 10)  # busca em largura
    graph_pcv50.dfs(0)  # busca em profundidade
