/*
 * Leitor.hpp
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#ifndef SEARCH_MANPAGES_UNIX_MODEL_LEITOR_HPP_
#define SEARCH_MANPAGES_UNIX_MODEL_LEITOR_HPP_
using namespace std;
#include "Registro.cpp"

class Leitor {
private:
	string arquivo;

public:

	Leitor(string arquivo);

	virtual ~Leitor();

	Registro lerArquivo();
};

#endif /* SEARCH_MANPAGES_UNIX_MODEL_LEITOR_HPP_ */
