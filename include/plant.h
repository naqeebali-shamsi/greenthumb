#pragma once
#include <string>

class Plant {
public:
    Plant(std::string name = "", double health = 100);
    void water();
    void addFertilizer();
    void updateHealth();
    std::string getName() const;
    std::string setName(std::string name);
    double getHealth() const;
    double getWaterLevel() const;
    int getGrowthStage() const;

private:
    std::string name;
    double health;
    int growthStage;
    double waterLevel;
};