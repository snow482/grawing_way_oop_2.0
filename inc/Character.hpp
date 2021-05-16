#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>

#include "Skill.hpp"

int queueThrow();

// Character - базовый класс
// std::enable_shared_from_this<Character> - шаблонная магия (статический полиморфизм)
class Character : public std::enable_shared_from_this<Character> {
public:
    Character(std::string name, int hp);
    ~Character() = default;

    //void characterInfo() = 0;
    //void knownSkills() = 0;

    std::string getName() const;
    void getDamage(int damage);
    void attack(std::shared_ptr<Character> enemy, int skillNum);
    void addSkill(std::shared_ptr<Skill> skill);




private:
    std::string m_name;
    int m_hp;
    std::vector<std::shared_ptr<Skill>> m_skills;

};
