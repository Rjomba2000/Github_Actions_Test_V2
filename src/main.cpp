#include <iostream>
#include <string>
#include "MyBinaryTree.h"

using namespace std;

int main() {
    MyBinaryTree<int> tree;
    string str = "";
    while (str != "exit") {
        int value;
        cin >> str;
        if (str == "insert") {
            cin >> value;
            tree.insert(value);
        }
        if (str == "find") {
            cin >> value;
            cout << tree.find(value) << endl;
        }
        if (str == "remove") {
            cin >> value;
            tree.remove(value);
        }
    }
}