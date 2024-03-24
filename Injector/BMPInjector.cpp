#include "Injector.hpp"

BMPInjector::BMPInjector(const std::string &in, const std::string &code, const std::string &out) : GenericInjector(in, code, out)
{
    
}

void BMPInjector::encode()
{
    int offset = 10;
    while (cipher.tellg() != offset)
        output.put(cipher.get());
    offset = cipher.get();
    output.put(offset);
    for (int i = 1; i < 4; i++)
    {
        char off = cipher.get();
        offset += off << (i * 8 - 1);
        output.put(off);
    }
    while (cipher.tellg() != offset)
        output.put(cipher.get());
    GenericInjector::encode();
}
