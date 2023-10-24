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
// const string Platform::keywords[] = {       // Mots clés des caractéristiques des composants
//     "TYPE",
//     "LABEL",
//     "SOURCE",
//     "WIDTH",
//     "CORES",
//     "FREQUENCY",
//     "PROGRAM",
//     "REFRESH",
//     "SIZE",
//     "ACCESS"
// };

//========== Private methods
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
        line = "../" + line;
        paths.push_back(new string(line));
    }

    return paths;
}

/**
 * @brief Lit les propriétés d'un composant à partir de son fichier de définition
 * 
 * @param path Chemin vers le fichier de définition
 * @param properties Structure de données pour stocker les caractéristiques des composants
 */
void Platform::readProperties(string path, compProperties_t *properties) {
    //----- Déclaration des variables
    vector<string*> lines;                  // Lignes du fichier
    ifstream file(path);                    // Fichier de définition
    string line;                            // Ligne courante
    string property, value;                 // Propriété et valeur courantes

    //----- Code
    // Initialisation de properties
    properties->type = "";
    properties->label = "";
    properties->source = "";
    properties->program = "";
    properties->width = 0;
    properties->cores = 0;
    properties->frequency = 0;
    properties->refresh = 0;
    properties->size = 0;
    properties->access = 0;

    // Lecture des propriétés
    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de définition " << path << endl;
        exit(EXIT_FAILURE);
    }

    while (getline(file, line)) {
        istringstream iss(line);
        if (getline(iss, property, ':') && iss >> value/*getline(iss, ' ') && getline(iss, value)*/) {
            switch (kwMap.at(property)) {
                case TYPE:
                    properties->type = value;
                break;
                case LABEL:
                    properties->label = value;
                break;
                case SOURCE:
                    properties->source = value;
                break;
                case WIDTH:
                    properties->width = stoi(value);
                break;
                case CORES:
                    properties->cores = stoi(value);
                break;
                case FREQUENCY:
                    properties->frequency = stoi(value);
                break;
                case PROGRAM:
                    properties->program = value;
                break;
                case REFRESH:
                    properties->refresh = stoi(value);
                break;
                case SIZE:
                    properties->size = stoi(value);
                break;
                case ACCESS:
                    properties->access = stoi(value);
                break;
                default:
                    /**/
                break;
            }
        }
        lines.push_back(new string(line));
    }
    printProperties(*properties);
}

/**
 * @brief Affiche des propriétés d'un composant (debug)
 * 
 * @param properties Propriétés à afficher
 */
void Platform::printProperties(compProperties_t properties) {
    cout << "Type : \"" << properties.type << "\"" << endl;
    cout << "Label : \"" << properties.label << "\"" << endl;
    cout << "Source : \"" << properties.source << "\"" << endl;
    cout << "Program : \"" << properties.program << "\"" << endl;
    cout << "Width : \"" << properties.width << "\"" << endl;
    cout << "Cores : \"" << properties.cores << "\"" << endl;
    cout << "Frequency : \"" << properties.frequency << "\"" << endl;
    cout << "Refresh : \"" << properties.refresh << "\"" << endl;
    cout << "Size : \"" << properties.size << "\"" << endl;
    cout << "Access : \"" << properties.access << "\"" << endl;
}

/**
 * @brief Lit la définition d'un composant
 * 
 * @param path - Chemin vers le fichier de définition
 * @return Component - Composant instancié
 */
Component* Platform::readComponent(string path) {
    Component* component = nullptr;
    cout << "----- " << path << endl;

    compProperties_t properties;
    readProperties(path, &properties);

    // FAIRE UN NOUVEAU MAP POUR LES TYPES DE COMPOSANTS
    /*switch (kwMap.at(properties.type)) {
        case CPU:
            cout << "CPU" << endl;
            //component = new CPU(properties.label, properties.source, properties.program, properties.cores, properties.frequency);
        break;
        case BUS:
            cout << "BUS" << endl;
            //component = new Bus(properties.label, properties.source, properties.width);
        break;
        case MEMORY:
            cout << "MEMORY" << endl;
            //component = new Memory(properties.label, properties.source, properties.size, properties.access);
        break;
        case DISPLAY:
            cout << "DISPLAY" << endl;
            //component = new Display(properties.label, properties.source, properties.refresh);
        break;
        default:
            
        break;
    }*/

    return component;
}

/**
 * @brief 
 * 
 */
void Platform::bindComponent() {
    /* TO DO */
}

//========== Constructors & destructors
//----- Constructeurs
/**
 * @brief Construct a new Platform:: Platform object
 * 
 * @param label Label de la plateforme
 * @param def_file Chemin vers le fichier de définition
 */
Platform::Platform(string label, string def_file) : Component(PLATFORM, label) {
    vector<string*> paths = getPaths(def_file);

    //----- Initialisation des mots clés
    const string keywords[] = {       // Mots clés des caractéristiques des composants
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

    for (int i = 0; i < (int)(sizeof(keywords)/sizeof(*keywords)); i=i+1)
        kwMap.insert(KWMap_t::value_type(keywords[i], (keyword_t)i));

    //----- Lecture des composants
    for (int i = 0; (size_t)i < paths.size(); i=i+1)
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

//========== Public methods
/**
 * @brief Récupères les données de la plateforme
 * 
 * @return dataValue - Données de la plateforme
 */
dataValue Platform::read() const {
    /* TODO */
    return dataValue();
}

/**
 * @brief Lance la simulation de la plateforme
 * 
 */
void Platform::simulate() {
    /* TODO */
}