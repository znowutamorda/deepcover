#include "Handler.hpp"

BMPHandler::BMPHandler(const std::string &in, const std::string &code, const std::string &out, const int offset) : GenericHandler(in, code, out, offset)
{

}

void BMPHandler::encode()
{
    int header_offset = 10;
    while (cipher.tellg() != header_offset)
        output.put(cipher.get());
    header_offset = cipher.get();
    output.put(header_offset);
    for (int i = 1; i < 4; i++)
    {
        char off = cipher.get();
        header_offset += off << (i * 8 - 1);
        output.put(off);
    }
    while (cipher.tellg() != header_offset)
        output.put(cipher.get());
    GenericHandler::encode();
}

void BMPHandler::decode()
{
    cipher.seekg(10);
    int header_offset = cipher.get();
    for (int i = 1; i < 4; i++)
        header_offset += cipher.get() << (i * 8 - 1);
    cipher.seekg(header_offset);
    message.seekg(header_offset);
    GenericHandler::decode();
}