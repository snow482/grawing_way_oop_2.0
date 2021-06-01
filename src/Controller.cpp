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
            auto character = std::make_shared<Character>("Vasya Monk", 44);
            character->addSkill(std::make_shared<PoisonArrow>(15, 3, 5));
            return character;
            }

        case 2: return std::make_shared<Character>("Tolya Paladin", 56);

        case 3: return std::make_shared<Character>("Venya Ranger", 56);

        case 4: return std::make_shared<Character>("Ekaterina Sorcerer", 35);
        case 5: {
            auto character = std::make_shared<Character>("Cleric Fedor", 48);
            //character->addSkill()
            return character;
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


