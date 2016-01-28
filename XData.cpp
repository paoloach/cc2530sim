//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "XData.h"
#include "registers/DPL0.h"
#include "registers/DPH0.h"
#include "registers/DPL1.h"
#include "registers/DPH1.h"
#include "registers/Acc.h"
#include "registers/B.h"
#include "registers/FMAP.h"
#include "registers/SP.h"
#include "registers/P0.h"
#include "registers/P1.h"
#include "registers/P2.h"
#include "registers/TCON.h"
#include "registers/S0CON.h"
#include "registers/S1CON.h"
#include "registers/IEN0.h"
#include "registers/IEN1.h"
#include "registers/IEN2.h"
#include "registers/T1STAT.h"
#include "registers/MEMCTR.h"
#include "registers/ADCCON1.h"
#include "registers/ADCCON2.h"
#include "registers/ADCCON3.h"
#include "registers/ADCL.h"
#include "registers/ADCH.h"
#include "registers/RNDL.h"
#include "registers/RNDH.h"
#include "registers/ENCDI.h"
#include "registers/ENCDO.h"
#include "registers/ENCCS.h"
#include "registers/PCON.h"
#include "registers/DPS.h"
#include "registers/IP0.h"
#include "registers/IP1.h"
#include "registers/IRCON.h"
#include "registers/PSW.h"
#include "registers/IRCON2.h"

XData::XData() {
    for (int i = 0; i < 0x10000; i++) {
        data.push_back(std::make_shared<MemoryLocation>(i));
    }

    data[0x80] = std::make_shared<P0>();
    data[0x81] = std::make_shared<SP>();
    data[0x82] = std::make_shared<DPL0>();
    data[0x83] = std::make_shared<DPH0>();
    data[0x84] = std::make_shared<DPL1>();
    data[0x85] = std::make_shared<DPH1>();
    data[0x86] = std::make_shared<PCON>();
    data[0x88] = std::make_shared<TCON>();
    data[0x90] = std::make_shared<P1>();
    data[0x92] = std::make_shared<DPS>();
    data[0x98] = std::make_shared<S0CON>();
    data[0x9A] = std::make_shared<IEN2>();
    data[0x9B] = std::make_shared<S1CON>();
    data[0xA0] = std::make_shared<P2>();
    data[0xA8] = std::make_shared<IEN0>();
    data[0xA9] = std::make_shared<IP0>();
    data[0xB8] = std::make_shared<IEN1>();
    data[0xB9] = std::make_shared<IP1>();
    data[0xC0] = std::make_shared<IRCON>();
    data[0xD0] = std::make_shared<PSW>();
    data[0xE0] = std::make_shared<Acc>();
    data[0xE8] = std::make_shared<IRCON2>();
    data[0xF0] = std::make_shared<B>();

    data[static_cast<uint16_t>(Register::T1STAT)] = std::make_shared<T1STAT>();

    data[0xB1] = std::make_shared<ENCDI>();
    data[0xB2] = std::make_shared<ENCDO>();
    data[0xB3] = std::make_shared<ENCCS>();
    data[0xB4] = std::make_shared<ADCCON1>();
    data[0xB5] = std::make_shared<ADCCON2>();
    data[0xB6] = std::make_shared<ADCCON3>();
    data[0xBA] = std::make_shared<ADCL>();
    data[0xBB] = std::make_shared<ADCH>();
    data[0xBC] = std::make_shared<RNDL>();
    data[0xBD] = std::make_shared<RNDH>();

    data[0xC7] = std::make_shared<MEMCTR>();
    data[0x9F] = std::make_shared<FMAP>();
}
