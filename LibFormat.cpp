//
// Created by Lukáš Kaplánek on 19.12.2024.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
int main() {
    system("mkdir KLib");
    system("copy ..\\library.cpp KLib\\");
    system("copy ..\\readme.md KLib\\");
    system("copy ..\\library.h KLib\\");
    std::cout << "Files ready located a: build/KLib foulder"<< std::endl;
    return 0;
}
#else
int main() {
    system("mkdir KLib");
    system("cp ../library.cpp ./KLib");
    system("cp ../readme.md ./KLib");
    system("cp ../library.h ./KLib");
    std::cout << "Files ready located a: build/KLib foulder"<< std::endl;
    return 0;
}

#endif

