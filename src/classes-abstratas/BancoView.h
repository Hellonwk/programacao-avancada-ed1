/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#ifndef _BANCO_VIEW_H_
#define _BANCO_VIEW_H_

#include "ContaCorrente.h"

#include <string>

using namespace std;

class BancoView {
public:
	//construtores
	BancoView() {
		cout << "BancoView()" << endl;
	}
	//metodos
	void exibirMenu(){
		cout << "1 - Cadastrar Conta" << endl;
		cout << "2 - Exibir Contas Cadastradas" << endl;
		cout << "3 - Realizar Deposito" << endl;
		cout << "4 - Realizar Retirada" << endl;
		cout << "5 - Realizar Transferencia" << endl;
		cout << "6 - Realizar Extrato" << endl;
		cout << "7 - Sair" << endl;
	}
	
	int lerOpcao(){
		int opcaoInserida;
		cin >> opcaoInserida;
		return opcaoInserida;
	}
	
	ContaCorrente exibirCadastroConta(){
		unsigned int numero;
		string nome;
		
		cout << "Digite o numero da conta: " << endl;
		cin >> numero;

		cout << "Digite o nome do cliente: " << endl;
		cin >> nome;
		
		Cliente novoCliente(nome);
		ContaCorrente novaConta(numero, novoCliente);

		return novaConta;
	}
	
	ContaCorrente* selecionarConta(ContaCorrente* contas, unsigned int qntdContas) {
		unsigned int numero;
		
		cout << "Digite o numero da conta: " << endl;
		cin >> numero;

		for (int i = 0; i < qntdContas; i++) {
			if (contas[i].getNumero() == numero) {
				exibirMensagemSucesso("A conta selecionada eh do cliente: " + contas[i].getNomeCliente());
				return &contas[i];
			}
		}
		exibirMensagemErro("Nenhuma conta foi encontrada com esse numero!");
		return NULL;
	}
	
	void exibirContas(ContaCorrente* contas, unsigned int qntdContas) {
		if(qntdContas == 0) {
			exibirMensagemErro("Ainda nao foi cadastrada nenhuma conta!");	
		}
		for (int i = 0; i < qntdContas; i++) {
			contas[i].imprimeSaldo();
		}
	}
	
	float exibirDeposito(ContaCorrente &conta) {
		if(&conta == NULL){
			exibirMensagemErro("Nenhuma conta foi selecionada!");
			return -1;
		}
		
		float deposito;
		
		cout << "Digite o valor a ser depositado: " << endl;
		cin >> deposito;
		
		if(deposito < 0){
			exibirMensagemErro("O valor deve ser positivo!");
			return -1;
		}

		conta.deposita(deposito);

		exibirMensagemSucesso("Deposito realizado!");
		
		return deposito;
	}
	
	float exibirRetirada(ContaCorrente &conta) {
		if(&conta == NULL){
			exibirMensagemErro("Nenhuma conta foi selecionada!");
			return -1;
		}
		
		float retirada;
		
		cout << "Digite o valor a ser retirado: " << endl;
		cin >> retirada;
		
		if(retirada < 0){
			exibirMensagemErro("O valor deve ser positivo!");
			return -1;
		}

		conta.retira(retirada);

		exibirMensagemSucesso("Retirada realizada!");
		
		return retirada;
	}
	
	float exibirTransferencia(ContaCorrente &contaRetira, ContaCorrente &contaDeposita){
		if(&contaRetira == NULL || &contaDeposita == NULL){
			exibirMensagemErro("Nenhuma conta de transferencia foi selecionada!");
			return -1;
		}
		
		float transfere;
		
		cout << "Digite o valor da transferencia: " << endl;
		cin >> transfere;

		if (contaRetira.getSaldo() < transfere) {
			exibirMensagemErro("O valor da transferencia deve ser menor que o saldo da conta!");
		}
		else {
			contaRetira.transfere(contaDeposita, transfere);
			exibirMensagemSucesso("Transferencia realizada!");
		}
		
		return transfere;
	}
	
	void exibirExtrato(ContaCorrente &conta) {
		if(&conta == NULL){
			exibirMensagemErro("Nenhuma conta foi selecionada!");
		}else{
			conta.extrato();
			exibirMensagemSucesso("Extrato realizado!");	
		}	
	}
	
	void exibirMensagemErro(string erro) {
		cout << "Ocorreu um erro!" << endl;
		cout << "Detalhes: " << erro << endl;
	}
	
	void exibirMensagemSucesso(string sucesso) {
		cout << "Operacao realizada com sucesso!" << endl;
		cout << "Detalhes: " << sucesso << endl;
	}
};

#endif
