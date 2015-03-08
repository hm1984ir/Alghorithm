#include<iostream>

int sayHello(){
	std::cout << "hello";
}

int(* p)() ={sayHello};

int main(){
	p();
}



