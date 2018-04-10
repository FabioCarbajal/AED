#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int val = 0, Node *sigue = nullptr){
		this->value = val;
		this->next = sigue;
	}
};

class LinkedList{
public:
	Node *head=nullptr;

	Linkedlist(int n){
		head= new Node(n);
		head->next = head;
	}
	
	void insertar(int val)
	{
		Node *temp= head;
		Node* temp2 = new Node(val);
		if(!head)
		{
			head=temp2;
		}
		else{
			if(head->value>val){
				temp2->next=head;
				head=temp2;
			}
			else{
				while((temp->next!=NULL)&&(temp->next->value<val)){
					temp=temp->next;
				}
				temp2->next=temp->next;
				temp->next=temp2;
			}
		}
	}
	
	void borrar(int val){
		
		if (head->next == nullptr){
			head = nullptr;
		}
		
		Node *temp= head;
		while(temp->next != nullptr && temp->next->value < val){
			temp = temp->next;
		}
		if (temp->value == val){
			head = temp->next;
			delete temp;
		}
		else if (temp->next->next == nullptr){
			delete temp->next;
			temp->next = nullptr;
		} else {
			Node* temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
		}
	}
	
	void print(){
		Node* temp=head;
		if(!head){
			cout<<"Lista Vacia"<<endl;
		}
		else{
			while(temp){
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
	Nod.insertar(1);
	Nod.insertar(10);
	Nod.insertar(11);
	Nod.borrar(4);
	Nod.borrar(1);
	Nod.borrar(11);
	Nod.print();
	return 0;
}

