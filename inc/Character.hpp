#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

enum class SkillType : uint8_t {
    Unknown = 0,
    FireBall = 1,
    Hurricane = 2,
    WindStrike = 3,
    Hudroblast = 4
};

SkillType SkillTypeCast (int skillNum);

int queueThrow();



// Character - базовый класс
class Character {
public:
    Character(std::string name, int hp);
    void setActionType(int number, int commandType);

    virtual ~Character() = default;


private:
    std::string m_name;
    int m_hp;
    //std::map<>
    std::unordered_map<int, std::shared_ptr<Character>> map;

};
