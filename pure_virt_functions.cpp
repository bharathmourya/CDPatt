#include <iostream>

using namespace std;

class Base {
private :
	int x;

public :
	Base(int x) {
		this->x = x;
	}
	virtual void fun() = 0;
	virtual void changeX() = 0;
	int getX () {
		return x;
	}
	void setX(int p) {
		x = p;
	}
};

class Type1 : public Base {
public:
	Type1(int i):Base(i){}
	void fun();
	void changeX();
};

void Type1::fun() {
	cout << "Fun at Type1 class" <<endl;
}

void Type1::changeX () {
	setX(getX() * 2);
}

class Type2 : public Base {
public:
	Type2(int i):Base(i){};
	void fun();
	void changeX();
};

void Type2::fun() {
	cout << "Fun at Type2 class" <<endl;
}

void Type2::changeX () {
	setX(getX() * 4);
}

int main() {
	Type1* t1 = new Type1(1);
	Type2* t2 = new Type2(1);
	cout<< "Having Fun\n";
	t1->fun();
	t2->fun();

	cout <<"\nPrinting 'x'\n";
	cout << "Type 1 : " << t1->getX() <<endl;
	cout << "Type 2 : " << t2->getX() <<endl;
	
	cout <<"\nChanging 'x'\n";
	t1->changeX();
	t2->changeX();
	cout << "Type 1 : " << t1->getX() <<endl;
	cout << "Type 2 : " << t2->getX() <<endl;

	cout<<"\nDoNe\n";
	return 0;
}