/* Hodaya Sror 208446518 */

#include <iostream>
#include <string>
#include "Document.h"

using namespace std;

class Editor {

private:
    Document * doc;

public:
    Editor();
    ~Editor();
    void loop();
    bool isNumber(string s);
};