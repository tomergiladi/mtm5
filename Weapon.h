#ifndef WEAPON_H_
#define WEAPON_H_
#include <iostream>

// defines the target values for a weapon
enum Target {
    LEVEL,
    STRENGTH,
    LIFE,
};
// a class that defines a weapon object and its methods
// a weapon has a name, target, strength, and value based on the strength and
// the target
class Weapon {
   private:
    // the weapon private field
    char* name;
    Target target;
    int hitStrength;

    // private method to get the weapon's target value
    // Level = 1, Strength =2, Life =3
    int getTargetValue() const;

   public:
    // creates a weapon with the given name,target, and strength
    explicit Weapon(const char* name, Target target, int hit_strength);

    // creates a copy of a given weapon, reallocates memory for the name to
    // avoid memory error
    Weapon(const Weapon& other);

    // assignment operator, deletes the weapon's resources and reassign them to
    // copies of the given weapon
    Weapon& operator=(const Weapon& other);

    // destroys all weapon's resources
    ~Weapon();

    // returns the target of the current weapon
    Target getTarget() const;

    // returns the strength of the current weapon
    int getHitStrength() const;

    // return the value of the current weapon based on it's strength and target
    int getValue() const;

    /*
    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;
    bool operator==(const Weapon& other) const;
    bool operator!=(const Weapon& other) const;
    */
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
};

bool operator>(const Weapon& weapon1, const Weapon& weapon2);
bool operator<(const Weapon& weapon1, const Weapon& weapon2);
bool operator==(const Weapon& weapon1, const Weapon& weapon2);
bool operator!=(const Weapon& weapon1, const Weapon& weapon2);
#endif