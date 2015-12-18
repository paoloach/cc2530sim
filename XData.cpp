//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "XData.h"
#include "registers/DPL0.h"
#include "registers/DPH0.h"
#include "registers/Acc.h"
#include "registers/FMAP.h"

XData::XData() {
    for (int i = 0; i < 0x10000; i++) {
        data.push_back(std::make_shared<MemoryLocation>(i));
    }

    data[0x82] = std::make_shared<DPL0>();
    data[0x83] = std::make_shared<DPH0>();
    data[0xE0] = std::make_shared<Acc>();
    data[0x9F] = std::make_shared<FMAP>();
}
