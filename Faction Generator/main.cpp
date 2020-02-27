// main.cpp
//
// Owlery Community Server Toolbox
// Faction Generator
//
// Copyright © 2020 GHIFARI160.

#include <iostream>

#include <string>
#include <vector>

#include "Faction.h"
#include "Team.h"

/// Prints the tool headers
void printHeader();

/**
* Prompts the user for input and validate repeatedly
* @param prompt        Message to be prompted
* @param validators    Vector of valid inputs
* @param input            Validated input
*/
void promptAndValidate(const std::string prompt, const std::vector<std::string> &validators,
                       std::string &input);

/**
* Prompts the user to add teams to the faction
*
* @param faction   Initiated and constructed faction
*/
void promptUserForTeams(Faction &faction);

/**
* Prints the details of all member teams
*
* @param teams   Vector of member teams
*/
void printTeamDetails(const std::vector<Team> &teams);

/**
* Interactively prints all team commands. Only non-default values will have its command generated
*
* @param teams   Vector of member teams
*/
void printCommandsInteractively(const std::vector<Team> &teams);

/**
* Constructs and initiates a faction
*
* @param faction   Faction to be constructed and initiated
*/
void createFaction(Faction &faction);

int main(int argc, const char *argv[])
{
    printHeader();
    
    Faction faction;
    createFaction(faction);

    std::string input{""};
    
    std::cout << std::endl;

    promptUserForTeams(faction);

    std::vector<Team> teams = faction.getTeams();

    printTeamDetails(teams);
    
    std::vector<std::string> validators{ "y", "n" };
    promptAndValidate("Generate commands? (y/n) ", validators, input);
    
    if(input == "y")
        printCommandsInteractively(teams);
    
    return 0;
}

void printHeader()
{
    std::cout << "Owlery Community Server Toolbox\n";
    std::cout << "Faction Generator v0.1.0\n\n";
}

void promptAndValidate(const std::string prompt, const std::vector<std::string> &validators,
                       std::string &input)
{
    bool inputIsValid{false};
    
    std::cout << prompt;
    
    while(!inputIsValid)
    {
        std::getline(std::cin, input);
        
        for(unsigned int i = 0; i < validators.size(); i++)
        {
            if(validators.at(i) == input)
                inputIsValid = true;
        }
        
        if(!inputIsValid && input == "list")
        {
            std::cout << "Valid inputs: [ ";
            
            for(unsigned int i = 0; i < validators.size(); i++)
                std::cout << validators.at(i) << " ";
            
            std::cout << "]. " << prompt;
        }
        else if(!inputIsValid && input == "")
            std::cout << prompt;
        else if(!inputIsValid)
            std::cout << "Invalid input: " << input << ". " << prompt;
    }
}

void promptUserForTeams(Faction &faction)
{
    std::string input{""};

    while(input != "n")
    {
        std::cout << "Team #" << faction.getTeams().size() + 1 << std::endl;
        
        std::cout << "Name Suffix: ";
        std::getline(std::cin, input);
        Team t{faction.getFactionName() + input};

        std::cout << "Display Name Suffix: ";
        std::getline(std::cin, input);
        t.setDisplayName(faction.getDisplayName() + input);

        std::cout << "Prefix: ";
        std::getline(std::cin, input);
        t.setPrefix(faction.getPrefix() + input);

        std::cout << "Suffix: ";
        std::getline(std::cin, input);
        t.setSuffix(faction.getSuffix() + input);

        faction.initTeam(t);
        faction.addTeam(t);

        std::cout << "\nTeams:\n";
        std::cout << faction.getTeamsList(true) << std::endl;

        std::vector<std::string> validators{ "y", "n" };
        promptAndValidate("Add another team? (y/n) ", validators, input); // add endl
        
        std::cout << std::endl;
    }
}

void printTeamDetails(const std::vector<Team> &teams)
{
    for(size_t i = 0; i < teams.size(); i++)
        std::cout << teams.at(i).getTeamDetails() << std::endl;
}

void printCommandsInteractively(const std::vector<Team> &teams)
{
    std::string input;
    std::string command;
    
    size_t i = 0;
    size_t t = 0;
    for(; t < teams.size();)
    {
        if(i > 8)
            i = 0;
        
        if(i == 0)
            command = teams.at(t).getCommand_init();
        else if(i == 1)
            command = teams.at(t).getCommand_collisionRule();
        else if(i == 2)
            command = teams.at(t).getCommand_color();
        else if(i == 3)
            command = teams.at(t).getCommand_deathMessageVisibility();
        else if(i == 4)
            command = teams.at(t).getCommand_friendlyFire();
        else if(i == 5)
            command = teams.at(t).getCommand_nametagVisibility();
        else if(i == 6)
            command = teams.at(t).getCommand_prefix();
        else if(i == 7)
            command = teams.at(t).getCommand_seeFriendlyInvisibles();
        else if(i == 8)
        {
            command = teams.at(t).getCommand_suffix();
            t++;
        }
        
        i++;
        
        if(command != "")
        {
            std::cout << command;
            std::getline(std::cin, input);
        }
    }
}

void createFaction(Faction &faction)
{
    std::string input;
    std::vector<std::string> validators;
    
    std::cout << "Faction Name: ";
    std::getline(std::cin, input);
    faction.setName(input);
    
    std::cout << "Display Name: ";
    std::getline(std::cin, input);
    faction.setDisplayName(input);
    
    validators = { "always", "pushOtherTeams", "pushOwnTeam", "never" };
    promptAndValidate("collisionRule: ", validators, input);
    faction.setCollisionRule(input);
    
    validators = { "aqua", "black", "blue", "dark_aqua", "dark_blue", "dark_gray", "dark_green", "dark_purple", "dark_red", "gold", "gray", "green", "light_purple", "red", "white", "yellow" };
    promptAndValidate("color: ", validators, input);
    faction.setColor(input);

    validators = { "always", "hideForOtherTeams", "hideForOwnTeam", "never" };
    promptAndValidate("deathMessageVisibility: ", validators, input);
    faction.setDeathMessageVisibility(input);
    
    validators = { "true", "false" };
    promptAndValidate("friendlyFire (true/false): ", validators, input);
    faction.setFriendlyFire(input);
    
    validators = { "always", "hideForOtherTeams", "hideForOwnTeam", "never" };
    promptAndValidate("nametagVisibility: ", validators, input);
    faction.setNametagVisibility(input);
    
    std::cout << "prefix: ";
    std::getline(std::cin, input);
    faction.setPrefix(input);
    
    validators = { "true", "false" };
    promptAndValidate("seeFriendlyInvisibles (true/false): ", validators, input);
    faction.setFriendlyInvisibles(input);
    
    std::cout << "suffix: ";
    std::getline(std::cin, input);
    faction.setSuffix(input);
}
