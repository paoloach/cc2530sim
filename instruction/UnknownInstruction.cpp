//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <iostream>
#include "UnknownInstruction.h"

std::shared_ptr<Instruction> UnknownInstruction::cycle() {
    std::cerr << "unknown op " << std::hex << (int)OP << " at " << (int)IP << std::endl;
    return instructionFactory.decode(OP);
}
