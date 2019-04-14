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
	BancoController() : _contasCorrente(new ContaCorrente[50]), _contasPoupanca(new ContaPoupanca[50]), _numContasCorrente(0), _numContasPoupanca(0),_bancoView() {
		//cout << "BancoController()" << endl;
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
	void cadastrarContaCorrente(ContaCorrente conta){
		_contasCorrente[_numContasCorrente++] = conta;
	}
	
	void cadastrarContaPoupanca(ContaPoupanca conta){
		_contasPoupanca[_numContasPoupanca++] = conta;
	}
	
	void listaContas(){
		_bancoView.exibirContas(_contasCorrente, _contasPoupanca, _numContasCorrente, _numContasPoupanca);
	}
		
	void realizarDeposito() {
		unsigned int tipo;
		cout << "A conta para deposito eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)?" << endl;
		cin >> tipo;
		
		if (tipo == 0) {
			ContaCorrente* conta = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
			_bancoView.exibirDeposito(*conta);
		}else{
			if(tipo == 1){
				ContaPoupanca* conta = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
				_bancoView.exibirDeposito(*conta);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a receber o deposito!");
				return;
			}
		}	
	}
	
	void realizarRetirada() {
		unsigned int tipo;
		cout << "A conta para retirada eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)? " << endl;
		cin >> tipo;
		
		if (tipo == 0) {
			ContaCorrente* conta = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
			_bancoView.exibirRetirada(*conta);
		}else{
			if(tipo == 1){
				ContaPoupanca* conta = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
				_bancoView.exibirRetirada(*conta);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a receber o deposito!");
				return;
			}
		}
	}
	
	void realizarTransferencia(){
		unsigned int tipo, tipo1;
		
		cout << "A conta para transferir o dinheiro da transferencia eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)?" << endl;
		cin >> tipo;
		Conta* contaTransfere;
		Conta* contaRecebe;
		if(tipo == 0){
			cout << "Selecione a conta que ira transferir o dinheiro: " << endl;
			contaTransfere = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
		}else{
			if(tipo == 1) {
				contaTransfere = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a tranferir o dinheiro!");
				return;
			}
		}
		
		cout << "A conta para receber o dinheiro da transferencia eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)?" << endl;
		cin >> tipo1;
		if(tipo1 == 0){
			cout << "Selecione a conta que ira transferir o dinheiro: " << endl;
			contaRecebe = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
		}else{
			if(tipo1 == 1) {
				contaRecebe = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a receber o dinheiro!");
				return;
			}
		}
		
		_bancoView.exibirTransferencia(*contaTransfere, *contaRecebe);
	}
	
	void exibirJuros() {
		unsigned int tipo;
		
		cout << "A conta para visualizar o juros eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)?" << endl;
		cin >> tipo;
		if(tipo == 0){
			ContaCorrente* conta = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
			_bancoView.exibirJuros(*conta);
		}else{
			if(tipo == 1) {
				ContaPoupanca* conta = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
				_bancoView.exibirJuros(*conta);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a receber o dinheiro!");
				return;
			}
		}
	}
	
	void exibirExtrato() {
		unsigned int tipo;
		
		cout << "A conta para visualizar o extrato eh tipo Corrente (digite 0) ou tipo Poupanca (digite 1)?" << endl;
		cin >> tipo;
		if(tipo == 0){
			ContaCorrente* conta = _bancoView.selecionarContaCorrente(_contasCorrente, _numContasCorrente);
			_bancoView.exibirExtrato(*conta);
		}else{
			if(tipo == 1) {
				ContaPoupanca* conta = _bancoView.selecionarContaPoupanca(_contasPoupanca, _numContasPoupanca);
				_bancoView.exibirExtrato(*conta);
			}else{
				_bancoView.exibirMensagemErro("Voce deve escolher o tipo da conta a receber o dinheiro!");
				return;
			}
		}
	}
	
	void realizarOpcao(int opcaoSelecionada) {
		switch (opcaoSelecionada) {
			case 0:
				cadastrarContaCorrente(_bancoView.exibirCadastroContaCorrente());
				break;
			case 1:
				cadastrarContaPoupanca(_bancoView.exibirCadastroContaPoupanca());
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
				exibirJuros();
				break;
			case 7:
				exibirExtrato();
				break;
			case 8:
				exit(0);
				break;
			default:
				cout << "Digite uma opcao valida!" << endl;
				break;
		}
	}
	//objetos
	ContaCorrente* _contasCorrente;
	ContaPoupanca* _contasPoupanca;
	int _numContasCorrente;
	int _numContasPoupanca;
	BancoView _bancoView;
};

#endif
