#include "Controller.hpp"
#include "Character.hpp"
/*#include "fireFist.hpp"
#include "PoisonArrow.hpp"
#include "Heal.hpp"
#include "Paralysis.hpp"
#include "VampiricClaw.hpp"
#include "MagicShield.hpp"*/



std::shared_ptr<Character> Controller::pickCharacter(int number) {
    switch (number) {
        case 1: return std::make_shared<Character>("Monk Vasya",44);
            break;
        case 2: return std::make_shared<Character>("Paladin Tolya", 56);
            break;
        case 3: return std::make_shared<Character>("Ranger Venya", 56);
            break;
        case 4: return std::make_shared<Character>("Sorcerer Ekaterina", 35);
            break;
        case 5: return std::make_shared<Character>("Cleric Fedor", 48);
            break;
        default: throw std::exception("pick character from 1 to 5");
    }
}


void Controller::func(std::shared_ptr<Character> player) {
    int characterNumber = 0;
    while(player == nullptr) {
        try {
            std::cin >> characterNumber;
            player = pickCharacter(characterNumber);
        }
        catch (const std::exception& ex){
            std::cout << ex.what() << std::endl;
        }
    }
}

void Controller::characterCreating() {
    std::string massage = "Hello! \n"
                          "Pleace, pick the character and write the number: \n"
                          "1 - Ranger (x_Ubiwator123_x), \n"
                          "2 - Moroz (TheDeathMorozzz), \n"
                          "3 - ,\n"
                          "4 - ,\n"
                          "5 - \n";

    std::cout << massage << std::endl;

    func(m_player1);
    func(m_player2);
}





