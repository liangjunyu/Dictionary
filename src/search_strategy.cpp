// search_strategy.cpp
#include "search_strategy.h"
#include <iostream>

using namespace std;

extern word_library word_lib;

search_strategy::search_strategy(const string& _search_word):search_word(_search_word){
    word_library::iterator it;
    for(it = word_lib.begin(); it != word_lib.end(); it ++)
		{
			if((*it).second->get_word_name() == search_word)
			{
				result = ((*it).second);
				break;
			}
		}
	if(it == word_lib.end()) found = 0;
	    else found = 1;
	// cout << _search_word << " " << found << endl;    
}

int search_strategy::is_found(){
	return found;
}

int search_strategy::features_count(){
	if(!found) return -1;
	return result->features_count();
}

const feature& search_strategy::get_feature(int i){
	return result->get_feature(i);
}

int search_strategy::is_new_word(){
	return word_lib.is_new_word(result->get_word_name());
}

int search_strategy::get_level(){
	return result->get_level();
}

void search_strategy::insert_examples(int i, const string& example){
	result->insert_examples(i, example);
}


int calc_dis(const string& s1, const string& s2){
	int m = s1.length(), n = s2.length();
	if(m == 0) return n;
	if(n == 0) return m;
	int **a;
	a = (int**)malloc(sizeof(int*)*(m+1));
	for(int i = 0;i<m+1;i++)
		a[i] = (int*)malloc(sizeof(int)*(n+1));
	for(int i = 0;i<m+1;i++)
		a[i][0] = i;
	for(int i = 0;i<n+1;i++)
		a[0][i] = i;
	for(int i = 1;i<m+1;i++)
		for(int j = 1;j<n+1;j++)
			a[i][j] = min(min(a[i-1][j]+1, a[i][j-1]+1), a[i-1][j-1]+(s1[i-1] == s2[j-1] ? 0 : 1));
	return a[m][n];	
}

vector<word*> search_strategy::get_similarist_words(){
	word_library::iterator it;
	vector<pair<int, word*> > for_sort;
    for(it = word_lib.begin(); it != word_lib.end(); it ++){
    	for_sort.push_back(make_pair(calc_dis(search_word, (*it).first), it->second));
	}
	sort(for_sort.begin(), for_sort.end());
	vector<word*> ret;
	for(int i = 0;i<10;i++) ret.push_back(for_sort[i].second);
	return ret;
}
















