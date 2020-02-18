// main.cpp
//
// Owlery Community Server Toolbox
// Faction Generator v0.1.0
//
// Copyright © 2020 GHIFARI160.

#include <iostream>

#include "Faction.h"
#include "Team.h"

void printHeader();
void promptAndValidate(std::string prompt, std::vector<std::string> *validators, std::string *input);
void promptUserForTeams(Faction *faction);

void printTeamDetails(std::vector<Team> *teams);
void printCommandsInteractively(std::vector<Team> *teams);

void createFaction(Faction *faction);

int main(int argc, const char * argv[])
{
    printHeader();
    
    Faction faction;
    createFaction(&faction);

    std::string input{""};

    promptUserForTeams(&faction);

    std::vector<Team> teams = faction.getTeams();

    std::cout << std::endl;
    printTeamDetails(&teams);
    
    std::vector<std::string> validators{ "y", "n" };
    promptAndValidate("Generate commands? (y/n) ", &validators, &input);
    
    if(input == "y")
        printCommandsInteractively(&teams);
    
    return 0;
}

void printHeader()
{
    std::cout << "Owlery Community Server Toolbox\n";
    std::cout << "Faction Generator v0.1.0\n\n";
}

void promptAndValidate(std::string prompt, std::vector<std::string> *validators, std::string *input)
{
    bool inputIsValid{false};
    std::string uInput;
    
    std::cout << prompt;
    
    while(!inputIsValid)
    {
        std::getline(std::cin, uInput);
        
        for(unsigned int i = 0; i < validators->size(); i++)
        {
            if(validators->at(i) == uInput)
                inputIsValid = true;
        }
        
        if(!inputIsValid && uInput == "list")
        {
            std::cout << "Valid inputs: [ ";
            
            for(unsigned int i = 0; i < validators->size(); i++)
                std::cout << validators->at(i) << " ";
            
            std::cout << "]. " << prompt;
        }
        else if(!inputIsValid)
            std::cout << "Invalid input: " << uInput << ". " << prompt;
    }
    
    input->assign(uInput);
}

void promptUserForTeams(Faction *faction)
{
    std::string input{""};

    while(input != "n")
    {
        std::cout << "Team Suffix: ";
        std::getline(std::cin, input);
        Team t{faction->getFactionName() + input};

        std::cout << "Display Name: ";
        std::getline(std::cin, input);
        t.setDisplayName((input != "") ? input : faction->getDisplayName());

        std::cout << "Prefix: ";
        std::getline(std::cin, input);
        t.setPrefix(faction->getPrefix() + input);

        std::cout << "Suffix: ";
        std::getline(std::cin, input);
        t.setSuffix(faction->getSuffix() + input);

        faction->initTeam(&t);
        faction->addTeam(t);

        std::cout << "\nTeams:\n";
        std::cout << faction->getTeamsList() << std::endl;

        std::vector<std::string> validators{ "y", "n" };
        promptAndValidate("Add another team? (y/n) ", &validators, &input);
    }
}

void printTeamDetails(std::vector<Team> *teams)
{
    for(size_t i = 0; i < teams->size(); i++)
        std::cout << teams->at(i).getTeamDetails() << std::endl;
}

void printCommandsInteractively(std::vector<Team> *teams)
{
    std::string input;
    
    size_t i = 0;
    size_t t = 0;
    for(; t < teams->size();)
    {
        if(i > 8)
            i = 0;
        
        if(i == 0)
            std::cout << teams->at(t).getCommand_init();
        else if(i == 1)
            std::cout << teams->at(t).getCommand_collisionRule();
        else if(i == 2)
            std::cout << teams->at(t).getCommand_color();
        else if(i == 3)
            std::cout << teams->at(t).getCommand_deathMessageVisibility();
        else if(i == 4)
            std::cout << teams->at(t).getCommand_friendlyFire();
        else if(i == 5)
            std::cout << teams->at(t).getCommand_nametagVisibility();
        else if(i == 6)
            std::cout << teams->at(t).getCommand_prefix();
        else if(i == 7)
            std::cout << teams->at(t).getCommand_seeFriendlyInvisibles();
        else if(i == 8)
        {
            std::cout << teams->at(t).getCommand_suffix();
            t++;
        }
            
        i++;
        
        std::getline(std::cin, input);
    }
}

void createFaction(Faction *faction)
{
    std::string input;
    std::vector<std::string> validators;
    
    std::cout << "Faction Name: ";
    std::getline(std::cin, input);
    faction->setName(input);
    
    std::cout << "Display Name: ";
    std::getline(std::cin, input);
    faction->setDisplayName(input);
    
    validators = { "always", "pushOtherTeams", "pushOwnTeam", "never" };
    promptAndValidate("collisionRule: ", &validators, &input);
    faction->setCollisionRule(input);
    
    validators = { "aqua", "black", "blue", "dark_aqua", "dark_blue", "dark_gray", "dark_green", "dark_purple", "dark_red", "gold", "gray", "green", "light_purple", "red", "white", "yellow" };
    promptAndValidate("color: ", &validators, &input);
    faction->setColor(input);

    validators = { "always", "hideForOtherTeams", "hideForOwnTeam", "never" };
    promptAndValidate("deathMessageVisibility: ", &validators, &input);
    faction->setDeathMessageVisibility(input);
    
    validators = { "true", "false" };
    promptAndValidate("friendlyFire (true/false): ", &validators, &input);
    faction->setFriendlyFire(input);
    
    validators = { "always", "hideForOtherTeams", "hideForOwnTeam", "never" };
    promptAndValidate("nametagVisibility: ", &validators, &input);
    faction->setNametagVisibility(input);
    
    std::cout << "prefix: ";
    std::getline(std::cin, input);
    faction->setPrefix(input);
    
    validators = { "true", "false" };
    promptAndValidate("seeFriendlyInvisibles (true/false): ", &validators, &input);
    faction->setFriendlyInvisibles(input);
    
    std::cout << "suffix: ";
    std::getline(std::cin, input);
    faction->setSuffix(input);
}
