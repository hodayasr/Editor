/* Hodaya Sror 208446518 */

#include <iostream>
#include <string>
#include <vector>
#include "Document.h"

Document::Document()
{
    vector<string> temp(0);
    lines = temp;
    current = 0;
}

//p
void Document::print_current_line()
{ 
    cout << lines[current-1] << endl;
}

//a
void Document::append() 
{ 
    string line;
    while(getline(cin, line) && (line.compare(".") != 0))
    {
        if(current != int(lines.size())) 
            lines.insert(lines.begin() + current, line);
        else lines.push_back(line);
        current++; 
    }
}

//n
void Document::print_current_tab_line()
{ 
    cout << current << "    " << lines[current-1] << endl;;
}

// %p
void Document::print_all()
{
    for(int i = 0; i < int(lines.size()); i++)
        cout << lines[i] << endl;
}

//change current line - by number
void Document::change_current(int num)
{
    if(num <= int(lines.size())){
        current = num;
        cout << lines[current-1] << endl;
    }
}

//i
void Document::insret_before_current_line()
{ 
    string line;
    while(getline(cin, line) && (line.compare(".") != 0)){
        lines.insert(lines.begin() + current - 1, line); 
    }
}

// c
void Document::change_current_to_follow()
{ 
    string line;
    while(getline(cin, line) && (line.compare(".") != 0)){
        lines[current-1] = line; 
    }
}

// d
void Document::delete_current_line()
{ 
    lines.erase(lines.begin() + current - 1);
}

// / ( /text )
void Document::search_text(string word)
{ 
    int count = 0;
    for(int i = current-1; i < int(lines.size()); i++)
    {
        if(lines[i].find(word) != string::npos)
        {
            current = i+1;
            cout << lines[i] << endl;
            break;
        }
        else if((i == int(lines.size()) -1) && count == 0)
        {
            count = 1;
            i = 0;
        } 
    }
}

 // s/old/new/ 
void Document::replace_old_with_new(string word)
{
    vector<string> result(0); 
    string delimiter = "/";
    size_t pos = 0;
    string token, temp;
    while ((pos = word.find(delimiter)) != string::npos)
    {
        token = word.substr(0, pos);
        result.push_back(token);
        word.erase(0, pos + delimiter.length());
    }
    result.push_back(token);
    if((pos = lines[current-1].find(result[1])) != string::npos)
    {
        lines[current-1] = lines[current-1].substr(0, pos) + result[2] + " " + lines[current-1].substr(pos+result[1].length());
    }
}