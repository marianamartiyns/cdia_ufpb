'''Usando a implementação de busca em largura que foi vista no vídeo como base, crie uma implementação similar para a busca em profundidade. O vídeo sobre busca em profundidade explica qual alteração deve ser feita; e

Usando a implementação de busca em profundidade desenvolvida anteriormente, resolva o problema de busca de rotas na Romênia (de Arad a Bucareste), usando os dados do livro e que estão disponíveis no código-fonte. Mostre o passo a passo da solução através da busca em profundidade e como a sequência de nós explorados difere da busca
em largura'''

import q1 #aonde está definido o problema da romênia
'''
# Definindo as constantes
q1.BUSCA_INICIANDO = 0
q1.BUSCA_FALHOU = 1
q1.BUSCA_SUCESSO = 2
q1.BUSCA_EM_CURSO = 3'''

class BuscaProfundidade:
    def __init__(self, problema):
        self.problema = problema
        self.fronteira = [problema.inicial]
        self.visitados = [problema.inicial.estado]
        self.solucao = []
        self.situacao = q1.BUSCA_INICIANDO

    def executar(self):
        while self.situacao != q1.BUSCA_FALHOU and self.situacao != q1.BUSCA_SUCESSO:
            self.passo_busca()

        if self.situacao == q1.BUSCA_FALHOU:
            print("Busca falhou")
        elif self.situacao == q1.BUSCA_SUCESSO:
            print("Busca teve sucesso")
            print(f"SOLUÇÃO: {self.solucao}\n")

        return

    def passo_busca(self):
        if (self.situacao == q1.BUSCA_FALHOU):
            print("Busca falhou")
            return

        if (self.situacao == q1.BUSCA_SUCESSO):
            print("Busca chegou ao objetivo com sucesso")
            return

        try:
            # Modificação 1: Agora removemos o último nó da fronteira
            no = self.fronteira.pop()
            print(f"\n--> Expandindo nó {no.estado}\n")  # Adição: Imprimir o nó que está sendo explorado
        except IndexError:
            self.situacao = q1.BUSCA_FALHOU
            return

        # Modificação 2: Testamos o objetivo após retirar o nó da fronteira
        if self.problema.objetivo(no):
            self.situacao = q1.BUSCA_SUCESSO
            self.solucao = no.constroi_solucao()
            return

        # Modificação 3: Obtém os filhos do nó atual
        for filho in no.filhos(self.problema):
            if not (filho in self.fronteira) and not (filho.estado in self.visitados):
                self.fronteira.append(filho)
                self.visitados.append(filho.estado)
                print(f"> Adicionando nó à fronteira: {filho.estado}")  # Adição: Imprimir o nó adicionado à fronteira

        return

problema_romenia = q1.Problema(q1.estados_romenia, q1.No('Arad', 0, None, None), lambda no: no.estado == 'Bucharest')

busca_profundidade = BuscaProfundidade(problema_romenia)
busca_profundidade.executar()