//Hey you :) :*
#include<iostream>

using namespace std;

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int a,b;
    a = 1;
    b = 2;

    swap(&a, &b);
    swap(a, b);

    cout << "a:" << a << " b:" << b;

}

