#include<iostream>
#include<thread>

void writeHelloEverySecond(){
	std::cout << "Hello" << "\n";
}

struct writeWorldEverySecond{
	void operator()(){
		std::cout << "World!" << "\n";
	}
};

int main(){
	std::thread t1 {wirteHelloEverySecond};
	std::thread t2 {writeWorldEverySecond()};
	
	t1.join();
	t2.join();
}
