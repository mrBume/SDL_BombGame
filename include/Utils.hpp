#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

#include <AnimatedSprite.hpp>

class Utils
{
public:
    static void readSpriteData(std::string bin_name, std::string & sprite_sheet, std::vector<SDL_Rect> & sprites, std::unordered_map<std::string, std::vector<int>> & animations);
    static std::vector<int> splitString(std::string text);
    static std::string rectToStr(SDL_Rect rect);

private:
};

#endif // UTILS_HPP