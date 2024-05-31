#include <iostream>
#include <string>
#include "Simulation.h"

/*
 *     ___    __  _______  _ ____
 *    /   |  /  |/  / __ )(_/ __ \___  _  __
 *   / /| | / /|_/ / __  / / / / / _ \| |/_/
 *  / ___ |/ /  / / /_/ / / /_/ /  ___>  <
 * /_/  |_/_/  /_/_____/_/_____/\___/_/|_|
 **************************************************************************************************************************
 * AMBiDex is a toy tool meant to explore (A)nonymous (M)essage (B)roadcasting, or AMB, via Chaum's Dining Cryptographer
 * Problem. The problem is presented as the following:
 * Three cryptographers are enjoying dinner. They are informed that arrangements have been made for anonymous payment.
 * This means that one of the diners may be paying for the meal, or a stranger may be paying for it. The diners wish to
 * know if one of them is paying for the dinner, or if another is paying, while retaining anonymity.
 * 
 * The solution to this is particularly strange, albeit interesting, particularly knowing that this algorithm is quite
 * old. Painfully, it requires time negotiations, which can slow down particularly active groups, however, it is 
 * theoretically extensible to any size >= 2. It is as follows:
 * Each cryptographer joins a circle and flips a fair coin between themself and the person to their right. The person
 * to their right will announce if the coins are different or the same. If they are the one who paid, they will 
 * instead lie. If an odd number of "different" answers arises, a cryptographer is paying. Otherwise, it is a stranger.
 * 
 * This induces unconditional sender and recipient untraceability over a reliable broadcast network. Additionally, when 
 * integrated with traditional asymmetric encryption, we obtain a particularly interesting result: encrypted, anonymous 
 * direct messaging. This is a result of being unable to know the sender (the purchaser, in the previous example), and 
 * being unable to know who is able to decrypt it (presuming proper storage of their private key, of course). 
 * 
 * Of course, a cryptographer could lie, and the network could falter. This is addressed in a further problem, Waidner 
 * and Pfitzmann's "Dining Cryptographers in the Disco". In this toy, we will be presuming that all cryptographers are 
 * truthful and a reliable network, but actual application should consult this problem for a more ruggedized protocol. 
 * We will also not be including typical asymmetric encryption, although an explanation for this mechanism is offered in 
 * the included README.
 * 
 * This project is licensed under the MIT license.
 * 
 * For more information on background, usage, and references, please check out the included README.
 * Have fun!
 * Project music recommendation: Kill Alters - Eyelid Viewing (Experimental) - https://www.youtube.com/watch?v=Gi6HLHsD5mM
 * AMBiDex -> Anonymous Message Broadcasting Decentralized EXchange
 **************************************************************************************************************************
 */

// main()
// PRE: N/A
// POST: Execution completes, 0 returned
// WARNINGS: N/A
// STATUS: Completed, tested
int main()
{
    Simulation mySim;
    while (1) {
        std::string menChoiceProxy;
        std::cout << "    ___    __  _______  _ ____" << std::endl;
        std::cout << "   /   |  /  |/  / __ )(_/ __ \\___  _  __" << std::endl;
        std::cout << "  / /| | / /|_/ / __  / / / / / _ \\| |/_/" << std::endl;
        std::cout << " / ___ |/ /  / / /_/ / / /_/ /  ___>  <" << std::endl;
        std::cout << "/_/  |_/_/  /_/_____/_/_____/\\___/_/|_|" << std::endl;
        std::cout << "*******************************************" << std::endl;
        std::cout << "1. Begin Simulation" << std::endl;
        std::cout << "2. Configure Simulation" << std::endl;
        std::cout << "3. Check Configuration" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "*******************************************" << std::endl;
        std::getline(std::cin, menChoiceProxy);
        int menChoice = menChoiceProxy[0] - '0';
        while (menChoice < 1 || menChoice > 4) {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            std::cout << "*******************************************" << std::endl;
            std::cout << "1. Begin Simulation" << std::endl;
            std::cout << "2. Configure Simulation" << std::endl;
            std::cout << "3. Check Configuration" << std::endl;
            std::cout << "4. Quit" << std::endl;
            std::cout << "*******************************************" << std::endl;
            std::getline(std::cin, menChoiceProxy);
            menChoice = menChoiceProxy[0] - '0';
        }
        switch (menChoice) {
        case 1:
            mySim.run();
            break;
        case 2:
            mySim.configure();
            break;
        case 3:
            mySim.printConfig();
            break;
        case 4:
            std::cout << "Quitting..." << std::endl;
            return 0;
        default:
            std::cout << "Unexpected Error: Uncaught menu input. Exiting..." << std::endl;
            return 1;
        }
    }
    return 0;
}