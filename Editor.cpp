/* Hodaya Sror 208446518 */

#include "Editor.h"
#include <iostream>
#include <string>


Editor::Editor()
{
    doc = new Document();
}

Editor::~Editor()
{
    delete doc;
}

void Editor::loop()
{
    string command;
    while(getline(cin, command)){
        if(command.compare("p") == 0) doc->print_current_line(); // print current line
        else if(command.compare("n") == 0) doc->print_current_tab_line(); // prints line number of current line followed by TAB followed by current line
        else if(command.compare("%p") == 0) doc->print_all(); // prine all lines
        else if(isNumber(command) == true) // make {num} line the current line
        {
            int num = 0;
            for(int i = 0; i < int(command.length()); i++) 
                num = num * 10 + char(command[i]) - 48; 
            doc->change_current(num);
        }
        else if(command.compare("a") == 0) doc->append();   //appends new text after the current line 
        else if(command.compare("i") == 0) doc->insret_before_current_line();  //inserts new text before the current line
        else if(command.compare("c") == 0) doc->change_current_to_follow();  //changes the current line for text that follows
        else if(command.compare("d") == 0) doc->delete_current_line();  // deletes the current line
        
        //searches forward after current line for the specified text. The search wraps to the beginning of the buffer and continues down to the current line, if necessary
        else if(command[0] == '/') doc->search_text(command.substr(1));  
        
        //replaces old string with new in current line (google: C++ split or token) 
        else if(command[0] == 's' && command[1] == '/') doc->replace_old_with_new(command);
        
        //Quits the editor without savin
        else if(command.compare("Q") == 0) break;   
   
    }
}


bool Editor::isNumber(string s) 
{ 
    for (int i = 0; i < s.length(); i++)
    { 

        if (isdigit(s[i]) == false) 
        {
        return false; 
        }
    }
    return true; 
}