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

void Character::setPoison(int turns, int damage) {
    m_poisonTurns = turns;
    m_poisonDamage = damage;
}

void Character::nextTurn() {
    if (m_poisonTurns > 0) {
        m_hp -= m_poisonDamage;
        m_poisonTurns -= 1;
    }
    //TODO
    /*if(m_paralyzed > 0) {

    }*/
    //подумать, как сделать еще скилл про заморозку, который уменьшает дамаг вносимый от цели
}


