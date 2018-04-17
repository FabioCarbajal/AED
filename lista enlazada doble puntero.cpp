#include <iostream>
using namespace std;

template <class T>
struct Node{
	Node(T x)
	{
		m_data=x;
		m_next=0;
	};
	T m_data;
	Node<T>*m_next;
};

template<class T>
class Lista{
public:
	Lista(){
		m_head=0;
	}
	bool find(T x, Node<T>**&p);
	bool insert(T x);
	bool remove(T x);
	bool print();
	
	Node<T>*m_head;
};

template<class T>
bool Lista<T>::find(T x, Node<T>**&p){
	for(p=&m_head;*p&&(*p)->m_data<x;p=&((*p)->m_next))
		return (*p)&&(*p)->m_data==x;
}

template<class T>
bool Lista<T>::insert(T x){
	Node<T>**p;
	if(find(x,p))return 0;
	Node<T>*t = new Node<T>(x);
	t->m_next=*p;
	*p=t;
	return 1;
}

template<class T>
bool Lista<T>::remove(T x){
	Node<T>**p;
	if(!find(x,p))return 0;
	Node<T>*t=*p;
	*p=t->m_next;
	delete t;
	return 1;
}

template<class T>
bool Lista<T>::print(){
	Node<T>**p = &m_head;
	while(*p){
		cout<<(*p)->m_data<<' ';
		p=&((*p)->m_next);
	}
	return 1;
}

int main() {
	Lista<int> H;
	H.insert(4);
	H.insert(5);
	H.insert(3);
	H.insert(6);
	H.print();
	return 0;
}

