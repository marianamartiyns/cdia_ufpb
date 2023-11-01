/* Exercício 4: Gerenciador de Tarefas (To-Do List)**

Crie uma classe `Tarefa` que armazena informações sobre tarefas, como descrição, data de vencimento e estado (concluída ou não).
Implemente um gerenciador de tarefas que permita adicionar, remover, listar e marcar tarefas como concluídas.
Utilize um `std::list` para armazenar objetos `Tarefa`. */

#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

class tarefa {
	string descricao;
	string deadline;
	bool concluida;
public:
	tarefa(const string& desc, const string& dead, bool c) :
		descricao(desc), deadline(dead), concluida(c) { }
	const string& get_descricao() { return descricao; }
	const string& get_deadline() { return deadline; }

	bool is_concluida() { return concluida; }

	void set_concluida(bool c) {
		concluida = c;
	}
};

class gerenciador_tarefas {
	list<tarefa> tarefas;
public:
	void adicionar_tarefa(const tarefa& t) {
		tarefas.push_back(t);
	}

	void listar_tarefas() {
		int counter = 1;
		for (tarefa& t : tarefas) {
			cout << "(" << counter++ << ") ";
			cout << t.get_descricao() << " | ";
			cout << t.get_deadline() << " | ";
			cout << (t.is_concluida()?"[Concluida]":"[Pendente]");
			cout << endl;
		}

	}

	void remover_tarefa(int n) {
		if (n >= 1 && n <= tarefas.size()) {
			auto it = tarefas.begin();
			std::advance(it, n - 1);
			tarefas.erase(it);
		}

	}

	void definir_tarefa_concluida(int n) {
		if (n >= 1 && n <= tarefas.size()) {
			auto it = tarefas.begin();
			std::advance(it, n - 1);
			it->set_concluida(true);
		}

	}

};

int main(void) {
	gerenciador_tarefas gt;

	gt.adicionar_tarefa(tarefa("Fazer a feira", "26/10/23", false));
	gt.adicionar_tarefa(tarefa("Arrumar a casa", "27/10/23", false));
	gt.adicionar_tarefa(tarefa("Corrigir as provas", "28/10/23", false));
	gt.adicionar_tarefa(tarefa("Consertar o carro", "31/10/23", false));

	gt.listar_tarefas();

	cout << endl;
	cout << "Removendo tarefa 4 e concluindo tarefa 3" << endl;

	gt.remover_tarefa(4);
	gt.definir_tarefa_concluida(3);

	cout << endl;

	gt.listar_tarefas();

	return 0;

}
