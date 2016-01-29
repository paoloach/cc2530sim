//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMAARM_H
#define CC2530SIM_DMAARM_H
class DMAARM : public MemoryLocation {
public:
    DMAARM() :MemoryLocation(0xD6) {
    }
public:
    virtual std::string getName() override {
        return "DMAARM";
    }
};
#endif //CC2530SIM_DMAARM_H
