#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "Extractor/Extractor.hpp"
#include "Injector/Injector.hpp"

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

void select_injector(protocol type, const std::string &in, const std::string &code, const std::string &out);

void select_extractor(protocol type, const std::string &in, const std::string &code, const std::string &out);

#endif //BUILDER_HPP
