#include "selector.hpp"

protocol match_protocol(const std::string &&str)
{
    protocol result = GENERIC;
    for (int i = 0; i < PROTOCOL_NUMBER; i++)
        if (str == PROTOCOL_LOOKUP[i])
            result = static_cast<protocol>(i);
    return result;
}

void select_injector(const protocol type, const std::string &in, const std::string &code, const std::string &out)
{
    switch (type)
    {
        case BMP:
        {
            BMPInjector(in, code, out).encode();
            break;
        }
        default:
            GenericInjector(in, code, out).encode();
    }
}

void select_extractor(const protocol type, const std::string &in, const std::string &code, const std::string &out)
{
    switch (type)
    {
        case BMP:
        {
            BMPExtractor(in, code, out).decode();
            break;
        }
        default:
            GenericExtractor(in, code, out).decode();
    }
}