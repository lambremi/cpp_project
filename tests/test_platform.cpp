/**
 * @file test_platform.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Test de la classe Platform
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// #include <iostream>
// #include <vector>
// #include <string>

#include "test.hpp"

using namespace std;

int test_plateform(Platform platform) {
    // Test the label and type
    #ifdef _DEBUG_
    cout << "Test the label and type" << endl;
    #endif
    if (platform.getLabel() != "platform") {
        cout << "Error: label is not \"platform\"" << endl;
        return 1;
    }
    #ifdef _DEBUG_
    cout << "Test the label and type" << endl;
    #endif
    if (platform.getType() != PLATFORM) {
        cout << "Error: type is not PLATFORM" << endl;
        return 1;
    }

    // Test the components vector
    #ifdef _DEBUG_
    cout << "Test the components vector" << endl;
    #endif
    vector<Component*> components = platform.getComponents();
    if (components.size() != 7) {
        cout << "Error: components vector size is not 7" << endl;
        return 1;
    }

    // Launch test on each components
    #ifdef _DEBUG_
    cout << "Launch test on each components" << endl;
    #endif
    for (int i = 0; (size_t)i < components.size(); i=i+1) {
        #ifdef _DEBUG_
        if (components[i] != nullptr) {
            cout << "Test on component " << components[i]->getLabel() << endl;
        }
        else {
            cout << "Test on component " << i << " is nullptr" << endl;
        }
        #endif
        switch (components[i]->getType()) {
            case UNKNOWN:
                cout << "Error: unknown component type" << endl;
                return 1;
            break;
            case MEMORY:
                cout << "MEMORY : no test available yet" << endl;
            break;
            case BUS:
                cout << "BUS : no test available yet" << endl;
                /*if (!test_bus(*(Bus*)components[i])) {
                    cout << "Error: test_bus() failed" << endl;
                    return 1;
                }*/
            break;
            case CPU:
                cout << "CPU : no test available yet" << endl;
                // if (!test_cpu(*(Cpu*)components[i], components[i]->getLabel()/*"cpu" + to_string(i+1)*/)) {
                    // cout << "Error: test_cpu() failed" << endl;
                    // return 1;
                // }*/
            break;
            case DISPLAY:
                cout << "DISPLAY : no test available yet" << endl;
            break;
            case PLATFORM:
                if (!test_plateform(*(Platform*)components[i])) {
                    cout << "Error: test_plateform() failed" << endl;
                    return 1;
                }
            break;
            default:
                cout << "Error: unknown component type" << endl;
                return 1;
            break;

        }
    }
    return 0;
}

int main() {
    Platform platform("platform", "../data/platform.txt");

    return test_plateform(platform);
}