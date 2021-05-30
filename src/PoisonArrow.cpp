#include "PoisonArrow.hpp"
#include "Character.hpp"


PoisonArrow::PoisonArrow(int damage)
    : Skill("Poison Arrow"), m_arrowDamage(damage)
{}

void PoisonArrow::Use(std::shared_ptr<Character> self,
                      std::shared_ptr<Character> enemy) {
    noused(self);
    enemy->getDamage(m_arrowDamage);
    enemy->setPoison(3, m_poisonDamage);

}
