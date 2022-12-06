#include <queue>
#include <iostream>

using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> fila;
	
    public:
        T popQueue() {
            if(!fila.empty()) {
                T inicio = fila.front();
                fila.pop();
                return inicio;
            }
        }
        
        void popTodos() {				
            while(!fila.empty()) {
                T inicio = popQueue();
                cout << inicio << endl;
            }
        }
        
        void simulaPilha(T novo) {
            queue<T> aux;
            while(!fila.empty()) {
                aux.push(fila.front());
                fila.pop();
            }
            fila.push(novo);
            while(!aux.empty()) {
                fila.push(aux.front());
                aux.pop();
            }
        }
};

int main(){
	Queue<int> fila;
	fila.simulaPilha(4);
	fila.simulaPilha(5);

	int item = fila.popQueue();
	cout << item << endl;
	fila.popTodos();
}