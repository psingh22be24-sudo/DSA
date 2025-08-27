#include<iostream>
#include<stack>
#include<string>
using namespace std;
 string reve(const string& input) {
    stack<char> s;
    
    
    for (char ch : input) {
        s.push(ch);
    }

   
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string original;

    cout << "Enter a string to reverse: ";
    getline(cin, original);

    string reversed = rev(original);

    cout << " Reversed string: " << reversed << endl;

    return 0;
}
 
stack<ch>st;