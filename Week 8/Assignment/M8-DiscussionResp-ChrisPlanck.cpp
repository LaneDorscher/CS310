/* Author: Chris Planck
 * 
    
    
 * Editor:  Lane Dorscher
 * Date:    05/08/2026
 */

#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string playerName;
    int health;

public:
    void setPlayer(string name, int hp) {
        playerName = name; // EDITOR NOTE: added semi-colon
        health = hp;
    }

    void displayPlayer() {
        cout << "Player: " << playerName << endl;
        cout << "Health: " << health << endl;
    }
};

class Weapon {
private:
    string weaponName;
    int damage;

public:
    void setWeapon(string wName, int dmg) {
        weaponName = wName;
        damage = dmg;
    }

    void displayWeapon() {
        cout << "Weapon: " << weaponName << endl;
        cout << "Damage: " << damage << endl;
    }
};

int main() {
    Player gamer;
    Weapon sword;

    gamer.setPlayer("Knight", 100);
    sword.setWeapon("Dragon Slayer", 50);

    gamer.displayPlayer();
    sword.displayWeapon(); //Editor note: added semi-colon

    return 0;
}
