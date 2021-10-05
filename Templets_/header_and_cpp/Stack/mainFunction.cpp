#include "stackhello.h"
#include "stackhello.cpp"
#include <string>
int main(){
    stack<string> s;
    s.push("hello");
    s.push("omi");
    s.push("mapari");
    // s.pop();
    // s.pop();
    // s.pop();
    s.print();
    return 0;
}