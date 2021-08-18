#include <iostream>

using namespace std;

class Coordenada {
    private:
        int x,y;
    public:
        void coord_new(int novo_x,int novo_y);
        Coordenada();
};

class Cubo {
    private:
        int x,y,z;
    public:
        void cube_new(int novo_x,int novo_y,int novo_z);
        void cube_print_volume();
        Cubo();
}; 

void Coordenada::coord_new(int novo_x,int novo_y) {
  x = novo_x;
  y = novo_y;
}

Coordenada::Coordenada(){
  x=0;
  y=0;
}


void Cubo::cube_new(int novo_x, int novo_y, int novo_z) {
  x = novo_x;
  y = novo_y;
  z = novo_z;
}

void Cubo::cube_print_volume() {
  cout << x*y*z << endl;
}

Cubo::Cubo(){
  x=0;
  y=0;
  z=0;
}

int main() {
  Coordenada *c1 = new Coordenada();
  Cubo *c2 = new Cubo();
  c1->coord_new(50, 10);
  c2->cube_new(10, 20, 30);
  c2->cube_print_volume();
  delete c1,c2;
  return 0;
}