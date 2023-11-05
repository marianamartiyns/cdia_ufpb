/* Exercício 5: Sistema de Biblioteca

Crie uma classe `Livro` que armazena informações sobre livros, como título, autor e ano de publicação.
Implemente um sistema de biblioteca que permita adicionar, remover, listar e buscar livros por título ou autor.
Utilize um `std::map` com o título do livro como chave e um `std::multimap` com o autor como chave. */
#include <iostream>
#include <string>
#include <map>

class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor, int anoPublicacao)
        : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao) {}

    const std::string& getTitulo() const { return titulo; }
    const std::string& getAutor() const { return autor; }
    int getAnoPublicacao() const { return anoPublicacao; }

    void imprimir() const {
        std::cout << "Título: " << titulo << ", Autor: " << autor << ", Ano de Publicação: " << anoPublicacao << std::endl;
    }

private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
};

class Biblioteca {
public:
    void adicionarLivro(const Livro& livro) {
        livrosPorTitulo[livro.getTitulo()] = livro;
        livrosPorAutor.insert(std::make_pair(livro.getAutor(), livro));
    }

    void removerLivro(const std::string& titulo) {
        auto it = livrosPorTitulo.find(titulo);
        if (it != livrosPorTitulo.end()) {
            const Livro& livro = it->second;
            livrosPorTitulo.erase(it);

            for (auto it = livrosPorAutor.begin(); it != livrosPorAutor.end(); ) {
                if (it->second.getTitulo() == titulo) {
                    it = livrosPorAutor.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    void listarLivros() const {
        for (const auto& pair : livrosPorTitulo) {
            pair.second.imprimir();
        }
    }

    void buscarPorTitulo(const std::string& titulo) const {
        auto it = livrosPorTitulo.find(titulo);
        if (it != livrosPorTitulo.end()) {
            it->second.imprimir();
        } else {
            std::cout << "Livro não encontrado com o título: " << titulo << std::endl;
        }
    }

    void buscarPorAutor(const std::string& autor) const {
        auto range = livrosPorAutor.equal_range(autor);
        if (range.first != livrosPorAutor.end()) {
            for (auto it = range.first; it != range.second; ++it) {
                it->second.imprimir();
            }
        } else {
            std::cout << "Livros não encontrados para o autor: " << autor << std::endl;
        }
    }

private:
    std::map<std::string, Livro> livrosPorTitulo;
    std::multimap<std::string, Livro> livrosPorAutor;
};

int main() {
    Biblioteca biblioteca;

    Livro livro1("Livro A", "Autor 1", 2000);
    Livro livro2("Livro B", "Autor 2", 2010);
    Livro livro3("Livro C", "Autor 1", 2015);

    biblioteca.adicionarLivro(livro1);
    biblioteca.adicionarLivro(livro2);
    biblioteca.adicionarLivro(livro3);

    std::cout << "Lista de Livros:" << std::endl;
    biblioteca.listarLivros();

    std::cout << "\nBusca por Título:" << std::endl;
    biblioteca.buscarPorTitulo("Livro B");

    std::cout << "\nBusca por Autor:" << std::endl;
    biblioteca.buscarPorAutor("Autor 1");

    biblioteca.removerLivro("Livro B");

    std::cout << "\nLista de Livros após remoção:" << std::endl;
    biblioteca.listarLivros();

    return 0;
}
