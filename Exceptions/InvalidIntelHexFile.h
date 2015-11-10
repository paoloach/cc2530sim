//
// Created by root on 11/9/15.
//

#ifndef CC2530_INVALIDINTELHEXFILE_H
#define CC2530_INVALIDINTELHEXFILE_H


#include <exception>
#include <string>

class InvalidIntelHexFile : public std::exception{
public:
    InvalidIntelHexFile(const std::string & message):message(message){}
    virtual ~InvalidIntelHexFile(){};
    virtual const char* what() const throw() override {return message.c_str();};
private:
    std::string message;
};


#endif //CC2530_INVALIDINTELHEXFILE_H
