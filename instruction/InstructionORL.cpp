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
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << " [" << address->getName() << "] <- A | [" << address->getName() << "]";
}


template<>
void InstrTemp4<Instructions::ORL_DIRECT_DATA>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    IP++;
    Data8 data = flashMemory[IP];
    IP++;
    auto newValue = address->getValue() | data;
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << " [" << address->getName() << "] <- " << data << " | [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_A_DATA>::execution() {
    IP++;
    Data8 data(flashMemory[IP]);
    auto REG_A = xdata.A->getValue();
    auto newValue = data | REG_A;
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  | " << data;
}