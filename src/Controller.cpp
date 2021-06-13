#include "Controller.hpp"
#include "Character.hpp"
#include "fireFist.hpp"
#include "PoisonArrow.hpp"
#include "Heal.hpp"
#include "Paralysis.hpp"
#include "VampiricClaw.hpp"
#include "MagicShield.hpp"


void Controller::info() {
    std::cout << "Good day, today is the fight day!\n"
                 "For you information, you should pick the character wood you like\n"
                 "Number for picking you can find below, skills info under the characters \n"
                 "\n"
                 "[1]Vasya Monk     [2]Sonya Paladin  [3]Venya Ranger  [4]Ekaterina Sorcerer  [5]Cleric Fedor\n"
                 "\n"
                 "[1]Fire fist      [1]Fire fist      [1]Poison arrow  [1]Vampiric claw       [1]Fire fist\n"
                 "[2]Vampiric Claw  [2]Heal           [2]Heal          [2]Poison arrow        [2]Vampiric claw\n"
                 "[3]Heal           [3]Paralysis      [3]Magic Shield  [3]Magic shield        [3]Heal\n"
                 "                                                     [4]Paralysis\n"
                 "Pleace, pick the character and write the number:\n"
                 "\n";
}

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
                auto paladin = std::make_shared<Character>("Sonya Paladin", 86);
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


void Controller::characterPulling(std::shared_ptr<Character>& player) {
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
    info();
    characterPulling(m_player1);
    characterPulling(m_player2);
}

void Controller::playerQueue() {
    int firstThrower, secondThrower = 0;
    std::cout << "Initiative throws" << std::endl;
    do {
        std::cout << "Rolling, who will be first\n";
        firstThrower = m_player1->queueThrow();
        secondThrower = m_player2->queueThrow();
    } while (firstThrower == secondThrower);

    std::cout << m_player1->getName() <<" rolled: " << firstThrower << "\n"
              << m_player2->getName() << " rolled: " << secondThrower << "\n";

    if (firstThrower < secondThrower) {
        std::swap(m_player1, m_player2);
    }
    std::cout << m_player1->getName() << " attacking first\n";
    std::cout << std::endl;
}

void Controller::fight() {
    while (m_player1->hpQuantity() > 0 && m_player2->hpQuantity() > 0) {
        int firstPlayerAttackNumber = 0;
        int secondPlayerAttackNumber = 0;
        m_player1->nextTurn();
        m_player2->nextTurn();

        std::cout << m_player1->getName()<< " please write number of attack" << std::endl;
        std::cout << m_player1->printSkills() << "\n";
        std::cin >> firstPlayerAttackNumber;
        switch (firstPlayerAttackNumber) {
            case 1: m_player1->attack(m_player2, 0);
                break;
            case 2: m_player1->attack(m_player2, 1);
                break;
            case 3: m_player1->attack(m_player2, 2);
                break;
            case 4: m_player1->attack(m_player2, 3);
                break;
            case 5: m_player1->attack(m_player2, 4);
                break;
            default: std::cout << "Needs to chose the skill what you want!" << std::endl;
        }

        std::cout << m_player2->getName() << " please write number of attack" << std::endl;
        std::cout << m_player2->printSkills() << "\n";
        std::cin >> secondPlayerAttackNumber;
        switch (secondPlayerAttackNumber) {
            case 1: m_player1->attack(m_player2, 0);
                break;
            case 2: m_player1->attack(m_player2, 1);
                break;
            case 3: m_player1->attack(m_player2, 2);
                break;
            case 4: m_player1->attack(m_player2, 3);
                break;
            case 5: m_player1->attack(m_player2, 4);
                break;
            default: std::cout << "Needs to chose the skill what you want!" << std::endl;
        }
        std::cout << m_player1->getName() << " - hp: "
                  << m_player1->hpQuantity() << "\n"
                  << m_player2->getName() << " - hp: "
                  << m_player2->hpQuantity() << "\n";
        std::cout << std::endl;

        std::swap(m_player1, m_player2);
    }

    if (m_player1->hpQuantity() > m_player2->hpQuantity()) {
        std::cout << m_player1->getName() << " Winner!" << std::endl;
    }
    else {
        std::cout << m_player2->getName() << " Winner!" << std::endl;
    }
}


