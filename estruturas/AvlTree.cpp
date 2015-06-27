/*
 * Avltree.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: Joelder
 */

#ifndef SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_CPP_
#define SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_CPP_


#include "AvlTree.hpp"
#include <cstddef>

template <typename T>
AvlTree<T>::AvlTree() {
	this->altura = 0;
	this->dado = new T(dado);
	this->esquerda = NULL;
	this->direita = NULL;
}

template <typename T>
AvlTree<T>::~AvlTree() {
	this->altura = -1;
	delete this->esquerda;
	delete this->direita;
	delete this->dado;
}

template <typename T>
int AvlTree<T>::getAltura() {
	return this->altura;
}

template <typename T>
std::vector<AvlTree<T>* > AvlTree<T>::getElementos() {
        return this->elementos;
}

template <typename T>
AvlTree<T>* AvlTree<T>::getEsquerda() {
        return this->esquerda;
}

template <typename T>
AvlTree<T>* AvlTree<T>::getDireita() {
        return this->esquerda;
}

template <typename T>
AvlTree<T>* AvlTree<T>::inserir(const T& dado, AvlTree<T>* arv) {
	AvlTree<T>* novo;
     if (dado < *(arv->getDado())) {
         if (arv->getEsquerda() == NULL) {
             novo = new AvlTree<T>(dado);
             arv->esquerda = novo;
         } else {
             arv->esquerda = this->inserir(dado, arv->getEsquerda());
         }
     } else if (dado > *(arv->getDado())) {
         if (arv->getDireita() == NULL) {
             novo = new AvlTree<T>(dado);
             arv->direita = novo;
         } else {
             arv->direita = this->inserir(dado, arv->getDireita());
         }
         }
     return balancear(arv);
}

template <typename T>
int AvlTree<T>::fator(AvlTree<T>* raiz) {
    if (raiz->getEsquerda() == NULL && raiz->getDireita() == NULL) {
        return -1;
    } else if (raiz->getEsquerda() != NULL && raiz->getDireita() != NULL) {
        this->atualizaAltura(raiz->getEsquerda());
        this->atualizaAltura(raiz->getDireita());
        return (raiz->getEsquerda()->getAltura() -
                    raiz->getDireita()->getAltura());
    } else if (raiz->getEsquerda() != NULL) {
        this->atualizaAltura(raiz->getEsquerda());
        return (raiz->getEsquerda()->getAltura() + 1);
    } else {
        this->atualizaAltura(raiz->getDireita());
        return (-1 - raiz->getDireita()->getAltura());
    }
}

template <typename T>
AvlTree<T>* AvlTree<T>::balancear(AvlTree<T>* auxiliar) {
    int balancoPai, balancoFilhoEsq, balancoFilhoDir;
balancoPai = this->fator(auxiliar);
if (auxiliar->getDireita() != NULL && balancoPai < -1) {
    balancoFilhoDir = this->fator(auxiliar->getDireita());
    if (balancoFilhoDir == 1) {
        auxiliar->direita = this->simp_roda_esq(auxiliar->getDireita());
    }
    auxiliar = this->simp_roda_dir(auxiliar);
} else if (auxiliar->getEsquerda() != NULL && balancoPai > 1) {
    balancoFilhoEsq = this->fator(auxiliar->getEsquerda());
    if (balancoFilhoEsq == -1) {
        auxiliar->esquerda = this->simp_roda_dir(auxiliar->getEsquerda());
    }
    auxiliar = this->simp_roda_esq(auxiliar);
}
this->atualizaAltura(auxiliar);
return auxiliar;
}

template <typename T>
AvlTree<T>* AvlTree<T>::simp_roda_esq(AvlTree<T>* nodo) {
	AvlTree<T>* temporario;

    temporario = nodo->getEsquerda();
    nodo->esquerda = temporario->getDireita();
    temporario->direita = nodo;

    this->atualizaAltura(temporario);
    this->atualizaAltura(nodo);
    return temporario;
}

template <typename T>
AvlTree<T>* AvlTree<T>::simp_roda_dir(AvlTree<T>* nodo) {
	AvlTree<T>* temporario;

    temporario = nodo->getDireita();
    nodo->direita = temporario->getEsquerda();
    temporario->esquerda = nodo;

    this->atualizaAltura(temporario);
    this->atualizaAltura(nodo);
    return temporario;
}

template <typename T>
AvlTree<T>* AvlTree<T>::dup_roda_esq(AvlTree<T>* nodo) {
    nodo->esquerda = this->simp_roda_dir(nodo->getEsquerda());
    return this->simp_roda_esq(nodo);
}

template <typename T>
AvlTree<T>* AvlTree<T>::dup_roda_dir(AvlTree<T>* nodo) {
    nodo->direita = this->simp_roda_esq(nodo->getDireita());
    return this->simp_roda_dir(nodo);
}

template <typename T>
void AvlTree<T>::atualizaAltura(AvlTree<T>* raiz) {
      raiz->altura = this->maximo(raiz->getEsquerda(), raiz->getDireita()) +1;
  }


template <typename T>
AvlTree<T>* AvlTree<T>::remover(AvlTree<T>* arv, const T& dado) {
	AvlTree<T>* temporario;
	AvlTree<T>* filho;
    if (arv == NULL) {
        return arv;
    } else if (dado < *(arv->getDado())) {
            arv->esquerda = this->remover(arv->getEsquerda(), dado);
            return balancear(arv);
        } else if (dado > *(arv->getDado())) {
                arv->direita = this->remover(arv->getDireita(), dado);
                return balancear(arv);
            } else if (arv->getDireita() != NULL &&
                        arv->getEsquerda() != NULL) {
                    temporario = this->minimo(arv->getDireita());
                    arv->dado = new T(static_cast<T const&>(*(temporario->
                                                               getDado())));
                    arv->direita = remover(arv->getDireita(),
                                            *(temporario->getDado()));
                    return balancear(arv);
                } else if (arv->getDireita() != NULL) {
                    filho = arv->getDireita();
                    return balancear(filho);
                    } else if (arv->esquerda != NULL) {
                            filho = arv->getEsquerda();
                            return balancear(filho);
                        }
    delete arv;
    return NULL;
}

template <typename T>
AvlTree<T>* AvlTree<T>::minimo(AvlTree<T>* nodo) {
    if (nodo->getEsquerda() == NULL) {
        return nodo;
    }
    return this->minimo(nodo->getEsquerda());
}


template <typename T>
T* AvlTree<T>::getDado() {
    return this->dado;
}

template <typename T>
T* AvlTree<T>::busca(const T& dado, AvlTree<T>* arv) {
    while (arv != NULL && *(arv->getDado()) != dado) {
        if (*(arv->getDado()) < dado) {
            arv = arv->getDireita();
        } else {
            arv = arv->getEsquerda();
        }
    }
    if (arv == NULL) {
        throw "Não encontrado";
    }
    return arv->getDado();
    }

template <typename T>
int AvlTree<T>::maximo(AvlTree<T>* nodo1, AvlTree<T>* nodo2) {
    if (nodo1 == NULL && nodo2 == NULL) {
        return -1;
    } else if (nodo1 == NULL) {
        return nodo2->getAltura();
    } else if (nodo2 == NULL) {
        return nodo1->getAltura();
    } else if (nodo1->getAltura() > nodo2->getAltura()) {
        return nodo1->getAltura();
    } else {
        return nodo2->getAltura();
    }
}

template <typename T>
void AvlTree<T>::preOrdem(AvlTree<T>* nodo) {
    if (nodo == NULL) {
         return;
    }
    this->elementos.push_back(nodo);
    this->posOrdem(nodo->getEsquerda());
    this->posOrdem(nodo->getDireita());
}


template <typename T>
void AvlTree<T>::emOrdem(AvlTree<T>* nodo) {
    if (nodo == NULL) {
         return;
    }
    this->posOrdem(nodo->getEsquerda());
    this->elementos.push_back(nodo);
    this->posOrdem(nodo->getDireita());
}

template <typename T>
void AvlTree<T>::posOrdem(AvlTree<T>* nodo) {
    if (nodo == NULL) {
         return;
    }
    this->posOrdem(nodo->getEsquerda());
    this->posOrdem(nodo->getDireita());
    this->elementos.push_back(nodo);
}

#endif /* SEARCH_MANPAGES_UNIX_ESTRUTURAS_AVLTREE_CPP_ */
