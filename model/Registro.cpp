/*
 * Registro.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#ifndef SEARCH_MANPAGES_UNIX_MODEL_REGISTRO_CPP_
#define SEARCH_MANPAGES_UNIX_MODEL_REGISTRO_CPP_


#include "Registro.hpp"
#include <cstring>


Registro::Registro(char comando[100], char conteudo[200000]) {
	strcpy(this->comando, comando);
	strcpy(this->conteudo, conteudo);
}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}

char* Registro::getComando() {
	return this->comando;
}

char* Registro::getConteudo(){
	return this->conteudo;
}

void Registro::setComando(char* comando) {
	strcpy(this->comando, comando);
}

void Registro::setConteudo(char* conteudo) {
	strcpy(this->conteudo, conteudo);
}


#endif
