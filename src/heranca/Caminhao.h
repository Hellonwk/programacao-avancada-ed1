/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CAMINHAO_H_
#define _CAMINHAO_H_

#include<string>

using namespace std;

class Caminhao : public Veiculo {
public:
	//construtores
    Caminhao() :	Veiculo(), 
					_capacidadeTon(0), 
					_comprimentoMet(0), 
					_alturaMaxMet(0) {
		//cout << "Caminhao()" << endl;
	}
	Caminhao(string placa, double peso, unsigned int velocidadeMaxima, double preco, 
			 double capacidadeTon, double comprimentoMet, double alturaMaxMet) : 	Veiculo(placa, peso, velocidadeMaxima, preco), 
																					_capacidadeTon(abs(capacidadeTon)),
																					_comprimentoMet(abs(comprimentoMet)),
																					_alturaMaxMet(abs(alturaMaxMet)) {
		//cout << "Caminhao(param)" << endl;
	}
	
    //destrutor
	~Caminhao() {
		//cout << "~Caminhao()" << endl;
	}
	
    //metodos
    void imprime(){
    	cout << "--- CAMINHAO ---" << endl;
    	Veiculo::imprimeDados();
    	imprimeDados();
	}
	void imprimeDados() {
		cout << "Capacidade: "<< _capacidadeTon << " toneladas"<< endl;
		cout << "Comprimento: "<< _comprimentoMet << " metros"<< endl;
		cout << "Altura Maxima: "<< _comprimentoMet << " metros"<< endl;
	}
private:
	double _capacidadeTon;
	double _comprimentoMet;
	double _alturaMaxMet;
};

#endif
