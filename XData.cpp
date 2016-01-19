//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "XData.h"
#include "registers/DPL0.h"
#include "registers/DPH0.h"
#include "registers/Acc.h"
#include "registers/FMAP.h"
#include "registers/SP.h"
#include "registers/P0.h"
#include "registers/P1.h"
#include "registers/P2.h"
#include "registers/TCON.h"
#include "registers/S0CON.h"
#include "registers/IEN0.h"
#include "registers/IEN1.h"
#include "registers/T1STAT.h"

XData::XData() {
    for (int i = 0; i < 0x10000; i++) {
        data.push_back(std::make_shared<MemoryLocation>(i));
    }

    data[static_cast<uint16_t>(Register::P0)] = std::make_shared<P0>();
    data[0x82] = std::make_shared<DPL0>();
    data[0x83] = std::make_shared<DPH0>();
    data[static_cast<uint16_t>(Register::SP)] = std::make_shared<SP>();
    data[static_cast<uint16_t>(Register::P1)] = std::make_shared<P1>();
    data[static_cast<uint16_t>(Register::TCON)] = std::make_shared<TCON>();
    data[static_cast<uint16_t>(Register::S0CON)] = std::make_shared<S0CON>();
    data[static_cast<uint16_t>(Register::P2)] = std::make_shared<P2>();
    data[static_cast<uint16_t>(Register::IEN0)] = std::make_shared<IEN0>();
    data[static_cast<uint16_t>(Register::IEN1)] = std::make_shared<IEN1>();
    data[static_cast<uint16_t>(Register::T1STAT)] = std::make_shared<T1STAT>();
    data[0xE0] = std::make_shared<Acc>();
    data[0x9F] = std::make_shared<FMAP>();
}
