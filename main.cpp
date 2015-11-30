#include <iostream>
#include <fstream>
#include "FlashMemory.h"
#include "CPU.h"

using namespace std;

int main(int argc, char *argv[]) {
    FlashMemory flashMemory;


    if (argc != 2){
        std::cerr << " you must add the filename: " << argc;
        exit(-1);
    }
    std::cout << "loading " << argv[1] << std::endl;
    std::ifstream hexFile(argv[1]);

    flashMemory.loafFromString(hexFile);

    CPU cpu(flashMemory);
    cpu.reset();

    while(true) {
        cpu.click();
    }
    return 0;
}