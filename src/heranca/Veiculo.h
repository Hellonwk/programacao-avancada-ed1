/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _VEICULO_H_
#define _VEICULO_H_

#include<string>
#include<math.h>

using namespace std;

class Veiculo {
public:
	//construtores
    Veiculo() : _placa("ZZZ0000"), 
				_peso(0), 
				_velocidadeMax(0), 
				_preco(0) {
		//cout << "Veiculo()" << endl;
	}
	Veiculo(string placa, double peso, unsigned int velocidadeMax, double preco) : 	_placa(placa), 
																					_peso(abs(peso)),
																					_velocidadeMax(velocidadeMax), 
																					_preco(abs(preco)) {
		//cout << "Veiculo(param)" << endl;
	}
	
    //destrutor
	~Veiculo() {
		//cout << "~Veiculo()" << endl;
	}
	
    //metodos
    void imprime(){
    	cout << "--- VEICULO ---" << endl;
    	imprimeDados();
	}
	void imprimeDados() {
		cout << "Placa: "<< _placa << endl;
		cout << "Peso: "<< _peso << " Kg"<< endl;
		cout << "Velocidade Maxima: "<< _velocidadeMax << " Km/Hr" << endl;
		cout << "Preco: R$"<< _preco << endl;
	}
private:
	string _placa;
	double _peso;
	unsigned int _velocidadeMax;
	double _preco;
};

#endif
