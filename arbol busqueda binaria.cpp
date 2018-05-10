#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
struct Node{
	T m_data;
	Node<T>* m_nodes[2];
	Node(T x){
		m_nodes[0] = m_nodes[1] = 0;
		m_data = x;
	}
};

template <class T>
struct Less{
	inline bool operator()(T a, T b){
		return a<b;
	}
};

template <class T, class C>
class Binario{
public:
	Node<T>* m_root;
	C cmp;
	Binario();
	bool find(T x, Node<T>**& p);
	bool insert(T x);
	bool remove(T x);
	void inorder(Node<T>* p);

	Node<T>** Remp(Node<T>** p);//para funcion reemplazo
};


template <class T, class C>
Binario<T,C>::Binario(){
	this->m_root = 0;
}

template <class T, class C>
Node<T>** Binario<T,C>::Remp(Node<T>** p){//funcion reemplazo
	srand(time(NULL));
	int a=rand()%1;
	for(p = &(*p)->m_nodes[0]; *p && (*p)->m_nodes[1]; p = &(*p)->m_nodes[a]);
	return p;
}

template <class T, class C>
bool Binario<T,C>::find(T x, Node<T>**& p){
	for(p = &m_root; *p && (*p)->m_data != x; p = &((*p)->m_nodes[cmp((*p)->m_data, x)]));
	return !!*p;
}

template <class T, class C>
bool Binario<T,C>::insert(T x){
	Node<T>** p;
	if(find(x, p)) return 0;
	*p = new Node<T>(x);
	return 1;
}

template<class T, class C>
bool Binario<T,C>::remove(T x){
	Node<T>** p;
	if(!(find(x,p))) return 0;
	if ((*p)->m_nodes[0] && (*p)->m_nodes[1]){
		Node<T>** q = Remp(p);
		(*p)->m_data = (*q)->m_data;
		p = q;
	}
	Node<T>* temp = *p;
	*p = (*p)->m_nodes[(*p)->m_nodes[1]!=0];
	delete temp;
	return 1;
}

template <class T, class C>
void Binario<T,C>::inorder(Node<T>* p){
	if (!p) return;
	inorder(p->m_nodes[0]);
	cout << p->m_data << " ";
	inorder(p->m_nodes[1]);
}

int main(int argc, char *argv[]) {
	Binario<int,Less<int> > Arbol;
	Arbol.insert(30);
	Arbol.insert(40);
	Arbol.insert(90);
	Arbol.remove(40);
	Arbol.remove(30);
	Arbol.remove(90);
	Arbol.inorder(Arbol.m_root);
	return 0;
}
