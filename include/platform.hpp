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
#include <map>
#include "component.hpp"

class Platform : public Component
{
private:
    //----- Rescources liées à la lecture des fichiers de définition
    //static const string keywords[];
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
    KWMap_t kwMap;                   // A discuter du static

    vector<string*> getPaths(string def_file);

    typedef struct {
        string  type,                       // Type de composant
                label,                      // Label du composant
                source,                     // Label de la source des données
                program;                    // Chemin vers le programmedu CPU
        int     width,                      // Largeur du bus
                cores,                      // Nombre de coeurs du CPU
                frequency,                  // Fréquence du CPU
                refresh,                    // Fréquence de rafraichissement de l'affichage
                size,                       // Taille de la mémoire
                access;                     // Temps d'accès à la mémoire
    } compProperties_t;                     // Structure de données pour stocker les caractéristiques des composants
    void readProperties(string path, compProperties_t *properties);
    void printProperties(compProperties_t properties);

    Component* readComponent(string path);

    void bindComponent();

public:
    // Constructeurs
    Platform(string label, string def_file);
    
    // Destructeurs
    ~Platform();

    // Vecteur de composants
    vector<Component*> components;

    // Interactions
    dataValue read() const override;
    void simulate() override;
};

#endif // _PLATFORM_HPP_