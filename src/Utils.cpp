#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <Utils.hpp>

using namespace std;

void Utils::readSpriteData(string bin_name, string & sprite_sheet, vector<SDL_Rect> & sprites, std::unordered_map<std::string, std::vector<int>> & anim)
{
    // read sprite.dat
    fstream file;
    file.open("assets/sprites.dat");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    string line;
    string filename;
    string tmp;
    vector<SDL_Rect> rects;
    vector<int> frame_props;
    unordered_map<string, vector<int>> animations;

    getline(file, filename);
    getline(file, line); // sprites

    for (int i = 0; i < atoi(line.c_str()); i++)
    {
        getline(file, tmp);
        frame_props = splitString(tmp);
        rects.push_back({frame_props[0], frame_props[1], frame_props[2], frame_props[3]});
    }

    getline(file, line); // animations
    for (int i = 0; i < atoi(line.c_str()); i++)
    {
        string name;
        vector<int> frames;
        // animation name
        getline(file, name);
        // animation sprites
        getline(file, tmp);
        frames = splitString(tmp);
        animations[name] = frames;
    }

    // // check info
    // for (auto rect : rects)
    // {
    //     cout << "x: " << std::to_string(rect.x) << ", y: " << std::to_string(rect.y) << ", w: " << std::to_string(rect.w) << ", h: " << std::to_string(rect.h) << endl;
    // }
    // for (auto anim : animations)
    // {
    //     cout << anim.first << " ";
    //     for (auto item : anim.second)
    //     {
    //         cout << to_string(item) << " ";
    //     }
    //     cout << endl;
    // }

    sprite_sheet = filename;
    sprites = rects;
    anim = animations;

    file.close();
}

vector<int> Utils::splitString(string text)
{
    vector<int> ret;
    string tmp = "";

    for (auto ch : text)
    {
        if (ch != ' ')
        {
            tmp += ch;
        }
        else
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

    text += "{ x: " + std::to_string(rect.x) + ", y: " + std::to_string(rect.y)  + ", w: " +std::to_string(rect.w) +", h: "+ std::to_string(rect.h);
    
    return text;
}