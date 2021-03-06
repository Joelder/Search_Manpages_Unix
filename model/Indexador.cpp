/*
 * Indexador.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#include "Indexador.hpp"

#include <iostream>
#include "Leitor.cpp"
#include "Leitor.hpp"
#include <unistd.h>
#include <vector>

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
		cout << "Indexando chave: " << i << endl;
	    // Lê o arquivo manpage atual.
	    Leitor *read = new Leitor(argv[i]);
	    Registro mr = read->lerArquivo();

	    // Adiciona na lista de índices primários
	    chavePrimaria.insere(mr);
	    //usleep(100000);

	}

	cout << "Salvando chaves primarias em arquivo"<< endl;


	 // Criando arquivo de saída
	        ofstream arquivoSaida("chavesPrimarias.dat");

	        // Verificando se arquivo de saida foi aberto
	        if (arquivoSaida.is_open()) {

	            // Pega todos os registros da árvore AVL EM ORDEM e armazena no arquivoSaida.
	            vector<Registro> registrosEmOrdem = chavePrimaria.breadth_first();
	            for(int i = 0; i < registrosEmOrdem.size(); i++) {
	                arquivoSaida << registrosEmOrdem.at(i).getComando();
	                arquivoSaida << " ";
	                arquivoSaida << registrosEmOrdem.at(i).getConteudo();
	                arquivoSaida << "\3"; // termina a escrita com um caracter "end of text".
	            }
	            vector<Registro>().swap(registrosEmOrdem);
	            // Fecha o arquivo.
	            arquivoSaida.close();

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

