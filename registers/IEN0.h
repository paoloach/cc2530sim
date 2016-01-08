//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_IEN0_H
#define CC2530SIM_IEN0_H
class IEN0 : public MemoryLocation {
public:
    IEN0() :MemoryLocation(0xA8) {
    }
public:
    virtual std::string getName() override {
        return "IEN0";
    }
};
#endif //CC2530SIM_IEN0_H
