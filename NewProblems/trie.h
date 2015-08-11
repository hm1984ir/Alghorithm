#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <string>
#include <list>
#include<memory>

using namespace std;

template<typename T>
class TrieNode{
    public:
    TrieNode(){
        parent = {};
        child= {};
        brother = {};
    }
    unique_ptr<TrieNode<T>> parent;
    unique_ptr<TrieNode<T>> child;
    unique_ptr<TrieNode<T>> brother;
    int level;

    string key;
    T value;
};

template<typename T>
class Trie{
public:
    Trie();
    void insert(const string key, const T value);
    void remove(const string key);
    bool isWord(const string key) const;
    //T operator[](const Trie<T>& trie,const string key);
    T find(const string key) const;
private:
    TrieNode<T>& recursive_find(const TrieNode<T>& node,const string key, int i) const;
    unique_ptr<TrieNode<T>> root{new TrieNode<T>};
};

template<typename T>
Trie<T>::Trie(){

}

template<typename T>
TrieNode<T>& Trie<T>::recursive_find(const TrieNode<T>& node,const string key , int i) const{
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
    TrieNode<T>& node = recursive_find(*root, key, 0);

    if(node != root){
        return true;
    }

    return false;
}

template<typename T>
T Trie<T>::find(const string key) const{
    TrieNode<T>& node = recursive_find(*root, key, 0);

    if(node != nullptr){
        return node.value;
    } else {
        return T();
    }
}

template<typename T>
void Trie<T>::insert(const string key, const T value){
    unique_ptr<TrieNode<T>> r{new TrieNode<T>};
    auto node = recursive_find(*r, key, 0);

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
