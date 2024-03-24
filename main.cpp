#include "selector.hpp"

using namespace std;

int main(int argc, char **argv)
{
    bool decode = false;
    int arg_index = 1;
    int f_index = 0;
    if (argc < 4)
        return 0;
    for (int i = 1; i < argc; i++)
    {
        if (string("-d") == argv[i])
        {
            decode = true;
            arg_index = i + 1;
        }
        else if (string("-f") == argv[i])
        {
            f_index = i + 1;
            arg_index = f_index + 1;
        }
    }
    protocol p = match_protocol(f_index ? argv[f_index] : "");
    if (decode)
        select_extractor(p, argv[arg_index], argv[arg_index + 1], argv[arg_index + 2]);
    else
        select_injector(p, argv[arg_index], argv[arg_index + 1], argv[arg_index + 2]);
}
