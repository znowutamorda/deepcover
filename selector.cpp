#include "selector.hpp"

#include <string>

#include "Handler/Handler.hpp"

protocol match_protocol(const std::string &&str)
{
    protocol result = GENERIC;
    for (int i = 0; i < PROTOCOL_NUMBER; i++)
        if (str == PROTOCOL_LOOKUP[i])
            result = static_cast<protocol>(i);
    return result;
}

GenericHandler *get_handler(const protocol type, const std::string &in, const std::string &code, const std::string &out, const int offset)
{
    switch (type)
    {
        case BMP:
            return new BMPHandler(in, code, out, offset);
        case WAV:
            return new GenericHandler(in, code, out, offset + 44);
        default:
            return new GenericHandler(in, code, out, offset);
    }
}

