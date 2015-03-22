#include "parser.h"
#include<iostream>
using namespace hm_mini_compiler;
int main(){
    Parser p{};
    std::string str {"1+12+5-20+5"};
    std::cout << p.calculate_expr(str) << "\n";
    str = "5+5+5";
    std::cout << p.calculate_expr(str);

}
