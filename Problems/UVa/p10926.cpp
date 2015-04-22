
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

void calculateTheMostDependentTask(vector<vector<bool>> lst){
    int max_dependency = 0;
    int max_index = -1;

    for(int i = 0; i<lst.size(); i++){
        int dependency = bfs(i,lst);
        if(dependency > max_dependency){
            max_index = i;
            max_dependency = dependency;
        }
    }

    cout << "\n";
    cout << max_index + 1 <<"\n" << max_dependency;
}

int main(){
    int task_count;


    int k = 0;
    while(cin >> task_count){
        if(task_count == 0) break;
        vector<vector<bool>> senario(task_count,vector<bool>(task_count,false));

        for(int i = 0;i < task_count; i++){
            int index;

            while(cin >> index){
                if(index == 0) break;
                senario[i][index-1] = true;
            }

            if(index == 0) break;
        }

        calculateTheMostDependentTask(senario);
    }




    return 0;

}




