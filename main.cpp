#include <iostream>
#include <string>
#include <cstdlib>

// Player's nickname
std::string Nickname;

// Player's money balance
double Cash = 0;

// Amount input
double Amount;

// Multiplier that increases income from work
double IncomeMultiplier = 1.0;

// Player's age in years
int Age = 1;

// Player's Statistics
int Health = 100;
int Hunger = 100;
int Energy = 100;
int Durability = 100;

// Menu selection - choice
int Choose;

// Clears the console depending on the operating system
void ClearConsole(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pause before clearing screen
void Pause(){
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

// Ensures all stats stay within valid limits
void LimitsLogic(){
    if (Health > 100) Health = 100;
    if (Health < 0) Health = 0;

    if (Hunger > 100) Hunger = 100;
    if (Hunger < 0) Hunger = 0;

    if (Energy > 100) Energy = 100;
    if (Energy < 0) Energy = 0;

    if (Durability > 100) Durability = 100;
    if (Durability < 0) Durability = 0;
}

// Handles health decrease logic
int HealthLogic(){
    if (Hunger == 0 && Energy == 0 && Durability == 0){
        Health -= 20;
    }

    if (Health <= 0){
        std::cout << "You died of poor health!" << std::endl;
        return 0;
    }
    return 1;
}

// Displays player statistics
void Statistics(){
    std::cout << "=============================" << std::endl;
    std::cout << "Nickname: " << Nickname << std::endl;
    std::cout << "Age: " << Age << std::endl;
    std::cout << "Cash: $" << Cash << std::endl;
    std::cout << "Income Multiplier: " << IncomeMultiplier << "x" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Health: %" << Health << std::endl;
    std::cout << "Hunger: %" << Hunger << std::endl;
    std::cout << "Energy: %" << Energy << std::endl;
    std::cout << "Durability: %" << Durability << std::endl;
    std::cout << "=============================" << std::endl;
}

// Shows the main menu options
void MainMenu(){
    std::cout << "[1] - Work" << std::endl;
    std::cout << "[2] - Increase Income" << std::endl;
    std::cout << "[3] - Eat" << std::endl;
    std::cout << "[4] - Sleep" << std::endl;
    std::cout << "[5] - Gym" << std::endl;
    std::cout << "[6] - Exit" << std::endl;
}

// Player entry and gift
void Entry(){
    std::cout << "Enter your nickname: ";
    std::getline(std::cin, Nickname);

    std::cout << "A $1000 cash prize for testing my project :)" << std::endl;
    Cash += 1000;
    Pause();
}

// Gets menu choice
void ChooseFunction(){
    std::cout << "Choose: ";
    std::cin >> Choose;
}

int main(){
    Entry();

    while (true){
        ClearConsole();
        LimitsLogic();

        if (!HealthLogic()){
            return 0;
        }

        Statistics();
        MainMenu();
        ChooseFunction();

        switch (Choose){
        case 1:
            if (Hunger >= 10 && Energy >= 10 && Durability >= 10){
                Hunger -= 10;
                Energy -= 10;
                Durability -= 10;
                Health--;
                Cash += IncomeMultiplier * 75;
                Age++;
            }
            else{
                std::cout << "You don't have enough energy, stamina, or appetite to work!" << std::endl;
            }
            Pause();
            break;

        case 2:
            std::cout << "[$5 = 0.1 Multiplier] Enter amount: ";
            std::cin >> Amount;

            if (Amount <= Cash && Amount > 0){
                Cash -= Amount;
                IncomeMultiplier += 0.1 * (Amount / 5.0);
            }
            else{
                std::cout << "Invalid or insufficient cash!" << std::endl;
            }
            Pause();
            break;

        case 3:
            Hunger += 100;
            Pause();
            break;

        case 4:
            Energy += 100;
            Hunger -= 10;
            Health--;
            Pause();
            break;

        case 5:
            Health += 100;
            Durability += 100;
            Energy -= 10;
            Pause();
            break;

        case 6:
            return 0;

        default:
            std::cout << "Invalid Selection!" << std::endl;
            Pause();
            break;
        }
    }
}

