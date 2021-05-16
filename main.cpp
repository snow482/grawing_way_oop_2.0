#include "Character.hpp"
#include "fireFist.hpp"


int main() {

    std::shared_ptr<FireFist> fireFist = std::make_shared<FireFist>(25);
    std::shared_ptr<FireFist> nuckFireFist = std::make_shared<FireFist>(10);
    std::shared_ptr<Character> maniken = std::make_shared<Character>("manyaken", 52);


    maniken->addSkill(fireFist);
    maniken->addSkill(nuckFireFist);

    std::shared_ptr<Character> monk = std::make_shared<Character>("monah_Sani", 27);
    monk->addSkill(fireFist);
    monk->attack(maniken, 0);




    return 0;
}


