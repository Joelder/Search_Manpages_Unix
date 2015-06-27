/*
 * Leitor.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: Joelder
 */

#include <fstream>
#include <sstream>

#ifndef SEARCH_MANPAGES_UNIX_MODEL_LEITOR_CPP_
#define SEARCH_MANPAGES_UNIX_MODEL_LEITOR_CPP_

#include "Leitor.hpp"

Leitor::Leitor(string arquivo) {
	this->arquivo = arquivo;
}

Leitor::~Leitor() {
	// TODO Auto-generated destructor stub
}

Registro Leitor::lerArquivo() {

		ifstream archive (this->arquivo.c_str());

		if(archive.is_open()){

			string nome_comando  = this->arquivo.substr((this->arquivo.find_last_of("/") + 1), (this->arquivo).find_last_of(".") - (this->arquivo.find_last_of("/") + 1));
			char comando[80];
			strcpy(comando, nome_comando.c_str());

			char conteudo[150000];
			std::stringstream buffer;
			buffer<<archive.rdbuf();
			strcpy(conteudo, buffer.str().c_str());


			Registro r (comando, conteudo);
			archive.close();
			return r;

		} else {
			cout << "Não está abrindo o arquivo " << endl;
		}




}


#endif /* SEARCH_MANPAGES_UNIX_MODEL_LEITOR_CPP_ */
