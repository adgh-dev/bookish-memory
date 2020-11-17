#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string _name;
    unordered_map<string, int> names; 

    cin >> n;
    while (n > 0) {
        n--;
        cin >> _name;
        if (names.find(_name) == names.end()) {
            names[_name] = 0;
            cout << "OK" << endl;
        } 
        else {
            names[_name]++;
            cout << _name << names[_name] << endl;
        }
    }

    return 0;
}