//
// Created by developer on 1/14/16.
//
#include <boost/log/trivial.hpp>
#include <stdint.h>
#include "Instruction.h"


template<>
void InstrTemp3<Instructions::AJMP>::execution() {
    uint16_t hiBits = flashMemory[IP];
    hiBits = (hiBits & 0xE0) << 3;
    IP++;
    uint16_t loBits = flashMemory[IP];
    auto newAddress = hiBits | loBits;
    IP.set(newAddress);
    BOOST_LOG_TRIVIAL(debug) << "AJMP to IP";
}

template<>
void InstrTemp6<Instructions::ACALL>::execution() {
    uint16_t hiBits = flashMemory[IP];
    hiBits = (hiBits & 0xE0) << 3;
    IP++;
    uint16_t loBits = flashMemory[IP];
    auto newAddress = hiBits | loBits;
    IP++;
    auto oldAddress = IP.getValue();
    uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
    spAddress++;
    xdata[spAddress]->setValue(IP.getLowByte());
    spAddress++;
    xdata[spAddress]->setValue(IP.getHiByte());
    xdata[Register::SP]->setValue(spAddress);
    IP.set(newAddress);
    BOOST_LOG_TRIVIAL(debug) << "ACALL to address " << newAddress << " (old address was " << oldAddress << ")";
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LJMP>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << IP << "  ";
        cycleCounter = 3;
        IP++;
        IP.set(flashMemory[IP] * 256 + flashMemory[IP + 1]);
        BOOST_LOG_TRIVIAL(debug) << "LJMP (at " << IP << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::JMP_A_DPTR>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        BOOST_LOG_TRIVIAL(debug) << IP << "  ";
        cycleCounter = 2;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue().getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue().getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A]->getValue();
        IP.set(dp + regA.getValue());
        BOOST_LOG_TRIVIAL(debug) << "JMP @A+DTR (at " << IP << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LCALL>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 6;
        IP++;
        InstructionPointer newAddress;
        newAddress.setHighByte(flashMemory[IP]);
        IP++;
        newAddress.setLowByte(flashMemory[IP]);
        IP++;
        InstructionPointer oldAddress = IP;
        uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
        spAddress++;
        xdata[spAddress]->setValue(IP.getLowByte());
        spAddress++;
        xdata[spAddress]->setValue(IP.getHiByte());
        xdata[Register::SP]->setValue(spAddress);
        IP = newAddress;
        BOOST_LOG_TRIVIAL(debug) << "LCALL to address " << newAddress << " (old address was " << oldAddress << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
void InstrTemp4<Instructions::RET>::execution() {
    uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
    uint32_t hiIP = xdata[spAddress]->getValue().getValue();
    spAddress--;
    uint32_t lowIP = xdata[spAddress]->getValue().getValue();
    spAddress--;
    xdata[Register::SP]->setValue(spAddress);

    IP.set((hiIP << 8) | lowIP);

    BOOST_LOG_TRIVIAL(debug) << "RET to address " << IP;
}

template<>
void InstrTemp4<Instructions::RETI>::execution() {
    uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
    uint32_t hiIP = xdata[spAddress]->getValue().getValue();
    spAddress--;
    uint32_t lowIP = xdata[spAddress]->getValue().getValue();
    spAddress--;
    xdata[Register::SP]->setValue(spAddress);

    IP.set((hiIP << 8) | lowIP);

    BOOST_LOG_TRIVIAL(debug) << "RET to address " << IP;
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CJNE_RN_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 4;
        uint16_t rAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        if (xdata[rAddress]->getValue().getValue() != data) {
            IP = IP + relAddr;
        }
        if (xdata[rAddress]->getValue().getValue() < data) {
            xdata[Register::PSW]->setBit(7, true);
        } else {
            xdata[Register::PSW]->setBit(7, false);
        }

        BOOST_LOG_TRIVIAL(debug) << "CJNE R" << (rAddress & 0x7) << ", " << (uint) data << ", " << (int) relAddr;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::DJNZ_RN>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 3;
        uint16_t regAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        auto rn = xdata[regAddress]->getValue();
        rn--;
        xdata[regAddress]->setValue(rn);
        if (rn.getValue() != 0) {
            IP += relAddr;
        }

        BOOST_LOG_TRIVIAL(debug) << "DJNZ R" << (regAddress & 0x7) << "," << (int) relAddr;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::SJMP>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 3;
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        IP += relAddr;

        BOOST_LOG_TRIVIAL(debug) << "SJMP AT " << IP;
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
void InstrTemp4<Instructions::JB>::execution() {
    IP++;
    auto bitAddress = flashMemory[IP];
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(bitAddress);
    auto xAddress = xdata[address];
    IP++;
    int8_t relAddr = flashMemory[IP];
    IP++;
    auto destIP = IP + relAddr;
    if (xAddress->getBit(bit)) {
        IP = destIP;
    }
    BOOST_LOG_TRIVIAL(debug) << "JB [" << xAddress->getName() << "], bit " << bit << " " << destIP;
}

template<>
void InstrTemp4<Instructions::JNB>::execution() {
    IP++;
    auto bitAddress = flashMemory[IP];
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(bitAddress);
    auto xAddress = xdata[address];
    IP++;
    int8_t relAddr = flashMemory[IP];
    IP++;
    auto destIP = IP + relAddr;
    if (!xAddress->getBit(bit)) {
        IP = destIP;
    }
    BOOST_LOG_TRIVIAL(debug) << "JNB [" << xAddress->getName() << "], bit " << bit << " " << destIP;
}

template<>
void InstrTemp4<Instructions::JBC>::execution() {
    IP++;
    auto bitAddress = flashMemory[IP];
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(bitAddress);
    auto xAddress = xdata[address];
    IP++;
    int8_t relAddr = flashMemory[IP];
    IP++;
    auto destIP = IP + relAddr;
    if (xAddress->getBit(bit)) {
        xAddress->setBit(bit, false);
        IP = destIP;
    }
    BOOST_LOG_TRIVIAL(debug) << "JBC [" << xAddress->getName() << "], bit " << bit << " " << destIP;
}

template<>
void InstrTemp3<Instructions::JC>::execution() {
    IP++;
    uint8_t rel_addr = flashMemory[IP];
    IP++;
    uint16_t ipVal = IP.getValue();
    if (rel_addr & 0x80) {
        rel_addr = (~rel_addr) + 1;
        ipVal -= rel_addr;
    } else {
        ipVal += rel_addr;
    }
    bool carry = xdata.status->getBit(7);
    if (carry) {
        IP.set(ipVal);
    }
    BOOST_LOG_TRIVIAL(debug) << "JC(C=" << carry << ") " << IP;
}

template<>
void InstrTemp3<Instructions::JNC>::execution() {
    IP++;
    uint8_t rel_addr = flashMemory[IP];
    IP++;
    uint16_t ipVal = IP.getValue();
    if (rel_addr & 0x80) {
        rel_addr = (~rel_addr) + 1;
        ipVal -= rel_addr;
    } else {
        ipVal += rel_addr;
    }
    bool carry = xdata.status->getBit(7);
    if (!carry) {
        IP.set(ipVal);
    }
    BOOST_LOG_TRIVIAL(debug) << "JNC(C=" << carry << ") " << IP;
}

template<>
void InstrTemp3<Instructions::JZ>::execution() {
    IP++;
    uint8_t rel_addr = flashMemory[IP];
    IP++;
    bool z = xdata.A->getValue().getValue() == 0;

    uint16_t ipVal = IP.getValue();
    if (rel_addr & 0x80) {
        rel_addr = (~rel_addr) + 1;
        ipVal -= rel_addr;
    } else {
        ipVal += rel_addr;
    }
    if (z) {
        IP.set(ipVal);
    }
    BOOST_LOG_TRIVIAL(debug) << "JZ(z=" << z << ") " << IP;
}

template<>
void InstrTemp3<Instructions::JNZ>::execution() {
    IP++;
    uint8_t rel_addr = flashMemory[IP];
    IP++;
    bool z = xdata.A->getValue().getValue() == 0;

    uint16_t ipVal = IP.getValue();
    if (rel_addr & 0x80) {
        rel_addr = (~rel_addr) + 1;
        ipVal -= rel_addr;
    } else {
        ipVal += rel_addr;
    }
    if (!z) {
        IP.set(ipVal);
    }
    BOOST_LOG_TRIVIAL(debug) << "JNZ(z=" << z << ") " << IP;
}