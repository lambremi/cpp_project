/**
 * @file platform.cpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief Classe platform
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include "platform.hpp"

//----- Rescources liées à la lecture du fichier de définition
// Initialisation des mots clés
const string Platform::keywords[] = {       // Mots clés des caractéristiques des composants
    "TYPE",
    "LABEL",
    "SOURCE",
    "WIDTH",
    "CORES",
    "FREQUENCY",
    "PROGRAM",
    "REFRESH",
    "SIZE",
    "ACCESS"
};

/**
 * @brief Récupère les chemins d'accès aux 
 * fichier de définition des différents composants
 * 
 * @param def_file Chemin vers le fichier 
 * contenant les chemins d'accès
 * @return vector<string*> - Chemins d'accès
 */
vector<string*> Platform::getPaths(string def_file) {
    vector<string*> paths;

    fstream file(def_file, ios::in);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de définition " << def_file << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    file.read((char*)&line, sizeof(line));
    cout << line << endl;

    return paths;
}

/**
 * @brief Lit la définition d'un composant
 * 
 * @param path - Chemin vers le fichier de définition
 * @return Component - Composant instancié
 */
Component* Platform::readComponent(string path) {
    Component* component = nullptr;

    return component;
}

/**
 * @brief 
 * 
 */
void Platform::bindComponent() {
    /* TO DO */
}

//----- Constructeurs
/**
 * @brief Construct a new Platform:: Platform object
 * 
 * @param label Label de la plateforme
 * @param def_file Chemin vers le fichier de définition
 */
Platform::Platform(string label, string def_file) : Component(PLATFORM, label) {
    /* TO DO */
}

//----- Destructeurs
/**
 * @brief Destroy the Platform:: Platform object
 * 
 */
Platform::~Platform() {
    /* TODO */
}