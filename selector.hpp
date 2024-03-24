#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "Handler/Handler.hpp"

enum protocol
{
    GENERIC,
    BMP
};

constexpr int PROTOCOL_NUMBER = 2;

inline std::string PROTOCOL_LOOKUP[] =
{
    "generic",
    "bmp"
};

protocol match_protocol(const std::string &&str);

GenericHandler *get_handler(protocol type, const std::string &in, const std::string &code, const std::string &out);

#endif //BUILDER_HPP
