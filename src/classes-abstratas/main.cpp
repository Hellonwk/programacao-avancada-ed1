/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#include <iostream>

#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Cliente.h"
#include "BancoController.h"

using namespace std;

void atividade3(){
	/**** Atividade 03 ****/
	Cliente cliente1("Amanda Cardoso");
	Cliente cliente2("Rafael Batista");
	
	ContaCorrente contaCorrente1(1, cliente1);
	ContaCorrente contaCorrente2(2, cliente2);
	
	ContaPoupanca contaPoupanca1(1, cliente1);
	ContaPoupanca contaPoupanca2(2, cliente2);

	contaCorrente1.deposita(100);
	contaCorrente1.deposita(400);
	contaCorrente1.retira(50);
	contaCorrente1.extrato();
	
	contaPoupanca1.deposita(1900);
	contaPoupanca1.retira(10);
	contaPoupanca1.extrato();
	
	contaCorrente2.deposita(1000);
	contaCorrente2.extrato();
	
	contaPoupanca2.deposita(1000);
	contaPoupanca2.extrato();
	
	contaCorrente2.aplicaJurosDiarios(100);
	contaPoupanca2.aplicaJurosDiarios(100);
	
	contaCorrente2.transfere(contaPoupanca1, 500);
	contaPoupanca1.extrato();
	contaCorrente2.extrato();
	contaPoupanca2.transfere(contaCorrente1, 500);
	contaCorrente1.extrato();
	contaPoupanca2.extrato();
}

void atividade5(){		
	/**** Atividade 05 ****
	 * Crie um vetor de 100 contas correntes. Analise o que aconteceu ao criar este vetor. Isto eh um problema? Se sim,como pode ser resolvido? Justifique. */
	ContaCorrente* *vetorContaCorrente = new ContaCorrente*[100];
	Cliente clientex("Todos");
	for(int i = 0; i < 100; i++){
		vetorContaCorrente[i] = new ContaCorrente(i, clientex);
	}
	/*
	 * 	O vetor eh criado, mas diferentemente das outras contas correntes criadas na atividade 3, essas contas nao chamam o destrutor da classe 
	 * 	Em uma aplicacao pequena, isso nao seria um problema tao grande, porem, em uma aplicacao com um uso maior de memoria, isso seria um grande problema, visto que 
	 * 	a memoria nao esta sendo desalocada.
	 *  A solucao pra este problema seria chamar os destrutores para cada item do vetor.
	*/
	for(int i = 0; i < 100; i++){
		vetorContaCorrente[i]->~Conta();
	}
}

int main() {
	BancoController bancoController;
	bancoController.executar();
	
	return 0;
}
