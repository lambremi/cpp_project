#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <queue>

using namespace std;

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