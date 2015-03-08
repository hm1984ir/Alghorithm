#include<iostream>
#include<vector>

int sayHello(){
	std::cout << "hello";
}

int(* p)() ={sayHello};

int main(){
	p();
	
	int *arr[5]{};
	int i = 12;
	arr[0] = &i;
	
	std::cout << *arr[0];
	
	int a[] = {1,2};
	
	std::cout << a[0];
}
		



