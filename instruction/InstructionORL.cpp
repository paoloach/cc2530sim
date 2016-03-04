//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"


template<>
void InstrTemp3<Instructions::ORL_DIRECT_A>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto newValue = address->getValue() | xdata.A->getValue();
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << " A("<<newValue<<") <-- A  | [" << address->getName() << "]";

}

//template<>
//void InstrTemp2<Instructions::DEC_ADDR>::execution() {
//    IP++;
//    uint8_t address = flashMemory[IP];
//    auto dest = xdata[address];
//    uint8_t val = dest->getValue();
//    val--;
//    dest->setValue(val);
//    IP++;
//    BOOST_LOG_TRIVIAL(debug) << "DEC [" << dest->getName() << "](" << val << ")";
//}
//
//template<>
//void InstrTemp2<Instructions::DEC_AT_Rn>::execution() {
//    uint16_t rbit = flashMemory[IP] & 0x01;
//    uint16_t Raddress = registryUtil.getRAddress(rbit);
//    IP++;
//    auto rn = xdata[Raddress];
//    uint8_t rVal = rn->getValue();
//    auto dest = xdata[rVal];
//    uint8_t val = dest->getValue();
//    val--;
//    dest->setValue(val);
//    BOOST_LOG_TRIVIAL(debug) << "DEC @R" << rbit << "[" << dest->getName() << "](" << val << ")";
//}
//
//template<>
//void InstrTemp1<Instructions::DEC_RN>::execution() {
//    uint16_t rbit = flashMemory[IP] & 0x01;
//    uint16_t Raddress = registryUtil.getRAddress(rbit);
//    auto dest = xdata[Raddress];
//    IP++;
//    uint8_t val = dest->getValue();
//    val--;
//    dest->setValue(val);
//    BOOST_LOG_TRIVIAL(debug) << "DEC R" << rbit << "(" << val << ")";
//}