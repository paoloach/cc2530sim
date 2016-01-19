//
// Created by developer on 1/18/16.
//

#ifndef CC2530SIM_INSTRUCTIONPOINTER_H
#define CC2530SIM_INSTRUCTIONPOINTER_H


#include <stdint.h>
#include <ostream>
#include <iomanip>
#include <boost/log/trivial.hpp>
#include <sstream>

class InstructionPointer {
    uint16_t value;
public:
    InstructionPointer() {
        value=0;
    }

    void reset(){
        value=0;
    }

    void set(uint16_t newValue){
        value = newValue;
    }

    void operator++(int) {
        value++;
    }

    InstructionPointer operator+(int16_t toAdd){
        InstructionPointer result;
        result.value = value+toAdd;
        return result;
    }

    void operator+=(int16_t toAdd){
        value += toAdd;
    }

    uint16_t getValue(){
        return value;
    }

    void setLowByte(uint8_t low){
        value = (value & 0xFF00) +  low;
    }

    uint8_t  getLowByte(){
        return value & 0xFF;
    }

    void setHighByte(uint8_t hight){
        value = ((uint16_t) hight << 8) + (value & 0xFF);
    }

    uint8_t  getHiByte(){
        return (value >> 8) & 0xFF;
    }

    friend boost::log::basic_formatting_ostream<char>  & operator<<(boost::log::basic_formatting_ostream<char>  & out, InstructionPointer & IP ) {
        std::stringstream ss;

         ss << "0x" << std::hex << std::setfill('0')  << std::setw(4) << IP.getValue();
        out << ss.str();
        return out;
    }

    friend std::ostream  & operator<<(std::ostream  & out, InstructionPointer & IP ) {
        out <<  std::setfill('0')  << std::setw(4) << IP.getValue();
        return out;
    }

};


#endif //CC2530SIM_INSTRUCTIONPOINTER_H
