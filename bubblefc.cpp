#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int* generar(int tamano){
	srand(time(NULL));
	int* piv = new int[tamano];
	int* arr = piv;
	for(int i = 0; i<tamano; arr++, i++){
		*arr = rand() % 10;
	}
	return piv;
}

bool less_(int a,int b){return a < b;}

bool greater_(int a, int b){return a > b;}

void swape(int* p1,int* p2)
{
	int aux=*(p1);
	*(p1)=*(p2);
	*(p2)=aux;
}

void imp(int* arr,int* tam)
{
	for(;arr<tam;arr++)
		cout<<*arr<<" ";
}

void burbuja(int* arr,int* tamano,bool (*p)(int,int))
{
	int *p0,*p1,*p2;
	p2=arr;
	bool sigue=true;
	while(sigue){
	p0=arr;
	p1=(p0+1);
	for(arr;arr<tamano;arr++)
	{
		if(greater_(*p0,*p1))
		{
			swape(p0,p1);
			sigue=true;
		}
		p0=p1;
		p1=(p1+1);
	}
	arr=p2;
	tamano--;
	}
	//imp(arr,tamano);
}

int main()
{
	int *c;
	c=generar(10);
	burbuja(c,c+10,greater_);
	return 0;
}

