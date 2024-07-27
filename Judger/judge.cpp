#include "judge.h"

// default judge: check std == test
int main(){
	string sc;

    string s1 = "", s2 = "";
    while(getline(stds, sc)) {
        while(!sc.empty() && (sc.back() == ' ' || sc.back() == '\n')) sc.pop_back(); //ignore enter and space
        s1 = s1 + sc + '\n';
    }
    while(getline(test, sc)) {
        while(!sc.empty() && (sc.back() == ' ' || sc.back() == '\n')) sc.pop_back(); //ignore enter and space
        s2 = s2 + sc + '\n';
    }

    if (s1 == s2) {
        AC();
        display();
    }
    else {
        WA();
        display();
    }

    inp.close();
    stds.close();
    test.close();
    return 0;
}