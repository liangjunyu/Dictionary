#include"review_history_library.h"
#include"word_library.h"
#include<vector>
#include<string>
#include<ctime>
#include<set>
#include<fstream>
#include<iostream>
using namespace std;

extern word_library word_lib;

review_history_library review_history_lib;

review_history_library::iterator review_history_library::begin()
{
	return lists.begin();
}

review_history_library::iterator review_history_library::end()
{
	return lists.end();
}

void review_history_library::insert_review_history(string& new_history)
{
        time_t currenttime;
        time(&currenttime);
        struct tm *current = localtime(&currenttime);
        if(!lists.empty() && current->tm_year == lists[lists.size()-1].get_year() && current->tm_yday == lists[lists.size()-1].get_yday())
        {
                lists[lists.size()-1].insert_review_history_inlist(new_history);
        }
        else
        {
                review_list new_list(current->tm_year, current->tm_yday);
                lists.push_back(new_list);
                lists[lists.size()-1].insert_review_history_inlist(new_history);
        }
        cout << 000 << new_history << endl;
		word_lib.newwords.erase(new_history);
		cout << 001 << new_history << endl;
}

void review_history_library::clear_review_history()
{
        lists.clear();
}

vector<string> review_history_library::get_list(int days)
{
	if(lists.size()-1-days >= 0)
		return lists[(int)lists.size()-1-days].get_histories();
	else
	{
		vector<string> empty_list;
		return empty_list;
	}
}

review_history_library::review_history_library()
{
	ifstream fin;
	fin.open("../data/review_history");
	if(!fin)
	{
		cout << "Open review_history error!\n";
		return;
	}
	//cout << "open\n";
	int _year = -1, _yday;
	string tmp;
	while(fin >> _year)
	{
		if(_year < 0) break;
		fin >> _yday;
		review_list new_list(_year, _yday);
		fin >> tmp;
		while(tmp != "#")
		{
			cout << "ready to insert " << tmp << "...\n";
			new_list.insert_review_history_inlist(tmp);
			fin >> tmp;
		}
		lists.push_back(new_list);

		_year = -1;
	}
	fin.close();
	//cout << "close\n";

	time_t currenttime;
	time(&currenttime);
	struct tm *current = localtime(&currenttime);

	if(lists.empty())
	{
		review_list first_list(current->tm_year, current->tm_yday);
		lists.push_back(first_list);
	}

	int recent_year = lists[lists.size()-1].get_year();
	int recent_yday = lists[lists.size()-1].get_yday();
	if(recent_year == current->tm_year && recent_yday < current->tm_yday)
		for(int i = recent_yday+1; i <= current->tm_yday; i ++)
		{
			review_list new_list(current->tm_year, i);
			lists.push_back(new_list);
		}
	//else if(recent_year < current->tm_year)
		//for(int i = recent_year; i <= current->tm_year)
			//for(int j = 0)
}

review_history_library::~review_history_library()
{
	ofstream fout;
	fout.open("../data/review_history");
	if(!fout)
	{
		cout << "Open review_history error!\n";
		return;
	}
	for(review_history_library::iterator it = lists.begin(); it != lists.end(); it ++)
	{
		fout << it->get_year() << ' ' << it->get_yday() << ' ';
		for(review_list::iterator itt = it->begin(); itt != it->end(); itt ++)
			fout << *itt << ' ';
		fout << "#\n";
	}

	fout.close();
}

const int& review_list::get_year()
{
        return year;
}

const int& review_list::get_yday()
{
        return yday;
}

void review_list::insert_review_history_inlist(string& new_history)
{
        histories.push_back(new_history);
        cout << "insert " << new_history << "!\n";
}

vector<string> review_list::get_histories()
{
	return histories;
}

review_list::review_list(int _year, int _yday): year(_year), yday(_yday){}

review_list::iterator review_list::begin()
{
	return histories.begin();
}

review_list::iterator review_list::end()
{
	return histories.end();
}
