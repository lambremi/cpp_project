#include "register.hpp"

using namespace std;

/**
 * @brief Construct a new Register:: Register object
 * 
 */
Register::Register() {
    fifo = queue<double>();
}

/**
 * @brief Destroy the Register:: Register object
 * 
 */
Register::~Register() {
}

/**
 * @brief Vérifie si le registre est vide
 * 
 * @return bool - true si le registre est vide, false sinon 
 */
bool Register::isEmpty() {
    return fifo.empty();
}

/**
 * @brief Lit la valeur la plus ancienne du registre
 * 
 * @return double - valeur du registre
 */
double Register::read() {
    double value = fifo.front();
    fifo.pop();
    return value;
}

/**
 * @brief Ecrit une valeur dans le registre
 * 
 * @param value - valeur à écrire
 */
void Register::write(double value) {
    fifo.push(value);
}