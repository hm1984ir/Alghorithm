#include<array>
#include<vector>
#include<iostream>

using namespace std;

bool check_can_split(array<int,2> chock,int p){
    int x = chock[0];
    int y = chock[1];

    if(x < 1 || y < 1){
        return false;
    }

    if(x*y == p)
        return true;

    bool r1 = check_can_split({x-1,y},p);
    bool r2 = check_can_split({x,y-1},p);

    if(r1 || r2)
        return true;

    return false;
}

int main(){
    int n{};
    vector<bool> result;
    while(cin >> n){
        if(n == 0) break;
        vector<int> parts;

        int x{},y{};

        cin >> x >> y;
        for(int i{0};i<n;i++){
            int s{};
            cin >> s;
            parts.push_back(s);
        }

        bool is_valid = true;

        for(auto p : parts){
           if(!check_can_split({x,y},p)){
                is_valid = false;
                break;
            }
        }

        result.push_back(is_valid);
    }

    for(int i{0};i<result.size(); i++){
        if(result[i]){
            cout << "case " << i+1 << ": " << "Yes" << "\n";
        }
        else{
            cout << "case " << i+1 << ": " << "No" << "\n";
        }
    }

}



