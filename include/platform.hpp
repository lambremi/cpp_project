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
    //----- Attributs
    // Vecteur de composants
    vector<Component*> components;

    //----- Rescources liées à la lecture des fichiers de définition
    // Mots clés des fichiers de définition
    typedef enum {
        TYPE,
        LABEL,
        SOURCE,
        WIDTH,
        CORES,
        FREQUENCY,
        PROGRAM,
        REFRESH,
        SIZE,
        ACCESS
    } keyword_t;
    typedef map<string, keyword_t> KWMap_t;
    // Initialisation de KWMap
    static KWMap_t& getKWMap() {
        static KWMap_t kwMap = {
            {"TYPE",      TYPE},
            {"LABEL",     LABEL},
            {"SOURCE",    SOURCE},
            {"WIDTH",     WIDTH},
            {"CORES",     CORES},
            {"FREQUENCY", FREQUENCY},
            {"PROGRAM",   PROGRAM},
            {"REFRESH",   REFRESH},
            {"SIZE",      SIZE},
            {"ACCESS",    ACCESS}
        };
        return kwMap;
    }
    
    vector<string*> getPaths(string def_file);

    typedef struct {
        component_t type;                   // Type de composant
        string      label,                  // Label du composant
                    source,                 // Label de la source des données
                    program;                // Chemin vers le programmedu CPU
        int         width,                  // Largeur du bus
                    cores,                  // Nombre de coeurs du CPU
                    frequency,              // Fréquence du CPU
                    refresh,                // Fréquence de rafraichissement de l'affichage
                    size,                   // Taille de la mémoire
                    access;                 // Temps d'accès à la mémoire
    } compProperties_t;                     // Structure de données pour stocker les caractéristiques des composants
    void readProperties(string path, compProperties_t *properties);
    void printProperties(compProperties_t properties);

    Component* readComponent(string path);

    void bindComponent();

public:
    // Constructeur
    Platform(string label, string def_file);
    
    // Destructeur
    ~Platform();

    // Interactions
    vector<Component*> getComponents() const;
    dataValue read() override;
    void simulate() override;
    int test(string label, size_t nb_comp);
};

#endif // _PLATFORM_HPP_