#include<string>
#include<iostream>
#include<list>

using namespace std;

class Person{
	public:
		Person(int age, string name) : _age{age},_name{name}{}
		string Get_Name() const{
			return _name;
		}
		int Get_Age() const{
			return _age;
		}
	private:
		int _age;
		string _name;
};

ostream& operator<<(ostream& os, const Person& p){
			return os << "Name : " << p.Get_Name() << " Age: " << p.Get_Age();
		}

class Society{
	public:
		Society(string title) : _title {title}{};
		void Add_Person(const Person& person){
			_People.push_back(person);
		}
		list<Person> Get_People() const{
			return _People;
		}
		string Get_Title() const{
			return _title;
		}
		
	private:
		list<Person> _People;
		string _title;
};

ostream& operator<<(const ostream& os,const Society& s){
	cout << s.Get_Title();
	for(const Person& p:s.Get_People()){
		cout << p << "\n";
	}
}


int main(){
	Society s("iran");
	Person p(22, "hamid");
	Person n(20, "Nastaran");
	Person v(21, "Photo");
	s.Add_Person(p);
	s.Add_Person(n);
	s.Add_Person(v);
	
	cout << s;
}
