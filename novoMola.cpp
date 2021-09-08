#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

using namespace std;

//Model
class Model{
  private:
    float m;
    float k;
    float b;
    float x0;
    float v0;
    float dt;
    float x_atual;
    float v_atual;

  public:
    Model(float m, float k, float b, float x0, float v0, float dt){

      //setando variaveis iniciais
      this->m = m;
      this->k = k;
      this->b = b;
      this->x0 = x0;
      this->v0 = v0;
      this->dt = dt;
      this->x_atual = x0;
      this->v_atual = v0;
    }
   
    float get_m(){
      return this->m;
    }
    float get_k(){
      return this->k;
    }
    float get_b(){
      return this->b;
    }
    float get_dt(){
      return this->dt;
    }
    float get_x_atual(){
      return this->x_atual;
    }
    void set_x_atual(float new_x){
      this->x_atual = new_x;
    }
    float get_v_atual(){
      return this->v_atual;
    }
    void set_v_atual(float new_v){
      this->v_atual = new_v;
    }
};

//View
class View{
  private:
    Model &model;
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Rect target;
    SDL_Texture *texture;
    SDL_Texture *texture2;

  public:
    View(Model &model) : model(model){

       // Inicializando o submodelema de video do SDL
      if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
          cout << SDL_GetError();
      }
        // Criando uma janela
      this->window = nullptr;
      this->window = SDL_CreateWindow("Demonstracao do SDL2",
          SDL_WINDOWPOS_UNDEFINED,
          SDL_WINDOWPOS_UNDEFINED,
          SCREEN_WIDTH,
          SCREEN_HEIGHT,
          SDL_WINDOW_SHOWN);
      if (this->window==nullptr) { // Em caso de erro...
          cout << SDL_GetError();
          SDL_Quit();
      }

          // Inicializando o renderizador
      this->renderer = SDL_CreateRenderer(
          this->window, -1,
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (this->renderer==nullptr) { // Em caso de erro...
          SDL_DestroyWindow(this->window);
          cout << SDL_GetError();
          SDL_Quit();
        }
      // Carregando texturas
      // personagem
      this->texture = IMG_LoadTexture(this->renderer, "./capi.png");
      // fundo
      this->texture2 = IMG_LoadTexture(this->renderer, "./park.jpeg");
      
      this->target.x = model.get_x_atual();
      this->target.y = 0;
      SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->target.w), &(this->target.h));

    }

    void renderizar(){
      // Desenhar a cena
      target.x = model.get_x_atual();
      SDL_RenderClear(this->renderer);
      SDL_RenderCopy(this->renderer, this->texture2, nullptr, nullptr);
      SDL_RenderCopy(this->renderer, this->texture, nullptr, &(this->target));
      SDL_RenderPresent(this->renderer);
      // Delay para diminuir o framerate
      SDL_Delay(10);
    }
    void destruir(){
      SDL_DestroyTexture(this->texture);
      SDL_DestroyRenderer(this->renderer);
      SDL_DestroyWindow(this->window);
      SDL_Quit();
    }
};


//Controller
class Controller{
  private:
    float a, f;
    bool rodando;
    // Variaveis para verificar eventos
    SDL_Event evento; // eventos discretos
    //const Uint8* state;  // estado do teclado
    Model &model;
    const Uint8* state;
  
  public:
  // Polling de eventos

    Controller(Model &model) : model(model){
        this->rodando = true;
        this->state = SDL_GetKeyboardState(nullptr);
        f=0;
        a=0;
    }

    void polling(){
      //SDL_PumpEvents(); // atualiza estado do teclado
      //if (state[SDL_SCANCODE_LEFT]) model.set_target((-1)*1, 0);
      //if (state[SDL_SCANCODE_RIGHT]) model.set_target(1, 0);
      //if (state[SDL_SCANCODE_UP]) model.set_target(0, (-1)*1);
      //if (state[SDL_SCANCODE_DOWN]) model.set_target(0, 1);

      while (SDL_PollEvent(&(this->evento))) {
        if (this->evento.type == SDL_QUIT) {
          this->rodando = false;
        }
        // Exemplos de outros eventos.
        // Que outros eventos poderiamos ter e que sao uteis?
        //if (evento.type == SDL_KEYDOWN) {
        //}
        //if (evento.type == SDL_MOUSEBUTTONDOWN) {
        //}
      }
    }  
    bool get_rodando(){
      return this->rodando;
    }
    void calcular_forca(){
      f = -(model.get_x_atual()-320)*model.get_k() - model.get_b()*model.get_v_atual();
    }
    void estimar_aceleracao(){
      a = f/model.get_m();
    }
    void calcular_velocidade(){
      model.set_v_atual(model.get_v_atual() + a * model.get_dt());
    }
    void calcular_posicao(){  
      model.set_x_atual(model.get_x_atual() + model.get_v_atual() * model.get_dt());
    }
    void update(){
      calcular_forca();
      estimar_aceleracao();   
      calcular_velocidade();
      calcular_posicao();              
    }
};

int main() { 
  Model model = Model(1, 1, 0, 320, 30, 0.1);
  View view = View(model);
  Controller controller = Controller(model);


  // Laco principal do jogo
  while(controller.get_rodando()) {
    controller.polling();
    controller.update();
    view.renderizar();
  }

  view.destruir();
  
  return 0;
}