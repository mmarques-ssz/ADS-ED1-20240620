#include <iostream>
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
	    free(no);	
	}
	return ret;
}


int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "-- Qtde de elementos: " << count(f) << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	cout << (isEmpty(filaFloat)?"Fila vazia":"Fila com elementos") << endl;
	
	enqueue(filaFloat, 11.11);
	enqueue(filaFloat, 22.22);
	enqueue(filaFloat, 33.33);
	
	cout << (isEmpty(filaFloat)?"Fila vazia":"Fila com elementos") << endl;
	
	print(filaFloat);
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	enqueue(filaFloat, 44.44);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	
	print(filaFloat);
	
    freeFila(filaFloat); 	
	
	return 0;
}