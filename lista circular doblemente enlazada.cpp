#include <iostream>

using namespace std;

class Node{
public:
	int value;
	Node *next;
	Node *prev;
	Node(int val){
		this->value = val;
		this->next = nullptr;
		this->prev = nullptr;
	}
	Node(int val,Node *ante,Node *sigue){
		value=val;
		prev=ante;
		next=sigue;
	}
};


class Linkedlist{
public:
	Node *head;
	Linkedlist(){
		head=nullptr;
	};

	bool buscar(int val,Node *&aux){
	aux=head;
	if(head->value == val)return 1;//encontrado
	aux = head->next;
	while(aux != head && aux->value < val){ //recorrer la lista buscando el nodo
		aux = aux->next;
	}
	return (aux->value==val);
	}
	
	void insertar(int val){
		Node* temp2 = new Node(val);
		if (head == nullptr){
			head = new Node(val);
			head->next = head;
			head->prev = head;
			return;
		}
		if(val<head->value)
		{
		Node *nue=new Node(val,head->prev,head);
			head->prev->next = nue;
			head->prev=nue;
			head=nue;
			return;
			}
		Node *aux;
		if(buscar(val,aux))return;
		Node *nue=new Node(val,aux->prev,aux);
		aux->prev->next = nue;
		aux->prev = nue;
		return;
		}
	
		void borrar(int dato){
			Node *aux;
			if(!buscar(dato,aux)) return;
			if(aux == head){
				head->prev->next = head->next;
				head->next->prev = head->prev;
				head = head->next;
				delete aux;
				return;
			}
			Node *temp = aux;
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			delete temp;
			return;
		}
		
	void print(){
		Node *aux= head;
		cout<<aux->value<<' ';
		aux=aux->next;
		while(aux != head){
			cout << aux->value << ' ';
			aux = aux->next;
		}
	}
};
int main(int argc, char *argv[]) {
	Linkedlist Circular;
	Circular.insertar(3);
	Circular.insertar(6);
	Circular.insertar(5);
	Circular.insertar(8);
	Circular.print();
	return 0;
}

