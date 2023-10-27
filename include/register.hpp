/**
 * @file register.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <queue>

using namespace std;

/**
 * @brief class Register
 * used to store the CPU data
 */
class Register {
    private:
        queue<double> fifo;
    public:
        Register();
        ~Register();
        bool isEmpty();
        double read();
        void write(double value);
};

#endif // REGISTER_HPP