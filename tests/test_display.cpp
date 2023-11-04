#include "display.hpp"
#include "cpu.hpp"

int main() {
    Display disp(DISPLAY, "source", 2);

    return disp.test("display", 2);
}