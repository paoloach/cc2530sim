//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"
class OP {
public:
    virtual const char * getOp() const = 0;
    virtual Data8 apply(Data8 a, Data8 b) const =0;
};

class AndOp : public OP {
    virtual const char * getOp()const  {return  "and";}
    virtual Data8 apply(Data8 a, Data8 b) const {return a & b;}
};

class OrOp : public OP {
    virtual const char * getOp() const {return  "or";}
    virtual Data8 apply(Data8 a, Data8 b) const {return a | b;};
};

class XorOp : public OP {
    virtual const char * getOp() const {return  "xor";}
    virtual Data8 apply(Data8 a, Data8 b) const{return a^b;}
};

AndOp andOp;
OrOp  orOp;
XorOp xorOp;

const OP * getOp(uint8_t data){
    if (data & 0xF0 == 0x050){
        return &andOp;
    }
    if (data & 0xF0 == 0x040){
        return &orOp;
    }

    if (data & 0xF0 == 0x060){
        return &xorOp;
    }
}

template<>
void InstrTemp3<Instructions::ORL_AND_DIRECT_A>::execution() {
    auto op = getOp(flashMemory[IP]);
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto newValue = op->apply(address->getValue(), xdata.A->getValue());
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- A " << op->getOp() <<" [" << address->getName() << "]";
}


template<>
void InstrTemp4<Instructions::ORL_AND_DIRECT_DATA>::execution() {
    auto op = getOp(flashMemory[IP]);
    IP++;
    auto address = xdata[flashMemory[IP]];
    IP++;
    Data8 data = flashMemory[IP];
    IP++;
    auto newValue = op->apply(address->getValue(), data);
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- " << op->getOp() <<" [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_DATA>::execution() {
    auto op = getOp(flashMemory[IP]);
    IP++;
    Data8 data(flashMemory[IP]);
    auto REG_A = xdata.A->getValue();
    auto newValue = op->apply(data, REG_A);
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  " << op->getOp() << " " << data;
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_DIRECT>::execution() {
    auto op = getOp(flashMemory[IP]);
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto newValue = op->apply(address->getValue(), xdata.A->getValue());
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A "<< op->getOp() <<" [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_AT_R0>::execution() {
    auto op = getOp(flashMemory[IP]);
    uint16_t RAddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[RAddress];
    auto rVal = rn->getValue();
    auto address = xdata[rVal];
    auto newValue = op->apply(address->getValue(), xdata.A->getValue());
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A "<< op->getOp() <<" @R" << RAddress << "([" << address->getName() << "])";
}

template<>
void InstrTemp1<Instructions::ORL_AND_A_RN>::execution() {
    auto op = getOp(flashMemory[IP]);
    int opcode = flashMemory[IP] & 0x07;
    uint16_t RAddress = registryUtil.getRAddress(opcode);
    IP++;
    auto rn = xdata[RAddress];
    auto newValue = op->apply(rn->getValue(), xdata.A->getValue());
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  "<< op->getOp() <<" R" << opcode;
}