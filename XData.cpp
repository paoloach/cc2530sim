//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "XData.h"

XData::XData() {
    for (int i = 0; i < 0x10000; i++) {
        data.push_back(std::make_shared<MemoryLocation>());
    }
}
