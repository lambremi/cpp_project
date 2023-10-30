/**
 * @file component.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Classe component
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
#include <map>
#include "dataValue.hpp"

using namespace std;

/**
 * @brief Type énumérant des différents composants
 * 
 */
typedef enum {
    UNKNOWN,                                // Valeur par défaut
    MEMORY,
    BUS,
    CPU,
    DISPLAY,
    PLATFORM
} component_t;

/**
 * @brief Classe de base permettant de définir tous les autres composants
 * 
 */
class Component
{
public:
    // Constructeurs
    Component(component_t type, string label);
    Component(component_t type, string label, string source);

    // Destructeurs
    ~Component();

    // Méthodes get
    virtual component_t getType() const;
    virtual string getLabel() const;
    virtual void getSource(Component* src) const;
    virtual void setSource(Component* src);
    virtual void getSource(string* src) const;
    /*virtual Component  &getSource() const;
    virtual string      getSource() const;*/

    // Interactions
    virtual dataValue read() = 0;
    virtual void simulate() = 0;
    
protected:
    // Propriétés de base
    component_t type;
    string      label;
    Component*  source;                     // Pointeur vers le composant sources
    string      source_str;                 // String indiquant le label de la source

    // Map du type entre le string et component_t
    typedef map<string, component_t> CTMap_t;
    static CTMap_t& getCTMap() {
        static CTMap_t CTMap = {
            {"MEMORY",   MEMORY},
            {"BUS",      BUS},
            {"CPU",      CPU},
            {"DISPLAY",  DISPLAY},
            {"PLATFORM", PLATFORM}
        };
        return CTMap;
    }
};

#endif // _COMPONENT_HPP_