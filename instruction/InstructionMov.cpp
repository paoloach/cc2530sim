//
// Created by developer on 1/15/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"

template<>
void  InstrTemp4<Instructions::MOV_DIRECT_DIRECT>::execution() {
    IP++;
    auto addressSrc = xdata[flashMemory[IP]];
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "MOV [" << addressDest->getName() << "](" << value << ") <-- [" <<
                             addressSrc->getName() << "]";
}

template<>
void InstrTemp3<Instructions::MOV_DIRECT_AT_R>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto addressSrc = xdata[rVal];
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "MOV [" << addressDest->getName() << "](" << value << ") <-- @R" <<
                             rbit << " [" << addressSrc->getName() << "]";
}

template<>
void InstrTemp3<Instructions::MOV_DIRECT_RN>::execution() {
    uint8_t data = flashMemory[IP];
    uint16_t reg = data & 0x07;
    uint16_t Raddress = registryUtil.getRAddress(data);
    auto addressSrc = xdata[Raddress];
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "MOV [" << addressDest->getName() << "](" << value << ") <-- R" << reg;
}


template<>
void InstrTemp2<Instructions::MOV_A_DIRECT>::execution() {
    IP++;
    auto address = flashMemory[IP];
    auto data = xdata[address]->getValue();
    xdata.A->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" << data << ") <-- [" << xdata[address]->getName() << "]";
}

template<>
void InstrTemp2<Instructions::MOV_A_AT_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto xMem = xdata[rVal];
    auto data = xMem->getValue();
    xdata[Register::A]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" << data << ") <-- @R" << rbit << "[" << xMem->getName() << "]";
}


template<>
void InstrTemp1<Instructions::MOV_A_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x07;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto rn = xdata[Raddress];
    IP++;
    auto data = rn->getValue();
    xdata[Register::A]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" << data << ") <-- R" << rbit;
}

template<>
void InstrTemp2<Instructions::MOV_DIRECT_A>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    auto dest = xdata[address];
    auto data = xdata.A->getValue();
    dest->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV [" << dest->getName() << "](" << data << ") <-- A";
}

template<>
void InstrTemp2<Instructions::MOV_AT_RN_A>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto dest = xdata[rVal];
    auto data = xdata.A->getValue();
    dest->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV @R" << rbit << "[" << dest->getName() << "](" << data << ") <-- A";
}

template<>
void InstrTemp1<Instructions::MOV_RN_A>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x07;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto dest = xdata[Raddress];
    IP++;
    auto data = xdata.A->getValue();
    dest->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV R" << rbit << "(" << data << ") <-- A";
}


template<>
void InstrTemp5<Instructions::MOV_AT_R_DIRECT>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto addressDest = xdata[rVal];
    IP++;
    auto addressSrc = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "MOV  @R" <<
                             rbit << " [" << addressSrc->getName() << "] <-- [" << addressDest->getName() << "](" <<
                             value << ") ";
}

template<>
void InstrTemp4<Instructions::MOV_RN_DIRECT>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto address = flashMemory[IP];
    auto data = xdata[address]->getValue();
    xdata[Raddress]->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV R" << (Raddress & 0x7) << "(" << data << ") <--  [" << xdata[address]->getName() << "]";
}

template<>
void InstrTemp2<Instructions::MOV_RN_DATA>::execution() {
    uint16_t address = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    uint8_t data = flashMemory[IP];
    xdata[address]->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV R" << (address & 0x7) << " <--  " << (uint) data;
}

template<>
void InstrTemp3<Instructions::MOV_AT_R0_DATA>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    uint8_t data = flashMemory[IP];
    auto rn = xdata[Raddress];
    rn->setValue(Data8(data));
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV @R" << rbit << "[" << rn->getName() << "] <-- " << data;
}


template<>
void InstrTemp3<Instructions::MOV_A_AT_A_PC>::execution() {
    IP++;
    uint16_t data = flashMemory[IP];
    uint16_t address = xdata.A->getValue().getSignedValue() + data;
    auto xMem = flashMemory[address];
    xdata.A->setValue(xMem);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(" << xMem << ") <-- @A+PC(" << address << ")";
}

template<>
void InstrTemp3<Instructions::MOVC_A_DPTR>::execution() {
    IP++;
    auto dph = xdata[registryUtil.getDPH()]->getValue();
    auto dpl = xdata[registryUtil.getDPL()]->getValue();
    uint16_t dp = ((uint16_t) dph.getValue() << 8) | dpl.getValue();
    auto aValue = xdata.A->getValue();
    uint8_t val = flashMemory[dp + aValue.getSignedValue()];
    xdata.A->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "MOVC A(=" << val << ") ,@A+DPTR (dptr=" << dp << ", A = " << aValue << ")";
}

template<>
void InstrTemp2<Instructions::MOV_C_BIT_ADDR>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    bool bitValue = xAddress->getBit(bit.getValue());
    xdata.status->setBit(7, bitValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV C <--  bit " << bit << " of [" << xAddress->getName() << "]";
}

template<>
void InstrTemp3<Instructions::MOV_BIT_ADDR_C>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    bool bitValue = xdata.status->getBit(7);
    xAddress->setBit(bit.getValue(), bitValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV bit " << bit << " of [" << xAddress->getName() << "] --> C";
}

template<>
void InstrTemp3<Instructions::MOVX_AT_DPTR_A>::execution() {
    IP++;
    auto dph = xdata[registryUtil.getDPH()]->getValue();
    auto dpl = xdata[registryUtil.getDPL()]->getValue();
    uint16_t dp = (((uint16_t) (dph.getValue())) << 8) | dpl.getValue();
    xdata.A->setValue(0);
    BOOST_LOG_TRIVIAL(warning) << "MOVX @DPTR (dptr=" << dp << "), A (not implem,emted)";
}

template<>
void InstrTemp3<Instructions::MOVX_A_AT_R>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    IP++;
    xdata.A->setValue(0);
    BOOST_LOG_TRIVIAL(warning) << "MOVX A,@R" << rbit << " (not implemented)";
}

template<>
void InstrTemp3<Instructions::MOVX_A_AT_DPTR>::execution() {
    IP++;
    auto dph = xdata[registryUtil.getDPH()]->getValue();
    auto dpl = xdata[registryUtil.getDPL()]->getValue();
    uint16_t dp = (((uint16_t) (dph.getValue())) << 8) | dpl.getValue();
    xdata.A->setValue(0);
    BOOST_LOG_TRIVIAL(warning) << "MOVX A, @DPTR (dptr=" << dp << ") (not implem,emted)";
}

template<>
void InstrTemp3<Instructions::MOVX_AT_R_A>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    IP++;
    xdata.A->setValue(0);
    BOOST_LOG_TRIVIAL(warning) << "MOVX @R" << rbit << ",A (not implemented)";
}