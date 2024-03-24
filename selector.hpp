#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "Handler/Handler.hpp"

enum protocol
{
    GENERIC,
    BMP,
    WAV
};

constexpr int PROTOCOL_NUMBER = 3;

inline std::string PROTOCOL_LOOKUP[] =
{
    "generic",
    "bmp",
    "wav"
};

protocol match_protocol(const std::string &&str);

GenericHandler *get_handler(protocol type, const std::string &in, const std::string &code, const std::string &out, int offset);

#endif //BUILDER_HPP
