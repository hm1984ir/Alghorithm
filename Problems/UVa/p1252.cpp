#include<cmath>
#include<math.h>
#include<vector>
#include<iostream>
#include<fstream>
#define fin cin
using namespace std;

vector<int> find_normal_distributer_feature(vector<int> subset, int subset_size, int feature_count){
    vector<int> best_feature_No;
    float best_feature_diff = feature_count;
    float ideal_sum = subset_size/2;

    for(int i = 0; i< feature_count; i++){
        int sum{};

        for(int j = 0; j < subset_size; j++){
            if(subset[j] & 1<<i)
                sum++;
        }

        if(ceil(ideal_sum) == sum || floor(ideal_sum) == sum){

            //for(auto n{best_feature_No.begin()};n!= best_feature_No.end();n++){
            //    if(n != ideal_sum){
            //        best_feature_No.
            //    }
           // }

            best_feature_No.push_back(i);
        } else {
            if(abs(ideal_sum - sum) == best_feature_diff){
                best_feature_No.push_back(i);
            }else if(abs(ideal_sum - sum) < best_feature_diff){
                best_feature_No.clear();
                best_feature_No.push_back(i);
                best_feature_diff = abs(ideal_sum - sum);
            }

        }
    }

    return best_feature_No;
}

int partition(vector<int> subset, int selected_objects, int feature_count, vector<int> table){
    int selected_obj_count = 0;

    for(int i{0};i<subset.size();i++){
        if(selected_objects & 1<<i)
            selected_obj_count++;
    }

    if(selected_obj_count == 2) return 1;
    if(selected_obj_count == 1) return 1;

    if (table[selected_objects] != 0)
        return table[selected_objects];

    //int seperator_feature = find_normal_distributer_feature(subset, subset_size, feature_count);

    int result{feature_count};

    for(int k=0;k<feature_count;k++){
        int selected_object1{0},selected_object2{0};

        for(int i=0;i<subset.size(); i++){
            if(selected_objects & 1<<i){
                if(subset[i] & 1<<(k)){
                    selected_object1 += 1<<i;
                } else {
                    selected_object2 += 1<<i;
                }
            }
        }

        int m1{},m2{};

        if(selected_object1 == selected_objects || selected_object2 == selected_objects) break;

        m1 = partition(subset, selected_object1, feature_count,table);
        table[selected_object1] = m1;

        m2 = partition(subset, selected_object2, feature_count,table);
        table[selected_object2] = m2;

        result = min(result,m1+m2);
    }

    table[selected_objects] = result;

    return result;
}

int main(){
    //ifstream fin("D:\\Algorithm\\Problems\\UVa\\p1252.in", ios::in);
    while(true){
        int number_of_feature{},number_of_object{};
        fin >> number_of_feature;

        if(number_of_feature == 0) break;

        fin >> number_of_object;

        vector<int> subset;

        for(int j=0; j<number_of_object;j++){
            int obj{};
            string object;
            fin >> object;
            for(int i=0;i<number_of_feature;i++){
                if(object[i] == '1')
                    obj+= 1<<number_of_feature-i-1;
            }

            subset.push_back(obj);
        }

        vector<int> table(1<<(number_of_object-1),0);

        if(number_of_object == 1){
            cout << "minimum count of comparison is : 0" << "\n";
        } else {
            int result = partition(subset, (1<<number_of_object)-1 ,number_of_feature, table);
            cout << "minimum count of comparison is : " << result << "\n";
        }
    }

    return 0;
}
