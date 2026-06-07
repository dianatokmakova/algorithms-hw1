#include <iostream>
#include <iterator>
#include <vector>
#include <cstdint>
#include <string>

#include "base85ed.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "base85") << " -e|-d\n";
        return 1;
    }
    const std::string mode = argv[1];
    if (mode != "-e" && mode != "-d")
    {
        std::cerr << "Usage: " << argv[0] << " -e|-d\n";
        return 1;
    }

    const std::vector<std::uint8_t> in(
        (std::istreambuf_iterator<char>(std::cin)),
        std::istreambuf_iterator<char>());

    const std::vector<std::uint8_t> out =
        (mode == "-e") ? base85::encode(in) : base85::decode(in);

    std::cout.write(reinterpret_cast<const char *>(out.data()),
                    static_cast<std::streamsize>(out.size()));
    return 0;
}
