#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<char> pila;
    char c;
    while (cin >> c) {
        pila.push_back(c);
        if (pila[pila.size()-1] == ';') {
            break;
        }   
    }
    for (int i = 0; i < pila.size(); i++) {
        if(pila[i] != ' '){
            cout << pila[i]<<endl;
        }
    }
    return 0;
}
