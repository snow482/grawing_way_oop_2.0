#pragma once
#include "Skill.hpp"


class PoisonArrow : public Skill {
public:
    explicit PoisonArrow(int damage);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;


private:
    int m_arrowDamage = 0;
    int m_poisonDamage = 0;
};