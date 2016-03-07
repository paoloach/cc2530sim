//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"

template<>
void InstrTemp1<Instructions::INC_DPTR>::execution() {
    IP++;
    uint16_t dph = xdata[registryUtil.getDPH()]->getValue().getValue();
    uint16_t dpl = xdata[registryUtil.getDPL()]->getValue().getValue();
    uint16_t dp = (dph << 8) | dpl;
    dp++;
    xdata[registryUtil.getDPH()]->setValue((dp & 0xFF00) >> 8);
    xdata[registryUtil.getDPL()]->setValue(dp & 0xFF);
    BOOST_LOG_TRIVIAL(debug) << "INC DPTR (dptr=" << dp << ")";
}


template<>
void InstrTemp1<Instructions::INC_A>::execution() {
    IP++;
    auto a = xdata.A->getValue();
    a++;
    xdata.A->setValue(a);
    BOOST_LOG_TRIVIAL(debug) << "INC A(" << a << ")";
}

template<>
void InstrTemp2<Instructions::INC_ADDR>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    auto dest = xdata[address];
    auto val = dest->getValue();
    val++;
    dest->setValue(val);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "INC [" << dest->getName() << "](" << val << ")";
}

template<>
void InstrTemp2<Instructions::INC_AT_Rn>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto dest = xdata[rVal];
    auto val = dest->getValue();
    val++;
    dest->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "INC @R" << rbit << "[" << dest->getName() << "](" << val << ")";
}

template<>
void InstrTemp1<Instructions::INC_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto dest = xdata[Raddress];
    IP++;
    auto val = dest->getValue();
    val++;
    dest->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "INC R" << rbit << "(" << val << ")";
}