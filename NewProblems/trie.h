#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <string>
#include <list>

using namespace std;

template<typename T>
class TrieNode{
    public:
    TrieNode(){
        parent = {};
        child= {};
        brother = {};
    }
    TrieNode<T>* parent;
    TrieNode<T>* child;
    TrieNode<T>* brother;

    int level = -1;

    string key;
    T value;

    ~TrieNode(){
        delete parent;
        delete child;
        delete brother;
    }
};

template<typename T>
class Trie{
public:
    Trie();
    ~Trie();
    void insert(string key, T value);
    void remove(string key);
    bool isWord(string key);
    //T operator[](const Trie<T>& trie,const string key);
    T find(string key) ;
private:
    TrieNode<T>* recursive_find( TrieNode<T>* node, string key, int i) ;
    TrieNode<T>* root;
};

template<typename T>
Trie<T>::Trie(){
	root = new TrieNode<T>;
}

template<typename T>
Trie<T>::~Trie(){
    delete root;
}

template<typename T>
TrieNode<T>* Trie<T>::recursive_find( TrieNode<T>* node, string key , int i) {
    string c = key.substr(i,1);

    if(node->key == c){
        if(i == key.size()-1){ return node;}

        if(node->child != nullptr){
            auto temp = recursive_find(node->child, key, i+1);

            if(temp != node->child){
                return temp;
            }
        }

    } else if(node->brother != nullptr){
        auto temp = recursive_find(node->brother, key, i);
        if(temp != node->brother){
            return temp;
        }
    }

    return node;
}

template<typename T>
bool Trie<T>::isWord(string key){
    TrieNode<T>* node = recursive_find(root->child, key, 0);

    if(node != root){
        return true;
    }

    return false;
}

template<typename T>
T Trie<T>::find(string key) {
    if(root->child == nullptr) return T();

    TrieNode<T>* node = recursive_find(root->child, key, 0);

    if(node->level == key.size()-1){
        return node->value;
    } else {
        return T();
    }
}

template<typename T>
void Trie<T>::insert(string key, T value){
    auto node = root;

    if(root->child != nullptr){
        auto node = recursive_find(root->child, key, 0);
    }

    auto temp = node->child;

    TrieNode<T>* new_node = new TrieNode<T>;
    new_node->level = node->level+1;
    new_node->key = key[node->level+1];
    node->child = new_node;
    new_node->brother = temp;

    for(int i = node->level+2;i < key.size();i++){
        TrieNode<T>* temp_node = new TrieNode<T>;
        temp_node->level = i;
        temp_node->key = key[i];

        new_node->child = temp_node;
        new_node = temp_node;
    }

    new_node->value = value;
}





#endif // TRIE_H_INCLUDED
