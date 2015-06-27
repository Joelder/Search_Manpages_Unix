/*
 * Indexador.h
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#ifndef SEARCH_MANPAGES_UNIX_MODEL_INDEXADOR_HPP_
#define SEARCH_MANPAGES_UNIX_MODEL_INDEXADOR_HPP_
#include "Registro.cpp"
#include "../estruturas/avl_tree.h"

class Indexador {
private:
	avl_tree<Registro> chavePrimaria;

	int argc;

	char ** argv;


public:

	Indexador(int argc, char **argv);

	virtual ~Indexador();

	void indexar();
};

#endif /* SEARCH_MANPAGES_UNIX_MODEL_INDEXADOR_HPP_ */
