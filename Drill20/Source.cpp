#include "std_lib_facilities.h"

template<typename T>
void kiir(T elem)
{
	for (auto e : elem)
		cout << e << ' ';
	cout << endl;
}

template<typename T>
void increase(T& elem, int n)
{
	for (auto& e : elem)
		e = e + n;
}


template<typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2) //mettõl meddig hova
{
	for (Iter1 element = f1; element != e1; element++) {
		*f2 = *element; //elem kell és nem cím
		f2++;
	}

	return f2;
}


int main()
{
	cout << " Array: " << endl;
	array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	kiir(arr);

	cout << " Vector: " << endl;
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	kiir(vec);

	cout << " List: " << endl;
	list <int> lis = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	kiir(lis);

	//copy-----------------------


	array<int, 10> arr2 = arr;
	vector<int> vec2 = vec;
	list<int> lis2 = lis;



	//increase---------------------
	cout << " increase--------------------- " << endl;
	cout << " Array: " << endl;
	increase(arr, 2);
	kiir(arr);

	cout << " Vector: " << endl;
	increase(vec, 3);
	kiir(vec);

	cout << " List: " << endl;
	increase(lis, 5);
	kiir(lis);

	//myCopy--------------------------
	cout << " myCopy-------------------------- " << endl;

	myCopy(arr.begin(), arr.end(), vec.begin());

	myCopy(lis.begin(), lis.end(), arr.begin());

	cout << " Array: " << endl;
	kiir(arr);
	cout << " Vector: " << endl;
	kiir(vec);
	cout << " List: " << endl;
	kiir(lis);


	auto vec_find = find(vec,3);
	int pos_of_3 = distance(vec.begin(), vec_find);

	auto lis_find = find(lis, 27);
	int pos_of_27 = distance(lis.begin(), lis_find);

	if (vec_find != vec.end()) { cout << "The position of the first element: " << pos_of_3 << endl; }
	else { cout << "The value wasn't found" << endl; }
	if (lis_find != lis.end()) { cout << "The position of the second element: " << pos_of_27 << endl; }
	else { cout << "The value wasn't found" << endl; }
}