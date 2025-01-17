/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CONTA_CORRENTE_H_
#define _CONTA_CORRENTE_H_

using namespace std;

class ContaCorrente : public Conta{
public:
	//construtores
	ContaCorrente(unsigned int numero, Cliente cliente) : Conta(numero, cliente) {
		//cout << "ContaCorrente()" << endl;
	}
	
	ContaCorrente() : Conta() {
		//cout << "ContaCorrente()" << endl;
	}
	//metodos
	void extrato(){
		Conta::extrato();
	}
	
	void aplicaJurosDiarios(int dias) {
		cout << "-- JUROS --" << endl;
		cout << "Juros: " << 0.0001 * dias * this->_saldo << endl;
	}
};

#endif
