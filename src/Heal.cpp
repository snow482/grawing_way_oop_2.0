#include "Heal.hpp"
#include "Character.hpp"


Heal::Heal(int healPoints)
    : Skill("Self Heal"), m_additionalHp(healPoints)
{}

void Heal::Use(std::shared_ptr<Character> self,
               std::shared_ptr<Character> enemy) {

    noused(self);
    self->addHp(m_additionalHp);
}