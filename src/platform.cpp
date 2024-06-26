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
#include "cpu.hpp"
#include "bus.hpp"
#include "memory.hpp"
#include "display.hpp"

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
    properties->type = UNKNOWN;
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
        if (getline(iss, property, ':') && iss.ignore(1, ' ') && getline(iss, value)) {
            switch (getKWMap().at(property)) {
                case TYPE:
                    properties->type = getCTMap().at(value);
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
    #ifdef _DEBUG_
    printProperties(*properties);
    #endif
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
    #ifdef _DEBUG_
    cout << "----- " << path << endl;
    #endif

    compProperties_t properties;
    readProperties(path, &properties);

    // Création des composants à proprement parlé
    switch (properties.type) {
        case CPU:
            #ifdef _DEBUG_
            cout << "NEW CPU" << endl;
            #endif
            component = new Cpu(
                properties.type,
                properties.label,
                properties.program,
                properties.cores,
                properties.frequency
            );
        break;
        case BUS:
            #ifdef _DEBUG_
            cout << "NEW BUS" << endl;
            #endif
            component = new Bus(
                properties.type,
                properties.label,
                properties.source,
                properties.width
            );
        break;
        case MEMORY:
            #ifdef _DEBUG_
            cout << "NEW MEMORY" << endl;
            #endif
            component = new Memory(
                properties.type,
                properties.label,
                properties.size,
                properties.access,
                properties.source
            );
        break;
        case DISPLAY:
            #ifdef _DEBUG_
            cout << "NEW DISPLAY" << endl;
            #endif
            component = new Display(
                properties.type,
                properties.source,
                properties.refresh
            );
        break;
        default:
            
        break;
    }

    return component;
}

/**
 * @brief Attache la source des composants
 * 
 */
void Platform::bindComponent() {
    #ifdef _DEBUG_
    cout << "============ BIND ============" << endl;
    #endif
    size_t j = 0;
    string source;

    // Parcours de tous les composants de la plateforme
    #ifdef _DEBUG_
    cout << "Nombre de composants : " << components.size() << endl;
    #endif
    for (size_t i = 0; i < components.size(); i=i+1) {
        if (components[i] != nullptr) {
            #ifdef _DEBUG_
            cout << "----- " << i  << " : " << components[i]->getLabel() << endl;
            #endif
            // Recherche de la source sans bindé les composants qui n'en ont pas
            components[i]->getSource(&source);
            if (source != "") {
                while ( (size_t)j < components.size()       && 
                        components[j] != nullptr            && 
                        source != components[j]->getLabel() )
                    j = j + 1;
                
                // Si la source est trouvée
                if ((size_t)j < components.size() && components[j] != nullptr) {
                    components[i]->setSource(components[j]);
                    #ifdef _DEBUG_
                    cout << "Source : " << components[j]->getLabel() << endl;
                    #endif
                }
                #ifdef _DEBUG_
                else
                    cout << "Source non trouvée" << endl;
                #endif

                j = 0;
            }
            #ifdef _DEBUG_
            else
                cout << "Pas de source" << endl;
            #endif
        }
        else
            cerr << "Erreur lors de l'instanciation du composant " << i << endl;
    }
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

    //----- Lecture des composants
    for (size_t i = 0; i < paths.size(); i=i+1)
        components.push_back(readComponent(*paths[i]));
    
    bindComponent();
}

//----- Destructeurs
/**
 * @brief Destroy the Platform:: Platform object
 * 
 */
Platform::~Platform() {
    #ifdef _DEBUG_
    cout << "============ DESTROY @ " << this << " ============" << endl;
    cout << "Nombre de composants : " << components.size() << endl;
    #endif
    for (size_t i = 0; i < components.size(); i=i+1) {
        #ifdef _DEBUG_
        cout << "----- " << i  << " : " << components[i]->getLabel() << endl;
        #endif
        delete components[i];
    }
    #ifdef _DEBUG_
    cout << "============ END DESTROY ============" << endl;
    #endif
}

//========== Public methods
/**
 * @brief Retourne les composants de la plateforme
 * 
 * @return vector<Component*> - Composants de la plateforme
 */
vector<Component*> Platform::getComponents() const {
    return components;
}

/**
 * @brief Récupères les données de la plateforme
 * 
 * @return dataValue - Données de la plateforme
 */
dataValue Platform::read() {
    /* TODO */
    return dataValue();
}

/**
 * @brief Lance un cycle de simulation de la plateforme
 * 
 */
void Platform::simulate() {
        for (size_t j = 0; j < components.size(); j=j+1) {
            #ifdef _DEBUG_
            cout << "----- " << j  << " : " << components[j]->getLabel() << endl;
            #endif
            components[j]->simulate();
        }
}

/**
 * @brief Lance une simulation de la plateforme
 * sur un nombre de cycles donné
 * 
 * @param cycles Nombre de cycles à simuler
 */
void Platform::simulate(int cycles) {
    #ifdef _DEBUG_
    cout << "============ SIMULATE ============" << endl;
    #endif
    for (int i = 0; i < cycles; i=i+1) {
        #ifdef _DEBUG_
        cout << "---------- Cycle " << i << endl;
        #endif
        simulate();
    }

    #ifdef _DEBUG_
    cout << "============ END SIMULATE ============" << endl;
    #endif
}

/**
 * @brief Test une instance de la classe Platform
 * 
 * @param label Label attendu
 * @param tst_arg Nombre de composants attendu
 * @return int - 1 si erreur, 0 sinon
 */
int Platform::test(string label, int tst_arg) {
    //----- Déclaration des variables
    vector<Component*> components;
    Memory* mem = nullptr;
    Bus* bus = nullptr;
    Cpu* cpu = nullptr;
    Display* display = nullptr;
    Platform* platform = nullptr;
    int return_value;

    //----- Code
    #ifdef _DEBUG_
    cout << "========== Start of test ==========" << endl;
    #endif

    // Test the label and type
    #ifdef _DEBUG_
    cout << "Test the label" << endl;
    #endif
    if (this->getLabel() != label) {
        cout << "Error: label is not \"" << label << "\"" << endl;
        return 1;
    }
    #ifdef _DEBUG_
    cout << "Test the type" << endl;
    #endif
    if (this->getType() != PLATFORM) {
        cout << "Error: type is not PLATFORM" << endl;
        return 1;
    }

    // Test the components vector
    #ifdef _DEBUG_
    cout << "Test the components vector" << endl;
    #endif
    components = this->getComponents();
    if (components.size() != size_t(tst_arg)) {
        cout << "Error: components vector size is not "<< tst_arg << endl;
        return 1;
    }

    // Launch test on each components
    #ifdef _DEBUG_
    cout << "========== Launch test on each components ==========" << endl;
    #endif
    for (size_t i = 0; i < components.size(); i=i+1) {
        #ifdef _DEBUG_
        if (components[i] != nullptr) {
            cout << "----- Test on " << components[i]->getLabel() << endl;
        }
        else {
            cout << "Test on " << i << " is nullptr" << endl;
        }
        #endif
        switch (components[i]->getType()) {
            case UNKNOWN:
                cout << "Error: unknown component type" << endl;
                return 1;
            break;
            case MEMORY:
                mem = (Memory*)components[i];
                return_value = mem->test(mem->getLabel(), mem->getAccess());
                if (return_value != 0) {
                    cout << "Error: test failed, return value is " << return_value << endl;
                    return 1;
                }
            break;
            case BUS:
                bus = (Bus*)components[i];
                return_value = bus->test(bus->getLabel(), bus->getWidth());
                if (return_value != 0) {
                    cout << "Error: test failed, return value is " << return_value << endl;
                    return 1;
                }
            break;
            case CPU:
                cpu = (Cpu*)components[i];
                return_value = cpu->test(cpu->getLabel()/*, cpu->getFrequency()*/);
                if (return_value != 0) {
                    cout << "Error: test failed, return value is " << return_value << endl;
                    return 1;
                }
            break;
            case DISPLAY:
                display = (Display*)components[i];
                return_value = display->test(display->getLabel(), display->getRefreshRate());
                if (return_value != 0) {
                    cout << "Error: test failed, return value is " << return_value << endl;
                    return 1;
                }
            break;
            case PLATFORM:
                platform = (Platform*)components[i];
                return_value = platform->test(platform->getLabel(), (int)platform->getComponents().size());
                if (return_value != 0) {
                    cout << "Error: test failed, return value is " << return_value << endl;
                    return 1;
                }
            break;
            default:
                cout << "Error: unknown component type" << endl;
                return 1;
            break;
        }
        #ifdef _DEBUG_
        cout << "PASS" << endl;
        #endif
    }

    #ifdef _DEBUG_
    cout << "========== End of test ==========" << endl;
    #endif

    return 0;
}