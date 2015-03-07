#include<Vector>
#include<iostream>
#include<algorithm>
using namespace std;

void printVector(vector<int> vs){
	for(const auto& v : vs ){
		cout << v << "  ";
	}
	
	cout << "\n";
}

int main(){
	vector<int> vs={5,9,-1,200,0};
	
	printVector(vs);
	
	sort(vs.begin(),vs.end());
	
	printVector(vs);
	
}

