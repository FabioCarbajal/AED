#include <iostream>
using namespace std;

template <class T, class C>
class Binario{
public:
	Binario();
	~Binario();
	
	bool find(T x, Binario<T>**&p);
	bool insert(T x);
	bool remove(T x);
	Binario<T>* m_root;
	C m_cmp;
};

template<T>
struct Binario{
	T m_data;
	BinNode<T>* m_nodes[2];
	BinNode(T x);
	{
		m_nodes[0]=m_nodes[1]=0;
		m_data=x;
	};
};

template<class T,class C>
bool Binario<T,C>::find(T x, BinNode<T>**&p){
	for(p=&m_root;*p&&(*p))
}

int main(int argc, char *argv[]) {
	
	return 0;
}

