#import<iostream>
#import<string>
#import<utility>
#import<vector>
#import<map>

using namespace std;

void remove_node(vector<vector<int>>& graph, int index){
    int len = graph.size();

    while(len--){
        graph[index][len] = -1;
        graph[len][index] = false;
    }

}


vector<vector<int>> make_graph(int count_of_node,vector<vector<string>> computations, vector<pair<string,string>> inter_computation_relation, map<string, int> names){

    vector<vector<int>> graph(count_of_node,vector<int>(count_of_node,false));

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

vector<vector<string>> calculate_concurent_events(vector<vector<int>> graph, vector<string> names){
    vector<vector<string>> lst_concurrent_nodes;
    int node_count = graph.size();
    while(node_count--){
        vector<string> concurrent_nodes;
        int i{0};
        int first_free_node{-1};
        for(auto row : graph){
            bool has_connection = false;
            for(auto cell : row){
                if(cell == -1){
                    has_connection = true;
                    break;
                }
                if(cell) {
                    has_connection = true;
                    break;
                }
            }

            if(!has_connection){
                concurrent_nodes.push_back(names[i]);
                if(first_free_node == -1) first_free_node = i;
            }

            i++;
        }

        if(concurrent_nodes.size() > 1){
            lst_concurrent_nodes.push_back(concurrent_nodes);
        }

        if(first_free_node != -1)
            remove_node(graph, first_free_node);
    }

    return lst_concurrent_nodes;
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

        vector<vector<int>> graph = make_graph(count_of_node,computations,inter_computation_relation, names);

        for(auto row : graph){
            for(auto cell : row){
                cout << cell;
            }
            cout << "\n";
        }

        vector<vector<string>> concurrents = calculate_concurent_events(graph, lst_name);
        int count_of_concurrent{};

        vector<pair<string, string>> temp;
        for(auto concurrent_group : concurrents){
            if(concurrent_group.size() == 2){
                temp.push_back(pair<string,string>({concurrent_group[0],concurrent_group[1]}));
            } else {
                temp.push_back(pair<string,string>({concurrent_group[0],concurrent_group[1]}));
                temp.push_back(pair<string,string>({concurrent_group[1],concurrent_group[2]}));
            }

            count_of_concurrent += concurrent_group.size();
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
