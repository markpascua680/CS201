/* Attacks.cpp
   Jay-Mark Pascua
   CS 201
   04/06/2020
   Holds Pokemon attacks
*/

#include "Pokemon.h"

///// Offensive Moves /////
    // Physical Moves - Uses the Pokemon's atk stats and defending Pokemon's def stat
        // Normal Attacks
Attacks QuickAttack("Quick Attack", "Normal", "Physical", 40, 100, 30);
Attacks Tackle("Tackle", "Normal", "Physical", 40, 100, 35);
Attacks Scratch("Scratch", "Normal", "Physical", 40, 100, 35);
        // Grass Attacks
Attacks VineWhip("Vine Whip", "Grass", "Physical", 45, 100, 25);
Attacks RazorLeaf("Razor Leaf", "Grass", "Physical", 55, 95, 25);
        // Fire Attacks
Attacks FireFang("Fire Fang", "Fire", "Physical", 65, 95, 15);
        // Electric Attacks
Attacks ElectroBall("Electro ball", "Electric", "Physical", 65, 100, 20);
        // Rock Attacks
Attacks Rollout("Rollout", "Rock", "Physical", 30, 90, 20);

    // Special Moves - Uses the Pokemon's spAtk stats and defending Pokemon's spDef stat
        // Fire Attacks
Attacks Ember("Ember", "Fire", "Special", 40, 100, 25);
        // Water Attacks
Attacks WaterGun("Water Gun", "Water", "Special", 40, 100, 25);
Attacks WaterPulse("Water Pulse", "Water", "Special", 60, 100, 20);
        // Electric Attacks
Attacks ThunderShock("Thunder Shock", "Electric", "Special", 40, 100, 30);


///// Defensive Moves /////
    // Affects user
Attacks Growth("Growth", "Normal", "Status", 0, 100, 40); // Raises atk and spAtk by 10%
Attacks DefenseCurl("Defense Curl", "Normal", "Status", 0, 100, 40); // Raises user's defense by 10%

    // Affects target
Attacks Smokescreen("Smokescreen", "Normal", "Status", 0, 100, 20); // Lowers target's accuracy by 10%
Attacks TailWhip("Tail Whip", "Normal", "Status", 0, 100, 30); // Lowers target's defense by 10%
Attacks PlayNice("Play Nice", "Normal", "Status", 0, 100, 20); // Lowers target's Attack by 10%


