#include <iostream>
#include <random>
#include <array>
#include "Plant.h"
#include "Namegen.h"

Plant::Plant(std::string name, double health) : health(health), growthStage(1), waterLevel(50)
{
    if (name.empty())
    {
        NameGen::Generator generator("sV i");
        this->name = generator.toString();
        std::cout << "Plant name: " << this->name << std::endl;
    }
    else
    {
        this->name = name;
    }
}

void Plant::water()
{
    waterLevel += 20;
    if (waterLevel > 100)
        waterLevel = 100;
}

void Plant::addFertilizer()
{
    growthStage++;
}

void Plant::updateHealth()
{
    health += growthStage - (100 - waterLevel) * 0.1;
    if (health > 100)
        health = 100;
    else if (health < 0)
        health = 0;
}

std::string Plant::getName() const
{
    return name;
}

std::string Plant::setName(std::string name)
{
    this->name = name;
    return name;
}

double Plant::getHealth() const
{
    return health;
}

double Plant::getWaterLevel() const
{
    return waterLevel;
}

int Plant::getGrowthStage() const
{
    return growthStage;
}
