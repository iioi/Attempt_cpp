#include<iostream>
using namespace std;


class szcl {
	int e;
public:
	szcl() { e = 0; };
	szcl(int value) { e = value; }
	int get_value() { return e; }
};

int main2() {
	szcl a1[3] = { 3,5,7 }, *elem;
	for (int i = 0; i < 3; i++)
		cout << a1[i].get_value() << "\n";//��̬
	elem = a1;
	for (int i = 0; i < 3; i++) {
		cout << elem->get_value() << "\n";//��̬
		elem++;
	}
	getchar();
	return 0;
}