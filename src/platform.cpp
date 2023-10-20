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
#include <sstream>
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
    ifstream file(def_file);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de définition " << def_file << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        // cout << line << endl;
        paths.push_back(new string(line));
    }

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
    cout << path << endl;
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
    vector<string*> paths = getPaths(def_file);

    for (int i = 0; i < paths.size(); i=i+1)
        readComponent(*paths[i]);

    
}

//----- Destructeurs
/**
 * @brief Destroy the Platform:: Platform object
 * 
 */
Platform::~Platform() {
    /* TODO */
}