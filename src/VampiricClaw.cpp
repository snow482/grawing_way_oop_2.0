#include "VampiricClaw.hpp"
#include "Character.hpp"


VampiricClaw::VampiricClaw(int vampiricDamage, int vampiricHp)
    : Skill("Vampiric Claw"), m_vampiricDamage(vampiricDamage), m_vampiricHp(vampiricHp)
{}

void VampiricClaw::Use(std::shared_ptr<Character> self,
                       std::shared_ptr<Character> enemy) {
    enemy->getDamage(m_vampiricDamage);
    self->addHp(m_vampiricHp);
}