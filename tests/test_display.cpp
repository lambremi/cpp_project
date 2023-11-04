#include "display.hpp"
#include "cpu.hpp"

int main() {
    Display disp(DISPLAY, "display", "source", 2);

    return disp.test("display", 2);
}