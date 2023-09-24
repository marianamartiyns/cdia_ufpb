/* 1) Sistema de Streaming com Suporte a Podcast

**Objetivo do Exercício:** Estender o sistema de streaming de música para incluir podcasts, que têm características adicionais, como um apresentador e uma lista de episódios. Além disso, os podcasts podem ser reproduzidos em um modo especial que inclui a introdução e o encerramento do apresentador.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 2. Modifique a classe `Musica` para incluir um método protegido `tocarIntro()`. Este método deve exibir uma mensagem genérica indicando que a música está prestes a ser tocada. */

class Musica {

    string titulo;
    string artista;

protected:

    void tocarIntro(){
        cout << "Sua musica sera tocada em 5 segundos.." << endl;
    };

    public:
    Musica(string t, string a): titulo(t), artista(a){};

    string get_titulo() { return titulo;};
    void set_titulo (const string& t){
        titulo = t;
    };

    string get_artista() { return artista; };
    void set_artista(const string& a){
        artista = a;
    };

    void print_info(){
        cout << "Titulo: " << titulo << endl;
        cout << "Artista: " << artista << endl;
        cout << endl;
    };

    virtual void tocar(){
        cout << "Tocando musica" << endl;
        cout << endl;
    };

};

class MusicaLocal : public Musica {

    int caminho_arquivo;

    public:
    MusicaLocal(string t, string a, int c) : Musica(t,a), caminho_arquivo(c){};

    int get_caminho_arquivo() { return caminho_arquivo; };
    void set_caminho_arquivo(int c){
        caminho_arquivo = c;
    };

    void tocar(){
        cout << "Tocando a musica local: " << get_titulo() << " - " << get_artista() << " (" << caminho_arquivo << ")" << endl;
    };
};

class MusicaStreaming : public Musica {

    int url;

    public:
    MusicaStreaming (string t, string a, int u) : Musica (t, a), url(u){};

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
    vector<string> episodios;

    public:

    Podcast(string t, string a, string ap): Musica(t, a), apresentador(ap){};

    string get_apresentador(){ return apresentador; };
    void set_apresentador(const string& ap){
        apresentador = ap;
    };

    void AdicionarEpisodio(const string* episodio){
        episodios.push_back(episodio);
    };

    void tocar(){
        tocarIntro();
        cout << "Tocando o podcast: " << titulo << " - " << artista << " (Apresentador: " << apresentador << ")" << endl;
        cout << "Episódios:" << endl;
        for (const string& episodio : episodios) {
            cout << "- " << episodio << endl;
        };
    };
};

class PodcastPremium : private Podcast{

    int preco;

public:
    PodcastPremium(string t, string a, string ap, int p) : Podcast(t, a, ap), preco(p){};

    void tocarPremium(){
    tocarIntro();
    cout << "Tocando podcast premium" << endl; }

    void adicionarEpisodio(const string& episodio) {
        Podcast::adicionarEpisodio(episodio);
    }
};

int main(void){

    vector<Musica*> playlist;

    MusicaLocal* m1 = new MusicaLocal("style", "taylor swift", 1989);
    MusicaLocal* m2 = new MusicaLocal("Escapism.", "Umadiva", 7372);

    playlist.push_back(m1);
    playlist.push_back(m2);

    MusicaStreaming* m3 = new MusicaStreaming("I'm just ken", "barbiethemovie", 12345678);
    MusicaStreaming* m4 = new MusicaStreaming("The boy is mine", "anthem", 87658);

    playlist.push_back(m3);
    playlist.push_back(m3);

    Podcast podcast("Podcast Legal", "Minha Rede", "João");
    podcast.adicionarEpisodio("Episódio 1");
    podcast.adicionarEpisodio("Episódio 2");
    playlist.push_back(&podcast);

    PodcastPremium podcastPremium("Podcast Premium", "Minha Rede", "Maria", 9.99);
    podcastPremium.adicionarEpisodio("Episódio 1 (Premium)");
    playlist.push_back(&podcastPremium);


    for (const auto& musicaAtual: playlist){
        musicaAtual -> tocar ();
        delete musicaAtual;
    };

    return 0;
};
