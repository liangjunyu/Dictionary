#include<vector>
#include<string>
#include<ctime>
#include<fstream>
#include<iostream>
#include"search_history_library.h"
using namespace std;

search_history_library search_history_lib;

void search_history_library::insert_search_history(string& history)
{
        search_histories.push_back(history);
}

search_history_library::search_history_library()
{
	ifstream fin;
	fin.open("../data/search_history");
	if(!fin)
	{
		cout << "Open search history error!\n";
		return;
	}

	string history;
	fin >> history;
	while(!fin.fail())
	{
		search_histories.push_back(history);
		fin >> history;
	}

	fin.close();
}

search_history_library::~search_history_library()
{
	ofstream fout;
	fout.open("../data/search_history");
	if(!fout)
	{
		cout << "Open search history error!\n";
		return;
	}

	for(search_history_library::iterator it = search_histories.begin(); it != search_histories.end(); it ++)
		fout << *it << endl;

	fout.close();
}

search_history_library::iterator search_history_library::begin()
{
	return search_histories.begin();
}

search_history_library::iterator search_history_library::end()
{
	return search_histories.end();
}

search_history_library::riterator search_history_library::rbegin()
{
	return search_histories.rbegin();
}

search_history_library::riterator search_history_library::rend()
{
	return search_histories.rend();
}

vector<string> search_history_library::get_latest_history(string substring, int n)
{
        vector<string> feedbacks;
        int count = 0;
        for(search_history_library::riterator rit = search_histories.rbegin(); rit != search_histories.rend(); rit ++)
        {
                if(rit->find(substring) != string::npos)
                {
                        feedbacks.push_back(*rit);
                        count++;
                        if(count >= n) break;
                }
        }
        return feedbacks;
}

void search_history_library::clear_search_history()
{
        search_histories.clear();
        //clear the file...
}
