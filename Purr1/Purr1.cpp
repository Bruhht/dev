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
    string heroname;
public:
    Hero(Weapon* weapon,int health = 100,int damage = 20,string heroname="Герой") : weapon(weapon), health(health), damage(damage),heroname(heroname) {}
    void setWeapon(Weapon* wp) {
        weapon = wp;
        cout << "\nЗброю змінено\n";
    }
    void changeHero(Hero* hr) {
        heroname = hr->heroname;
        cout << "\nЗмінено героя\n";
    }
    virtual void usehero() const {
        cout << "\nГерой " << heroname << " Використав зброю:"; weapon->useweapon(); cout << ",здоров'я:" << health << ",шкода:" << damage << "\n";
    };
    virtual ~Hero() = default;
};
class Mage : public Hero {
public:
    Mage(Weapon* weapon, int health = 80, int damage = 25,string heroname = "Маг") : Hero(weapon, health, damage, heroname) {};
};
class Knight : public Hero {
public:
    Knight(Weapon* weapon, int health = 120, int damage = 40, string heroname = "Лицар") : Hero(weapon, health, damage, heroname) {};
};
class Shooter : public Hero {
public:
    Shooter(Weapon* weapon, int health = 70, int damage = 30, string heroname = "Стрілець") : Hero(weapon, health, damage, heroname) {};
};
class Fighter : public Hero {
public:
    Fighter(Weapon* weapon, int health =100, int damage = 20, string heroname = "Боєць") : Hero(weapon, health, damage, heroname) {};
};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Bow num1;
    Axe num2;
    Mage h1(&num1);
    h1.usehero();
    h1.setWeapon(&num2);
    h1.usehero();
    Knight hero(&num1);
    h1.changeHero(&hero);
    h1.usehero();
}

