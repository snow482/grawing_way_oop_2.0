#include <fstream>
#include <stdexcept>

#include "Character.hpp"


Character::Character(std::string name, int hp)
    :m_name(name), m_hp(hp)
{}

int Character::queueThrow() const {
    return rand() % 5 + 1;
}

std::string Character::getName() const {
    return std::string();
}

void Character::getDamage(int damage) {
    m_hp -= damage;
}

void Character::addHp(int hp) {
    m_hp += hp;
}

void Character::attack(std::shared_ptr<Character> enemy, int skillNum) {
    m_skills[skillNum]->Use(shared_from_this(), enemy);
}

void Character::addSkill(std::shared_ptr<Skill> skill) {
    m_skills.push_back(skill);
}



