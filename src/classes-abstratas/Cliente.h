/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include<string>

using namespace std;

class Cliente{
public:
	//contrutores
	Cliente(string nome) : _nome(nome){
		cout << "Cliente()" <<endl;
	}
	
	//destrutores
	~Cliente(){}
	
	//metodos
	void setNome(string nome){
		_nome = nome;
	}
	
	string getNome(){
		return _nome;
	}
private:
	string _nome;
};

#endif
