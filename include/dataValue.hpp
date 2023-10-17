/**
 * @file dataValue.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief dataValue type
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DATAVALUE_HPP_
#define _DATAVALUE_HPP_

/**
 * @brief Type permettant de transférer des données entre composants
 * 
 */
typedef struct dataValue {
    double  value;                       // Valeur de la donnée
    bool    flag;                        // Indique si la donnée est disponible
} dataValue_t;

#endif // _DATAVALUE_HPP_