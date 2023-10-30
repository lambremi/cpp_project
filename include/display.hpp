/**
 * @file display.hpp
 * @author LAMBERT Rémi & OUSSET Gaël
 * @brief 
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "component.hpp"
#include "dataValue.hpp"

class Display : public Component {
    private : 
        int refresh_rate;
        int current_refresh;
    public : 
        Display(component_t type, string label, string src, int refresh_rate);
        ~Display();
        int getRefreshRate();
        void simulate() override;
        dataValue read() override;
};

#endif // DISPLAY_HPP