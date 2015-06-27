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

	Leitor *read = new Leitor(argv[1]);
	Registro r = read->lerArquivo();

	NoAVL<Registro> *chavePrimaria = new NoAVL<Registro>(r);


	cout << "comando: " << r.getComando() << endl;
	cout << "conteudo: " << r.getConteudo() << endl;


	Leitor *read2 = new Leitor(argv[2]);
	Registro r2 = read2->lerArquivo();

	chavePrimaria->inserir(r2,chavePrimaria);

	cout << "comando: " << r2.getComando() << endl;
	cout << "conteudo: " << r2.getConteudo() << endl;


	/*
	for (int i = 2; i < this->argc; i++) {
		cout << "Indexando chave" << i << endl;
	}
*/
}

