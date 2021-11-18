#include "StringUtil.hpp"

using namespace game;

bool StringUtil::EndsWith(const std::string& haystack, const std::string& needle)
{
    if (haystack.length() >= needle.length())
    {
        return (0 == haystack.compare(haystack.length() - needle.length(), needle.length(), needle));
    }

    return false;
}

bool StringUtil::StartsWith(const std::string& haystack, const std::string& needle)
{
    if (haystack.length() >= needle.length())
    {
        return haystack.rfind(needle, 0) == 0;
    }

    return false;
}
