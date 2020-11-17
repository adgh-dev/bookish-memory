#include <iostream>

using namespace std;

int main() {
    string input_string;
    cin >> input_string;

    for(int i=0; i<input_string.size(); i++) {
        char ch = tolower(input_string[i]);
        if (ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' || ch == 'i')
            continue;
        else {
            cout << '.' << ch;
        }
    }
    
    return 0;
}