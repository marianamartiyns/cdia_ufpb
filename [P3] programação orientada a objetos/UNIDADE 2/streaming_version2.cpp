/* 1) Sistema de Streaming com Suporte a Podcast

**Objetivo do Exercício:** Estender o sistema de streaming de música para incluir podcasts, que têm características adicionais, como um apresentador e uma lista de episódios. Além disso, os podcasts podem ser reproduzidos em um modo especial que inclui a introdução e o encerramento do apresentador.*/

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/* 2. Modifique a classe `Musica` para incluir um método protegido `tocarIntro()`. Este método deve exibir uma mensagem genérica indicando que a música está prestes a ser tocada. */

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

/* 1. Crie uma classe `Podcast` que herde publicamente da classe `Musica`. Esta classe deve ter os seguintes membros:

   - Um membro de dados privado `apresentador` para armazenar o nome do apresentador do podcast.
   - Um membro de dados privado `episodios` para armazenar a lista de episódios do podcast.
   - Um construtor que aceite três parâmetros para inicializar o título, o artista (neste caso, pode ser a rede ou o produtor do podcast) e o apresentador.
   - Uma função `AdicionarEpisodio()` para adicionar episódios à lista.
   - Uma implementação da função `tocar()` que "toca" o podcast, exibindo uma mensagem que inclui o título, a rede, o apresentador e a lista de episódios.  */

class Podcast : public Musica {

    string apresentador;
    std::vector <string> episodios;

    public:

    Podcast(const string& t, const string& a, const string* a): Musica(t, a){
        a = apresentador;
        codigo = 3;
    };

    string get_apresentador(){ return apresentador; };
    void set_apresentador(const string& a){
        a = apresentador;
    };

    void AdicionarEpisodio(const string* episodio){
        episodios.push_back(episodio);
    };

    /******/
    void tocar() {
        cout << "Tocando o podcast: " << titulo << " - " << artista << " (Apresentador: " << apresentador << ")" << endl;
        cout << "Episódios:" << endl;
        for (const string& episodio : episodios) {
            cout << "- " << episodio << endl;
        };
    };
};


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