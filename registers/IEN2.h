//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_IEN2_H
#define CC2530SIM_IEN2_H
class IEN2 : public MemoryLocation {
public:
    IEN2() :MemoryLocation(0x9A) {
    }
public:
    virtual std::string getName() override {
        return "IEN2";
    }
};
#endif //CC2530SIM_IEN0_H
