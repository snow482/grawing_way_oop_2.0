#include "Controller.hpp"
#include "Character.hpp"
#include "fireFist.hpp"
#include "PoisonArrow.hpp"
#include "Heal.hpp"
#include "Paralysis.hpp"
#include "VampiricClaw.hpp"
#include "MagicShield.hpp"



std::shared_ptr<Character> Controller::pickCharacter(int number) {
    switch (number) {
        case 1:
            {
                auto monk = std::make_shared<Character>("Vasya Monk", 64);
                monk->addSkill(std::make_shared<FireFist>(20));
                monk->addSkill(std::make_shared<VampiricClaw>(20));
                monk->addSkill(std::make_shared<Heal>(10));
                return monk;
            }
        case 2:
            {
                auto paladin = std::make_shared<Character>("Tolya Paladin", 86);
                paladin->addSkill(std::make_shared<FireFist>(30));
                paladin->addSkill(std::make_shared<Heal>(20));
                paladin->addSkill(std::make_shared<Paralysis>(1));
                return paladin;
            }
        case 3:
            {
                auto ranger = std::make_shared<Character>("Venya Ranger", 86);
                ranger->addSkill(std::make_shared<PoisonArrow>(17, 3, 5));
                ranger->addSkill(std::make_shared<Heal>(15));
                ranger->addSkill(std::make_shared<MagicShield>(1, 0));
                return ranger;
            }
        case 4:
            {
                auto sorcerer = std::make_shared<Character>("Ekaterina Sorcerer", 55);
                sorcerer->addSkill(std::make_shared<VampiricClaw>(30));
                sorcerer->addSkill(std::make_shared<PoisonArrow>(20, 2, 10));
                sorcerer->addSkill(std::make_shared<MagicShield>(1, 0));
                sorcerer->addSkill(std::make_shared<Paralysis>(1));
                return sorcerer;
            }
        case 5:
            {
                auto cleric = std::make_shared<Character>("Cleric Fedor", 75);
                cleric->addSkill(std::make_shared<FireFist>(15));
                cleric->addSkill(std::make_shared<VampiricClaw>(40));
                cleric->addSkill(std::make_shared<Heal>(40));
                return cleric;
            }
        default: throw std::exception("pick character from 1 to 5");
    }
}


void Controller::characterPulling(std::shared_ptr<Character> player) {
    int characterNumber = 0;
    while(player == nullptr) {
        try {
            std::cin >> characterNumber;
            player = pickCharacter(characterNumber);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}

void Controller::characterCreating() {
    std::string massage = "Hello! \n"
                          "Pleace, pick the character and write the number: \n"
                          "1 - Vasya Monk, \n"
                          "2 - Tolya Paladin, \n"
                          "3 - Venya Ranger, \n"
                          "4 - Ekaterina Sorcerer,\n"
                          "5 - Cleric Fedor\n";

    std::cout << massage << std::endl;

    characterPulling(m_player1);
    characterPulling(m_player2);
}

void Controller::playerQueue() {


}

void Controller::fight() {

}


