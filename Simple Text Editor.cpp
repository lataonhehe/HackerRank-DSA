#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "";
    int cas;
    cin >> cas;
    vector<string> prev;
    for(int i = 0; i < cas; i++){
        string t, r;
        cin >> t;
        if(t != "4") cin >> r;

        if(t == "1"){
            prev.push_back(s);
            s += r;
        }
        else if( t == "2"){
            prev.push_back(s);
            s.erase(s.end() - stoi(r), s.end());
        }
        else if(t == "3"){ cout << s[stoi(r)-1] << endl; }
        else {
            s = prev.back();
            prev.pop_back();
        }
    }
    return 0;
}
