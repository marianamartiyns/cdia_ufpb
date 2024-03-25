'''Escolha um outro problema que pode ser resolvido por busca e resolva-o utilizando busca em largura e busca em profundidade. Mostre as mudanças que foram necessárias no código e o passo-a-passo da solução.

PROBLEMA ESCOLHIDO: Medir exatamente 4 litros usando garrafas de 3, 5 e 8 litros
'''
import q1 # para usar o BuscaLargura()
import q2_q3 #para usar o BuscaProfundidade()

# Definindo o problema das garrafas
class ProblemaGarrafas:
    def __init__(self):
        self.capacidades = [3, 5, 8]

    # Definição de objetivo: o objetivo é alcançado quando uma das garrafas tem 4 litros
    def objetivo(self, no):
        for garrafa in no.estado:
            if garrafa == 4:
                return True
        return False

    # Método para gerar os filhos de um nó
    def gerar_filhos(self, no):
        filhos = []
        for i in range(3):  # Para cada garrafa
            for j in range(3):  # Para cada outra garrafa
                if i != j:  # Garrafas diferentes
                    novo_estado = no.estado[:]
                    # Despeja a água da garrafa 'i' na garrafa 'j'
                    quantidade = min(novo_estado[i], self.capacidades[j] - novo_estado[j])
                    novo_estado[i] -= quantidade
                    novo_estado[j] += quantidade
                    filhos.append(NoGarrafas(novo_estado))
        return filhos

    # Método para retornar o estado inicial do problema
    def inicial(self):
        return NoGarrafas([0, 0, 8])  # Estado inicial: [0, 0, 8]

# Definindo a classe NoGarrafas
class NoGarrafas:
    def __init__(self, estado):
        self.estado = estado

    # Implementação do método __eq__ para comparação de nós
    def __eq__(self, outro):
        return self.estado == outro.estado

    # Implementação do método __hash__ para uso em conjuntos
    def __hash__(self):
        return hash(str(self.estado))

    # Método para gerar os filhos do nó
    def filhos(self, problema):
        return problema.gerar_filhos(self)



# Criando uma instância do problema das garrafas e da busca em largura
problema_garrafas = ProblemaGarrafas()
busca_garrafas_largura = q1.BuscaLargura(problema_garrafas)

# Executando a busca em largura
print("Executando busca em largura para o problema das garrafas:")
busca_garrafas_largura.executar()
