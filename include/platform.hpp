/**
 * @file platform.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Classe platform
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

#include <vector>
#include "component.hpp"

class Platform : public Component
{
private:
    static const string keywords[];

    vector<string*> getPaths(string def_file);
    Component readComposant(string path);
    
    void bindComponent();

public:
    // Constructeurs
    Platform(string def_file);
    
    // Destructeurs
    ~Platform();

    // Vecteur de composants
    vector<Component*> components;
};

#endif // _PLATFORM_HPP_