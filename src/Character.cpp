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
    return m_name;
}
int Character::hpQuantity() const {
    return m_hp;
}

void Character::getDamage(int damage) {
    m_hp -= damage;
}

/*std::string Character::printSkills() const {
    std::string skillName;
    for(auto& it : m_skills) {
       it->Skill::skillName();
    }
    return skillName;
}*/

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
void Character::setParalyse(int turns) {
    m_paralysetTurns = turns;
}
void Character::setShield(int turns) {
    m_shieldTurns = turns;
}

void Character::nextTurn() {
    if (m_poisonTurns > 0) {
        m_hp -= m_poisonDamage;
        m_poisonTurns -= 1;
    }
    if(m_paralysetTurns > 0) {
        m_paralysetTurns -= 1;
    }
    if(m_shieldTurns > 0) {
        m_shieldTurns -= 1;
    }
    //TODO
    //подумать, как сделать еще скилл про заморозку, который уменьшает дамаг вносимый от цели
}


