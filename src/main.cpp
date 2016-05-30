#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"
#include "search_strategy.h"

using namespace std;
extern word_library word_lib;

int main()
{
	cout << "Loaded.\n";
	//auto it = word_lib.end()-1;
	//cout << it->get_word_name() << endl;
    string nword;
    cin >> nword;
    while(nword != "xxxxx")
	{
		search_strategy new_search(nword);
        cout << new_search.is_found() << " " << new_search.features_count() << endl;
        int cnt = new_search.features_count();
        cout << "The level is " << new_search.get_level() << endl;
        for(int i = 0;i<cnt;i++){
            cout << "The " << i << "-th meaning is " << endl;
            feature now_feature = new_search.get_feature(i);
            cout << now_feature.get_pos() << endl << now_feature.get_meaning() << endl;
            int cnt1 = now_feature.examples_count();
            for(int j = 0;j<cnt1;j++)
                cout << now_feature.get_example(j) << endl;
        }
        // int i;
        // string str;
        // cin >> i >> str;
        // new_search.insert_examples(i, str);
        vector<word*> sim_words = new_search.get_similarist_words();
        for(auto &i : sim_words){
            cout << i->get_word_name() << endl;
        }


        cin >> nword;
	}
    cout << "Hello world!" << endl;
    return 0;
}
