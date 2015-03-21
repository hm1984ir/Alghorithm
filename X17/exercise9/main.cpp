#include "parser.h"
#include<iostream>
using namespace hm_mini_compiler;
int main(){
    Parser p{};
    std::string str {"1234"};
    std::cout << p.calculate_expr(str);
}
