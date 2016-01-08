//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <stdint.h>
#include "Instruction.h"
#include "InstructionFactory.h"
#include "Instructions.h"


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::NOP>::cycle() {
    IP++;
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[Register::A]->setValue(data);
        std::cout << "move A <-- 0x" <<   std::setw(2) <<(uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DATA_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint8_t address = flashMemory[IP];
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[address]->setValue(data);
        std::cout << "move [" << xdata[address]->getName()<< "] <-- 0x" <<   std::setw(2) <<(uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LJMP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        IP = flashMemory[IP]*256 + flashMemory[IP+1];
        std::cout << "LJMP (at " << std::uppercase << std::setw(4) << std::setfill('0') << std::hex <<  (uint)IP << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::JMP_A_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A]->getValue();
        IP = dp + regA;
        std::cout << "JMP @A+DTR (at " << std::uppercase << std::setw(4) << std::setfill('0') << std::hex <<  (uint)IP << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LCALL>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=6;
        IP++;
        uint16_t newAddress = flashMemory[IP]*256;
        IP++;
        newAddress += flashMemory[IP];
        IP++;
        uint32_t oldAddress = IP;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        spAddress++;
        xdata[spAddress]->setValue( IP & 0xFF);
        spAddress++;
        xdata[spAddress]->setValue((IP >> 8) & 0xFF);
        xdata[Register::SP]->setValue(spAddress);
        IP = newAddress;
        std::cout << "lcall to address 0x" << std::uppercase << std::setw(4) << std::setfill('0') << std::hex <<  (uint)newAddress << " (old address was 0x" << std::setw(4) <<  oldAddress << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::RET>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        uint32_t hiIP = xdata[spAddress]->getValue();
        spAddress--;
        uint32_t lowIP = xdata[spAddress]->getValue();
        spAddress--;
        xdata[Register::SP]->setValue(spAddress);

        IP = (hiIP << 8)  | lowIP;

        std::cout << "ret to address 0x" << std::uppercase << std::setw(4) << std::setfill('0') << std::hex <<  (uint)IP << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}




template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[address]->getValue();
        xdata[Register::A]->setValue(data);
        IP++;
        std::cout << "A <-- [" << xdata[address]->getName() << "]" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DIRECT_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=2;
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[Register::A]->getValue();
        xdata[address]->setValue(data);
        IP++;
        std::cout << "[" <<xdata[address]->getName() << "] <-- A" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ANL_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data & REG_A);
        IP++;
        std::cout << "A <-- A  & 0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ORL_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data | REG_A);
        IP++;
        std::cout << "A <-- A  | 0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CLR_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        xdata[Register::A]->setValue(0);
        IP++;
        std::cout << "CLR A"<< std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_RN_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[address]->getValue();
        xdata[Raddress]->setValue(data);
        IP++;
        std::cout << "R" << (Raddress & 0x7) << " <--  [" << xdata[address]->getName() << "]" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DIRECT_RN>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[Raddress]->getValue();
        xdata[address]->setValue(data);
        IP++;
        std::cout << "[" << xdata[address]->getName() << "] <-- R" << (Raddress & 0x7) << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_RN_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        uint16_t address = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        xdata[address]->setValue(data);
        IP++;
        std::cout << "R" << (address & 0x7) << " <--  0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DPTR_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint8_t  dphVal =flashMemory[IP];
        uint16_t DPH=registryUtil.getDPH();
        xdata[DPH]->setValue( dphVal);
        IP++;
        uint8_t  dplVal =flashMemory[IP];
        uint16_t DPL=registryUtil.getDPL();
        xdata[DPL]->setValue( dplVal);
        IP++;
        std::cout << "MOV DPTR,0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)dphVal << (uint)dplVal << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOVC_A_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A];
        uint8_t val = flashMemory[dp+regA->getValue()];
        regA->setValue(val);
        std::cout << "MOVC A,@A+DPTR (dptr=" << std::setfill('0')  << std::setw(4) << std::hex << dp << ", A = " << (int)regA->getValue() << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOVX_A_AT_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A];
        uint8_t val = xdata[dp]->getValue();
        regA->setValue(val);
        std::cout << "MOVX A,@DPTR (dptr=" << std::setfill('0')  << std::setw(4) << std::hex << dp << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CJNE_RN_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t rAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        if (xdata[rAddress]->getValue() != data){
            IP += relAddr;
        }
        if (xdata[rAddress]->getValue() < data){
            xdata[Register::PSW]->setBit(7,true);
        } else {
            xdata[Register::PSW]->setBit(7,false);
        }

        std::cout << "CJNE R" << (rAddress & 0x7) <<", 0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)data << ", " << std::dec << (int)relAddr << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::DJNZ_RN>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        uint16_t regAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        uint8_t rn= xdata[regAddress]->getValue();
        rn--;
        xdata[regAddress]->setValue(rn);
        if (rn != 0){
            IP += relAddr;
        }

        std::cout << "DJNZ R" << (regAddress & 0x7) << "," << std::dec << (int)relAddr << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::SJMP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        IP += relAddr;

        std::cout << "SJMP AT 0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)IP  << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}



template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::INC_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        dp++;
        xdata[registryUtil.getDPH()]->setValue( (dp & 0xFF00) >> 8);
        xdata[registryUtil.getDPL()]->setValue(dp & 0xFF);
        std::cout << "INC DPTR (dptr=" << std::setfill('0')  << std::setw(4) << std::hex << dp << ")" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::PUSH>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        spAddress++;
        IP++;
        uint8_t address = flashMemory[IP];
        auto mem = xdata[address];
        xdata[spAddress]->setValue( mem->getValue());
        xdata[Register::SP]->setValue(spAddress);
        IP++;

        std::cout << "push " << mem->getName() << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::POP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        IP++;
        uint8_t address = flashMemory[IP];
        auto mem = xdata[address];
        mem->setValue( xdata[spAddress]->getValue());
        spAddress--;
        xdata[Register::SP]->setValue(spAddress);
        IP++;

        std::cout << "pop " << mem->getName() << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::RL_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        uint16_t regA = xdata[Register::A]->getValue();
        regA = regA << 1;
        if (regA & 0x100){
            regA |= 1;
        }
        xdata[Register::A]->setValue(regA);
        IP++;
        std::cout << "RL A" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
void InstrTemp3<Instructions::CLR_BIT>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[bitAddress];
    xAddress->setBit(bit, false);
    IP++;
    std::cout << "CLR BIT " << bit << " of [" << xAddress->getName() << "]" << std::endl;
}

template<>
void InstrTemp1<Instructions::CLR_C>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7,false);
    std::cout << "CLR C " << std::endl;
}
