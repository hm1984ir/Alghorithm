#include<string>
#include<iostream>>
#include<vector>

using namespace std;

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

    cout << v[0];

}
