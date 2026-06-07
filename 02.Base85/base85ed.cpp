#include <vector>
#include <cstdint>
#include <string>

#include "base85ed.h"

namespace
{
const std::string alphabet =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    "!#$%&()*+-;<=>?@^_`{|}~";
}

std::vector<uint8_t> base85::encode(std::vector<uint8_t> const &bytes)
{
    std::vector<uint8_t> out;
    const std::size_t sz = bytes.size();
    for (std::size_t i = 0; i < sz; i += 4)
    {
        std::uint32_t v = 0;
        const std::size_t remaining = sz - i;
        const std::size_t t = remaining < 4 ? remaining : 4;
        for (std::size_t j = 0; j < 4; ++j)
        {
            v <<= 8;
            if (j < t) v |= bytes[i + j];
        }
        std::uint8_t digits[5];
        for (int j = 4; j >= 0; --j)
        {
            digits[j] = static_cast<std::uint8_t>(alphabet[v % 85]);
            v /= 85;
        }
        const std::size_t out_len = t + 1;
        for (std::size_t j = 0; j < out_len; ++j)
        {
            out.push_back(digits[j]);
        }
    }
    return out;
}

std::vector<uint8_t> base85::decode(std::vector<uint8_t> const &b85str)
{
    int rev[256];
    for (int i = 0; i < 256; ++i) rev[i] = 0;
    for (int i = 0; i < 85; ++i)
    {
        rev[static_cast<std::uint8_t>(alphabet[i])] = i;
    }

    std::vector<uint8_t> out;
    const std::size_t sz = b85str.size();
    for (std::size_t i = 0; i < sz; i += 5)
    {
        std::uint64_t v = 0;
        const std::size_t remaining = sz - i;
        const std::size_t t = remaining < 5 ? remaining : 5;
        for (std::size_t j = 0; j < 5; ++j)
        {
            v *= 85;
            v += (j < t) ? static_cast<std::uint64_t>(rev[b85str[i + j]]) : 84;
        }
        const std::size_t out_len = t - 1;
        for (int j = 3; j >= 0; --j)
        {
            const std::uint8_t x = static_cast<std::uint8_t>((v >> (j * 8)) & 0xFF);
            if (static_cast<std::size_t>(3 - j) < out_len)
            {
                out.push_back(x);
            }
        }
    }
    return out;
}
