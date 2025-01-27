#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

class Hero
{
    int power;
    int defence;
    int HPmax; // максимальное значение здоровья
    int HPnow;
    int magic;
    const int magicMax{ 7 }; //максимальное количество очков - 7
    std::string name;
public:
    Hero(int powerP, int defenceP, int HPp,
        int magicP, std::string nameP);
    Hero() = delete;
    // усиления персонажа
    void powerUp(int upper);
    void defenceUp(int upper);
    void HPup(int upper);

    // лечение
    void Heal(int heal);
    //получение урона
    void damage(int damage, int baff);
    
    //  атаки героя
    int BowAttack(int baff);
    int SwordAttack(int baff);
    // магические приемы
    int MagicPunch(int baff);
    int MagicBarrier();
    int Hypnose(Monster& monster);
    int Curse(Monster& monster);

    //геттеры
    int powerGet();
    int defenceGet();
    int HPGet();
    std::string nameGet();
    int magicGet();
    
    friend std::ostream& operator<<(std::ostream& out, const Hero& hero);
};



class Item
{
    // характеристики вещи
    std::string name;
    int upper; // количество единиц лечения или усиления защиты/силы атаки
    short type; // тип вещи: 1 - целитель 2 - усилитель атаки, 3 - усилитель защиты
public:
    Item(std::string nameP, int upperP, short typeP);
    Item();
    //использовать
    int use(Hero& hero);
    //геттеры
    short typeGet();
    std::string nameGet();

    //выводит характеристику предмета
    friend std::ostream& operator<<(std::ostream& out, const Item& item);
    bool operator==(const Item& item);
    bool operator!=(const Item& item);
    Item& operator=(const Item& item);
};



class Monster
{
    std::string name;
    int power;
    int defence;
    int HPmax; // максимальное значение здоровья
    int HPnow;
public:
    Monster(std::string nameP, int powerP, int defenceP, int HPp);
    Monster();

    // получение урона
    void damage(int damage, int baff);
    // атаки
        // обычные
        int NormalAttack(int baff);
        int HardAttack(int baff);
        // магия
        int MagicAttack(int baff);
        // лечение/защита/усиление
        void Heal();
        int barrier();
        int powerUp();
        // гипнозы
        int Poison();
        int PsyAttack(Hero& hero); // для монстров замка разума
    
    //геттеры
    int powerGet();
    int defenceGet();
    int HPGet();
    std::string nameGet();
    //вывод облика монстра
    void print();
    void SetPrint(const char* image);

    friend std::ostream& operator<<(std::ostream& out, const Monster& monster);
    Monster& operator=(const Monster& monster);
};


void Scene(short level);

void PrintFightWindow(Monster& monster, Hero& hero,
                    int MonDefBaff, int MonPowBaff,
                    int HeroDefBaff, int HeroPowBaff);

void fightMenu(short& option, short& choose, int arrows,
                Monster& monster, Hero& hero, Item inventory[],
                int MonDefBaff, int MonPowBaff,
                int HeroDefBaff, int HeroPowBaff);

bool Fighting(int arrows, short level,
                Monster monsters[], Hero& hero, Item inventory[],
                int InvSize, int InvFull);

void GetItem(int& arrows, Item items[], int InvSize, int InvFull, const int Objects, Item inventory[], Monster& monster);

void MoveInInventory(int idx, Item inventory[], int& InvSize);