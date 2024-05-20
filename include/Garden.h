#pragma once
#include <memory>
#include <map>
#include "Environment.h"
#include "Plant.h"
#include "ILogger.h"

class Garden : public EnvironmentObserver, public std::enable_shared_from_this<Garden> {
public:
    Garden(std::shared_ptr<Environment> environment, std::shared_ptr<ILogger> logger);
    void addPlant(const std::shared_ptr<Plant>& plant);
    void updateGarden();
    void displayStatus() const;
    void onEnvironmentChanged(const EnvironmentEvent& event) override;
    void renamePlant(const std::string& oldName, const std::string& newName);
    std::string assignName(std::string baseName);
    void initialize();
    void waterAll();
    void fertilizeAll();
    Environment& getEnvironment();
    virtual ~Garden() {}

private:
    std::vector<std::shared_ptr<Plant>> plants;
    std::shared_ptr<Environment> environment;
    std::shared_ptr<ILogger> logger;
    std::map<std::string, int> nameCount;
};
