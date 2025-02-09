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
    double def = defence;
    trueDamage = damage - std::rand() % (int)(def / 3 * 2 + baff);
    HPnow -= trueDamage;
}

    //  атаки героя
int Hero::BowAttack(int baff)
{
    std::srand(std::time(NULL));
    double pow = power + baff;
    return (pow / 100 * 105) + std::rand() % 5;
}
int Hero::SwordAttack(int baff)
{
    std::srand(std::time(NULL));
    double pow = power + baff;
    return (pow / 100 * 90) + std::rand() % 5;
}
    // магические приемы
int Hero::MagicPunch(int baff)
{
    std::srand(std::time(NULL));
    return ((power + baff) * 1.5) + std::rand() % 5;
}
int Hero::MagicBarrier()
{
    double def = defence;
    return (def / 100 * 25);
}
int Hero::Hypnose(Monster& monster) //снижает силу монстра на 20%
{
    double pow = monster.powerGet();
    return pow / 100 * -20;
}
int Hero::Curse(Monster& monster) //снижает защиту монстра на 20%
{
    double def = monster.defenceGet();
    return def / 100 * -20;
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
int Hero::HPGetMax()
{
    return HPmax;
}
std::string Hero::nameGet()
{
    return name;
}
int Hero::magicGet()
{
    return magic;
}

//сеттеры?
void Hero::nameSet(std::string nameP)
{
    name = nameP;
}
void Hero::PlusMagPoint()
{
    if(magic < 7)
    magic++;
}
void Hero::MagSpend(int points)
{
    magic -= points;
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
    return 0;
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
    return *this;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////РЕАЛИЗАЦИЯ КЛАССА MONSTER///////////////////////
//////////////////////////////////////////////////////////////////////////

Monster::Monster(std::string nameP, int powerP, int defenceP, int HPp)
    : name{ nameP }, power{ powerP }, defence{ defenceP }, HPmax{ HPp }
    {
        HPnow = HPmax;
    }

    //получение урона
    void Monster::damage(int damage, int baff)
    {
        int trueDamage;
        std::srand(std::time(NULL));
        double def = defence;
        trueDamage = damage - std::rand() % (int)(def / 3 * 2 + baff);
        HPnow -= trueDamage;
    }

// атаки
    // обычные
    int Monster::NormalAttack(int baff)
    {
        std::srand(std::time(NULL));
        double pow = power + baff;
        return (pow / 100 * 90) + std::rand() % 5;
    }
    int Monster::HardAttack(int baff)
    {
        std::srand(std::time(NULL));
        double pow = power + baff;
        return (pow / 100 * 120) + std::rand() % 5;
    }
    // магия
        int Monster::MagicAttack(int baff)
        {
            std::srand(std::time(NULL));
            double pow = power + baff;
            return (pow / 100 * 135) + std::rand() % 5;
        }
        // лечение/защита
        void Monster::Heal()
        {
            std::srand(std::time(NULL));
            double HPm = HPmax;
            HPnow += HPm / 100 * 15 + std::rand() % 5;
            if(HPnow > HPmax)
                HPnow = HPmax;
        }
        int Monster::barrier()
        {
            double def = defence;
            return (def / 100 * 25);
        }
        int Monster::powerUp()
        {
            double pow = power;
            return (pow / 100 * 25);
        }
        // гипнозы
        int Monster::Poison() //отравляет героя, снижает его здоровье на 30% от силы монстра
        {
            std::srand(std::time(NULL));
            double pow = power;
            return (pow / 100 * 35);
        }
        int Monster::PsyAttack(Hero& hero) // для монстров замка разума
        {
            // снижает силу героя на 15%
            double pow = hero.powerGet();
            return (pow / 100 * -15);
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
        int Monster::HPGetMax()
        {
            return HPmax;
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
        printImage = monster.printImage;
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const Monster& monster)
    {
        out << monster.name;
        return out;
    }

    //вывод облика монстра
    void Monster::print()
    {
        std::cout << printImage;
    }
    void Monster::SetPrint(const char* image)
    {
        printImage = image;
    }

//////////////////////////////////////////////////////////////////////////
/////////////////////ИГРОВЫЕ ФУНКЦИИ И КАТСЦЕНЫ///////////////////////////
//////////////////////////////////////////////////////////////////////////

bool Fighting(int arrows, short level,
                Monster monsters[], Hero& hero, Item inventory[],
                int& InvSize, const int InvFull,
                Item items[], int const Objects, short fights)
{
    short option{}, choose{};
    int delay{1500}; // время ожидания Sleep()
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
    Monster monster{"", 0, 0, 0};
    monster = monsters[std::rand() % 5];
    
    //цикл боя
    while(hero.HPGet() > 0 && monster.HPGet() > 0)
    {
                            //////////////////
                            ////ХОД ИГРОКА////
                            //////////////////
        fightMenu(option, choose, arrows,
                    monster, hero, inventory,
                    MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff,
                    InvSize, InvFull, fights);
        // атака
        if(choose == 1)
        {
            switch(option)
            {
                case 1:
                    std::cout << hero << " used the sword.\n";
                    monster.damage(hero.SwordAttack(HeroPowBaff), MonDefBaff);
                    hero.PlusMagPoint();
                    Sleep(delay);
                    break;
                case 2:
                    std::cout << hero << " used the bow.\n";
                    monster.damage(hero.BowAttack(HeroPowBaff), MonDefBaff);
                    hero.PlusMagPoint();
                    arrows--;
                    Sleep(delay);
                    break;
                case 3:
                    std::cout << hero << " used the magic punch.\n";
                    monster.damage(hero.MagicPunch(HeroPowBaff), MonDefBaff);
                    hero.MagSpend( 7 ); //тратится 7 очков магии на это заклинание
                    Sleep(delay);
                    break;
                case 4:
                    std::cout << hero << " used the magic barrier.\n";
                    HeroDefBaff = hero.MagicBarrier();
                    HeroDefTime = 3 + 1;
                    hero.MagSpend( 3 ); //тратится 3 очков магии на это заклинание
                    Sleep(delay);
                    break;
                case 5:
                    std::cout << hero << " used the hypnose.\n";
                    MonPowBaff = hero.Hypnose(monster);
                    MonPowTime = 3 + 1;
                    hero.MagSpend( 5 ); //тратится 5 очков магии на это заклинание
                    Sleep(delay);
                    break;
                case 6:
                    std::cout << hero << " used the curse.\n";
                    MonDefBaff = hero.Curse(monster);
                    MonDefTime = 3 + 1;
                    hero.MagSpend( 5 ); //тратится 5 очков магии на это заклинание
                    Sleep(delay);
                    break;
            }
            // минус одно использование баффа(сокращается с каждым ходом)
                HeroPowTime--;
                MonDefTime--;
                // если таймер иссяк, то анулировать бафф
                if(HeroPowTime == 0)
                    HeroPowBaff = 0;
                if(MonDefTime == 0)
                    MonDefBaff = 0;

        }
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
            inventory[option - 1] = Item{"", 0, 0};
            MoveInInventory(option - 1, inventory, InvSize); //текущий размер уменьшается в фукнции
        }

        //если монстр уже побежден, он не может атаковать. Выход из цикла
        if(monster.HPGet() < 1)
            break;

                            ///////////////////
                            ////ХОД МОНСТРА////
                            ///////////////////
        //вывод окна боя
            system("cls");
            PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff, fights);
        //ожидание
            std::cout << '.';
            Sleep(400);
            std::cout << " .";
            Sleep(400);
            std::cout << " .\n\n";
            Sleep(400);
        
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
                MonDefTime = 3 + 1;
                Sleep(delay);
                break;
            case 6:
                std::cout << monster << " upgreated it's power.\n";
                MonPowBaff = monster.powerUp();
                MonPowTime = 3 + 1;
                Sleep(delay);
                break;
            case 7:
                std::cout << monster << " poisoned " << hero << ".\n";
                MonPowBaff = monster.Poison();
                MonPowTime = 3 + 1;
                Sleep(delay);
                break;
            case 8:
                std::cout << monster << " used a psyattack on " << hero << ".\n";
                HeroPowBaff = monster.PsyAttack(hero);
                HeroPowTime = 3 + 1;
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
    {
        GetItem(arrows, items, InvSize, InvFull, Objects, inventory, monster);
        return 1; // герой победил
    }
    else
        return 0; // монстр победил

    return 0;
}

void fightMenu(short& option, short& choose, int arrows,
                Monster& monster, Hero& hero, Item inventory[],
                int MonDefBaff, int MonPowBaff,
                int HeroDefBaff, int HeroPowBaff,
                int& InvSize, const int InvFull, short fights)
{
    do
    {
        do
        {
            system("cls");
            PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff, fights);

            std::cout << "1 - Attack\n"
                        "2 - inventory\n";
            std::cin >> choose;
        } while (choose < 1 || choose > 2);

        system("cls");
        PrintFightWindow(monster, hero, MonDefBaff, MonPowBaff, HeroDefBaff, HeroPowBaff, fights);

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
                option = 0;
            }
            // если герой использует лук, а у него нет стрел
            if(option == 2 && arrows == 0)
            {
                std::cout << "You have no arrows!\n";
                Sleep(3000);
                option = 0;
            }
        }
        // выбор предмета
        else
        {
            std::cout << "Your inventory: ";
            std::cout << "Your arrows: " << arrows << '\n'
                    << "0 - back to menu <---\n";
            for(int i{}; i < InvSize; i++)
            {
                std::cout << (i + 1) << " " << inventory[i].nameGet() << " ( "
                        << inventory[i] << " )\n";
            }
            do
            {
                    std::cout << "(Enter a number of option): ";
                    std::cin >> option;
            } while(option < 0 || option > InvSize);
        }
    } while(option == 0);
}


void GetItem(int& arrows, Item items[], int& InvSize, const int InvFull, const int Objects, Item inventory[], Monster& monster)
{
    std::srand(std::time(NULL));
    short object = std::rand() % Objects;
    
    std::cout << monster << " left " << items[object].nameGet() << " ( "<< items[object] << " ).\n"
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
                for(int i{0}; i < InvSize; i++)
                {
                    std::cout << (i + 1) << ' ' << items[object].nameGet()
                                << " - " << items[object] << '\n';
                }
                do
                {
                    std::cout << "Enter a number of object: ";
                    std::cin >> objectThrough;
                } while (objectThrough < 1 || objectThrough > InvSize);
                objectThrough--;
                inventory[objectThrough] = items[object];
            }
        }
        else
        {
            inventory[InvSize] = items[object];
            InvSize++;
        }

        std::cout << "You got " << items[object].nameGet() << '\n';


                //УСЛОВИЯ ПОЛУЧЕНИЯ СТРЕЛ
        int arrowsPlus = std::rand() % 3;
        if(arrows < 10 && (arrows + arrowsPlus) <= 10)
        {
            arrows += arrowsPlus;
        }
        else if(arrows < 10 && (arrows + arrowsPlus) > 10)
        {
            arrowsPlus = arrowsPlus + arrows - 10;
            arrows = 10;
        }

        std::cout << "Also you got " << arrowsPlus << " arrows.\n";
        Sleep(2000);
    }
}

void MoveInInventory(int idx, Item inventory[], int& InvSize) //индекс элемента с пустым слотом
{
    for(int i{idx}; i < InvSize; i++)
        inventory[i] = inventory[i + 1];

    InvSize--;
}

void PrintFightWindow(Monster& monster, Hero& hero,
                    int MonDefBaff, int MonPowBaff,
                    int HeroDefBaff, int HeroPowBaff, short fights)
{
    std::cout << "\t" << monster << " is atacking you!\n\n"
            << "\t\t" << (fights + 1) << "/3 fights\n"
            << "Monster's power: " << (monster.powerGet() + MonPowBaff) << "\t\t"
            << hero << "'s power: " << (hero.powerGet() + HeroPowBaff) << '\n'
            << "Monster's defence: " << (monster.defenceGet() + MonDefBaff) << "\t\t"
            << hero << "'s defence: " << (hero.defenceGet() + HeroDefBaff) << '\n'
            << "Monster's HP: " << monster.HPGet() << '/' << monster.HPGetMax() << "\t\t"
            << hero << "'s HP: " << hero.HPGet() << '/' << hero.HPGetMax()<< "\n\n";
        monster.print();
    std::cout << "\n\n";
}