#include <iostream>
#include <string>

using namespace std;

class usuario{

protected:
    string nome;
    int idade;

public:
    usuario(string n, int i) : nome(n), idade(i) {} // construtor
    virtual ~usuario(){} // destrutor

    //gets e sets
    string get_nome() {return nome; }
    int get_idade() {return idade; }

    void set_nome(const string& n) { nome = n; }
    void set_idade(int i) { idade = i; }

    //sobrecarga
    friend ostream& operator << (ostream& os, const usuario& u){
        os << "Nome: " << u.nome << endl;
        os << "Idade: " << u.idade << endl;
        return os;
    }

    //metodo virtual puro
    virtual void exibir_detalhes() const =0;
    virtual void tipo_usuario() const = 0;
};

class estudante : public usuario {

protected:
    string matricula;
    string curso;
public:
    estudante(string n, int i, string m, string c) : usuario(n, i), matricula(m), curso(c) {};

    //get e sets
    string get_matricula(){ return matricula; }
    string get_curso() { return curso; }

    void set_matricula(const string& m){matricula = m;}
    void set_curso(const string& c){ curso = c; }

    void exibir_detalhes() const override{
        cout << "Tipo de usuario: Estudante." << endl;
        cout << *this << "\n Matricula: " << matricula << "\nCurso: " << curso <<endl;
    }

    string tipo_usuario() const override { return "Estudante"; }

    //sobrecarga
    friend ostream& operator<<(ostrema os, const estudante& e ){
        os << "Tipo de usuario: " << e.tipo_usuario() << "\n" << static_cast < const usuario& > (e) << "\Matricula: " << e.matricula << "\nCurso: " << e.curso;
        return os;
    }
};

class professor : public usuario{
    string departamento; // public
public:
    professor(string n, int i, string d) : usuario(n, i), departamento(d){} //construtor

    //get e sets
    string get_departamento() { return departamento; }
    void set_departamento(const string& d){ departamento = d; }

    void exibir_detalhes() const override{
        cout << "Tipo do usuario: Professor" << endl;
        cout << this* << "Departamento: " << departamento << endl;
    }

    void tipo_usuario() const override { return "Professor"; }

    friend ostream& operator<< (ostream& os, const professor& prof){
        os << "Tipo de usuario: " << prof.tipo_usuario() << "\n" << static_cast < const usuario& > (prof) << "Departamento: " << e.departamento << endl;
        return os;
    }
};

class material{
protected:
    string titulo;

public:
    material(string t) : titulo(t) {}
    virtual ~material() {}

    //get e sets
    string get_titulo(){ return titulo; }
    void set_titulo(const string& t){ titulo = t; }

    virtual void exibir_detalhes() const = 0;

    friend ostream& operator<< (ostream& os, const material& m ) {
        cout << "Titulo do Material: " << m.titulo << endl;
        return os;
    }
};

class livro: public material {
    string autor;
    int ano_publicacao;

public:
    livro(string t, string a, int ap) : material(t), autor(a), ano_publicacao(ap) {};

    //get e sets
    string get_autor(){ return autor; }
    int get_ano_publicacao(){return ano_publicacao; }

    void set_autor(const string& a){ autor = a; }
    void set_ano_publicacao(int ap) { ano_publicacao = ap; }

    void exibir_detalhes() const override(){
        cout << this* << "Autor: " << autor << " - " << "Ano da Publicacao: " << ano_publicacao << endl;
    }

    friend ostrema& operator<< ( ostream& os, const livro& l){
        os << "Tipo de Material: Livro\n" << static_cast < const material& > (l) << "\nAutor: " << l.autor << "\nAno de Publicacao: " << l.ano_publicacao;
        return os;
    }
};

class revista : public material {

    int numero_edicao; //privado
public:
    revista(string t, int n) : material(t), numero_edicao(n) {}

    //get e set
    int get_numero_edicao() {return numero_edicao; }
    void set_numero_edicao(int n) {numero_edicao = n; }

    void exibir_detalhes()const override{
        cout << this* << "Numero da edicao: " << numero_edicao << endl;
    }

    friend ostrema& operator<< (oestream& os, revista& r){
        os << "Tipo de material: Revista" << static_cast < const material& > (r) << "\nNumero da edicao: " << r.numero_edicao;
    }
};

/******************/
class emprestimo {
private:
    usuario* usuario_emprestimo;
    material* material_emprestimo;
    std::string data_emprestimo;
public:
    emprestimo(usuario* usr, material* mat, const std::string& data)
        : usuario_emprestimo(usr), material_emprestimo(mat), data_emprestimo(data) {}

    void exibir_detalhes() const {
        std::cout << "Detalhes do Empréstimo:\n";
        std::cout << "Usuário:\n" << *usuario_emprestimo << "\nMaterial emprestado:\n" << *material_emprestimo << "\nData do Empréstimo: " << data_emprestimo << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const emprestimo& emp) {
        os << "Detalhes do Empréstimo:\n" << "Usuário:\n" << *(emp.usuario_emprestimo) << "\nMaterial emprestado:\n" << *(emp.material_emprestimo) << "\nData do Empréstimo: " << emp.data_emprestimo;
        return os;
    }
};

class biblioteca {
private:
    usuario** usuarios;
    material** materiais;
    emprestimo* emprestimos;
    int num_usuarios;
    int num_materiais;
    int num_emprestimos;
    const int max_usuarios;
    const int max_materiais;
public:
    biblioteca(int max_users, int max_materials)
        : max_usuarios(max_users), max_materiais(max_materials) {
        usuarios = new usuario*[max_usuarios];
        materiais = new material*[max_materiais];
        emprestimos = new emprestimo[max_usuarios * max_materials];
        num_usuarios = 0;
        num_materiais = 0;
        num_emprestimos = 0;
    }

    ~biblioteca() {
        for (int i = 0; i < num_usuarios; i++) {
            delete usuarios[i];
        }
        for (int i = 0; i < num_materiais; i++) {
            delete materiais[i];
        }
        delete[] usuarios;
        delete[] materiais;
        delete[] emprestimos;
    }

    void adicionar_usuario(usuario* usr) {
        if (num_usuarios < max_usuarios) {
            usuarios[num_usuarios++] = usr;
        }
    }

    void adicionar_material(material* mat) {
        if (num_materiais < max_materiais) {
            materiais[num_materiais++] = mat;
        }
    }

    void listar_usuarios() {
        std::cout << "Lista de Usuários:\n";
        for (int i = 0; i < num_usuarios; i++) {
            std::cout << "-----------------------\n";
            usuarios[i]->exibir_detalhes();
            std::cout << "-----------------------\n";
        }
    }

    void listar_materiais() {
        std::cout << "Lista de Materiais:\n";
        for (int i = 0; i < num_materiais; i++) {
            std::cout << "-----------------------\n";
            materiais[i]->exibir_detalhes();
            std::cout << "-----------------------\n";
        }
    }

    void emprestar_material(usuario* usr, material* mat, const std::string& data) {
        if (num_emprestimos < (max_usuarios * max_materiais)) {
            emprestimos[num_emprestimos++] = emprestimo(usr, mat, data);
        }
    }

    void devolver_material(usuario* usr, material* mat) {
        for (int i = 0; i < num_emprestimos; i++) {
            if (emprestimos[i].usuario_emprestimo == usr && emprestimos[i].material_emprestimo == mat) {
                // Desloca os empréstimos restantes para preencher o espaço vazio
                for (int j = i; j < num_emprestimos - 1; j++) {
                    emprestimos[j] = emprestimos[j + 1];
                }
                num_emprestimos--;
                break;
            }
        }
    }

    void listar_emprestimos() {
        std::cout << "Lista de Empréstimos Ativos:\n";
        for (int i = 0; i < num_emprestimos; i++) {
            std::cout << "-----------------------\n";
            emprestimos[i].exibir_detalhes();
            std::cout << "-----------------------\n";
        }
    }
};

int main() {
    biblioteca minha_biblioteca(10, 10);

    // Criar usuários
    usuario* usuario1 = new estudante("João", 20, "2021001", "Engenharia");
    usuario* usuario2 = new professor("Maria", 35, "Departamento de Ciência da Computação");

    minha_biblioteca.adicionar_usuario(usuario1);
    minha_biblioteca.adicionar_usuario(usuario2);

    // Criar materiais
    material* material1 = new livro("Introdução à Programação", "Alice Smith", 2019);
    material* material2 = new livro("Cálculo Avançado", "Bob Johnson", 2018);
    material* material3 = new revista("Revista de Ciência", 45);
    material* material4 = new revista("Revista de Matemática", 30);

    minha_biblioteca.adicionar_material(material1);
    minha_biblioteca.adicionar_material(material2);
    minha_biblioteca.adicionar_material(material3);
    minha_biblioteca.adicionar_material(material4);

    // Realizar empréstimos
    minha_biblioteca.emprestar_material(usuario1, material1, "2023-09-22");
    minha_biblioteca.emprestar_material(usuario2, material3, "2023-09-23");

    // Listar usuários, materiais e empréstimos
    minha_biblioteca.listar_usuarios();
    minha_biblioteca.listar_materiais();
    minha_biblioteca.listar_emprestimos();

    // Devolver material
    minha_biblioteca.devolver_material(usuario1, material1);

    // Listar empréstimos novamente
    minha_biblioteca.listar_emprestimos();

    return 0;
}

