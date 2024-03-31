'''Escolha um outro problema que pode ser resolvido por busca e resolva-o utilizando busca em largura e busca em profundidade. Mostre as mudanças que foram necessárias no código e o passo-a-passo da solução.

PROBLEMA ESCOLHIDO: O problema dos Missionários e Canibais é um tipo de problema de busca em que o objetivo é transferir missionários e canibais de uma margem do rio para a outra, utilizando um barco, seguindo algumas regras específicas para garantir que os missionários não sejam superados em número pelos canibais em nenhuma das margens do rio.

Regras do Problema:

O barco só pode transportar no máximo duas pessoas (missionários ou canibais).
Em qualquer margem do rio, se houver missionários presentes, o número de canibais não pode ser maior do que o número de missionários, caso contrário, os canibais comeriam os missionários.
O objetivo do problema (a solução buscada) é transferir todos os missionários e canibais da margem inicial para a margem final, respeitando as regras mencionadas.
'''
# Constantes para situações da busca
BUSCA_INICIANDO = "Iniciando"
BUSCA_FALHOU = "Falhou"
BUSCA_SUCESSO = "Sucesso"

class EstadoMC:
    def __init__(self, margem_esquerda, margem_direita, barco_na_esquerda):
        self.margem_esquerda = margem_esquerda
        self.margem_direita = margem_direita
        self.barco_na_esquerda = barco_na_esquerda

    def __eq__(self, other):
        return (self.margem_esquerda == other.margem_esquerda and
                self.margem_direita == other.margem_direita and
                self.barco_na_esquerda == other.barco_na_esquerda)

    def __str__(self):
        return f'Margem Esquerda: {self.margem_esquerda}, Margem Direita: {self.margem_direita}, Barco na Esquerda: {self.barco_na_esquerda}'

    def __repr__(self):
        return self.__str__()

    def operacoes_possiveis(self):
        operacoes = []
        if self.barco_na_esquerda:
            for i in range(3):
                for j in range(i + 1):
                    novo_estado = EstadoMC(self.margem_esquerda - j, self.margem_direita + j, not self.barco_na_esquerda)
                    if self.validar_estado(novo_estado):
                        operacoes.append(novo_estado)
        else:
            for i in range(3):
                for j in range(i + 1):
                    novo_estado = EstadoMC(self.margem_esquerda + j, self.margem_direita - j, not self.barco_na_esquerda)
                    if self.validar_estado(novo_estado):
                        operacoes.append(novo_estado)
        return operacoes

    def validar_estado(self, estado):
        if (estado.margem_esquerda < 0 or estado.margem_direita < 0 or
            estado.margem_esquerda > 3 or estado.margem_direita > 3):
            return False
        if (estado.margem_esquerda != 0 and estado.margem_esquerda < estado.margem_direita) or \
                (estado.margem_direita != 0 and estado.margem_direita < estado.margem_esquerda):
            return False
        return True

    def objetivo(self):
        return self.margem_esquerda == 0 and self.margem_direita == 3 and not self.barco_na_esquerda


class ProblemaMC:
    def __init__(self, inicial):
        self.inicial = inicial

    def objetivo(self, estado):
        return estado.objetivo()


class Busca:
    def __init__(self, problema):
        self.problema = problema
        self.fronteira = [problema.inicial]
        self.visitados = [problema.inicial]
        self.solucao = []
        self.situacao = BUSCA_INICIANDO

    def executar(self):
        while self.situacao != BUSCA_FALHOU and self.situacao != BUSCA_SUCESSO:
            self.passo_busca()

        if self.situacao == BUSCA_FALHOU:
            print("Busca falhou")
        elif self.situacao == BUSCA_SUCESSO:
            print("\n--> Busca teve sucesso <--")
            print(f"\nSOLUÇÃO: {self.solucao}\n")

        return

    def passo_busca(self):
        if self.situacao == BUSCA_FALHOU:
            print("Busca falhou")
            return

        if self.situacao == BUSCA_SUCESSO:
            print("---> Busca chegou ao objetivo com sucesso <---")
            return

        try:
            no = self.fronteira.pop(0)
        except IndexError:
            self.situacao = BUSCA_FALHOU
            print("Fronteira vazia. Busca falhou.")
            return

        print(f"\n--> Expandindo nó {no}\n")

        if self.problema.objetivo(no):
            self.situacao = BUSCA_SUCESSO
            self.solucao = no
            print("Objetivo encontrado!\n")
            return

        for acao in no.operacoes_possiveis():
            if self.problema.objetivo(acao):
                self.solucao = acao
                self.situacao = BUSCA_SUCESSO
                print("Objetivo encontrado!\n")
                return

            if acao not in self.visitados:
                self.fronteira.append(acao)
                self.visitados.append(acao)
                print(f"> Adicionando nó {acao} à fronteira")
        return


# Criando o estado inicial
estado_inicial_mc = EstadoMC(3, 0, True)

# Criando o problema dos Missionários e Canibais
problema_mc = ProblemaMC(estado_inicial_mc)

# Criando e executando a busca em largura
busca_largura = Busca(problema_mc)
print("\n----- Busca em Largura -----\n")
busca_largura.executar()

# Criando e executando a busca em profundidade
busca_profundidade = Busca(problema_mc)
print("\n----- Busca em Profundidade -----\n")
busca_profundidade.executar()
