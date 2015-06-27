/*
 * Indexador.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#include "Indexador.hpp"
#include "Leitor.hpp"
#include <iostream>
using namespace std;

Indexador::Indexador(int argc, char ** argv) {
 this->argc = argc;
 this->argv = argv;

}

Indexador::~Indexador() {
	// TODO Auto-generated destructor stub
}

void Indexador::indexar() {





	for (int i = 1; i < argc; i++) {
		cout << "Indexando chave" << i << endl;
	    // Lê o arquivo manpage atual.
	    Leitor *read = new Leitor(argv[i]);
	    Registro mr = read->lerArquivo();

	    // Adiciona na lista de índices primários
	    chavePrimaria.insere(mr);


	}

	/*
	NoAVL<Registro> *p = chavePrimaria->getDireita();
	Registro* pesquisa = p->getDado();
	cout << "comando direita: " << pesquisa->getComando() << endl;
	cout << "conteudo direita: " << pesquisa->getConteudo() << endl;


	NoAVL<Registro> *p2 = chavePrimaria->getEsquerda();
	Registro* pesquisa2 = p2->getDado();
	cout << "comando esquerda: " << pesquisa2->getComando() << endl;
	cout << "conteudo esquerda: " << pesquisa2->getConteudo() << endl;
*/


}

