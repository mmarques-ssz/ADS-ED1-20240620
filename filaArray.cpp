#include <iostream>
using namespace std;

#define MAX 5

struct Fila {
	int ini;
	int fim;
	float nos[MAX];
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return(f->ini == f->fim);
}

int incrementa(int i) {
	/*
	int ret;
	if (i == MAX) {
		ret = 0;
	}
	else {
		ret = i +1;
	}
	return ret;
	*/
	return (i==MAX?0:++i);
}

int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
	return podeEnfileirar;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(Fila *f) {
	int i = f->ini;
	cout << "- Qtde de elementos: " << count(f) << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
	cout << "---------------" << endl;
}

void freeFila(Fila * f) {
	free(f);
}


int main(int argc, char** argv)
{
	Fila *filaFloat = new Fila;
	filaFloat = init();
	cout << (isEmpty(filaFloat)?"Fila vazia":"Fila com elementos") << endl;
	
	cout << ((enqueue(filaFloat, 11.11))?"Enfileirou":"Não enfileirou") << endl;
	cout << ((enqueue(filaFloat, 22.22))?"Enfileirou":"Não enfileirou") << endl;
	cout << ((enqueue(filaFloat, 33.33))?"Enfileirou":"Não enfileirou") << endl;
	cout << ((enqueue(filaFloat, 44.44))?"Enfileirou":"Não enfileirou") << endl;
	cout << ((enqueue(filaFloat, 55.55))?"Enfileirou":"Não enfileirou") << endl;
    cout << ((enqueue(filaFloat, 66.66))?"Enfileirou":"Não enfileirou") << endl;

	cout << (isEmpty(filaFloat)?"Fila vazia":"Fila com elementos") << endl;

	print(filaFloat);
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	
	cout << ((enqueue(filaFloat, 77.77))?"Enfileirou":"Não enfileirou") << endl;
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	print(filaFloat);
	
	freeFila(filaFloat);
	
	return 0;
}