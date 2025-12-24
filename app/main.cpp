#include <SDL2/SDL.h>

#include <cstdio>
#include <cstdlib>

#include "yeenboy/yeenboy.hpp"

namespace {
void PrintUsage(char* command) { printf("Usage: %s <rom_file>\n", command); }
}  // namespace

int main(int argc, char** argv) {
    if (argc != 2) {
        PrintUsage(argv[0]);
        return EXIT_FAILURE;
    }

    Yeenboy yeenboy(argv[1]);
    yeenboy.Init();

    return EXIT_SUCCESS;
}