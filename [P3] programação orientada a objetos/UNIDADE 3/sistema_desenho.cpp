/*Sistema de Desenho de Polígonos

    1) Implementar as classes descritas abaixo em C++
        a. Canvas (Tela de Desenho)
            i. Atributos (tipos entre parênteses)
                1. Tamanho em pixels (Array contendo valores inteiros para tamanho em pixels da altura e da largura da tela para desenho)
                2. Conjunto de Polígonos do Canvas (Array contendo os polígonos criados pelo usuário)
            ii. Métodos
                1. Recuperar tamanho (retorna Array de inteiros com tamanho em pixels da tela de desenho – largura e altura)
                2. Recuperar polígonos do canvas (retorna Array de Polígonos)
                3. Exibir polígonos (exibe na tela quais polígonos pertencem ao canvas)
        b. Polígono
            i. Atributos (tipos entre parênteses)
                1. Coordenadas (x,y) do centro do polígono (Array de Inteiros)
                2. Z-Index – coordenada Z para sobreposição de polígonos (Inteiro)
                3. Cor do polígono (String)
            ii. Métodos
                1. Calcular e retornar Área (retorna Inteiro) – método virtual
                2. Calcular e retornar Perímetro (retorna Inteiro) – método virtual
                3. Retornar centro do polígono (retorna Array com valores Inteiros para ponto do centro)
                4. Retornar cor do polígono (retorna String)
        c. Retângulo (herança pública de Polígono)
            i. Atributos
                1. Base em pixels (Inteiro)
                2. Altura em pixels (Inteiro)
            ii. Métodos
                1. Calcular e retornar área (retorna Inteiro)
                2. Calcular e retornar perímetro (retorna Inteiro)
        d. Círculo (herança pública de Polígono)
            i. Atributos
                1. Raio (Inteiro)
            ii. Métodos
                1. Calcular e retornar área (retorna Inteiro)
                2. Calcular e retornar perímetro (retorna Inteiro)
        e. Mais dois tipos de polígonos (ex. Triângulo, Pentágono, Hexágono etc.) à escolha do aluno, com atributos e métodos equivalentes (herança pública de Polígono)

 Implementar um programa em C++ que crie uma instância da classe Canvas, a partir de informações fornecidas pelo usuário, e em seguida criar um loop de execução que apresente um menu com as opções apresentadas a seguir, cujas funcionalidades devem ser realizadas quando selecionadas:
        a. Exibir informações do canvas (tamanho e quantos polígonos possui)
        b. Inserir Retângulo
        c. Inserir Círculo
        d. Inserir Polígono definido pelo Aluno (1)
        e. Inserir Polígono definido pelo Aluno (2)
        f. Exibir Polígonos na tela (listar polígonos e exibir informações: tipo, centro, cor, área e perímetro)
        g. Eliminar polígono pelo índice de inserção (índice associado à ordem de criação do Polígono)
        h. Salvar um arquivo de texto com a lista de polígonos do canvas (com as informações: tipo, centro, cor, área e perímetro).
        i. Sair
Faça o programa lançar exceções caso valores expúrios sejam inseridos; trate as exceções de forma que o cadastro seja cancelado e se solicite ao usuário para que faça um novo cadastro.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Classe Polígono
class Poligono {
public:
    Poligono(const vector<int>& _coordenadas, int _zIndex, const string& _cor)
        : coordenadas(_coordenadas), zIndex(_zIndex), cor(_cor) {}

    virtual int CalcularArea() const = 0;
    virtual int CalcularPerimetro() const = 0;

    const vector<int>& GetCoordenadas() const {
        return coordenadas;
    }

    int GetZIndex() const {
        return zIndex;
    }

    const string& GetCor() const {
        return cor;
    }

    virtual string GetTipo() const = 0;

    virtual ~Poligono() {}

private:
    vector<int> coordenadas;
    int zIndex;
    string cor;
};

// Classe Retângulo (herda de Polígono)
class Retangulo : public Poligono {
public:
    Retangulo(const vector<int>& _coordenadas, int _zIndex, const string& _cor, int _base, int _altura)
        : Poligono(_coordenadas, _zIndex, _cor), base(_base), altura(_altura) {}

    int CalcularArea() const override {
        return base * altura;
    }

    int CalcularPerimetro() const override {
        return 2 * (base + altura);
    }

    string GetTipo() const override {
        return "Retângulo";
    }

    ~Retangulo() {}

private:
    int base;
    int altura;
};

// Classe Círculo (herda de Polígono)
class Circulo : public Poligono {
public:
    Circulo(const vector<int>& _coordenadas, int _zIndex, const string& _cor, int _raio)
        : Poligono(_coordenadas, _zIndex, _cor), raio(_raio) {}

    int CalcularArea() const override {
        return 3.14 * raio * raio; // Supondo o valor de pi como 3.14
    }

    int CalcularPerimetro() const override {
        return 2 * 3.14 * raio; // Supondo o valor de pi como 3.14
    }

    string GetTipo() const override {
        return "Círculo";
    }

    ~Circulo() {}

private:
    int raio;
};

// Classe Triângulo (herda de Polígono)
class Triangulo : public Poligono {
public:
    Triangulo(const vector<int>& _coordenadas, int _zIndex, const string& _cor, int _lado1, int _lado2, int _lado3)
        : Poligono(_coordenadas, _zIndex, _cor), lado1(_lado1), lado2(_lado2), lado3(_lado3) {}

    int CalcularArea() const override {
        // Usando a fórmula de Heron para calcular a área de um triângulo
        int s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    int CalcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }

    string GetTipo() const override {
        return "Triângulo";
    }

    ~Triangulo() {}

private:
    int lado1;
    int lado2;
    int lado3;
};

// Classe Canvas
class Canvas {
public:
    Canvas(int _largura, int _altura) : largura(_largura), altura(_altura) {}

    vector<int> RecuperarTamanho() const {
        return {largura, altura};
    }

    const vector<Poligono*>& RecuperarPoligonos() const {
        return poligonos;
    }

    void ExibirPoligonos() const {
        int index = 1;
        for (const Poligono* poligono : poligonos) {
            cout << "Polígono " << index << " - Tipo: " << poligono->GetTipo()
                 << ", Centro: (" << poligono->GetCoordenadas()[0] << ", " << poligono->GetCoordenadas()[1] << ")"
                 << ", Cor: " << poligono->GetCor()
                 << ", Área: " << poligono->CalcularArea()
                 << ", Perímetro: " << poligono->CalcularPerimetro() << endl;
            index++;
        }
    }

    void InserirPoligono(Poligono* poligono) {
        poligonos.push_back(poligono);
    }

    void EliminarPoligono(int indice) {
        if (indice >= 1 && indice <= poligonos.size()) {
            delete poligonos[indice - 1];
            poligonos.erase(poligonos.begin() + (indice - 1));
        }
    }

    void SalvarPoligonosParaArquivo(const string& nomeArquivo) {
        ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            int index = 1;
            for (const Poligono* poligono : poligonos) {
                arquivo << "Polígono " << index << " - Tipo: " << poligono->GetTipo()
                        << ", Centro: (" << poligono->GetCoordenadas()[0] << ", " << poligono->GetCoordenadas()[1] << ")"
                        << ", Cor: " << poligono->GetCor()
                        << ", Área: " << poligono->CalcularArea()
                        << ", Perímetro: " << poligono->CalcularPerimetro() << endl;
                index++;
            }
            arquivo.close();
        } else {
            cout << "Não foi possível criar o arquivo." << endl;
        }
    }

    ~Canvas() {
        for (Poligono* poligono : poligonos) {
            delete poligono;
        }
    }

private:
    int largura;
    int altura;
    vector<Poligono*> poligonos;
};

// Função para inserir um polígono definido pelo aluno (1)
Poligono* InserirPoligonoDefinidoPeloAluno1() {
    int tipo;
    int x, y, zIndex;
    string cor;

    cout << "Escolha o tipo de polígono definido pelo aluno (1: Retângulo, 2: Círculo, 3: Triângulo): ";
    cin >> tipo;

    cout << "Informe as coordenadas do centro do polígono (x y): ";
    cin >> x >> y;

    cout << "Informe a coordenada Z (Z-Index): ";
    cin >> zIndex;

    cout << "Informe a cor do polígono: ";
    cin >> cor;

    if (tipo == 1) {
        int base, altura;
        cout << "Informe a base do retângulo em pixels: ";
        cin >> base;
        cout << "Informe a altura do retângulo em pixels: ";
        cin >> altura;
        return new Retangulo({x, y}, zIndex, cor, base, altura);
    } else if (tipo == 2) {
        int raio;
        cout << "Informe o raio do círculo em pixels: ";
        cin >> raio;
        return new Circulo({x, y}, zIndex, cor, raio);
    } else if (tipo == 3) {
        int lado1, lado2, lado3;
        cout << "Informe os tamanhos dos lados do triângulo em pixels (lado1 lado2 lado3): ";
        cin >> lado1 >> lado2 >> lado3;
        return new Triangulo({x, y}, zIndex, cor, lado1, lado2, lado3);
    } else {
        throw invalid_argument("Tipo de polígono definido pelo aluno inválido.");
    }
}

int main() {
    int largura, altura;
    cout << "Informe a largura da tela de desenho em pixels: ";
    cin >> largura;
    cout << "Informe a altura da tela de desenho em pixels: ";
    cin >> altura;

    Canvas canvas(largura, altura);

    char opcao;
    while (true) {

        cout << "\nMenu de Opções:" << endl;
        cout << "a. Exibir informações do canvas" << endl;
        cout << "b. Inserir Retângulo" << endl;
        cout << "c. Inserir Círculo" << endl;
        cout << "d. Inserir Polígono definido pelo Aluno (1)" << endl;
        cout << "e. Inserir Polígono definido pelo Aluno (2)" << endl;
        cout << "f. Exibir Polígonos na tela" << endl;
        cout << "g. Eliminar polígono pelo índice de inserção" << endl;
        cout << "h. Salvar um arquivo de texto com a lista de polígonos do canvas" << endl;
        cout << "i. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        try {
            switch (opcao) {
                case 'a': {
                    vector<int> tamanho = canvas.RecuperarTamanho();
                    cout << "Tamanho da tela de desenho: Largura=" << tamanho[0] << " pixels, Altura=" << tamanho[1] << " pixels" << endl;
                    cout << "Número de polígonos no canvas: " << canvas.RecuperarPoligonos().size() << endl;
                    break;
                }
                case 'b': {
                    int base, altura, x, y, zIndex;
                    string cor;
                    cout << "Informe a base do retângulo em pixels: ";
                    cin >> base;
                    cout << "Informe a altura do retângulo em pixels: ";
                    cin >> altura;
                    cout << "Informe as coordenadas do centro do retângulo (x y): ";
                    cin >> x >> y;
                    cout << "Informe a coordenada Z (Z-Index): ";
                    cin >> zIndex;
                    cout << "Informe a cor do retângulo: ";
                    cin >> cor;
                    canvas.InserirPoligono(new Retangulo({x, y}, zIndex, cor, base, altura));
                    cout << "Retângulo inserido com sucesso!" << endl;
                    break;
                }
                case 'c': {
                    int raio, x, y, zIndex;
                    string cor;
                    cout << "Informe o raio do círculo em pixels: ";
                    cin >> raio;
                    cout << "Informe as coordenadas do centro do círculo (x y): ";
                    cin >> x >> y;
                    cout << "Informe a coordenada Z (Z-Index): ";
                    cin >> zIndex;
                    cout << "Informe a cor do círculo: ";
                    cin >> cor;
                    canvas.InserirPoligono(new Circulo({x, y}, zIndex, cor, raio));
                    cout << "Círculo inserido com sucesso!" << endl;
                    break;
                }
                case 'd': {
                    Poligono* poligono = InserirPoligonoDefinidoPeloAluno1();
                    canvas.InserirPoligono(poligono);
                    cout << "Polígono definido pelo aluno (1) inserido com sucesso!" << endl;
                    break;
                }
                case 'e': {
                    Poligono* poligono = InserirPoligonoDefinidoPeloAluno1();
                    canvas.InserirPoligono(poligono);
                    cout << "Polígono definido pelo aluno (2) inserido com sucesso!" << endl;
                    break;
                }
                case 'f': {
                    canvas.ExibirPoligonos();
                    break;
                }
                case 'g': {
                    int indice;
                    cout << "Informe o índice do polígono a ser eliminado: ";
                    cin >> indice;
                    if (indice >= 1 && indice <= canvas.RecuperarPoligonos().size()) {
                        canvas.EliminarPoligono(indice);
                        cout << "Polígono eliminado com sucesso!" << endl;
                    } else {
                        cout << "Índice inválido." << endl;
                    }
                    break;
                }
                case 'h': {
                    string nomeArquivo;
                    cout << "Informe o nome do arquivo para salvar a lista de polígonos: ";
                    cin >> nomeArquivo;
                    canvas.SalvarPoligonosParaArquivo(nomeArquivo);
                    cout << "Lista de polígonos salva com sucesso!" << endl;
                    break;
                }
                case 'i': {
                    cout << "Saindo do programa." << endl;
                    return 0;
                }
                default: {
                    cout << "Opção inválida. Tente novamente." << endl;
                    break;
                }
            }
        } catch (const invalid_argument& e) {
            cerr << "Erro: " << e.what() << endl;
        }
    }

    return 0;
}
