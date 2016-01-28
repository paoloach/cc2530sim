//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"

//template<>
//void InstrTemp1<Instructions::DEC_DPTR>::execution() {
//    IP++;
//    uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
//    uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
//    uint16_t dp = (dph << 8) | dpl;
//    dp--;
//    xdata[registryUtil.getDPH()]->setValue((dp & 0xFF00) >> 8);
//    xdata[registryUtil.getDPL()]->setValue(dp & 0xFF);
//    BOOST_LOG_TRIVIAL(debug) << "DEC DPTR (dptr=" << dp << ")";
//}


template<>
void InstrTemp1<Instructions::DEC_A>::execution() {
    IP++;
    uint8_t a = xdata[Register::A]->getValue();
    a--;
    xdata[Register::A]->setValue(a);
    BOOST_LOG_TRIVIAL(debug) << "DEC A(" << a << ")";
}

template<>
void InstrTemp2<Instructions::DEC_ADDR>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    auto dest = xdata[address];
    uint8_t val = dest->getValue();
    val--;
    dest->setValue(val);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "DEC [" << dest->getName() << "](" << val << ")";
}

template<>
void InstrTemp2<Instructions::DEC_AT_Rn>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    uint8_t rVal = rn->getValue();
    auto dest = xdata[rVal];
    uint8_t val = dest->getValue();
    val--;
    dest->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "DEC @R" << rbit << "[" << dest->getName() << "](" << val << ")";
}

template<>
void InstrTemp1<Instructions::DEC_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto dest = xdata[Raddress];
    IP++;
    uint8_t val = dest->getValue();
    val--;
    dest->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "DEC R" << rbit << "(" << val << ")";
}