/*
 * Registro.hpp
 *
 *  Created on: Jun 25, 2015
 *      Author: home
 */

#ifndef SEARCH_MANPAGES_UNIX_MODEL_REGISTRO_HPP_
#define SEARCH_MANPAGES_UNIX_MODEL_REGISTRO_HPP_

class Registro {

private:
	char comando[100];
	char conteudo[200000];

public:

	Registro(char comando[100], char conteudo[200000]);

	virtual ~Registro();

	char* getComando();

	char* getConteudo();

	void setComando(char* comando);

	void setConteudo(char* conteudo);

	bool operator<(const Registro& rhs) const {
			return comando < rhs.comando;
		}
};

#endif /* SEARCH_MANPAGES_UNIX_MODEL_REGISTRO_HPP_ */
