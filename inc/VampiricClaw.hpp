#pragma once
#include "Skill.hpp"

class VampiricClaw : public Skill {
public:
    explicit VampiricClaw(int vampiricDamage);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;

private:
    int m_vampiricDamage = 0;
};

