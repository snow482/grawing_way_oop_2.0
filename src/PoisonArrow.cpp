#include "PoisonArrow.hpp"
#include "Character.hpp"


PoisonArrow::PoisonArrow(int damage, int additionDamage)
    : Skill("Poison Arrow"), m_arrowDamage(damage), m_poisonDamage(additionDamage)
{}

void PoisonArrow::Use(std::shared_ptr<Character> self,
                      std::shared_ptr<Character> enemy) {
    noused(self);
    enemy->getDamage(m_arrowDamage);
    enemy->setPoison(2, m_poisonDamage);

}
