#import<iostream>
#import<string>
#import<utility>
#import<vector>
#import<map>
#import<queue>

using namespace std;

enum class color_type{white,gray};

vector<int> bfs(vector<vector<bool>> lst_graph,int root){
    int count_of_nodes = lst_graph.size();
    vector<color_type> lst_visit(count_of_nodes,{color_type::white});
    vector<int> lst_visited;

    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int current_node = q.front();
        q.pop();

        for(int i=0; i<count_of_nodes; i++){
            if(lst_graph[current_node][i] && lst_visit[i] == color_type::white){
                q.push(i);
            }
        }

        lst_visit[current_node] = color_type::gray;
        lst_visited.push_back(current_node);
    }

    return lst_visited;
}

void two_combination_of(vector<int> lst,array<int,2> p,int index, vector<array<int,2>> result){
    for(auto i :lst){
        p[index] =i;
        if(index == 1){
            result.push_back(p);
        } else {
            two_combination_of(lst,p,1,result);
        }
    }
}


vector<vector<bool>> make_graph(int count_of_node,vector<vector<string>> computations, vector<pair<string,string>> inter_computation_relation, map<string, int> names){

    vector<vector<bool>> graph(count_of_node,vector<bool>(count_of_node,false));

    int i{};
    for(auto c : computations){
        int j{};
        for(auto e : c){
            for(int k{0};k < j; k++){
                graph[names[c[k]]][names[c[j]]] = true;
            }

            j++;
        }
        i++;
    }

    for(auto relation : inter_computation_relation){
        int i{},j{};
        i = names[get<0>(relation)];
        j = names[get<1>(relation)];
        graph[i][j] = true;
   }

    return graph;
}

int main(){
    int nc;

    vector<pair<int,vector<pair<string,string>>>> result;

    while(cin >> nc){
        if(nc == 0) break;
        int count_of_node = 0;
        map<string,int> names;
        vector<string> lst_name;
        vector<vector<string>> computations(nc, vector<string>{});
        int ci = 0;
        int ne;

        for(;nc>0;nc--){
            cin >> ne;
            string event;
            for(; ne>0;ne--){
                cin >> event;
                computations[ci].push_back(event);
                count_of_node++;
                names.insert({event, count_of_node - 1});
                lst_name.push_back(event);
            }
            ci++;
        }

        vector<pair<string,string>>  inter_computation_relation;
        int nm;
        cin >> nm;

        for(;nm>0;nm--){
            string e1,e2;
            cin >> e1 >> e2;

            inter_computation_relation.push_back({e1,e2});
        }

        vector<vector<bool>> graph = make_graph(count_of_node,computations,inter_computation_relation, names);

        for(auto row : graph){
            for(auto cell : row){
                cout << cell;
            }
            cout << "\n";
        }

        vector<vector<int>> concurrent_groups;

        for(int i=0;i<graph.size();i++){
            vector<int> lst_not_visited = bfs(graph,i);
            lst_not_visited.push_back(i);
            concurrent_groups.push_back(lst_not_visited);
        }

        vector<array<int,2>> all_concurrent_events;
        for(auto group : concurrent_groups){
            two_combination_of(group,array<int,2>{},0,all_concurrent_events);
        }

        int count_of_concurrent = all_concurrent_events.size();

        vector<pair<string, string>> temp;
        for(array<int,2> c : all_concurrent_events){
            temp.push_back(pair<string,string>({lst_name[c[0]], lst_name[c[1]]}));
        }

        result.push_back(pair<int,vector<pair<string,string>>>(count_of_concurrent,temp));
    }

    int i{1};
    for(auto item : result){
        cout << "Case " << i << "," << get<0>(item) <<" concurrent events:" << "\n";
        if(get<1>(item).size()>0){
            for(auto concurrent_events : get<1>(item)){
                cout << "(" << get<0>(concurrent_events) << "," << get<1>(concurrent_events) << ") ";
            }
        }else {
            cout << "0";
        }

        cout << "\n";
        i++;

    }

     return 0;


}

