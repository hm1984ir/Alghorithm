
#import<random>
#import<vector>
#import<list>
#import<queue>
#import<iostream>

using namespace std;

enum class color_type {white, gray, black};

int bfs(int root, vector<vector<bool>> adjacyList){
    vector<color_type> colors;

    for(auto row : adjacyList){
        colors.push_back(color_type::white);
    }

    queue<int> q;
    q.push(root);
    colors[root] = color_type::gray;

    int child_count = -1;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        colors[current_node] = color_type::gray;
        for(int index = 0; index < adjacyList[current_node].size();index++){
            if(adjacyList[current_node][index] && colors[index] == color_type::white){
                q.push(index);
            }
        }

        child_count ++;
    }

    return child_count;

}

int main(){
    vector<vector<bool>> lst{};

    vector<bool> temp;
    temp.push_back(false);
    temp.push_back(true);
    temp.push_back(false);

    lst.push_back(temp);

    vector<bool> temp1;
    temp1.push_back(false);
    temp1.push_back(false);
    temp1.push_back(true);

    lst.push_back(temp1);

    vector<bool> temp2;
    temp2.push_back(false);
    temp2.push_back(false);
    temp2.push_back(false);

    lst.push_back(temp2);


    int max_dependency = 0;
    int max_index = -1;

    for(int i = 0; i<lst.size(); i++){
        int dependency = bfs(i,lst);
        if(dependency > max_dependency){
            max_index = i;
            max_dependency = dependency;
        }
    }

    cout << "max_index : " << max_index <<"  max_dependency : " << max_dependency;

}




