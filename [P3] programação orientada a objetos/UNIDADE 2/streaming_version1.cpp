#include <iostream>
#include <string>

using namespace std;

class Musica {

    string titulo;
    string artista;

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

#include <vector>

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

    for (const auto& musicaAtual: playlist){
        musicaAtual -> tocar ();
        delete musicaAtual;
    };

    return 0;
};
