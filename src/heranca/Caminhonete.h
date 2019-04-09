/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CAMINHONETE_H_
#define _CAMINHONETE_H_

#include<string>

using namespace std;

class Caminhonete : public Carro, public Caminhao {
public:
	//construtores
    Caminhonete() : Carro(), 
					Caminhao() {
		//cout << "Caminhonete()" << endl;
	}
	Caminhonete(string placa, double peso, unsigned int velocidadeMaxima, 
				double preco, string modelo, string cor, 
				double capacidadeTon, double comprimentoMet, double alturaMaxMet) : 	Carro(placa, peso, velocidadeMaxima, preco, modelo, cor),
																						Caminhao(placa, peso, velocidadeMaxima, preco, capacidadeTon, comprimentoMet, alturaMaxMet) {																																			
		//cout << "Caminhonete(param)" << endl;
	}
	
    //destrutor
	~Caminhonete() {
		//cout << "~Caminhonete()" << endl;
	}
	
    //metodos
	void imprime() {
		cout << "--- CAMINHONETE ---" << endl;
		Carro::imprimeDados();
		Caminhao::imprimeDados();
	}
};

#endif
