#include "register.hpp"

using namespace std;


Register::Register() {
    fifo = queue<double>();
}

Register::~Register() {
}

bool Register::isEmpty() {
    return fifo.empty();
}

double Register::read() {
    double value = fifo.front();
    fifo.pop();
    return value;
}

void Register::write(double value) {
    fifo.push(value);
}