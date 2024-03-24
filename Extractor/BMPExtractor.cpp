#include "Extractor.hpp"

BMPExtractor::BMPExtractor(const std::string &in, const std::string &code, const std::string &out) : GenericExtractor(in, code, out)
{
    
}

void BMPExtractor::decode()
{
    cipher.seekg(10);
    int offset = cipher.get();
    for (int i = 1; i < 4; i++)
        offset += cipher.get() << (i * 8 - 1);
    cipher.seekg(offset);
    message.seekg(offset);
    GenericExtractor::decode();
}