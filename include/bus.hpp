/**
 * @file bus.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BUS_HPP
#define BUS_HPP

#include "component.hpp"
#include "dataValue.hpp"
#include <queue>

/**
 * @brief Classe Bus
 * 
 */
class Bus : public Component
{
    private:
        int width;
        queue<dataValue> pending_data;
        queue<dataValue> ready_data;
        int read_count;
    public:
        Bus(component_t type, string label, string src, int width);
        ~Bus();
        dataValue read() override;
        void simulate() override;
        int getReadCount() const;
        int getWidth() const;
};

#endif // BUS_HPP