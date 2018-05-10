#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int val){
		this->value = val;
		this->next = NULL;
	}
};

class LinkedList{
public:
	Node *head;
	Linkedlist(){
		head=NULL;
	}
	void insertar(int val)
	{
		Node *temp= head;
		Node* temp2 = new Node(val);
		if(head==NULL)
		{
			head=temp2;
		}
			if(val<head->value){
				temp2->next=head;
				head=temp2;
				return;
			}
			Node *aux=temp->next;
			while(aux!=NULL && aux->value<val){
				temp=aux;
				aux=aux->next;
			}
		if(aux == NULL){
			if(temp->value == val){
				return;
			}
		}
		if(temp->value < val){
			if(aux!= NULL && aux->value == val) return;
			temp->next = temp2;
			temp2->next = aux;
			return;
			}
		}

	void borrar(int val){
			
		if (head == nullptr){//si es vacio
			return;
		}
		if (head->value == val){//si tiene el mismo valor
			Node *cabeza=head;
			head = head->next;
			delete cabeza;
			return;
		}
		
		Node *temp = head;//creo variables de apoyo 
		Node *aux = temp->next;
		
		while(aux != nullptr && aux->value < val){
			temp = aux;
			aux = aux->next;
		}

		if (aux == nullptr){
			if(temp->value==val)
			delete temp;
			return;
		
		if(aux->value==val){
			Node* cabeza = aux;
			temp->next = aux->next;
			delete cabeza;
			return;
		}
	}
	}
	void print(){
		if(!head){
			cout<<"Lista Vacia"<<endl;
		}
		else{
			Node* temp=head;
			while(temp->next!=nullptr){
				cout<<temp->value<<' ';
				temp=temp->next;
			}
		}
		
	}
};

int main(int argc, char *argv[]) {
	LinkedList Nod;
	Nod.insertar(4);
	Nod.insertar(2);
	Nod.insertar(3);
	Nod.print();
	return 0;
}
