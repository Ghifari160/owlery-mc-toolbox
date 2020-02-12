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
void promptUserForTeams(Faction *faction);

void printTeamDetails(std::vector<Team> *teams);
void printCommandsInteractively(std::vector<Team> *teams);

Faction createFaction();

int main(int argc, const char * argv[])
{
    printHeader();
    
    Faction faction = createFaction();

    std::string input;

    promptUserForTeams(&faction);

    std::vector<Team> teams = faction.getTeams();

    std::cout << std::endl;
    printTeamDetails(&teams);
    
    std::cout << "Generate commands? (y/n) ";
    std::getline(std::cin, input);
    
    if(input == "y")
        printCommandsInteractively(&teams);
    
    return 0;
}

void printHeader()
{
    std::cout << "Owlery Community Server Toolbox\n";
    std::cout << "Faction Generator v0.1.0\n\n";
}

void promptUserForTeams(Faction *faction)
{
    std::string input;

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

        std::cout << "Add another team? (y/n) ";
        std::getline(std::cin, input);
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

Faction createFaction()
{
    Faction faction;
    std::string input;
    
    std::cout << "Faction Name: ";
    std::getline(std::cin, input);
    faction.setName(input);
    
    std::cout << "Display Name: ";
    std::getline(std::cin, input);
    faction.setDisplayName(input);
    
    std::cout << "collisionRule: ";
    std::getline(std::cin, input);
    faction.setCollisionRule(input);
    
    std::cout << "color: ";
    std::getline(std::cin, input);
    faction.setColor(input);
    
    std::cout << "deathMessageVisibility: ";
    std::getline(std::cin, input);
    faction.setDeathMessageVisibility(input);
    
    std::cout << "friendlyFire (true/false): ";
    std::getline(std::cin, input);
    faction.setFriendlyFire(input);
    
    std::cout << "nametagVisibility: ";
    std::getline(std::cin, input);
    faction.setNametagVisibility(input);
    
    std::cout << "prefix: ";
    std::getline(std::cin, input);
    faction.setPrefix(input);
    
    std::cout << "seeFriendlyInvisibles (true/false): ";
    std::getline(std::cin, input);
    faction.setFriendlyInvisibles(input);
    
    std::cout << "suffix: ";
    std::getline(std::cin, input);
    faction.setSuffix(input);
    
    return faction;
}
