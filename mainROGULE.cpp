#include "classLibROGULE.cpp"
#include "catScenesROGULE.cpp"

int main()
{
    int LEVEL{}, //для катсцен
        fights{}; //счетчик боев за уровень

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
    Monster GardenMonster[5]
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

    std::string heroName{};
    //сила, защита, здоровье, мана, имя
    Hero hero{13, 12, 45, 0, heroName};

        //возможные вещи в игре
    //зелья
        Item PowerPotion{"Power potion", hero.powerGet() / 100 * 20, 2};
        Item Shield{"Shield", hero.defenceGet() / 100 * 20, 3};

        Item PeaceOfFog{"Peace of fog", hero.defenceGet() / 100 * 20, 3};
        Item CoolStick{"Cool stick", hero.powerGet() / 100 * 15, 2};
        Item WetLeaves{"Wet leaves", hero.defenceGet() / 100 * 15, 3};

        Item Roses{"Roses", hero.powerGet() / 100 * 20, 2};
        Item Flute{"Flute?", hero.powerGet() / 100 * 30, 2};
        Item SheepFur{"Sheep's fur", hero.defenceGet() / 100 * 30, 3};

        Item Gouache{"Gouache", hero.powerGet() / 100 * 25, 2};
        Item Crayons{"Crayons", hero.defenceGet() / 100 * 30, 3};
        Item Clay{"Clay", hero.defenceGet() / 100 * 20, 3};
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
    Item emptyItem{};

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

    // катсцены
    //Scene(LEVEL, heroName, inventory, InvSize);
    // бой

    //усиление персонажа после прохождения первого уровня
    

    return 0;
}