#include<string>
#include<iostream>
#include<list>

using namespace std;

class Person{
	public:
		Person(int age, string name) : _age{age},_name{name}{}
		string Get_Name(){
			return _name;
		}
		int Get_Age(){
			return _age;
		}
	private:
		int _age;
		string _name;
};

ostream& operator<<(ostream& os, Person& p){
			return os << "Name : " << p.Get_Name() << " Age: " << p.Get_Age();
		}

class Society{
	public:
		Society(string title) : _title {title}{};
		void Add_Person(Person& person){
			_Peaple->push_back(person);
		}
		list<Person> Get_People(){
			return _Peaple;
		}
	private:
		list<Person>* _People = new list<Person>();
		string _title;
};

ostream& operator<<(ostream& os, Society& s){
	for(auto& p:s){
		cout << p << "/n";
	}
}


int main(){
	Vector<Person> vp= new Vector<Person>();
	
	Person p(22, "hamid");
	cout << p;
}
