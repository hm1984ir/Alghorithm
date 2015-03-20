#include<iostream>
#include "Histogram.h"

int main(){
    HM::Histogram h{1,25};

    h.add_number(5);
    h.add_number(20);
    h.add_number(12);
    h.add_number(3);
    h.add_number(7);
    h.add_number(10);


    std::cout << h;
}
