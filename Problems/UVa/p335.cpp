#import<iostream>
#import<string>
#import<utility>
#import<vector>
#import<map>
#import<queue>
#import<algorithm>
#import<set>

using namespace std;

enum class color_type{white,gray};

set<int> bfs(vector<vector<bool>> lst_graph,int root){
    int count_of_nodes = lst_graph.size();
    vector<color_type> lst_visit(count_of_nodes,{color_type::white});
    set<int> set_not_visited;

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
    }

    for(int i{0}; i< count_of_nodes; i++){
        if(lst_visit[i] == color_type::white){
            set_not_visited.insert(i);
        }
    }

    return set_not_visited;
}

vector<vector<bool>> transpose_graph(const vector<vector<bool>> graph){
    vector<vector<bool>> transpose_graph(graph.size(),vector<bool>(graph.size()));

    for(int i=0; i< graph.size();i++){
        for(int j=0; j<graph.size(); j++){
            transpose_graph[j][i] = graph[i][j];
        }
    }

    return transpose_graph;
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

    vector<pair<int,vector<array<string,2>>>> result;

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

        vector<array<string,2>> all_concurrent_events;

        int count_of_concurrent_events{};

        for(int i=0;i<graph.size();i++){
            vector<int> lst_concurrent{};
            set<int> set_not_visited = bfs(graph,i);
            vector<vector<bool>>  t_graph = transpose_graph(graph);
            set<int> set_transpose_not_visited = bfs(t_graph,i);

            set_intersection(set_not_visited.begin(),set_not_visited.end(),set_transpose_not_visited.begin(),set_transpose_not_visited.end(),  std::back_inserter(lst_concurrent));

            for(auto c : lst_concurrent){
                all_concurrent_events.push_back(array<string,2>({lst_name[i],lst_name[c]}));
                count_of_concurrent_events++;
            }
        }

        count_of_concurrent_events = count_of_concurrent_events/2;

        result.push_back(pair<int,vector<array<string,2>>>({count_of_concurrent_events,all_concurrent_events}));
    }

    int i{1};
    for(auto item : result){
        if(item.first >= 2){
                cout << "Case " << i << ", " << item.first <<" concurrent events:" << "\n";
                cout << "(" << item.second[0][0] << "," << item.second[0][1] << ") ";
                cout << "(" << item.second[1][0] << "," << item.second[1][1] << ") ";
        }else if(item.first == 1){
            cout << "Case " << i << ", " << item.first <<" concurrent events:" << "\n";
            cout << "(" << item.second[0][0] << "," << item.second[0][1] << ") ";
        }else {
            cout << "Case " << i << "," << " no concurrent events.";
        }

        cout << "\n";
        i++;
    }

     return 0;
}

