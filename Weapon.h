#ifndef WEAPON_H_
#define WEAPON_H_
#include <iostream>
#include <string>
enum Target {
    LEVEL,
    STRENGTH,
    LIFE,
};
class Weapon {
   private:
    const std::string name;
    const Target target;
    const int hitStrength;
    int getTargetValue() const;

   public:
    explicit Weapon(const std::string& name, Target target, int hit_strength);
    Weapon(const Weapon& other) = default;
    Weapon& operator=(const Weapon& other) = default;
    ~Weapon() = default;
    Target getTarget() const;
    int getHitStrength() const;
    int getValue() const;
    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;
    bool operator==(const Weapon& other) const;
    bool operator!=(const Weapon& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);
};
#endif