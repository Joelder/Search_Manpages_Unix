/*
 * Avltree.h
 *
 *  Created on: Jun 24, 2015
 *      Author: Joelder
 */

#ifndef SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_HPP_
#define SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_HPP_
#include <vector>


template <typename T>
class AvlTree {
private:
	int altura;
	T* dado;
	AvlTree<T>* direita;
	AvlTree<T>* esquerda;
	std::vector<AvlTree<T>* > elementos;


public:

	explicit AvlTree();

	virtual ~AvlTree();

	int getAltura();

	std::vector<AvlTree<T>* > getElementos();

	AvlTree<T>* getEsquerda();

	AvlTree<T>* getDireita();

	AvlTree<T>* inserir(const T& dado, AvlTree<T>* arv);

	int fator(AvlTree<T>* raiz);

	AvlTree<T>* balancear(AvlTree<T>* auxiliar);

	AvlTree<T>* simp_roda_esq(AvlTree<T>* nodo);

	AvlTree<T>* simp_roda_dir(AvlTree<T>* nodo);

	AvlTree<T>* dup_roda_esq(AvlTree<T>* nodo);

	AvlTree<T>* dup_roda_dir(AvlTree<T>* nodo);

	void atualizaAltura(AvlTree<T>* raiz);

	AvlTree<T>* remover(AvlTree<T>* arv, const T& dado);

	AvlTree<T>* minimo(AvlTree<T>* nodo);

	T* getDado();

	T* busca(const T& dado, AvlTree<T>* arv);

	int maximo(AvlTree<T>* nodo1, AvlTree<T>* nodo2);

	void preOrdem(AvlTree<T>* nodo);

	void emOrdem(AvlTree<T>* nodo);

	void posOrdem(AvlTree<T>* nodo);

};

#endif /* SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_HPP_ */
