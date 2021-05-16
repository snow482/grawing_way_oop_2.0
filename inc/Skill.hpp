#pragma once
#include <memory>
#include <string>

#define noused(x) (void)(x)

class Character;

enum class SkillType {
    Unknown = 0,
    FireBall = 1,
    Hurricane = 2,
    WindStrike = 3,
    Hudroblast = 4,
    ShieldBlock = 5
};

SkillType SkillTypeCast (int skillNum);

// Skills - базовый класс для скилов, другие скилы будут наследоваться от него

class Skill {
public:
    explicit Skill(std::string skillName);
    virtual ~Skill() = default;
    //ссылка на Character, но ни чего не знает о нем
    virtual void Use(std::shared_ptr<Character> self,
                     std::shared_ptr<Character> enemy) = 0;

    //std::string getSkillName() const;



private:
    std::string m_skillName;
};
