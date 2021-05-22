
#include "std_lib_facilities.h"

template<typename T>
struct S {
private:
	T val;
public:
	S (T a) {val = a;}

	T& get();
	T& get() const; //csak declar, késõbb defin

	//void set(T val);
	S& operator=(const T&);
};

template<typename T>
T& S<T>::get() const { return val; } //defin

template<typename T>
T& S<T>::get() { return val; }

template<typename T>
S<T>& S<T>::operator=(const T& value) {
	val = value;
	return *this;
}

template<typename T>
void read_val(T& v) {
	cin >> v;
}

/*
template<typename T>
void S<T>::set(T value){ val = value; }
*/


int main()
{

	S<int> integ (2);
	cout << (integ.get()) << endl;

	S<char> chara('v');
	cout << (chara.get()) << endl;

	S<double> doubl(2.22);
	cout << (doubl.get()) << endl;

	S<string> str("Alma");
	cout << (str.get()) << endl;

	vector<int> vektor{ 15, 43, 63 };
	S<vector<int>> vect(vektor);
	for (int v : vect.get())
	{
		cout << v << endl;
	}

	cout << "Beolvasás (int, char, double, string)" << endl;

	int a;
	read_val(a);
	cout << a << endl;

	char b;
	read_val(b);
	cout << b << endl;

	double c;
	read_val(c);
	cout << c << endl;

	String d;
	read_val(d);
	cout << d << endl;

	return 0;
}
