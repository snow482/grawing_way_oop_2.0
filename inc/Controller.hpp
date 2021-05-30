#pragma once
#include <iostream>
#include <filesystem>
#include "Character.hpp"
#include "Skill.hpp"


class Controller {
public:
    Controller() = default;
    ~Controller() = default;

    void characterCreating();
    void playerQueue();
    void fight();

private:
    std::shared_ptr<Character> pickCharacter(int number);
    void func(std::shared_ptr<Character> player);
private:
    std::shared_ptr<Character> m_player1 = nullptr;
    std::shared_ptr<Character> m_player2 = nullptr;
};
