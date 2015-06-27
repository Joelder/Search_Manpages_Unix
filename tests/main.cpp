/*
 * main.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: home
 */


#ifndef SEARCH_MANPAGES_UNIX_TESTS_MAIN_CPP_
#define SEARCH_MANPAGES_UNIX_TESTS_MAIN_CPP_
using namespace std;
#include <iostream>
#include <stdlib.h>
#include "../model/Leitor.cpp"
#include "../model/Indexador.cpp"


#include <stdio.h>
int main (int argc, char* argv[]) {

	Indexador index(argc, argv);
	index.indexar();





	/*
	int i;
	printf("\n Arquivos: %d \n", argc - 1);

	for (i=1; i < argc; i++) {
		printf("--> %s\n", argv[i]);
	}

	*/

//string comando("../ManPages/admin.4.txt");

/*
int size = comando.find_last_of("/") + 1;
int size2 = comando.find_last_of(".");
int tamanho = size2 - size;

string teste = comando.substr(size, tamanho);

cout << "Posicao slash: " << size << endl;
cout << "Posicao point: " << size2 << endl;
cout << "Substring : " << teste << endl;
*/


/*
Leitor* l = new Leitor(comando);
Registro r = l->lerArquivo();

cout << "comando: " << r.getComando() << endl;
cout << "conteudo: " << r.getConteudo() << endl;
*/


}


#endif /* SEARCH_MANPAGES_UNIX_TESTS_MAIN_H_ */
