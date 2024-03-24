#include "Extractor.hpp"

GenericExtractor::GenericExtractor(const std::string &in, const std::string &code, const std::string &out) : AbstractExtractor(in, code, out)
{
    
}

void GenericExtractor::decode()
{
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
