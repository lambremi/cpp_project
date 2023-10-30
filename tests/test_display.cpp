#include "display.hpp"
#include "cpu.hpp"

int main() {
    Cpu cpu(CPU, "source", "../data/basic_program.txt", 2, 3);
    Display disp(DISPLAY, "display", "source", 2);
    Component* source = &cpu;
    if (disp.getRefreshRate() != 2) {
        cout << "Error: Expected display to have refresh rate 2\n" << endl;
        return 1;
    }
    disp.setSource(&cpu);
    disp.getSource(source);
    if (source->getType() != CPU) {
        cout << "Error: Expected display to have cpu as source\n" << endl;
        return 1;
    }
    cpu.simulate();
    disp.simulate();
    return 0;
}