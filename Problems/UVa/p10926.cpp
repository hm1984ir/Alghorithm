
#import<random>
#import<vector>
#import<list>
#import<queue>
#import<iostream>

using namespace std;

enum class color_type {white, gray, black};

int bfs(const int root, const vector<vector<bool>> adjacency_matrix){
    vector<color_type> colors(adjacency_matrix.size(), color_type::white);

    queue<int> q;
    q.push(root);
    colors[root] = color_type::gray;

    int child_count = -1;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        colors[current_node] = color_type::gray;
        for(int index = 0; index < adjacency_matrix[current_node].size();index++){
            if(adjacency_matrix[current_node][index] && colors[index] == color_type::white){
                q.push(index);
            }
        }

        child_count ++;
    }

    return child_count;

}

int main(){
    vector<vector<vector<bool>>> lst;
    char c;
    int task_count;
    vector<vector<bool>> senario;
    while(cin >> task_count){
        do{
            vector<bool> task(task_count,false);
            for(int i=0; i<task_count; i++){
                int index;
                cin >> index;
                task[index] = true;
            }
            senario.push_back(task);
            cin >> c;
            } while(c == '\n');
        lst.push_back(senario);
    }

    int max_dependency = 0;
    int max_index = -1;
    for(auto item : lst){
        for(int i = 0; i<item.size(); i++){
            int dependency = bfs(i,item);
            if(dependency > max_dependency){
                max_index = i;
                max_dependency = dependency;
            }
        }
    }

    cout << "max_index : " << max_index <<"  max_dependency : " << max_dependency;
    return 0;

}




