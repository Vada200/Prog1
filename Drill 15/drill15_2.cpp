#include "std_lib_facilities.h"

struct Person {
private:
	string fname;
	string lname;
	int age;
	
public:
	Person(){}
	Person (string fn, string ln, int a) {
		fname = fn;
		lname = ln;
		age = a;
		
	}
	
	
	string get_Fname()  const
	{
		return fname;
	}
	
	string get_Lname()  const
	{
		return lname;
	}
	
	int get_Age() const
	{
		return age;
	}
	
	void set_Fname(string n) 
	{
		fname = n;
	}
	
	
	void set_Lname(string n) 
	{
		lname = n;
	}
	
	void set_Age(int a)
	{
		age = a;
	}
	
	
};

ostream& operator<< (ostream& os, Person& p) { 
	os << "Name: " << p.get_Fname() << " " << p.get_Lname() << " " << p.get_Age(); 
	return os; 
}

istream& operator>> (istream& is, Person& p) { 
	string fnamee;
	string lnamee;
	int agee;
	is >> fnamee;
	is >> lnamee;
	
	is >> agee;
/*
	for (auto l : namee) { 
		if (!isalpha(l)) { // ha nem karakter 
			error("Hibás név"); // hiba kód
		}
	}
	*/
	
	std::size_t found1 = fnamee.find_first_of("; : \" ' [ ] * & % $ # @ !");
	std::size_t found2 = lnamee.find_first_of("; : \" ' [ ] * & % $ # @ !");
	
        if (found1 != std::string::npos) {
            error("Hibás vezetéknév");
        }

	p.set_Fname(fnamee);
	
	if (found2 != std::string::npos) {
            error("Hibás keresztnév");
        }
		
	p.set_Lname(lnamee);
	
	if (0 >= agee || agee > 150) { 
		error("Hibás kor"); 
	}
	
	p.set_Age(agee);
	
	return is; 
}



int main()
{
	//Goofy----
	/*
	Person p("Goofy", 63);
	
	cout << p << endl;
	*/
	
	//beolvasós-----
	
	Person p2;
	
	cin >> p2;
	
	cout << p2 << endl;
	
	
	
	//vector----
	
	/*
	vector<Person> persons;
	Person t;
	int i;
	int db;
	cout << "Adjon meg neveket életkorukkal: " << endl;
	
	while (cin >> t)
	{
		persons.push_back(t);
	}
	
	
	cout << "Lista: "<< endl;
	
	for (i = 0; i < persons.size(); ++i) {
		cout << persons[i] << " " << endl;
	}
	*/
	
	return 0;
}

