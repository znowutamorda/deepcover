#include "Injector.hpp"

GenericInjector::GenericInjector(const std::string &in, const std::string &code, const std::string &out) : AbstractInjector(in, code, out)
{
    
}

void GenericInjector::encode()
{
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
