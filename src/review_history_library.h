#ifndef REVIEW_HISTORY_LIBRARY_H_INCLUDED
#define REVIEW_HISTORY_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
#include<ctime>
using namespace std;

class review_list
{
        int year;
        int yday;
        vector<string> histories;
public:
	   typedef vector<string>::iterator iterator;
	   iterator begin();
	   iterator end();
	   const int& get_year();
	   const int& get_yday();
       void insert_review_history_inlist(string& new_history);
       review_list(int _year, int _yday);
       vector<string> get_histories();
};

class review_history_library
{

        vector<review_list> lists;
public:
		typedef vector<review_list>::iterator iterator;
		iterator begin();
		iterator end();
        void insert_review_history(string& new_history);//only push_back
        void clear_review_history();
        vector<string> get_list(int days);
        review_history_library();
        ~review_history_library();
};

#endif // REVIEW_HISTORY_LIBRARY_H_INCLUDED
