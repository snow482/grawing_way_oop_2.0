#include "fireFist.hpp"
#include "Character.hpp"

FireFist::FireFist(int fireDamage)
    : Skill("Fire damage"), m_fireDamage(fireDamage)
{}

void FireFist::Use(std::shared_ptr<Character> self,
                    std::shared_ptr<Character> enemy) {
    enemy->getDamage(m_fireDamage);
    noused(self);
}

