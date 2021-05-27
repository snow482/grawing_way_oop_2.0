#include "VampiricClaw.hpp"
#include "Character.hpp"


VampiricClaw::VampiricClaw(int vampiricDamage)
    : Skill("Vampiric Claw"), m_vampiricDamage(vampiricDamage)
{}

void VampiricClaw::Use(std::shared_ptr<Character> self,
                       std::shared_ptr<Character> enemy) {
    enemy->getDamage(m_vampiricDamage, 0);
    self->addHp(m_vampiricDamage);
}