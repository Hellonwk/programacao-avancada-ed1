/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _BANCO_CONTROLLER_H_
#define _BANCO_CONTROLLER_H_

#include "Conta.h"
#include "BancoView.h"

using namespace std;

class BancoController {
public:
	//construtores
	BancoController() : _contas(new ContaCorrente[100]), _numContas(0), _bancoView() {
		cout << "BancoController()" << endl;
	}
	//metodos publicos
	void executar(){
		while(1){
			_bancoView.exibirMenu();
			int opcaoSelecionada = _bancoView.lerOpcao();	
			realizarOpcao(opcaoSelecionada);
		}
	}
	
private:
	//metodos privados		
	void cadastrarConta(ContaCorrente conta){
		_contas[_numContas++] = conta;
	}
	
	void listaContas(){
		_bancoView.exibirContas(_contas, _numContas);
	}
		
	void realizarDeposito() {
		ContaCorrente* conta = _bancoView.selecionarConta(_contas, _numContas);
		_bancoView.exibirDeposito(*conta);
	}
	
	void realizarRetirada() {
		ContaCorrente* conta = _bancoView.selecionarConta(_contas, _numContas);
		_bancoView.exibirRetirada(*conta);
	}
	
	void realizarTransferencia(){
		cout << "Selecione a conta que ira transferir o dinheiro: " << endl;
		ContaCorrente* contaTransfere = _bancoView.selecionarConta(_contas, _numContas);	
		cout << "Selecione a conta que ira receber o dinheiro da transferencia: " << endl;	
		ContaCorrente* contaRecebe = _bancoView.selecionarConta(_contas, _numContas);
		_bancoView.exibirTransferencia(*contaTransfere, *contaRecebe);
	}
	
	void exibirExtrato() {
		ContaCorrente* conta = _bancoView.selecionarConta(_contas, _numContas);
		_bancoView.exibirExtrato(*conta);
	}
	
	void realizarOpcao(int opcaoSelecionada) {
		switch (opcaoSelecionada) {
			case 1:
				cadastrarConta(_bancoView.exibirCadastroConta());
				break;
			case 2:
				listaContas();
				break;
			case 3:
				realizarDeposito();
				break;
			case 4:
				realizarRetirada();
				break;
			case 5:
				realizarTransferencia();
				break;
			case 6:
				exibirExtrato();
				break;
			case 7:
				exit(0);
				break;
			default:
				cout << "Digite uma opcao valida!" << endl;
				break;
		}
	}
	//objetos
	ContaCorrente* _contas;
	int _numContas;
	BancoView _bancoView;
};

#endif
