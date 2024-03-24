#ifndef GENERICHANDLER_HPP
#define GENERICHANDLER_HPP

#include <fstream>

class GenericHandler
{
protected:
    int offset;
    std::ifstream cipher;
    std::ifstream message;
    std::ofstream output;
public:
    GenericHandler(const std::string &in, const std::string &code, const std::string &out, int offset = 0);
    virtual void encode();
    virtual void decode();
    virtual ~GenericHandler();
};

class BMPHandler : public GenericHandler
{
public:
    BMPHandler(const std::string &in, const std::string &code, const std::string &out, int offset = 0);
    void encode() override;
    void decode() override;
};


#endif //GENERICHANDLER_HPP
