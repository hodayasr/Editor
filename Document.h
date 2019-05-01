/* Hodaya Sror 208446518 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Document
{

private:
	vector<string> lines;
	int current;

public:

    Document();
	void print_current_line(); //p
    void print_current_tab_line(); //n
    void print_all(); //%p
    void change_current(int num); //change current line - by number
    void append(); //a
    void insret_before_current_line(); //i
    void change_current_to_follow(); //c
    void delete_current_line(); //d
    void search_text(string word); // /text
    void replace_old_with_new(string s); // s/old/new/
    bool isNumber(string s);
};