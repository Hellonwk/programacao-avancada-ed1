/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CONTA_POUPANCA_H_
#define _CONTA_POUPANCA_H_

using namespace std;

class ContaPoupanca : public Conta{
public:
	//contrutores
	ContaPoupanca(unsigned int numero, Cliente cliente) : Conta(numero, cliente){
		//cout << "ContaPoupanca()" << endl;
	}
	//metodos
	void extrato(){
		
	}
	
	void aplicaJurosDiarios(int dias) {
		cout << "Juros: " << 0.0008 * dias * this->_saldo << endl;
	}
};

#endif
