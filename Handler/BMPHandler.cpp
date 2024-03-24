#include "Handler.hpp"

BMPHandler::BMPHandler(const std::string &in, const std::string &code, const std::string &out) : GenericHandler(in, code, out)
{
    
}

void BMPHandler::encode()
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
    GenericHandler::encode();
}

void BMPHandler::decode()
{
    cipher.seekg(10);
    int offset = cipher.get();
    for (int i = 1; i < 4; i++)
        offset += cipher.get() << (i * 8 - 1);
    cipher.seekg(offset);
    message.seekg(offset);
    GenericHandler::decode();
}