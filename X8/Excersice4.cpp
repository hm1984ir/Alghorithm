#include<string>
#include<iostream>

using namespace std;

int calc_distance(char* c1, char* c2);

int main(){
    string str {"She is the One."};

    char* c1 {&str[3]};
    char* c2{&str[10]};

    cout << calc_distance(c1, c2);
}

int calc_distance(char* c1, char* c2){
    int i{0};
    for(;c1!=c2;++c1) ++i;

    return i;
}
