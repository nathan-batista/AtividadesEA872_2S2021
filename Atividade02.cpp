#include <iostream>
#include <math.h>
#include <memory>

using namespace std;


class Sistema{
    private:
        float x0,v0,alpha,omega,coefA,coefB;
    public:
        Sistema(float novo_x,float novo_v,float novo_k, float novo_b, float novo_m);
        float getX0();
        float getV0();
        float getAlpha();
        float getOmega();
        float getA();
        float getB();
        void setA(float a);
        void setB(float b);
};

void Sistema::setA(float a){
    coefA = a;
}

void Sistema::setB(float b){
    coefB = b;
}

Sistema::Sistema(float novo_x,float novo_v,float novo_k, float novo_b, float novo_m){
    alpha = novo_b/(2*novo_m);
    omega = sqrt(novo_k/novo_m);
    v0=novo_v;
    x0=novo_x;
    coefA = 0.;
    coefB = 0.;
}

float Sistema::getX0(){
    return x0;
}

float Sistema::getV0(){
    return v0;
}

float Sistema::getA(){
    return coefA;
}

float Sistema::getB(){
    return coefB;
}

float Sistema::getAlpha(){
    return alpha;
}

float Sistema::getOmega(){
    return omega;
}


class Equacoes{
    private:
        shared_ptr<Sistema> sistema;
        float calcularVelocidade(int n);
        float velocidadeCritico(int n);
        float posicaoCritico(int n,float T);
        void coef_A_Critico();
        void coef_B_Critico();
        float calcularVelocidade(int n,float T);
    public:
        float calcularPosicao(int n);
        Equacoes(shared_ptr<Sistema> sis);
};

Equacoes::Equacoes(shared_ptr<Sistema> sis){
    sistema = sis;
};

void Equacoes::coef_A_Critico(){
    float x0 = sistema->getX0();
    sistema->setA(x0);
}

void Equacoes::coef_B_Critico(){
    float x0 = sistema->getX0();
    float b = sistema->getV0() + x0 * (-sistema->getAlpha());
    sistema->setB(b);
}

float Equacoes::calcularPosicao(int n){
    float alpha = sistema->getAlpha();
    float omega = sistema->getOmega();
    float x0 = sistema->getX0();
    float v0=sistema->getV0();

    float T = 0.1;
    cout << "Valor de omega^2 = " << pow(omega,2) << endl;
    cout << "Valor de alpha^2 = " << pow(alpha,2) << endl;

    if(pow(omega,2) == pow(alpha,2)){
        return posicaoCritico(n,T);
    }
}

float Equacoes::posicaoCritico(int n,float T){
    float xAtual = 0;
    coef_A_Critico();
    coef_B_Critico();
    float coefA = sistema->getA();
    float alpha = sistema->getAlpha();
    float coefB = sistema->getB();
    cout << "Valor de A: " << coefA << endl;
    cout << "Valor de B: " << coefB << endl;
    xAtual = coefA;
    float vAtual = coefB;
    float valorB = coefB * T * exp(alpha*T);
    for(int i=0;i<n;i++){
        // vAtual = exp(alpha*T)*vAtual;
        xAtual =  exp(alpha*T)*xAtual + valorB;
        valorB = valorB*exp(alpha*T);
        
        // exp(alpha*T)*(coefA*alpha + coefB*alpha*T + coefB)*T;
        // coefA*exp(alpha*T) + coefB*T*exp(alpha*T);
        // exp(alpha*T)*(coefA*alpha + coefB*alpha*T + coefB)*T;
        cout << "Tempo i: " << i << " Posicao Atual: " << xAtual   << endl;
    }

    cout << "Posicao: " << coefA*exp(alpha*n*T) + coefB*n*T*exp(alpha*n*T) << endl;
    return xAtual;
}



int main(){
    float beta = 4.;
    float k= 2.;
    shared_ptr<Sistema> sis (new Sistema(1,2,k, beta, 2));
    shared_ptr<Equacoes> eq (new Equacoes(sis));
    eq->calcularPosicao(10);
    return 0;
}

