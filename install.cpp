//
// Created by Lukáš Kaplánek on 19.12.2024.
//

#include <cstdlib>
#ifdef _WIN32

#else
int main() {
    system("mkdir KLib");
    system("cp ./libKLib.a ./KLib");
    system("cp ../readme.md ./KLib");
    system("cp ../library.h ./KLib");
    return 0;
}

#endif

