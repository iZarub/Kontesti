#include<iostream>
#include<vector>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


struct stack {
	int value;
	stack* next;
	int s;
};

void add_top(stack** top, int value) {
						
	if (*top == NULL) {
		*top = (stack*)malloc(sizeof(stack));
		(*top)->value = value;
		(*top)->next = NULL;
	}
	else {
		stack* a;
		a = (stack*)malloc(sizeof(stack));
		a->value = value;
		a->next = *top;
		*top = a;
	
	}
}



int pop_top(stack** top) {
	stack* a = *top;
	*top = a->next;
	free(a);
	a->value = NULL;
	
}



void print(stack* top) {
	stack* a = top;
	
	while (a != NULL) {
		cout << a->value << " ";
		a = a->next;
		
	

	}
}

int main() {
	vector<int>v;
	int a;
	cin >> a;
	while (a != 0) {
		v.push_back(a);
		cin >> a;
	}
	
	for (int& i : v) {
		
	}



	stack* top;
	top = NULL;
	int s;
	s = 0;

	for (int i = 0; i < v.size() ; ++i) {

		if (v[i] > 0) {
			add_top(&top, v[i]);
			
			s = s + 1;
		}
		if (top != NULL) {
			if (v[i] < 0 and abs(v[i]) < (*top).value) {
				(*top).value = (*top).value - abs(v[i]);

			}

			else if (v[i] < 0 and abs(v[i]) >= (*top).value) {

				pop_top(&top);
				s = s - 1;


			}
		}
	}

	cout << s << " ";
	if (top == NULL) {
		cout << -1;
	}
	else {
		cout << (*top).value;
	}



	return 0;
}
