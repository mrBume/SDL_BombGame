#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <Utils.hpp>
#include <rapidxml.hpp>

using namespace std;

void Utils::readSpriteData(string bin_name, string & sprite_sheet, vector<SDL_Rect> & sprites, unordered_map<string, AnimatedSprite::Animation> & animations)
{
    // read sprite.dat
    ifstream file;
    file.open("assets/sprites.dat");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    string filename;
    vector<SDL_Rect> local_sprites;
    unordered_map<string, AnimatedSprite::Animation> local_animations; 

    rapidxml::xml_document doc;
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);

    filename = doc.first_node("Spritesheet")->first_attribute("sourcefile")->value();

    for (rapidxml::xml_node<> *node = doc.first_node("Spritesheet")->first_node(); node != nullptr; node = node->next_sibling())
    {
        if("Frame" == static_cast<string>(node->name()))
        {
            SDL_Rect local_rect = {
                atoi((node->first_attribute("x")->value())),
                atoi((node->first_attribute("y")->value())),
                atoi((node->first_attribute("w")->value())),
                atoi((node->first_attribute("h")->value()))
                };
            local_sprites.push_back(local_rect);
        }


        if("Animation" == static_cast<string>(node->name()))
        {
            local_animations[node->first_attribute("name")->value()].frames = splitString(node->first_attribute("frames")->value());
            local_animations[node->first_attribute("name")->value()].speed = atoi(node->first_attribute("speed")->value());
        }
    }

    sprite_sheet = filename;
    sprites = local_sprites;
    animations = local_animations;

    

    file.close();

}

vector<Uint8> Utils::splitString(string text)
{
    vector<Uint8> ret;
    string tmp = "";

    for (auto ch : text)
    {
        if (ch != ' ' && ch != ',')
        {
            tmp += ch;
        }
        else if (tmp != "")
        {
            ret.push_back(stoi(tmp));
            tmp = "";
        }
    }
    ret.push_back(stoi(tmp));

    return ret;
}

string Utils::rectToStr(SDL_Rect rect)
{
    string text = "";

    text += "{ x: " + to_string(rect.x) + ", y: " + to_string(rect.y)  + ", w: " +std::to_string(rect.w) +", h: "+ std::to_string(rect.h);
    
    return text;
}
