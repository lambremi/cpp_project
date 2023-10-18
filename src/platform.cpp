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

#include "platform.hpp"

//----- Rescources liées à la lecture du fichier de définition
// Initialisation des mots clés
const string Platform::keywords[] = {
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