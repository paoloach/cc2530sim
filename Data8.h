//
// Created by paolo on 04/03/16.
//

#ifndef CC2530SIM_DATA8_H
#define CC2530SIM_DATA8_H

#include <bitset>
#include <stdint.h>
#include <ostream>
#include <iomanip>
#include <boost/log/trivial.hpp>
#include <sstream>

class Data8 {
private:
    uint8_t value;
public:
    Data8(uint8_t data) : value(data) { }

    Data8() : value(0) { }

    uint8_t getValue() {
        return value;
    }

    int8_t getSignedValue() {
        return (int8_t) value;
    }

    bool getBit(uint index) {
        return std::bitset<8>(value)[index];
    }

    void setBit(int index, bool binValue) {
        auto bits = std::bitset<8>(value);
        bits[index] = binValue;
    }

    Data8 operator|(Data8 b) {
        return Data8(value | b.value);
    }

    Data8 operator^(Data8 b) {
        return Data8(value ^ b.value);
    }

    Data8 operator|=(int b) {
        value = value | b;
        return Data8(value);
    }

    Data8 operator&(Data8 b) {
        return Data8(value & b.value);
    }

    Data8 operator&=(int b) {
        value = value & b;
        return Data8(value);
    }

    Data8 operator+(Data8 b) {
        return Data8(value + b.value);
    }

    Data8 operator-(Data8 b) {
        return Data8(value - b.value);
    }

    Data8 operator/(Data8 b) {
        return Data8(value / b.value);
    }

    Data8 operator%(Data8 b) {
        return Data8(value % b.value);
    }

    bool operator<(uint8_t b) {
        return value < b;
    }

    bool operator<(Data8 b) {
        return value < b.value;
    }

    bool operator!=(uint8_t b) {
        return value != b;
    }

    bool operator!=(Data8 b) {
        return value != b.value;
    }

    bool operator==(uint8_t b) {
        return value == b;
    }

    Data8 operator>>(int i) {
        return Data8(value >> i);
    }

    Data8 operator<<(int i) {
        return Data8(value << i);
    }

    Data8 operator--(int){
        value--;
        return  Data8(value);
    }

    Data8 operator--(){
        auto res = Data8(value);
        value--;
        return  res;
    }

    Data8 operator++(int){
        value++;
        return  Data8(value);
    }

    Data8 operator++(){
        auto res = Data8(value);
        value++;
        return  res;
    }

    friend boost::log::basic_formatting_ostream<char> &operator<<(boost::log::basic_formatting_ostream<char> &out,
                                                                  Data8 &data) {
        std::stringstream ss;

        ss << "0x" << std::hex << std::setfill('0') << std::setw(2) << (int) data.value;
        out << ss.str();
        return out;
    }

    template <typename T>
    friend std::ostream &operator<<(std::basic_ostream<T> &out, Data8 &data) {
        out << std::setfill('0') << std::setw(2) << (int) data.value;
        return out;
    }

    template <typename T>
    friend std::ostream &operator<<(std::basic_ostream<T> &out, Data8 data) {
        out << std::setfill('0') << std::setw(2) << (int) data.value;
        return out;
    }
};


#endif //CC2530SIM_DATA8_H
