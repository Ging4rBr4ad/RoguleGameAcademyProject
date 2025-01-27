#include "classLibROGULE.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////РЕАЛИЗАЦИЯ КЛАССА HERO//////////////////////////
//////////////////////////////////////////////////////////////////////////

Hero::Hero(int powerP, int defenceP, int HPp,
        int magicP, std::string nameP)
        :
        power{ powerP }, defence{ defenceP },
        HPmax{ HPp }, HPnow{ HPp }, magic{ magicP }, name{ nameP }
        {
        }

        // усиления персонажа
void Hero::powerUp(int upper)
{
    power += upper;
}
void Hero::defenceUp(int upper)
{
    defence += upper;
}
void Hero::HPup(int upper)
{
    HPmax += upper;
    HPnow = HPmax;
}
    // лечение
void Hero::Heal(int heal)
{
    HPnow += heal;
    if(HPnow > HPmax)
        HPnow = HPmax;
}
    //получение урона
void Hero::damage(int damage, int baff)
{
    int trueDamage;
    std::srand(std::time(NULL));
    trueDamage = damage - std::rand() % (defence + baff);
    HPnow -= damage;
}

    //  атаки героя
int Hero::BowAttack(int baff)
{
    std::srand(std::time(NULL));
    return (power + baff) / 100 * 75 + std::rand() % 10;
}
int Hero::SwordAttack(int baff)
{
    std::srand(std::time(NULL));
    return ((power + baff) / 100 * 95) + std::rand() % 10;
}
    // магические приемы
int Hero::MagicPunch(int baff)
{
    std::srand(std::time(NULL));
    return ((power + baff) * 1.5) + std::rand() % 12;
}
int Hero::MagicBarrier()
{
    return defence / 100 * 20;
}
int Hero::Hypnose(Monster& monster) //снижает силу монстра на 20%
{
    return monster.powerGet() / 100 * -20;
}
int Hero::Curse(Monster& monster) //снижает защиту монстра на 20%
{
    return monster.defenceGet() / 100 * -20;
}

//геттеры для заклятий монстра
int Hero::powerGet()
{
    return power;
}
int Hero::defenceGet()
{
    return defence;
}
int Hero::HPGet()
{
    return HPnow;
}
std::string Hero::nameGet()
{
    return name;
}
int Hero::magicGet()
{
    return magic;
}

std::ostream& operator<<(std::ostream& out, const Hero& hero)
{
    out << hero.name;
    return out;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////РЕАЛИЗАЦИЯ КЛАССА ITEM//////////////////////////
//////////////////////////////////////////////////////////////////////////

Item::Item(std::string nameP, int upperP, short typeP)
    : name{ nameP }, upper{ upperP }, type{ typeP }
    {
    }

Item::Item() : name{ nullptr }, upper{ 0 }, type{ 0 }
    {
    }

    //использовать
int Item::use(Hero& hero) // baff: 1 - усиление атаки, 2 - защиты
{
    //если это еда, то вылечить героя
    if(type == 1)
        hero.Heal(upper);
    //если это зелье, то усилить героя
    else if(type == 2)
        return upper;
    return;
}

    //геттеры
short Item::typeGet()
{
    return type;
}
std::string Item::nameGet()
{
    return name;
}

//выводит характеристику предмета
std::ostream& operator<<(std::ostream& out, const Item& item)
{
    out << '+' << item.upper;
    if(item.type == 1)
        out << " HP";
    else if(item.type == 2)
        out << " pow";
    else
        out << " def";
    return out;
}

bool Item::operator==(const Item& item)
{
    if((item.name == name) &&
        (item.type == type) &&
        (item.upper == upper))
        return true;
    else
        return false;

    return 0;
}

bool Item::operator!=(const Item& item)
{
    if((item.name != name) ||
        (item.type != type) ||
        (item.upper != upper))
        return true;
    else
        return false;

    return 0;
}

Item& Item::operator=(const Item& item)
{
    name = item.name;
    type = item.type;
    upper = item.upper;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////РЕАЛИЗАЦИЯ КЛАССА MONSTER///////////////////////
//////////////////////////////////////////////////////////////////////////

Monster::Monster(std::string nameP, int powerP, int defenceP, int HPp)
    : name{ nameP }, power{ powerP }, defence{ defenceP }, HPmax{ HPp }
    {
        HPnow = HPmax;
    }
Monster::Monster() : Monster{ nullptr, 0, 0, 0 }
{
    HPnow = HPmax;
}

    //получение урона
    void Monster::damage(int damage, int baff)
    {
        int trueDamage;
        std::srand(std::time(NULL));
        trueDamage = damage - std::rand() % (defence + baff);
        HPnow -= damage;
    }

// атаки
    // обычные
    int Monster::NormalAttack(int baff)
    {
        std::srand(std::time(NULL));
        return ((power + baff) / 100 * 95) + std::rand() % 10;
    }
    int Monster::HardAttack(int baff)
    {
        std::srand(std::time(NULL));
        return power + baff + ((power + baff) / 100 * 20) + std::rand() % 12;
    }
    // магия
        int Monster::MagicAttack(int baff)
        {
            std::srand(std::time(NULL));
        return power + baff + ((power + baff) / 100 * 30) + std::rand() % 12;
        }
        // лечение/защита
        void Monster::Heal()
        {
            std::srand(std::time(NULL));
            HPnow += HPmax / 100 * 15 + std::rand() % 15;
        }
        int Monster::barrier()
        {
            return defence / 100 * 15;
        }
        int Monster::powerUp()
        {
            return power / 100 * 15;
        }
        // гипнозы
        int Monster::Poison() //отравляет героя, снижает его здоровье на 30% от силы монстра
        {
            std::srand(std::time(NULL));
            return power / 100 * 30;
        }
        int Monster::PsyAttack(Hero& hero) // для монстров замка разума
        {
            // снижает силу героя на 15%
            return hero.powerGet() / 100 * -15;
        }
    //геттеры
        int Monster::powerGet()
        {
            return power;
        }
        int Monster::defenceGet()
        {
            return defence;
        }
        int Monster::HPGet()
        {
            return HPnow;
        }
        std::string Monster::nameGet()
        {
            return name;
        }
    // операторы
    Monster& Monster::operator=(const Monster& monster)
    {
        name = monster.name;
        power = monster.power;
        defence = monster.defence;
        HPmax = monster.HPmax;
        HPnow = monster.HPnow;
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const Monster& monster)
    {
        out << monster.name;
        return out;
    }

//////////////////////////////////////////////////////////////////////////
/////////////////////ИГРОВЫЕ ФУНКЦИИ И КАТСЦЕНЫ///////////////////////////
//////////////////////////////////////////////////////////////////////////

bool Fighting(int arrows, short level,
                Monster monsters[], Hero& hero, Item inventory[],
                int InvSize, int InvFull)
{
    short option{}, choose{};
    int delay{3000}; // время ожидания Sleep()
    // усиления/послабления героя/монстра
    int MonDefBaff{}, //Monster Defence Baff
        MonPowBaff{}, //Monster Power Baff
        HeroDefBaff{}, //Hero Defence Baff
        HeroPowBaff{}; //Hero Power Baff
    // ТАЙМЕРЫ усиления/послабления героя/монстра
    int MonDefTime{}, //Monster Defence Time
        MonPowTime{}, //Monster Power Time
        HeroDefTime{}, //Hero Defence Time
        HeroPowTime{}; //Hero Power Time
    //выбор монстра
    std::srand(std::time(NULL));
    Monster monster{};
    monster = monsters[std::rand() % 5];
    
    //цикл боя
    while(hero.HPGet() > 0 || monster.HPGet() > 0)
    {
                            //////////////////
                            ////ХОД ИГРОКА////
                            //////////////////
        fightMenu(option, choose, arrows,
                    monster, hero, inventory,
                    MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff,
                    InvSize, InvFull);
        // атака
        if(choose == 1)
        {
            switch(option)
            {
                case 1:
                    std::cout << hero << " used the sword.\n";
                    monster.damage(hero.SwordAttack(HeroPowBaff), MonDefBaff);
                    Sleep(delay);
                    break;
                case 2:
                    std::cout << hero << " used the bow.\n";
                    monster.damage(hero.BowAttack(HeroPowBaff), MonDefBaff);
                    Sleep(delay);
                    break;
                case 3:
                    std::cout << hero << " used the magic punch.\n";
                    monster.damage(hero.MagicPunch(HeroPowBaff), MonDefBaff);
                    Sleep(delay);
                    break;
                case 4:
                    std::cout << hero << " used the magic barrier.\n";
                    HeroDefBaff = hero.MagicBarrier();
                    HeroDefTime = 3;
                    Sleep(delay);
                    break;
                case 5:
                    std::cout << hero << " used the hypnose.\n";
                    MonPowBaff = hero.Hypnose(monster);
                    MonPowTime = 3;
                    Sleep(delay);
                    break;
                case 6:
                    std::cout << hero << " used the curse.\n";
                    MonDefBaff = hero.Curse(monster);
                    MonDefTime = 3;
                    Sleep(delay);
                    break;
            }
        }
        // минус одно использование баффа(сокращается с каждым ходом)
                HeroPowTime--;
                MonDefTime--;
                // если таймер иссяк, то анулировать бафф
                if(HeroPowTime == 0)
                    HeroPowBaff = 0;
                if(MonDefTime == 0)
                    MonDefBaff = 0;

        // применение предмета
        else
        {
            if(inventory[option - 1].typeGet() == 1)
                inventory[option - 1].use(hero);
            else if(inventory[option - 1].typeGet() == 2)
            {
                HeroPowBaff = inventory[option - 1].use(hero);
                HeroPowTime = 3;
            }
            else if(inventory[option - 1].typeGet() == 3)
            {
                HeroDefBaff = inventory[option - 1].use(hero);
                HeroDefTime = 3;
            }
            //предмет использован! Удаляем его из инвентаря и делаем сдвиг в инвенторе
            inventory[option - 1] = Item{};
            MoveInInventory(option - 1, inventory, InvSize); //текущий размер уменьшается в фукнции
        }
                            ///////////////////
                            ////ХОД МОНСТРА////
                            ///////////////////
        //вывод окна боя
            system("cls");
            PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff);
        //ожидание
            std::cout << '.';
            Sleep(400);
            std::cout << " .";
            Sleep(400);
            std::cout << " .\n\n";
            Sleep(400);

        std::srand(std::time(NULL));
        
        short MonsterAct{};
        do
        {
            MonsterAct = std::rand() % 8 + 1;
        } while((MonsterAct > 5 && level == 1) || (MonsterAct > 7 && level == 2));
        switch(MonsterAct)
        {
            case 1:
                std::cout << monster << " attacked " << hero << ".\n";
                hero.damage(monster.NormalAttack(MonPowBaff), HeroDefBaff);
                Sleep(delay);
                break;
            case 2:
                std::cout << monster << " hardly attacked " << hero << ".\n";
                hero.damage(monster.HardAttack(MonPowBaff), HeroDefBaff);
                Sleep(delay);
                break;
            case 3:
                std::cout << monster << " used a magic punch on " << hero << ".\n";
                hero.damage(monster.MagicAttack(MonPowBaff), HeroDefBaff);
                Sleep(delay);
                break;
            case 4:
                std::cout << monster << " healed itself.\n";
                monster.Heal();
                Sleep(delay);
                break;
            case 5:
                std::cout << monster << " used a magic barrier.\n";
                MonDefBaff = monster.barrier();
                MonDefTime = 3;
                Sleep(delay);
                break;
            case 6:
                std::cout << monster << " upgreated it's power.\n";
                MonPowBaff = monster.powerUp();
                MonPowTime = 3;
                Sleep(delay);
                break;
            case 7:
                std::cout << monster << " poisoned " << hero << ".\n";
                MonPowBaff = monster.Poison();
                MonPowTime = 3;
                Sleep(delay);
                break;
            case 8:
                std::cout << monster << " used a psyattack on " << hero << ".\n";
                HeroPowBaff = monster.PsyAttack(hero);
                HeroPowTime = 3;
                Sleep(delay);
                break;
        }
        // минус одно использование баффа(сокращается с каждым ходом)
                MonPowTime--;
                HeroDefTime--;
                // если таймер иссяк, то анулировать бафф
                if(MonPowTime == 0)
                    MonPowBaff = 0;
                if(HeroDefTime == 0)
                    HeroDefBaff = 0;
    }

    // кто победил?
    if(monster.HPGet() < 1)
        return 1; // герой победил
    else
        return 0; // монстр победил

    return;
}

void fightMenu(short& option, short& choose, int arrows,
                Monster& monster, Hero& hero, Item inventory[],
                int MonDefBaff, int MonPowBaff,
                int HeroDefBaff, int HeroPowBaff,
                int InvSize, int InvFull)
{
    do
    {
        do
        {
            system("cls");
            PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff);

            std::cout << "1 - Attack\n"
                        "2 - inventory\n";
            std::cin >> choose;
        } while (choose < 1 || choose > 2);

        system("cls");
        PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff);

        //выбор атаки
        if(choose == 1)
        {
            std::cout << "Magic points: " << hero.magicGet() << "/7\n";
            std::cout << "0 - back to menu <---\n"
                        "1 - Sword attack\n"
                        "2 - Bow attack\n"
                        "3 - Magic punch (7 points)\n"
                        "4 - Magic barrier / increase your defence on 20% ( 3 points )\n"
                        "5 - Hypnose / reduce monster's power on 20%( 5 points )\n"
                        "6 - Curse / reduce monster's defence on 20%( 5 points )\n";
            do
            {
                std::cout << "(Enter a number of option): ";
                std::cin >> option;
            } while(option < 0 || option > 6);
            //если игрок использует заклинание, а у него недостаточно очков
            if((option == 3 && hero.magicGet() < 7) ||
                (option == 4 && hero.magicGet() < 3) ||
                ((option == 5 || option == 6) && hero.magicGet() < 5))
            {
                std::cout << "You have not enough points!\n";
                Sleep(3000);
                option == 0;
            }
            // если герой использует лук, а у него нет стрел
            if(option == 2 && arrows == 0)
            {
                std::cout << "You have no arrows!\n";
                Sleep(3000);
                option == 0;
            }
        }
        // выбор предмета
        else
        {
            std::cout << "Your inventory: ";
            std::cout << "Your arrows: " << arrows << '\n'
                    << "0 - back to menu <---\n";
            // int i{};
            // for(; i < 10; i++)
            // {
            //     if(inventory[i].typeGet() == 0) //если слот пустой
            //         break;
            //     else //иначе вывести предмет в списке
            //         std::cout << (i + 1) << " - " << inventory[i].nameGet() << " ("
            //         << inventory[i] << ")\n";
            //     do
            //     {
            //         std::cout << "(Enter a number of option): ";
            //         std::cin >> option;
            //     } while(option < 0 || option > i);
            // }
            for(int i{1}; i < InvSize; i++)
            {
                std::cout << i << " " << inventory[i - 1].nameGet() << " ( "
                        << inventory[i - 1] << " )\n";
            }
        }
    } while(option == 0);
}


void GetItem(int& arrows, Item items[], int InvSize, int InvFull, const int Objects, Item inventory[], Monster& monster)
{
    std::srand(std::time(NULL));
    short object = std::rand() % Objects;
    
    std::cout << monster << " left " << items[object] << ".\n"
                "Would you like to take it?\n"
                "1 - Yes\n"
                "0 - No\n";
    short menuitem{};
    std::cin >> menuitem;
    if(menuitem)
    {
        if(InvSize == InvFull) //если инвентарь полон
        {
            std::cout << "Yout inventory is full!\n"
                        "Would you like to through away something?\n"
                        "1 - Yes\n"
                        "0 - No\n";
            std::cin >> menuitem;
            if(menuitem)
            {
                short objectThrough{};
                for(int i{1}; i < InvSize; i++)
                {
                    std::cout << i << ' ' << items[object].nameGet()
                                << " - " << items[object] << '\n';
                }
                do
                {
                    std::cout << "Enter a number of object: ";
                    std::cin >> objectThrough;
                } while (objectThrough < 1 || objectThrough > InvSize);
                objectThrough--;
                items[objectThrough] = items[object];
                std::cout << "You got " << items[object].nameGet() << '\n';
                Sleep(2000);
            }
        }
        else
        {
            items[InvSize] = items[object];
            InvSize++;
            std::cout << "You got " << items[object].nameGet() << '\n';
            Sleep(2000);
        }
                //УСЛОВИЯ ПОЛУЧЕНИЯ СТРЕЛ
        int arrowsPlus = std::rand() % 3;
        if(arrows == 10)
        {
            // ничего не выводится в таком случае
        }
        else if(arrows < 10 && (arrows + arrowsPlus) <= 10)
        {
            arrows += arrowsPlus;
            std::cout << "You got " << arrowsPlus << " arrows.\n";
        }
        else if(arrows < 10 && (arrows + arrowsPlus) > 10)
        {
            arrowsPlus = arrowsPlus + arrows - 10;
            arrows = 10;
            std::cout << "You got " << arrowsPlus << " arrows.\n";
        }
    }
}

void MoveInInventory(int idx, Item inventory[], int& InvSize) //индекс элемента с пустым слотом
{
    for(int i{idx}; i < InvSize - 2; i++)
        inventory[i] = inventory[i + 1];

    InvSize--;
}

void PrintFightWindow(Monster& monster, Hero& hero,
                    int MonDefBaff, int MonPowBaff,
                    int HeroDefBaff, int HeroPowBaff)
{
    std::cout
            << "Monster's power: " << (monster.powerGet() + MonPowBaff) << "\t\t"
            << hero << "'s power: " << (hero.powerGet() + HeroPowBaff) << '\n'
            << "Monster's defence: " << (monster.defenceGet() + MonDefBaff) << "\t\t"
            << hero << "'s defence: " << (hero.defenceGet() + HeroDefBaff) << '\n'
            << "Monster's HP: " << monster.HPGet() << "\t\t"
            << hero << "'s HP: " << hero.HPGet() << "\n\n";
        monster.print();
}