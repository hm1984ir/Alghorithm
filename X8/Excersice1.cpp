#include<string>
#include<array>
using namespace std;

char f();

int main(){
    char N {'n'};
    int a[10];
    array<string, 10> array_of_string;
    string str;
    int const number = 10;
    int number2 = 12;

    char* pointer_to_char{&N};
    int* pointer_to_array{a};
    int& reference_to_array{a[0]};
    //string& reference_to_array2{array_of_string}; //????

    char* pointer_to_string {&str[0]};
    char*pointer_to_pointer_of_char{pointer_to_char};

    const int* ponter_to_const {&number};
    int* const const_pointer_to_int{&number2};



}
