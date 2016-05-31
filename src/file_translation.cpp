// file_translation.cpp
#include "file_translation.h"

file_translation::file_translation(const string& file_name){
	fin.open(file_name, fstream::in);
	if(!fin) opened_properly = 0;
	    else opened_properly = 1;
	fout.open("../res/result", fstream::out);
}

int file_translation::is_opened_properly(){
	return opened_properly;
}

void file_translation::run(){
	string line;
	while(!fin.eof()){
		getline(fin, line);
		char* str = (char*)line.c_str();
		char* pch = strtok (str," ,.-?!");
		while(pch != NULL){
			printf("%s\n", pch);
		    search_strategy new_search((string(pch)));
		    if(!new_search.is_found()) continue;
		    if(!new_search.is_new_word()) continue;
		    fout << string(pch) << endl;
		    int cnt = new_search.features_count();
            for(int i = 0;i<cnt;i++){
                feature now_feature = new_search.get_feature(i);
                fout << i << endl << now_feature.get_pos() << endl << now_feature.get_meaning() << endl;
            }
            fout << endl;
		    pch = strtok(NULL, " ,.-?!");
        }
    }
}
