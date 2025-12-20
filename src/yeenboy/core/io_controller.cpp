#include "yeenboy/core/io_controller.hpp"

#include <stdexcept>

u8 IOController::Read(size_t addr) const {
    (void)addr;
    throw std::runtime_error("IO controller read not implemented");
}

void IOController::Write(size_t addr, u8 val) {
    (void)addr;
    (void)val;
    throw std::runtime_error("IO Controller write not implemented");
}
