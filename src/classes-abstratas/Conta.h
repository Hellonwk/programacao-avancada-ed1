/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CONTA_H_
#define _CONTA_H_

#include "Cliente.h"

using namespace std;

class Conta{
public:
	//contrutores
    Conta(unsigned int numero, Cliente cliente) : _numero(numero),
                                	 	 _cliente(cliente),
										 _saldo(0) {
        cout << "Criando conta " << _numero << " do cliente "  << _cliente.getNome() << endl;
    }

	//destrutor
    virtual ~Conta() {
        cout << "Destruindo conta " << _numero << " do cliente "  << _cliente.getNome() << endl;
    }

	//metodos
	virtual void imprimeSaldo() {
		cout << "Conta: " << _numero << " / Cliente: " << _cliente.getNome() << endl;
		cout << "Saldo: " << _saldo << endl;
	}
	
    virtual void deposita(float valor) {
    	_saldo += valor;
    	//imprimeSaldo();
	}
	
	virtual void retira(float valor) {
		_saldo -= valor;
		//imprimeSaldo();
	}

	virtual void transfere(Conta &contaDestino, float valor){
		if (valor <= _saldo) {
			retira(valor);
			contaDestino.deposita(valor);
		}else{
			cout << "Saldo insuficiente!" << endl;
		}
	}

	virtual void extrato(){
		cout << "-- EXTRATO --" << endl;
		imprimeSaldo();	
	}

    //metodos abstratos
    virtual void aplicaJurosDiarios(int dias) = 0;

protected:
    unsigned int _numero;
    Cliente _cliente;
    float _saldo;
};

#endif
