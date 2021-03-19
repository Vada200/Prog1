#include "std_lib_facilities.h"

class B1 
{
public:
	virtual void vf() { cout << "B1 :: vf()" << endl;};
	void f() { cout << "B1 :: f()" << endl; };
	virtual void pvf() = 0; //pure virtual -> <fv_nev>() = 0;
};

class D1 : public B1 {
public:
	void vf() override {cout<<"D1 :: vf()"<<endl;}
	void f() {cout << "D1 :: f()" << endl; };
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2 :: pvf()" << endl;};
};

class B2
{
public:
	virtual void pvf() = 0; 
};

class D21 : public B2
{
	string asd = "asd";
	void pvf() override { cout << asd << endl; };
};

class D22 : public B2
{
	int number = 12;
	void pvf() override { cout << number << endl; };
};

void f( B2& a)
{
	a.pvf();
}

int main()
{
	/*
	cout << "1. feladat" << endl;
	B1 b;
	b.vf();
    b.f();
	b.pvf();
	
	cout << "2. feladat" << endl;
	D1 d;
	d.vf();
	d.f();
	d.pvf();
	
	cout << "3. feladat" << endl;
	B1& b_ref = d;
	b_ref.vf();
	b_ref.f();
	b_ref.pvf();
	*/
	//4. Mivel f() nem virtual ezért nincs mit felülírni
	//
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	
	D21 c;
	D22 d;
	
	f(c);
	f(d);
	

	return 0;
}
