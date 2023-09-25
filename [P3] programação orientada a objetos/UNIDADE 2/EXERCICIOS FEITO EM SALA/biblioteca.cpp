#include <iostream>
#include <string>

class usuario {
protected:
    std::string nome;
    int idade;
public:
    usuario(const std::string& n, int i) : nome(n), idade(i) {}
    virtual ~usuario() {}
    virtual void exibir_detalhes() const = 0;
    virtual std::string tipo_usuario() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const usuario& usr) {
        os << "Nome: " << usr.nome << "\nIdade: " << usr.idade;
        return os;
    }
};

class estudante : public usuario {
private:
    std::string matricula;
    std::string curso;
public:
    estudante(const std::string& n, int i, const std::string& mat, const std::string& c)
        : usuario(n, i), matricula(mat), curso(c) {}

    void exibir_detalhes() const override {
        std::cout << "Tipo de usuário: Estudante\n";
        std::cout << *this << "\nMatrícula: " << matricula << "\nCurso: " << curso << std::endl;
    }

    std::string tipo_usuario() const override {
        return "Estudante";
    }

    friend std::ostream& operator<<(std::ostream& os, const estudante& est) {
        os << "Tipo de usuário: " << est.tipo_usuario() << "\n" << static_cast<const usuario&>(est) << "\nMatrícula: " << est.matricula << "\nCurso: " << est.curso;
        return os;
    }
};

class professor : public usuario {
private:
    std::string departamento;
public:
    professor(const std::string& n, int i, const std::string& dep)
        : usuario(n, i), departamento(dep) {}

    void exibir_detalhes() const override {
        std::cout << "Tipo de usuário: Professor\n";
        std::cout << *this << "\nDepartamento: " << departamento << std::endl;
    }

    std::string tipo_usuario() const override {
        return "Professor";
    }

    friend std::ostream& operator<<(std::ostream& os, const professor& prof) {
        os << "Tipo de usuário: " << prof.tipo_usuario() << "\n" << static_cast<const usuario&>(prof) << "\nDepartamento: " << prof.departamento;
        return os;
    }
};

class material {
protected:
    std::string titulo;
public:
    material(const std::string& t) : titulo(t) {}
    virtual ~material() {}
    virtual void exibir_detalhes() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const material& mat) {
        os << "Título: " << mat.titulo;
        return os;
    }
};

class livro : public material {
private:
    std::string autor;
    int ano_publicacao;
public:
    livro(const std::string& t, const std::string& a, int ano)
        : material(t), autor(a), ano_publicacao(ano) {}

    void exibir_detalhes() const override {
        std::cout << "Tipo de material: Livro\n";
        std::cout << *this << "\nAutor: " << autor << "\nAno de Publicação: " << ano_publicacao << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const livro& liv) {
        os << "Tipo de material: Livro\n" << static_cast<const material&>(liv) << "\nAutor: " << liv.autor << "\nAno de Publicação: " << liv.ano_publicacao;
        return os;
    }
};

class revista : public material {
private:
    int numero_edicao;
public:
    revista(const std::string& t, int num)
        : material(t), numero_edicao(num) {}

    void exibir_detalhes() const override {
        std::cout << "Tipo de material: Revista\n";
        std::cout << *this << "\nNúmero da Edição: " << numero_edicao << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const revista& rev) {
        os << "Tipo de material: Revista\n" << static_cast<const material&>(rev) << "\nNúmero da Edição: " << rev.numero_edicao;
        return os;
    }
};

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
