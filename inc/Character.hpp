#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include "Skill.hpp"

int queueThrow();

// Character - базовый класс
// std::enable_shared_from_this<Character> - шаблонная магия (статический полиморфизм)
class Character : public std::enable_shared_from_this<Character> {
public:
    Character(std::string name, int hp);
    ~Character() = default;

    void nextTurn();

    //void characterInfo() = 0;
    //void knownSkills() = 0;
    int queueThrow() const;

    std::string getName() const;
    void getDamage(int damage);

    void addHp(int hp);
    void attack(std::shared_ptr<Character> enemy, int skillNum);
    void addSkill(std::shared_ptr<Skill> skill);

    void setPoison(int turns, int damage);
    void setParalyse(int turns);
    void setShield(int turns);
private:
    std::string m_name;
    int m_hp = 0;
    std::vector<std::shared_ptr<Skill>> m_skills;

    int m_poisonTurns = 0;
    int m_poisonDamage = 0;
    int m_paralysetTurns = 0;
    int m_shieldTurns = 0;
};
