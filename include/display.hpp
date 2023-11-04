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

/**
 * @brief class Display
 * 
 */
class Display : public Component {
    private : 
        int refresh_rate;
        int current_refresh;
    public : 
        Display(component_t type, string label, string src, int refresh_rate);
        ~Display();
        int getRefreshRate();
        dataValue read() override;
        void simulate() override;
        int test(string label, int tst_arg = 0) override;
};

#endif // DISPLAY_HPP