#include "HashTable.hpp"
#include <iostream>
#include <vector>


 
int main(void){
    std::vector<std::string> arr = 
    {    
    "apple", "banana", "cherry", "dragon", "echo", "falcon", "galaxy", "horizon", "icicle", "jupiter",  
    "koala", "lantern", "mango", "nebula", "octopus", "pyramid", "quantum", "rocket", "saturn", "tornado",  
    "unicorn", "vortex", "wildfire", "xenon", "yellow", "zephyr", "alpha", "bravo", "cobra", "delta",  
    "epsilon", "fiesta", "glacier", "harbor", "illusion", "jungle", "karma", "leviathan", "monsoon", "neutron",  
    "oracle", "phoenix", "quasar", "rainbow", "skyline", "tempest", "utopia", "velocity", "whirlwind", "xylophone",  
    "yeti", "zodiac", "amber", "basilisk", "crystal", "domino", "evergreen", "furnace", "geyser", "halogen",  
    "inertia", "jackpot", "krypton", "labyrinth", "momentum", "nitrogen", "obsidian", "panorama", "quiver", "resonance",  
    "symphony", "tornado", "ultraviolet", "voyager", "whistler", "xenophobia", "yucca", "zirconium", "abyss", "blizzard",  
    "catalyst", "dynamo", "eclipse", "frontier", "goliath", "hurricane", "infinity", "jigsaw", "knuckle", "luminous",  
    "mystic", "nucleus", "oxygen", "pendulum", "quagmire", "ripple", "tsunami", "ultraviolet", "velocity", "whirlwind",  
    "xenon", "yellowstone", "zeppelin"

    };
    HashTable test;

    for(int i = 0; i < arr.size(); i++)
    {
        test.insert(arr[i]);
        test.cuckoo(arr[i]);
    }

    return 0;
}

