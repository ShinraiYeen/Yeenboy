#pragma once

#include "yeenboy/common/types.hpp"

class Timer {
   public:
    Timer() = default;
    ~Timer() = default;

    void Tick(u32 m_cycles);

   private:
    void Test();
};