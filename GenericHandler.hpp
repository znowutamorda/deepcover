#ifndef GENERICHANDLER_HPP
#define GENERICHANDLER_HPP

#include <fstream>

class GenericHandler
{
protected:
    std::ifstream cipher;
    std::ifstream message;
    std::ofstream output;
public:
    GenericHandler(const std::string &in, const std::string &code, const std::string &out);
    virtual void encode();
    virtual void decode();
    virtual ~GenericHandler();

};



#endif //GENERICHANDLER_HPP
