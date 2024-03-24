#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include <fstream>

class AbstractInjector
{
protected:
    std::ifstream cipher;
    std::ifstream message;
    std::ofstream output;
public:
    AbstractInjector(const std::string &in, const std::string &code, const std::string &out);
    virtual void encode() = 0;
    virtual ~AbstractInjector();
};

class GenericInjector : public AbstractInjector
{
public:
    GenericInjector(const std::string &in, const std::string &code, const std::string &out);
    void encode() override;
};

class BMPInjector : public GenericInjector
{
public:
    BMPInjector(const std::string &in, const std::string &code, const std::string &out);
    void encode() override;
};

#endif //INJECTOR_HPP
