#include <SDL2/SDL.h>

#include <cstdio>
#include <cstdlib>

void PrintUsage(char *command) { printf("Usage: %s <rom_file>\n", command); }

int main(int argc, char **argv) {
    if (argc != 2) {
        PrintUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}