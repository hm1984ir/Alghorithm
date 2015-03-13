#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void print_list(const vector<string> list){
    for(auto v : list){
        cout << v << "--";
    }
}

int main(){
    vector<string> list_month;

    for(string str;str != "out";cin >> str){
        list_month.push_back(str);
    }

    sort(list_month.begin(), list_month.end());

    print_list(move(list_month));

    //Must Not Print Anything
    print_list(list_month);
}
