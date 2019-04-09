/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CARRO_H_
#define _CARRO_H_

#include<string>

using namespace std;

class Carro : public Veiculo {
public:
	//construtores
    Carro() : 	Veiculo(), 
				_modelo("0"), 
				_cor("Branca") {
		//cout << "Carro()" << endl;
	}
	Carro(string placa, double peso, unsigned int velocidadeMax, double preco, 
		  string modelo, string cor) : 	Veiculo(placa, peso, velocidadeMax, preco), 
										_modelo(modelo), 
										_cor(cor) {
		//cout << "Carro(param)" << endl;	
	}
	
    //destrutor
	~Carro() {
		//cout << "~Carro()" << endl;
	}
	
    //metodos
    void imprime(){
    	cout << "--- CARRO ---" << endl;
    	imprimeDados();
	}
	void imprimeDados() {
		Veiculo::imprimeDados();
		cout << "Modelo: "<< _modelo << endl;
		cout << "Cor: "<< _cor << endl;
	}
private:
	string _modelo;
	string _cor;
};

#endif
