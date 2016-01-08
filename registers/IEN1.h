//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_IEN1_H
#define CC2530SIM_IEN1_H
class IEN1 : public MemoryLocation {
public:
    IEN1() :MemoryLocation(0xB8) {
    }
public:
    virtual std::string getName() override {
        return "IEN1";
    }
};
#endif //CC2530SIM_IEN0_H
