//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "Nop.h"

std::shared_ptr<Instruction> Nop::cycle() {
    IP++;
    return instructionFactory.decode(flashMemory[IP]);
}


