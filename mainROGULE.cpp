#include "classLibROGULE.h"
//#include "catScenesROGULE.cpp"

int main()
{
    short LEVEL{}, //для катсцен
        fights{}, //счетчик боев за уровень
        Try{ 1 }; //(проигрыш)попытаться еще раз или нет

            // массивы монстров трех локаций
    //Эхо топи
    Monster SwampMonsters[5]
    {
        {"Mukka", 12, 20, 55},
        {"Mad tree", 10, 10, 30},
        {"Silhouette in the fog", 9, 2, 60},
        {"Whale shark", 15, 11, 33}, 
        {"The sank fisher", 13, 13, 33}
    };
    // вьющийся сад
    Monster GardenMonsters[5]
    {
        {"What is in the bushes", 8, 40, 30},
        {"Annoyng mosquito", 5, 50, 15},
        {"chinchilla with a flute", 15, 15, 40},
        {"Mocking hydrangeas", 17, 13, 25}, 
        {"Fire-breathing ferret", 20, 10, 35}
    };
    // замок разума
    Monster CastleMonsters[5]
    {
        {"Unfinished sketch", 24, 20, 55},
        {"Poem \"Memoris about Jeronimo\"", 32, 33, 90},
        {"Sculpture \"musa\"", 22, 30, 100},
        {"Picture\"Ballerina and her swans\"", 23, 20, 58}, 
        {"Tapestry\"Eclipse\"", 27, 15, 60}
    };

    SetMonstersImage(SwampMonsters, GardenMonsters, CastleMonsters);

    //сила, защита, здоровье, мана, имя
        std::string heroName{};
        Hero hero{13, 12, 45, 0, heroName};

        //возможные вещи в игре
    //зелья
        Item PowerPotion{"Power potion", 8, 2};
        Item Shield{"Shield", 8, 3};

        Item PeaceOfFog{"Peace of fog", 5, 3};
        Item CoolStick{"Cool stick", 6, 2};
        Item WetLeaves{"Wet leaves", 7, 3};

        Item Roses{"Roses", 10, 2};
        Item Flute{"Flute?", 12, 2};
        Item SheepFur{"Sheep's fur", 8, 3};

        Item Gouache{"Gouache", 12, 2};
        Item Crayons{"Crayons", 20, 3};
        Item Clay{"Clay", 14, 3};
    //еда
        Item Fish{"Fish from swamp", 8, 1};
        Item Aplant{"Delicious plant", 30, 1};
        Item Snail{"A snail", 13, 1};

        Item Honey{"A jar of honey!", 20, 1};
        Item Flowers{"Flowers", 16, 1};
        Item Bees{"Bees", 11, 1};

        Item PeaceOfPaper("Peace of paper", 13, 1);
        Item LeftSandwich("Left sandwich", 22, 1);
        Item Undrinkedtea{"Undrinked tea", 18, 1};
        //массивы вещей из трех локаций
    Item emptyItem{ "", 0, 0 };

    int const Objects{8};
    Item SwampItems[Objects]{PowerPotion, Shield, PeaceOfFog, Fish, Aplant, CoolStick, Snail, WetLeaves};

    Item GardenItems[Objects]{PowerPotion, Shield, SheepFur, Bees, Flowers, Roses, Flute, Honey};

    Item CastleItems[Objects]{PowerPotion, Shield, PeaceOfPaper, Gouache, LeftSandwich, Clay, Undrinkedtea, Crayons};

    int arrows{ 10 };
    int InvSize{}, // текущее количество предметов
        InvFull{ 10 }; // полный инвентарь
    Item inventory[10]{{emptyItem},{emptyItem},{emptyItem},
                       {emptyItem},{emptyItem},{emptyItem},
                       {emptyItem},{emptyItem},{emptyItem},
                       {emptyItem}}; // пустой инвентарь


    //СОЗДАНИЕ ГЕРОЯ. ИМЯ ГЕРОЯ. (LEVEL = 0)
        Scene(LEVEL, heroName, inventory, InvSize);
        hero.nameSet(heroName);

    //ЭХО-ТОПИ (LEVEL = 1)
            Scene(LEVEL, heroName, inventory, InvSize);

        do
        {
            //при победе
            if ( Fighting(arrows, LEVEL,
                    SwampMonsters, hero, inventory,
                    InvSize, InvFull, 
                    SwampItems, Objects, fights) )
            {
                fights++;
            }
            //при поражении
            else
            {
                fights = 0;
                std::cout << "\t\t--- GAME OVER ---\n\n"
                        "\t\tTry again?\n"
                        "\t1 - Yes\n"
                        "\t0 - No\n";
                std::cin >> Try;
                if(Try == 1)
                    Try = true;
                else
                    return 0;
            }
            hero.Heal(100);//лечение героя после боя
        } while(fights != 3 && Try);

        fights = 0;
        //усиление персонажа после прохождения уровня
        hero.powerUp(6);
        hero.defenceUp(5);
        hero.HPup(18);
    

    //ВЬЮЩИЙСЯ САД (LEVEL = 2)
            system("cls");
            Scene(LEVEL, heroName, inventory, InvSize);

        do
        {
            //при победе
            if ( Fighting(arrows, LEVEL,
                    GardenMonsters, hero, inventory,
                    InvSize, InvFull, 
                    GardenItems, Objects, fights) )
            {
                fights++;
            }
            //при поражении
            else
            {
                fights = 0;
                std::cout << "\t\t--- GAME OVER ---\n\n"
                        "\t\tTry again?\n"
                        "\t1 - Yes\n"
                        "\t0 - No\n";
                std::cin >> Try;
                if(Try == 0)
                    return 0;
            }
            hero.Heal(100);//лечение героя после боя
        } while(fights != 3 && Try);

        fights = 0;
        //усиление персонажа после прохождения уровня
        hero.powerUp(11);
        hero.defenceUp(7);
        hero.HPup(15);



    //БАШНЯ РАЗУМА (LEVEL = 3)
            system("cls");
            Scene(LEVEL, heroName, inventory, InvSize);

        do
        {
            //при победе
            if ( Fighting(arrows, LEVEL,
                    CastleMonsters, hero, inventory,
                    InvSize, InvFull, 
                    CastleItems, Objects, fights) )
            {
                fights++;
            }
            //при поражении
            else
            {
                fights = 0;
                std::cout << "\t\t--- GAME OVER ---\n\n"
                        "\t\tTry again?\n"
                        "\t1 - Yes\n"
                        "\t0 - No\n";
                std::cin >> Try;
                if(Try == 0)
                    return 0;
            }
            hero.Heal(100);//лечение героя после боя
        } while(fights != 3 && Try);

    //КОНЦОВКА (LEVEL = 4)
        system("cls");
        Scene(LEVEL, heroName, inventory, InvSize);

    return 0;
}