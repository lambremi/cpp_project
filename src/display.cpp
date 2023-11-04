/**
 * @file display.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "display.hpp"
#include "cpu.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Display:: Display object
 * 
 * @param type - type of the component (DISPLAY)
 * @param src - label of the source component
 * @param refresh_rate - refresh rate of the display
 */
Display::Display(component_t type, string src, int refresh_rate) :    Component(type, src + " display", src), 
                                                                                    refresh_rate(refresh_rate), 
                                                                                    current_refresh(0){}

/**
 * @brief Destroy the Display:: Display object
 * 
 */
Display::~Display() {}

/**
 * @brief retourne le taux de rafraichissement
 * 
 * @return int - taux de rafraichissement
 */
int Display::getRefreshRate() {
    return refresh_rate;
}

/**
 * @brief Méthode de simulation du display.
 * Lit toutes les valeurs de la source et les affiche.
 */
void Display::simulate() {
    dataValue value;
    if (current_refresh == 0) {
        current_refresh++;
        value = source->read();
        while(value.flag == true) {
            cout << label << " : " << value.value << endl;
            value = source->read();
        }
    }
    else if (current_refresh == refresh_rate) {
        current_refresh = 0;
    }
    else {
        current_refresh++;
    }
}

/**
 * @brief Non utilisable : retourne une valeur par défaut
 * 
 * @return dataValue
 */

dataValue Display::read() {
    dataValue value;
    value.flag = false;
    value.value = 0;
    return value;
}

int Display::test(string label, int tst_arg) {
    Cpu cpu(CPU, "source", "data/basic_program.txt", 2, 3);
    Component* source = &cpu;

    // Test the label and type
    if (this->getLabel() != this->label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
        return 1;
    }
    if (this->getType() != DISPLAY) {
        cout << "Error: type is not DISPLAY" << endl;
        return 1;
    }

    if (this->getRefreshRate() != tst_arg) {
        cout << "Error: Expected display to have refresh rate " << tst_arg << "\n" << endl;
        return 1;
    }
    this->setSource(&cpu);
    this->getSource(source);
    if (source->getType() != CPU) {
        cout << "Error: Expected display to have cpu as source\n" << endl;
        return 1;
    }
    cpu.simulate();
    this->simulate();
    return 0;
}