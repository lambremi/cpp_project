// FILEPATH: /c:/Users/Gael/Documents/Phelma/POO/cpp_project/tests/test_platform.cpp

#include <iostream>
#include <vector>
#include <string>

#include "platform.hpp"
#include "component.hpp"

using namespace std;

int main() {
    Platform platform("platform", "../data/platform.txt");

    // Test the label and type
    if (platform.getLabel() != "platform") {
        cout << "Error: label is not \"platform\"" << endl;
        return 1;
    }
    if (platform.getType() != PLATFORM) {
        cout << "Error: type is not PLATFORM" << endl;
        return 1;
    }
/*
    // Test the read method
    dataValue value = platform.read();
    if (value.flag != false) {
        cout << "Error: read() is not false but nothing happened yet" << endl;
        return 1;
    }

    // Test the simulate method
    platform.simulate();
    value = platform.read();
    if (value.flag != true) {
        cout << "Error: read() is not true" << endl;
        return 1;
    }

    // Test the components vector
    vector<Component*> components = platform.getComponents();
    if (components.size() != 2) {
        cout << "Error: components vector size is not 2" << endl;
        return 1;
    }
    if (components[0]->getLabel() != "component1") {
        cout << "Error: component1 label is not \"component1\"" << endl;
        return 1;
    }
    if (components[1]->getLabel() != "component2") {
        cout << "Error: component2 label is not \"component2\"" << endl;
        return 1;
    }
*/
    return 0;
}