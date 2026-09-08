#include <iostream>
#include<windows.h>
using namespace std;

class Weapon {
protected:
    int extradmg;
    int cooldown;
    int range;
public:
    Weapon(int extradmg = 0, int cooldown = 0, int range = 0) :extradmg(extradmg), cooldown(cooldown), range(range) {};
    virtual void useweapon() const = 0;
    virtual ~Weapon() = default;
};
class Bow: public Weapon{
public:
    Bow(int extradmg = 5, int cooldown = 5, int range = 10) : Weapon(extradmg, cooldown, range) {};
    void useweapon() const override{
        cout << "Вистріл з лука, дистанція:" << range << ",додаткова шкода:" << extradmg;
    }
};
class Knife : public Weapon {
public:
    Knife(int extradmg = 10, int cooldown = 5, int range = 1) : Weapon(extradmg, cooldown, range) {};
    void useweapon() const override {
        cout << "Удар ножем, дистанція:" << range << ",додаткова шкода:" << extradmg;
    }
};
class Axe : public Weapon {
public:
    Axe(int extradmg = 15, int cooldown = 5, int range = 4) : Weapon(extradmg, cooldown, range) {};
    void useweapon() const override {
        cout << "Удар сокирою, дистанція:" << range << ",додаткова шкода:" << extradmg << ",перезарядка:" << cooldown;
    }
};
class Hero {
protected:
    Weapon* weapon;
    int health;
    int damage;
public:
    Hero(Weapon* weapon,int health,int damage): weapon(weapon),health(health),damage(damage) {}
    void setWeapon(Weapon* wp) {
        weapon = wp;
        cout << "\nЗброю змінено\n";
    }
    virtual void usehero() const = 0;
    virtual ~Hero() = default;
};
class Mage : public Hero {
public:
    Mage(Weapon* weapon, int health, int damage) : Hero(weapon, health, damage) {};
    void usehero() const override{
        cout << "Використано зброю:"; weapon->useweapon(); cout << ",здоров'я:" << health << ",шкода:" << damage;
    }
};
class Knight : public Hero {
public:
    Knight(Weapon* weapon, int health, int damage) : Hero(weapon, health, damage) {}
    void usehero() const override {
        cout << "Використано зброю:"; weapon->useweapon(); cout << ",здоров'я:" << health << ",шкода:" << damage;
    }
};
class Shooter : public Hero {
public:
    Shooter(Weapon* weapon, int health, int damage) : Hero(weapon, health, damage) {}
    void usehero() const override {
        cout << "Використано зброю:"; weapon->useweapon(); cout << ",здоров'я:" << health << ",шкода:" << damage;
    }
};
class Fighter : public Hero {
public:
    Fighter(Weapon* weapon, int health, int damage) : Hero(weapon, health, damage) {}
    void usehero() const override {
        cout << "Використано зброю:"; weapon->useweapon(); cout << ",здоров'я:" << health << ",шкода:" << damage;
    }
};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Bow num1;
    Axe num2;
    Mage h1(&num1, 100, 20);
    h1.usehero();
    h1.setWeapon(&num2);
    h1.usehero();
}

