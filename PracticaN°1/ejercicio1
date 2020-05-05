#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<char> pila;
    char c;
    // in
    while (cin >> c) {
        pila.push_back(c);
        if (pila[pila.size()-1] == ';') {
            break;
        }   
    }
    // out

    for (int i=0;i<pila.size();i++) {
        if(pila[i]!=' ')
            cout<<pila[i]<<endl;
    }
    cout << endl;

    return 0;
}
