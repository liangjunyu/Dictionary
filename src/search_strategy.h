//search_strategy.h
#ifndef SEARCH
#define SEARCH
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "word_library.h"
using namespace std;

class search_strategy{
private:
	string search_word;
	word* result;
	int found;
	void search_in_library(const string&);
public:
	search_strategy(const string&);
	int is_found();
	int features_count();
	int is_new_word();
	const feature& get_feature(int i);//get the i-th feature in the features
	int get_level();
	void insert_examples(int, const string&);
	vector<word*> get_similarist_words();
};


#endif
