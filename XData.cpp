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
#include "registers/T1CC0L.h"
#include "registers/T1CC0H.h"
#include "registers/T1CC1L.h"
#include "registers/T1CC1H.h"
#include "registers/T1CC2L.h"
#include "registers/T1CC2H.h"
#include "registers/T1CNTH.h"
#include "registers/T1CNTL.h"
#include "registers/T1CTL.h"
#include "registers/T1CCTL0.h"
#include "registers/T1CCTL1.h"
#include "registers/T1CCTL2.h"
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
#include "registers/MPAGE.h"
#include "registers/RFD.h"
#include "registers/RFERRF.h"
#include "registers/RFIRQF0.h"
#include "registers/RFIRQF1.h"
#include "registers/RFST.h"
#include "registers/ST0.h"
#include "registers/ST1.h"
#include "registers/ST2.h"
#include "registers/STLOAD.h"
#include "registers/SLEEPCMD.h"
#include "registers/SLEEPSTA.h"
#include "registers/CLKCONCMD.h"
#include "registers/CLKCONSTA.h"

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
    data[0x91] = std::make_shared<RFIRQF1>();
    data[0x92] = std::make_shared<DPS>();
    data[0x93] = std::make_shared<MPAGE>();
    data[0x95] = std::make_shared<ST0>();
    data[0x96] = std::make_shared<ST1>();
    data[0x97] = std::make_shared<ST2>();
    data[0x98] = std::make_shared<S0CON>();
    data[0x9A] = std::make_shared<IEN2>();
    data[0x9B] = std::make_shared<S1CON>();
    data[0x9D] = std::make_shared<SLEEPSTA>();
    data[0x9E] = std::make_shared<CLKCONSTA>();
    data[0x9F] = std::make_shared<FMAP>();

    data[0xA0] = std::make_shared<P2>();
    data[0xA8] = std::make_shared<IEN0>();
    data[0xA9] = std::make_shared<IP0>();
    data[0xAB] = std::make_shared<P0IEN>();
    data[0xAC] = std::make_shared<P2IEN>();
    data[0xAD] = std::make_shared<STLOAD>();
    data[0xAE] = std::make_shared<PMUX>();
    data[0xAF] = std::make_shared<T1STAT>();

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
    data[0xBE] = std::make_shared<SLEEPCMD>();
    data[0xBF] = std::make_shared<RFERRF>();

    data[0xC0] = std::make_shared<IRCON>();
    data[0xC6] = std::make_shared<CLKCONCMD>();
    data[0xC7] = std::make_shared<MEMCTR>();

    data[0xD0] = std::make_shared<PSW>();
    data[0xD1] = std::make_shared<DMAIRQ>();
    data[0xD2] = std::make_shared<DMA1CFGL>();
    data[0xD3] = std::make_shared<DMA1CFGH>();
    data[0xD4] = std::make_shared<DMA0CFGL>();
    data[0xD5] = std::make_shared<DMA0CFGH>();
    data[0xD6] = std::make_shared<DMAARM>();
    data[0xD7] = std::make_shared<DMAREQ>();
    data[0xD9] = std::make_shared<RFD>();
    data[0xDA] = std::make_shared<T1CC0L>();
    data[0xDB] = std::make_shared<T1CC0H>();
    data[0xDC] = std::make_shared<T1CC1L>();
    data[0xDD] = std::make_shared<T1CC1H>();
    data[0xDE] = std::make_shared<T1CC2L>();
    data[0xDF] = std::make_shared<T1CC2H>();

    data[0xE0] = std::make_shared<Acc>();
    data[0xE1] = std::make_shared<RFST>();
    data[0xE2] = std::make_shared<T1CNTL>();
    data[0xE3] = std::make_shared<T1CNTH>();
    data[0xE4] = std::make_shared<T1CTL>();
    data[0xE5] = std::make_shared<T1CCTL0>();
    data[0xE6] = std::make_shared<T1CCTL1>();
    data[0xE7] = std::make_shared<T1CCTL2>();

    data[0xE8] = std::make_shared<IRCON2>();
    data[0xE9] = std::make_shared<RFIRQF0>();

    data[0xF0] = std::make_shared<B>();
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
