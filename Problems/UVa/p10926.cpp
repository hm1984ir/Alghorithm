
#import<vector>
#import<queue>
#import<iostream>

using namespace std;

enum class color_type {white, gray, black};

int bfs(const int root, const vector<vector<bool>> adjacency_matrix){
    vector<color_type> colors(adjacency_matrix.size(), color_type::white);

    queue<int> q;
    q.push(root);


    int child_count = -1;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        if(colors[current_node] != color_type::gray){

            colors[current_node] = color_type::gray;
            for(int index = 0; index < adjacency_matrix[current_node].size();index++){
                if(adjacency_matrix[current_node][index] && colors[index] == color_type::white){
                    q.push(index);
                }
            }

            child_count ++;
        }
    }

    return child_count;
}

int calculateTheMostDependentTask(vector<vector<bool>> lst){
    int max_dependency = 0;
    int max_index = -1;

    for(int i = 0; i<lst.size(); i++){
        int dependency = bfs(i,lst);
        if(dependency > max_dependency){
            max_index = i;
            max_dependency = dependency;
        }
    }

    return max_index +1;
     //<<"\n" << max_dependency << "\n";
}

int main(){
    int task_count;
       
    while(cin >> task_count){
        if(task_count == 0) break;
	
        vector<vector<bool>> senario(task_count,vector<bool>(task_count,false));

        for(int i = 0;i < task_count; i++){
            int num_direct_dependency;
	    cin >> num_direct_dependency;
	    
            for(int j = 0; j < num_direct_dependency;j++){
                int index;
		cin >> index;
                senario[i][index-1] = true;
            }
        }

	cout << calculateTheMostDependentTask(senario)<<endl;
    }

    
    return 0;

}




