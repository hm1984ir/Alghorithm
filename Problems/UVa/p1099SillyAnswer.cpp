#include<array>
#include<vector>
#include<iostream>
#include<set>

using namespace std;
using choc = array<int,2>;

vector<array<choc,2>> vertical_divider(choc c){
    vector<array<choc,2>> result;

    for(int i=1;i<c[0];i++){
        array<choc,2> pices{};
        pices[0] = {i,c[1]};

        if(c[0]-i > 0){
            pices[1]=choc({c[0] - i,c[1]});
        }

        result.push_back(pices);
    }

    return result;
}

vector<array<choc,2>> horizintal_divider(choc c){
    vector<array<choc,2>> result;

    for(int j=1;j<c[1];j++){
        array<choc,2> pices{};
        pices[0] = {c[0],j};

        if(c[1] - j > 0){
            pices[1]={c[0],c[1] - j};
        }

        result.push_back(pices);
    }

    return result;
}

int exists_in(choc c,vector<array<int,2>> parts){
    for(int i = 0 ; i < parts.size(); i++){
        if(parts[i][1] == -1 && c[0]*c[1] == parts[i][0])
            return i;
    }

    return -1;
}

bool all_parts_visited(const vector<array<int,2>> parts){
    for(auto item : parts){
        if(item[1] == -1)
            return false;
    }

    return true;
}

void clear_parts(vector<array<int,2>>& parts, int id){
    for(auto item : parts){
        if(item[1] > id){
            item[1] = -1;
        }
    }
}


bool try_distribute_choc(choc c, vector<array<int,2>>& parts, vector<vector<int>>& mem, int id){
    id++;
    if(mem[c[0]-1][c[1]-1] > -1 ){
        //return mem[c[0]-1][c[1]-1];
    }

    int i = exists_in(c, parts);
    if(i > -1){
        parts[i][1] = id;
        return true;
    }

    for(auto h : horizintal_divider(c)){
        bool h1 = try_distribute_choc(h[0], parts, mem,id);
        bool h2 = false;
        if(h1 == true){
            h2 = try_distribute_choc(h[1], parts, mem,id);
        }

        mem[h[0][0]-1][h[0][1]-1] = h1;
        mem[h[1][0]-1][h[1][1]-1] = h2;

        if(h1 && h2){
            return true;
        }
    }


    for(auto v : vertical_divider(c)){
         bool v1 = try_distribute_choc(v[0], parts, mem,id);
         bool v2 = false;
         if(v1 == true){
            v2 = try_distribute_choc(v[1], parts,mem,id);
         }

         mem[v[0][0]-1][v[0][1]-1] = v1;
         mem[v[1][0]-1][v[1][1]-1] = v2;

         if(v1 && v2){
                return true;
         }
    }

    clear_parts(parts, id);

    return false;
}

int main(){
    int n{};
    vector<bool> result;
    while(cin >> n){
        if(n == 0) break;
        vector<array<int, 2>> parts;

        int x{},y{};

        cin >> x >> y;
        for(int i{0};i<n;i++){
            int s{};
            cin >> s;
            parts.push_back({s,-1});
        }

        vector<vector<int>> m (x,vector<int>(y,-1));

        try_distribute_choc({x,y},parts,m,-1);

        result.push_back(all_parts_visited(parts));
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



