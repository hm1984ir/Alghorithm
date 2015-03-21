#include<string>
#include<iostream>>
#include<vector>

using namespace std;

class Human{
public:
    explicit Human(string name) : _name{name},_name_code{0} {};
    string get_name() const{return _name;}
    int get_name_code() const
    {
        if(!_name_code){
            calc_name_code();
        }

        return _name_code;
    }
    Human DO(){
        return *this;
    }
private:
    string _name;
    mutable int _name_code;
    void calc_name_code() const {
        _name_code = _name.length();
    }
};


void Does(vector<string>&& a){
    cout << a[0];

}

int a(){
    return 4;
}

int main(){
    char* p {"Hamid"};
    string str {p};

    cout << str;

    vector<string> v;

    v.push_back("hamid");

    Does(move(v));
    vector<string> aa{"hasan"};

    cout << v[0] << "\n";

    Human* h = new Human("HamidMOG");
    cout << h->DO().get_name();
    delete h;

}

