#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/* Sistema de gerenciamento de funcionarios */

class funcionario {
	string nome;
	int id;
	float salario;
	static int contador;
protected:
	static void add_contador() {
		contador++;
	}
	static void dec_contador() {
		contador--;
	}
public:
	funcionario(const string& n, int i, float s):
			nome(n), id(i), salario(s) { }

	static int get_contador() {
		return contador;
	}

	virtual void print_info() {
		cout << "funcionario" << endl;
		cout << "nome: " << nome << " | ";
		cout << "id: " << id << " | ";
		cout << "salario: " << salario << endl;
	}
	string& get_nome() {
		return nome;
	}
};

int funcionario::contador = 0;

class empregado_regular : public funcionario {
	int codigo_categoria;
public:
	empregado_regular(int cc, const string& n, int i, float s):
				codigo_categoria(cc), funcionario(n,i,s) {
		funcionario::add_contador();
	}
	virtual void print_info() {
		funcionario::print_info();
		cout << "regular" << endl;
		cout << "categoria: " << codigo_categoria << endl;
	}
};

class gerente : public funcionario {
	float bonus;
public:
	gerente(float b, const string& n, int i, float s):
			bonus(b), funcionario(n,i,s) {
		funcionario::add_contador();
	}
	virtual void print_info() {
		funcionario::print_info();
		cout << "gerente" << endl;
		cout << "bonus: " << bonus << endl;
	}
};

class estagiario : public funcionario {
	string data_treinamento;
public:
	estagiario(const string& dt, const string& n, int i, float s):
			data_treinamento(dt), funcionario(n,i,s) {
		funcionario::add_contador();

	}

	virtual void print_info() {
		funcionario::print_info();
		cout << "estagiario" << endl;
		cout << "data treinamento: " << data_treinamento << endl;
	}
};

class empregado_gerente : public empregado_regular, public gerente {
public:
	empregado_gerente(int cc, float b, const string& n, int i, float s):
				empregado_regular(cc, n, i, s),
				gerente(b, n, i, s) {
		funcionario::dec_contador(); //pois chama funcionario() 2x
	}

	void print_info() {
		cout << "empregado gerente" << endl;
		empregado_regular::print_info();
		gerente::print_info();
	}

	string& get_nome() {
		return gerente::get_nome();
	}

};

class empresa {
	vector<funcionario*> funcionarios;
	vector<empregado_gerente*> e_gerentes;
	static empresa* _instance;
	empresa() { }
public:
	static empresa* get_instance() {
		if (_instance == NULL) {
			_instance = new empresa();
		}

		return _instance;

	}

	void add_funcionario(funcionario* f) {
		funcionarios.push_back(f);
	}

	void del_funcionario(int index) {
		funcionarios.erase (funcionarios.begin()+index);
	}

	void add_empregado_gerente(empregado_gerente* eg) {
		e_gerentes.push_back(eg);
	}

	void del_empregado_gerente(int index) {
		e_gerentes.erase(e_gerentes.begin()+index);
	}

	void list_funcionarios() {
		for (funcionario* f : funcionarios) {
			f->print_info();
		}

	}

	void list_empregados_gerentes() {
		for (empregado_gerente* eg : e_gerentes) {
			eg->print_info();
		}
	}
};

empresa* empresa::_instance = NULL;

class funcionario_exception {
	string msg;
public:
	funcionario_exception(const string& m):msg(m) { }
	void print_info() {
		cout << msg << endl;
	}
};

estagiario* create_estagiario() {
	int id;
	string n, d;
	float s;
	cout << "Digite o nome do estagiario: ";
	cin >> n;
	cout << "Digite o id do estagiario: ";
	cin >> id;
	cout << "Digite a data de treinamento: ";
	cin >> d;
	cout << "Digite o salario do estagiario: ";
	cin >> s;
	if (s <= 0)
		throw new funcionario_exception("salario");
	if (id <= 0)
		throw new funcionario_exception("id");
	if (n.size() == 0)
		throw new funcionario_exception("nome");
	if (d.size() < 6)
		throw new funcionario_exception("data");

	return new estagiario(d,n,id,s);
}

int main(void) {
	empresa* e;
	e = empresa::get_instance();

	estagiario* est1 = new estagiario("31/10/2023", "Ana", 1013, 1500);
	empregado_regular* ere1 =
		new empregado_regular(10, "Maria", 1015, 6000);
	gerente* ger1 = new gerente(1500, "Jose", 1020, 7000);
	empregado_gerente* ege1 = new
			empregado_gerente(11, 1500, "Josefa", 1030, 8000);

	e->add_funcionario(est1);
	e->add_funcionario(ere1);
	e->add_funcionario(ger1);
	e->add_empregado_gerente(ege1);

	insert_est:
	try {
		estagiario* est2 = create_estagiario();
		e->add_funcionario(est2);

	} catch (funcionario_exception* e) {
		cout << "Erro ao criar funcionario: ";
		e->print_info();
		goto insert_est;
	}

	e->list_funcionarios();

	e->list_empregados_gerentes();

	cout << "Quantidade de funcionarios: " << funcionario::get_contador();
	cout << endl;


	return 0;
}
