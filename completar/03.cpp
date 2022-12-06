#include <stack>
#include <iostream>

using namespace std;

template <class T>
class Stack: public stack<T> {
	protected:
		stack<T> pilha;

	public:
		T popStack() {
			if(!pilha.empty()) {
				T topo = pilha.top();
				pilha.pop();
				return topo;
			} 
		}
	
		void popTodos() {
			while(!pilha.empty()) {
				T topo = popStack();
				cout << topo << endl;
			}
		}
		
		void simulaFila(T novo) {
			stack<T> aux;
			while(!pilha.empty()) {
				aux.push(pilha.top());
				pilha.pop();
			}
			pilha.push(novo);
			while(!aux.empty()) {
				pilha.push(aux.top());
				aux.pop();
			}
		}
};

int main(){
	Stack<int> pilha;

	pilha.simulaFila(1);
	pilha.simulaFila(2);
	pilha.simulaFila(3);
	pilha.simulaFila(4);

    cout << pilha.popStack() << endl;
}