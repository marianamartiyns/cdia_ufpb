/* 1) Sistema de Streaming

**Objetivo do Exercício:** Criar uma hierarquia de classes que simule um sistema de streaming de música. */

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/* 1. Crie uma classe abstrata (VIRTUAL) chamada `Musica`, que representará uma música genérica no sistema. Esta classe deve ter os seguintes membros:

   - Um membro de dados privado `titulo` para armazenar o título da música.
   - Um membro de dados privado `artista` para armazenar o nome do artista.
   - Um construtor que aceite dois parâmetros para inicializar o título e o artista.
   - Uma função membro virtual pura chamada `tocar()` que será usada para "tocar" a música.  */

class Musica {

    string titulo;
    string artista;

    //  *********
    protected:
    int codigo;

    public:
    Musica(const string& t, const string& a){
        t = titulo;
        a = artista;
    };

    string get_titulo() { return titulo;};
    void set_titulo (const string& t){
        t = titulo;
    };

    string get_artista() { return artista; };
    void set_artista(const string& a){
        a = artista;
    };

    void print_info(){
        cout << "Titulo: " << titulo << endl;
        cout << "Artista: " << artista << endl;
    };

    virtual void tocar() const = 0;

};

/* 2. Crie uma classe chamada `MusicaLocal` que herde publicamente da classe `Musica`. Esta classe deve ter os seguintes membros:
   - Um membro de dados privado `caminhoArquivo` para armazenar o caminho do arquivo da música.
   - Um construtor que aceite três parâmetros para inicializar o título, o artista e o caminho do arquivo.
   - Uma implementação da função `tocar()` que "toca" a música local, exibindo uma mensagem que inclui o título, o artista e o caminho do arquivo. */

class MusicaLocal : public Musica {
     
    int caminho_arquivo;

    public:
    Musicalocal(const string& t, const string& a, int c) : Musica (t, a){
        c = caminho_arquivo;
        codigo = 1;
    };

    int get_caminho_arquivo() { return caminho_arquivo; };
    void set_caminho_arquivo(int c){
        caminho_arquivo = c;
    };

    void tocar() const override {
        std::cout << "Tocando a música local: " << get_titulo() << " - " << get_artista() << " (" << caminho_arquivo << ")" << std::endl;
    };

    void tocar() {
		cout << "Caminho do arquivo:" << caminho_arquivo << endl;
		Musica::print_info();
	};
};

/*3. Crie outra classe chamada `MusicaStreaming` que também herde publicamente da classe `Musica`. Esta classe deve ter os seguintes membros:
   - Um membro de dados privado `url` para armazenar a URL da música.
   - Um construtor que aceite três parâmetros para inicializar o título, o artista e a URL.
   - Uma implementação da função `tocar()` que "toca" a música de streaming, exibindo uma mensagem que inclui o título, o artista e a URL.*/

   class MusicaStreaming : public Musica {
     
    int url;

    public:
    MusicaStreaming (const string& t, const string& a, int u) : Musica (t, a){
        url = u;
        codigo = 2;
    };

    int get_url() { return url; };
    void set_url(int u){
        url = u;
    };

    void tocar() {
		cout << "URL:" << url << endl;
		Musica::print_info();
	};
};

/* 4. No `main()`, crie objetos das classes `MusicaLocal` e `MusicaStreaming`, armazene-os em um vetor de ponteiros para `Musica`, e então percorra o vetor, chamando a função `tocar()` para cada música. Isso demonstrará a ligação dinâmica em ação. */

#include <vector>

int main(){

    MusicaLocal musicaLocal("Música Local 1", "Artista Local", "/caminho/para/musica1.mp3");
    MusicaStreaming musicaStreaming("Música Streaming 1", "Artista Streaming", "https://exemplo.com/streaming1");

    // Criando um vetor de ponteiros para a classe Musica
    std::vector <Musica*> playlist;

    // Adicionando os objetos ao vetor
    playlist.push_back(&musicaLocal);
    playlist.push_back(&musicaStreaming);

    // Tocando todas as músicas da playlist
    for (const Musica* musica : playlist) {
        musica->tocar();
    };

    return 0;
};