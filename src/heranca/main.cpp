/*
 * Trablho de BCC, UTP
 * Programacao Avancada
 * Autora: Sabrina Eloise Nawcki
*/

#include <iostream>
#include <string>

#include"Veiculo.h"
#include"Carro.h"
#include"Caminhao.h"
#include"Caminhonete.h"

using namespace std;

int main() {
/********************** Atividade 04 **********************/
/**** Atividade 01 ****/
	Veiculo veiculo1("AAA0101", 500, 220, 110000);
	Veiculo veiculo2;
	
	veiculo1.imprime();
	veiculo2.imprime();
	
/**** Atividade 02 ****/	
	Carro carro1("AAA0102", 450, 320, 510000, "Modelasso", "Ciano");
	Carro carro2;
	
	carro1.imprime();
	carro2.imprime();
	
/**** Atividade 03 ****/
	Caminhao caminhao1("AAA0103", 700, 120, 120000, 10, 10, 4);
	Caminhao caminhao2;
	
	caminhao1.imprime();
	caminhao2.imprime();
	
/**** Atividade 05 ****/
	Caminhonete caminhonete1("AAA0104", 600, 220, 300000, "Modelao", "Vermelho", 5, 4, 4);
	Caminhonete caminhonete2;
	
	caminhonete1.imprime();
	caminhonete2.imprime();
	return 0;
}
