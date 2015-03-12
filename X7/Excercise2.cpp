#include<iostream>
int main(){
    char letter = 255;

    if(letter == -1 ) std::cout << "Signed";
    else std::cout << "Unsigned";

    std::cout << "\n";

    int i = 0;
    int j = 1;

    int*  p = &i;
    p = &j;

    std::cout << *p;

    int& a {i};
    const long& b {i};

}

void doSomething(const int* p){
//    *p = 2;
}
