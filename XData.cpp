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
#include "registers/P0IFC.h"
#include "registers/P0DIR.h"
#include "registers/P0SEL.h"
#include "registers/P0IEN.h"
#include "registers/P0INP.h"
#include "registers/P1.h"
#include "registers/P1IFG.h"
#include "registers/P1DIR.h"
#include "registers/P1SEL.h"
#include "registers/P1IEN.h"
#include "registers/P1INP.h"
#include "registers/P2.h"
#include "registers/P2IFG.h"
#include "registers/P2DIR.h"
#include "registers/P2SEL.h"
#include "registers/P2IEN.h"
#include "registers/P2INP.h"
#include "registers/PICTL.h"
#include "registers/PMUX.h"
#include "registers/PERCFG.h"
#include "registers/APCFG.h"
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
#include "registers/DMA0CFGH.h"
#include "registers/DMA0CFGL.h"
#include "registers/DMA1CFGH.h"
#include "registers/DMA1CFGL.h"
#include "registers/DMAARM.h"
#include "registers/DMAIRQ.h"
#include "registers/DMAREQ.h"

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
    data[0x89] = std::make_shared<P0IFG>();
    data[0x8A] = std::make_shared<P1IFG>();
    data[0x8B] = std::make_shared<P2IFG>();
    data[0x8C] = std::make_shared<PICTL>();
    data[0x8D] = std::make_shared<P1IEN>();
    data[0x8F] = std::make_shared<P0INP>();
    data[0x90] = std::make_shared<P1>();
    data[0x92] = std::make_shared<DPS>();
    data[0x98] = std::make_shared<S0CON>();
    data[0x9A] = std::make_shared<IEN2>();
    data[0x9B] = std::make_shared<S1CON>();
    data[0x9F] = std::make_shared<FMAP>();
    data[0xA0] = std::make_shared<P2>();
    data[0xA8] = std::make_shared<IEN0>();
    data[0xA9] = std::make_shared<IP0>();
    data[0xAB] = std::make_shared<P0IEN>();
    data[0xAC] = std::make_shared<P2IEN>();
    data[0xAE] = std::make_shared<PMUX>();
    data[0xB1] = std::make_shared<ENCDI>();
    data[0xB2] = std::make_shared<ENCDO>();
    data[0xB3] = std::make_shared<ENCCS>();
    data[0xB4] = std::make_shared<ADCCON1>();
    data[0xB5] = std::make_shared<ADCCON2>();
    data[0xB6] = std::make_shared<ADCCON3>();
    data[0xB8] = std::make_shared<IEN1>();
    data[0xB9] = std::make_shared<IP1>();
    data[0xBA] = std::make_shared<ADCL>();
    data[0xBB] = std::make_shared<ADCH>();
    data[0xBC] = std::make_shared<RNDL>();
    data[0xBD] = std::make_shared<RNDH>();

    data[0xC0] = std::make_shared<IRCON>();

    data[0xE0] = std::make_shared<Acc>();
    data[0xE8] = std::make_shared<IRCON2>();
    data[0xF0] = std::make_shared<B>();

    data[static_cast<uint16_t>(Register::T1STAT)] = std::make_shared<T1STAT>();
    data[0xD0] = std::make_shared<PSW>();
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

    data[0xD1] = std::make_shared<DMAIRQ>();
    data[0xD2] = std::make_shared<DMA1CFGL>();
    data[0xD3] = std::make_shared<DMA1CFGH>();
    data[0xD4] = std::make_shared<DMA0CFGL>();
    data[0xD5] = std::make_shared<DMA0CFGH>();
    data[0xD6] = std::make_shared<DMAARM>();
    data[0xD7] = std::make_shared<DMAREQ>();

    data[0xF1] = std::make_shared<PERCFG>();
    data[0xF2] = std::make_shared<APCFG>();
    data[0xF3] = std::make_shared<P0SEL>();
    data[0xF4] = std::make_shared<P1SEL>();
    data[0xF5] = std::make_shared<P2SEL>();
    data[0xF6] = std::make_shared<P1INP>();
    data[0xF7] = std::make_shared<P2INP>();
    data[0xFD] = std::make_shared<P0DIR>();
    data[0xFE] = std::make_shared<P1DIR>();
    data[0xFF] = std::make_shared<P2DIR>();



}
