//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMAREQ_H
#define CC2530SIM_DMAREQ_H
class DMAREQ : public MemoryLocation {
public:
    DMAREQ() :MemoryLocation(0xD7) {
    }
public:
    virtual std::string getName() override {
        return "DMAREQ";
    }
};
#endif //CC2530SIM_DMAARM_H
