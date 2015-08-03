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
    TrieNode& parent;
    TrieNode& child;
    TrieNode& brother;
    int level;


    string key;
    T value;
};

template<typename T>
class Trie{
public:
    Trie();
    void insert(const string key, const T value) const;
    void remove(const string key) const;
    bool isWord(const string key) const;
    //T operator[](const Trie<T>& trie,const string key);
    T find(const string key) const;
private:
    TrieNode<T>& recursive_find(TrieNode<T>& node,string key, int i);
    TrieNode<T>& root;
};

template<typename T>
Trie<T>::Trie(TrieNode root_node){
    root = &root_node;
}

template<typename T>
TrieNode<T>& Trie<T>::recursive_find(TrieNode<T>& node, string key , int i){
    string c = key.substr(0,i);

    if(node.key == c){
        if(i == key.size()){ return node;}

        if(node.child != nullptr){
            auto temp = recursive_find(node.child, key, i+1);
            if(temp != nullptr){
                return temp;
            }
        }

        return node;
    } else if(node.brother != nullptr){
        auto temp = recursive_find(node.brother, key, i);
        if(temp != nullptr){
            return temp;
        }
    }

    return nullptr;
}

template<typename T>
bool Trie<T>::isWord(const string key)const{
    TrieNode<T>& node = recursive_find(root,key,0);

    if(node != root){
        return true;
    }

    return false;
}

template<typename T>
T Trie<T>::find(const string key) const{
    TrieNode<T>& node = recursive_find(root,key,0);

    if(node != nullptr){
        return node.value;
    } else {
        return T();
    }
}

template<typename T>
void Trie<T>::insert(const string key, const T value)const{
    auto node = recursive_find(root,key,0);

    auto temp = node.child;

    TrieNode<T> new_node;
    new_node.level = node.level+1;
    new_node.key = key[node.level+1];
    node.child = new_node;
    new_node.brother = temp;

    for(int i = node.level+2;i < key.size();i++){
        TrieNode<T> temp_node;
        temp_node.level = i;
        temp_node.key = key[i];

        new_node.child = temp_node;
        new_node = temp_node;
    }

    new_node.value = value;
}





#endif // TRIE_H_INCLUDED
