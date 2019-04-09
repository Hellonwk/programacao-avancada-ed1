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
#include "BancoView.h"

using namespace std;

int main() {
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
	
	contaPoupanca1.deposita(1900);
	contaPoupanca1.retira(10);
	
	contaCorrente2.deposita(1000);
	
	contaPoupanca2.deposita(1000);
	
	contaCorrente2.aplicaJurosDiarios(100);
	contaPoupanca2.aplicaJurosDiarios(100);
	
	contaCorrente2.transfere(contaPoupanca1, 500);
	contaPoupanca2.transfere(contaCorrente1, 500);

	return 0;
}
