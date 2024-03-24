#include "Injector.hpp"

AbstractInjector::AbstractInjector(const std::string &in, const std::string &code, const std::string &out)
{
    cipher.open(in, std::ios::binary | std::ios::in);
    message.open(code, std::ios::binary | std::ios::in);
    output.open(out, std::ios::binary | std::ios::out | std::ios::trunc);
}

AbstractInjector::~AbstractInjector()
{
    cipher.close();
    message.close();
    output.close();
}

