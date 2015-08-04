
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "trie.h"
#include <utility>

using namespace std;

void FindAllTableWords(const Trie<string> & dic, const vector<vector<char>> & letter_table, vector<vector<int>> & lock_table, int x, int y, string letter);

int main() {
	ifstream fin("data.in", ios::in);

	Trie<string> dic{};
	vector<char> words(16);
	vector<vector<char>> letter_table(4, vector<char>(4, '\0'));

	string letter;
	char word;

	int number_of_read;
	cout << "Please enter the number of dictionary items : ";
	fin >> number_of_read;

	while (number_of_read--)
	{
		cout << number_of_read;

		cout << "input dic-item : ";
		fin >> letter;
		dic.insert(letter,letter);
	}

	cout << "\n Now input 16 alphabete : \n";

	number_of_read = 16;


	while (number_of_read--)
	{
		cout << "input word(" << (15 - number_of_read) / 4 << "," << (15 - number_of_read) % 4 << ")";
		fin >> word;
		letter_table[(15 - number_of_read) / 4][(15 - number_of_read) % 4] = word;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << letter_table[i][j];
		}

		cout << "\n";
	}




	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			string my_letter{};
			auto lock_table = vector<vector<int>>(4, vector<int>(4, 1));
			lock_table[i][j] = 0;
			FindAllTableWords(dic, letter_table, lock_table, i, j, my_letter);
		}
	}

	cout << "finished";

}

//void fn(const int& i, const string str){};

//void cc(const string strr){
//    unique_ptr<int> ii;
//    fn(*ii, strr);
//}

void FindAllTableWords(const Trie<string> & dic, const vector<vector<char>> & letter_table, vector<vector<int>> & lock_table,int x,  int y, string letter) {
	letter += letter_table[x][y];

	if(!dic.isWord(letter))
        return;

	auto got = dic.find(letter);

	if (got == letter)
		cout << got << " is in dic" << "\n";

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0) continue;
			if (x + i > 3 || x + i < 0 || y + j > 3 || y + j < 0 || lock_table[x + i][y + j] == 0) continue;

			lock_table[x+i][y+j] = 0;
			FindAllTableWords(dic, letter_table, lock_table, x + i, y + j,letter);
			lock_table[x+i][y+j] = 1;
		}
	}

	return;
}

