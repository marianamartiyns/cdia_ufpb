/*Sistema de Desenho de Pol�gonos

    1) Implementar as classes descritas abaixo em C++
        a. Canvas (Tela de Desenho)
            i. Atributos (tipos entre par�nteses)
                1. Tamanho em pixels (Array contendo valores inteiros para tamanho em pixels da altura e da largura da tela para desenho)
                2. Conjunto de Pol�gonos do Canvas (Array contendo os pol�gonos criados pelo usu�rio)
            ii. M�todos
                1. Recuperar tamanho (retorna Array de inteiros com tamanho em pixels da tela de desenho � largura e altura)
                2. Recuperar pol�gonos do canvas (retorna Array de Pol�gonos)
                3. Exibir pol�gonos (exibe na tela quais pol�gonos pertencem ao canvas)
        b. Pol�gono
            i. Atributos (tipos entre par�nteses)
                1. Coordenadas (x,y) do centro do pol�gono (Array de Inteiros)
                2. Z-Index � coordenada Z para sobreposi��o de pol�gonos (Inteiro)
                3. Cor do pol�gono (String)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro) � m�todo virtual
                2. Calcular e retornar Per�metro (retorna Inteiro) � m�todo virtual
                3. Retornar centro do pol�gono (retorna Array com valores Inteiros para ponto do centro)
                4. Retornar cor do pol�gono (retorna String)
        c. Ret�ngulo (heran�a p�blica de Pol�gono)
            i. Atributos
                1. Base em pixels (Inteiro)
                2. Altura em pixels (Inteiro)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro)
                2. Calcular e retornar per�metro (retorna Inteiro)
        d. C�rculo (heran�a p�blica de Pol�gono)
            i. Atributos
                1. Raio (Inteiro)
            ii. M�todos
                1. Calcular e retornar �rea (retorna Inteiro)
                2. Calcular e retornar per�metro (retorna Inteiro)
        e. Mais dois tipos de pol�gonos (ex. Tri�ngulo, Pent�gono, Hex�gono etc.) � escolha do aluno, com atributos e m�todos equivalentes (heran�a p�blica de Pol�gono)

 Implementar um programa em C++ que crie uma inst�ncia da classe Canvas, a partir de informa��es fornecidas pelo usu�rio, e em seguida criar um loop de execu��o que apresente um menu com as op��es apresentadas a seguir, cujas funcionalidades devem ser realizadas quando selecionadas:
        a. Exibir informa��es do canvas (tamanho e quantos pol�gonos possui)
        b. Inserir Ret�ngulo
        c. Inserir C�rculo
        d. Inserir Pol�gono definido pelo Aluno (1)
        e. Inserir Pol�gono definido pelo Aluno (2)
        f. Exibir Pol�gonos na tela (listar pol�gonos e exibir informa��es: tipo, centro, cor, �rea e per�metro)
        g. Eliminar pol�gono pelo �ndice de inser��o (�ndice associado � ordem de cria��o do Pol�gono)
        h. Salvar um arquivo de texto com a lista de pol�gonos do canvas (com as informa��es: tipo, centro, cor, �rea e per�metro).
        i. Sair
Fa�a o programa lan�ar exce��es caso valores exp�rios sejam inseridos; trate as exce��es de forma que o cadastro seja cancelado e se solicite ao usu�rio para que fa�a um novo cadastro.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Classe Pol�gono
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

// Classe Ret�ngulo (herda de Pol�gono)
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
        return "Ret�ngulo";
    }

    ~Retangulo() {}

private:
    int base;
    int altura;
};

// Classe C�rculo (herda de Pol�gono)
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
        return "C�rculo";
    }

    ~Circulo() {}

private:
    int raio;
};

// Classe Tri�ngulo (herda de Pol�gono)
class Triangulo : public Poligono {
public:
    Triangulo(const vector<int>& _coordenadas, int _zIndex, const string& _cor, int _lado1, int _lado2, int _lado3)
        : Poligono(_coordenadas, _zIndex, _cor), lado1(_lado1), lado2(_lado2), lado3(_lado3) {}

    int CalcularArea() const override {
        // Usando a f�rmula de Heron para calcular a �rea de um tri�ngulo
        int s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    int CalcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }

    string GetTipo() const override {
        return "Tri�ngulo";
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
            cout << "Pol�gono " << index << " - Tipo: " << poligono->GetTipo()
                 << ", Centro: (" << poligono->GetCoordenadas()[0] << ", " << poligono->GetCoordenadas()[1] << ")"
                 << ", Cor: " << poligono->GetCor()
                 << ", �rea: " << poligono->CalcularArea()
                 << ", Per�metro: " << poligono->CalcularPerimetro() << endl;
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
                arquivo << "Pol�gono " << index << " - Tipo: " << poligono->GetTipo()
                        << ", Centro: (" << poligono->GetCoordenadas()[0] << ", " << poligono->GetCoordenadas()[1] << ")"
                        << ", Cor: " << poligono->GetCor()
                        << ", �rea: " << poligono->CalcularArea()
                        << ", Per�metro: " << poligono->CalcularPerimetro() << endl;
                index++;
            }
            arquivo.close();
        } else {
            cout << "N�o foi poss�vel criar o arquivo." << endl;
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

// Fun��o para inserir um pol�gono definido pelo aluno (1)
Poligono* InserirPoligonoDefinidoPeloAluno1() {
    int tipo;
    int x, y, zIndex;
    string cor;

    cout << "Escolha o tipo de pol�gono definido pelo aluno (1: Ret�ngulo, 2: C�rculo, 3: Tri�ngulo): ";
    cin >> tipo;

    cout << "Informe as coordenadas do centro do pol�gono (x y): ";
    cin >> x >> y;

    cout << "Informe a coordenada Z (Z-Index): ";
    cin >> zIndex;

    cout << "Informe a cor do pol�gono: ";
    cin >> cor;

    if (tipo == 1) {
        int base, altura;
        cout << "Informe a base do ret�ngulo em pixels: ";
        cin >> base;
        cout << "Informe a altura do ret�ngulo em pixels: ";
        cin >> altura;
        return new Retangulo({x, y}, zIndex, cor, base, altura);
    } else if (tipo == 2) {
        int raio;
        cout << "Informe o raio do c�rculo em pixels: ";
        cin >> raio;
        return new Circulo({x, y}, zIndex, cor, raio);
    } else if (tipo == 3) {
        int lado1, lado2, lado3;
        cout << "Informe os tamanhos dos lados do tri�ngulo em pixels (lado1 lado2 lado3): ";
        cin >> lado1 >> lado2 >> lado3;
        return new Triangulo({x, y}, zIndex, cor, lado1, lado2, lado3);
    } else {
        throw invalid_argument("Tipo de pol�gono definido pelo aluno inv�lido.");
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

        cout << "\nMenu de Op��es:" << endl;
        cout << "a. Exibir informa��es do canvas" << endl;
        cout << "b. Inserir Ret�ngulo" << endl;
        cout << "c. Inserir C�rculo" << endl;
        cout << "d. Inserir Pol�gono definido pelo Aluno (1)" << endl;
        cout << "e. Inserir Pol�gono definido pelo Aluno (2)" << endl;
        cout << "f. Exibir Pol�gonos na tela" << endl;
        cout << "g. Eliminar pol�gono pelo �ndice de inser��o" << endl;
        cout << "h. Salvar um arquivo de texto com a lista de pol�gonos do canvas" << endl;
        cout << "i. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        try {
            switch (opcao) {
                case 'a': {
                    vector<int> tamanho = canvas.RecuperarTamanho();
                    cout << "Tamanho da tela de desenho: Largura=" << tamanho[0] << " pixels, Altura=" << tamanho[1] << " pixels" << endl;
                    cout << "N�mero de pol�gonos no canvas: " << canvas.RecuperarPoligonos().size() << endl;
                    break;
                }
                case 'b': {
                    int base, altura, x, y, zIndex;
                    string cor;
                    cout << "Informe a base do ret�ngulo em pixels: ";
                    cin >> base;
                    cout << "Informe a altura do ret�ngulo em pixels: ";
                    cin >> altura;
                    cout << "Informe as coordenadas do centro do ret�ngulo (x y): ";
                    cin >> x >> y;
                    cout << "Informe a coordenada Z (Z-Index): ";
                    cin >> zIndex;
                    cout << "Informe a cor do ret�ngulo: ";
                    cin >> cor;
                    canvas.InserirPoligono(new Retangulo({x, y}, zIndex, cor, base, altura));
                    cout << "Ret�ngulo inserido com sucesso!" << endl;
                    break;
                }
                case 'c': {
                    int raio, x, y, zIndex;
                    string cor;
                    cout << "Informe o raio do c�rculo em pixels: ";
                    cin >> raio;
                    cout << "Informe as coordenadas do centro do c�rculo (x y): ";
                    cin >> x >> y;
                    cout << "Informe a coordenada Z (Z-Index): ";
                    cin >> zIndex;
                    cout << "Informe a cor do c�rculo: ";
                    cin >> cor;
                    canvas.InserirPoligono(new Circulo({x, y}, zIndex, cor, raio));
                    cout << "C�rculo inserido com sucesso!" << endl;
                    break;
                }
                case 'd': {
                    Poligono* poligono = InserirPoligonoDefinidoPeloAluno1();
                    canvas.InserirPoligono(poligono);
                    cout << "Pol�gono definido pelo aluno (1) inserido com sucesso!" << endl;
                    break;
                }
                case 'e': {
                    Poligono* poligono = InserirPoligonoDefinidoPeloAluno1();
                    canvas.InserirPoligono(poligono);
                    cout << "Pol�gono definido pelo aluno (2) inserido com sucesso!" << endl;
                    break;
                }
                case 'f': {
                    canvas.ExibirPoligonos();
                    break;
                }
                case 'g': {
                    int indice;
                    cout << "Informe o �ndice do pol�gono a ser eliminado: ";
                    cin >> indice;
                    if (indice >= 1 && indice <= canvas.RecuperarPoligonos().size()) {
                        canvas.EliminarPoligono(indice);
                        cout << "Pol�gono eliminado com sucesso!" << endl;
                    } else {
                        cout << "�ndice inv�lido." << endl;
                    }
                    break;
                }
                case 'h': {
                    string nomeArquivo;
                    cout << "Informe o nome do arquivo para salvar a lista de pol�gonos: ";
                    cin >> nomeArquivo;
                    canvas.SalvarPoligonosParaArquivo(nomeArquivo);
                    cout << "Lista de pol�gonos salva com sucesso!" << endl;
                    break;
                }
                case 'i': {
                    cout << "Saindo do programa." << endl;
                    return 0;
                }
                default: {
                    cout << "Op��o inv�lida. Tente novamente." << endl;
                    break;
                }
            }
        } catch (const invalid_argument& e) {
            cerr << "Erro: " << e.what() << endl;
        }
    }

    return 0;
}
