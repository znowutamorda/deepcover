#include "Handler.hpp"

GenericHandler::GenericHandler(const std::string &in, const std::string &code, const std::string &out, int offset)
{
    this->offset = offset;
    cipher.open(in, std::ios::binary | std::ios::in);
    message.open(code, std::ios::binary | std::ios::in);
    output.open(out, std::ios::binary | std::ios::out | std::ios::trunc);
}

void GenericHandler::encode()
{
    for (int i = 0; i < offset && !cipher.eof(); i++) // offset
    {
        output.put(cipher.get());
    }
    int count = 0;
    char in;
    while (true)
    {
        char ciph;
        ciph = cipher.get();
        if (cipher.eof())
            break;
        if (!count)
            in = message.get();
        if (message.eof())
        {
            output.put(ciph);
            break;
        }
        unsigned char bit = ((1 << count) & in) >> count;
        output.put(ciph^bit);
        count = (count + 1) % 8;
        // std::cout << (int) mask << " " << std::bitset<8>(in) << " " << (int) bit << " " << std::bitset<8>(ciph) << " " << std::bitset<8>(ciph^bit) << '\n';
    }
    while (!cipher.eof())
    {
        char ciph = cipher.get();
        if (cipher.eof())
            break;
        output.put(ciph);
    }
}

void GenericHandler::decode()
{
    cipher.seekg(offset, std::ios::cur);
    message.seekg(offset, std::ios::cur);
    int count = 0;
    unsigned char out = 0;
    while (true)
    {
        char ciph, code;
        ciph = cipher.get();
        code = message.get();
        if (cipher.eof() || message.eof())
            break;
        out >>= 1;
        out |= (ciph^code) << 7;
        // std::cout << std::bitset<8>(ciph) << " " << std::bitset<8>(code)  << " " << std::bitset<8>((ciph^code) << 2) << " " << std::bitset<8>(out) << " " << count <<'\n';
        if (++count == 8)
        {
            output.put(out);
            out = 0;
            count = 0;
        }
    }
}


GenericHandler::~GenericHandler()
{
    cipher.close();
    message.close();
    output.close();
}