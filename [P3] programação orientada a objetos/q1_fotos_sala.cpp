/*
    poligono - cor, conjunto de pontos
    pontos - (x,y)

*/

class ponto {

    int x, y;

    public:
        //construtor
        ponto(int xx = 0, int y = 0){
            x = xx;
            y = y;
        };

        int get_x(){
            return x;
        };

        int get_y(){
            return y;
        };

        void set_x(int a){
            x = a;
        };

        void set_y(int b){
            y = b;
        };
};

class poligono {

    int cor, cons;
    ponto* pontos;
    int qtd_pontos;

    public:
        // construtor
        poligono(int c, ponto* p, int q, int co = 0){
            c = cor;
            pontos = p;
            q = qtd_pontos;
        };

    int get_cor(){
        return cor;
    };

    int get_cons(){
        return cons;
    };

    // ***************
    ponto* get_ponto(){
        return pontos;
    };

    int qtd_pontos(){
        return qtd_pontos;
    };

    //deletor: so faz quando aloca memoria dinamicamente(usa ponteiro)
    ~poligono(){
        delete[] pontos;
    };
};

int main(void){
    ponto ps[4];

    // adicionar os pontos (0,0), (1,0), (0,1), (1,1)
    ps[1].set_x(1);
    ps[2].set_y(1);
    ps[3].set_x(1);
    ps[3].set_y(1);

    poligono p1(10, ps, 4);
}