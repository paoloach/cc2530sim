//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <iostream>
#include "UnknownInstruction.h"
#include <iomanip>

std::shared_ptr<Instruction> UnknownInstruction::cycle() {
    std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at 0x" <<std::setw(4) << (int)IP << std::endl;
    exit(-1);
    return instructionFactory.decode(OP);
}
