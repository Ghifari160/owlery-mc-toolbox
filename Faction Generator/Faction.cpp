// Faction.cpp
//
// Owlery Community Server Toolbox
// Faction Generator
//
// Copyright © 2020 GHIFARI160.

#include "Faction.h"

Faction::Faction()
: name{"faction"}, displayName{"faction"}
{}

Faction::Faction(std::string factionName)
: name{factionName}, displayName{factionName}
{}

Faction::Faction(std::string factionName, std::string factionDisplayName)
: name{factionName}, displayName{factionDisplayName}
{}

bool Faction::setName(std::string factionName)
{
    name = factionName;
    
    return true;
}

bool Faction::setCollisionRule(std::string rule)
{
    collisionRule = rule;
    
    return true;
}

bool Faction::setColor(std::string teamColor)
{
    color = teamColor;
    
    return true;
}

bool Faction::setDeathMessageVisibility(std::string rule)
{
    deathMessageVisibility = rule;
    
    return true;
}

bool Faction::setDisplayName(std::string factionDisplayName)
{
    displayName = factionDisplayName;
    
    return true;
}

bool Faction::setFriendlyFire(std::string rule)
{
    friendlyFire = rule;
    
    return true;
}

bool Faction::setNametagVisibility(std::string rule)
{
    nametagVisibility = rule;
    
    return true;
}

bool Faction::setPrefix(std::string teamPrefix)
{
    prefix = teamPrefix;
    
    return true;
}

bool Faction::setFriendlyInvisibles(std::string rule)
{
    seeFriendlyInvisibles = rule;
    
    return true;
}

bool Faction::setSuffix(std::string teamSuffix)
{
    suffix = teamSuffix;
    
    return true;
}

bool Faction::initTeam(Team &team)
{
    team.setCollisionRule(getCollisionRule());
    team.setColor(getColor());
    team.setDeathMessageVisibility(getDeathMessageVisibility());
    team.setFriendlyFire(getFriendlyFire());
    team.setNametagVisibility(getNametagVisibility());
    team.setFriendlyInvisibiles(getFriendlyInvisibles());
    
    return true;
}

bool Faction::checkForDuplicateTeam(const Team &team)
{
    bool duplicate = false;
    
    for(Team t : getTeams())
    {
        if(t.getName() == team.getName())
            duplicate = true;
    }
    
    return duplicate;
}

bool Faction::addTeam(Team team)
{
    if(checkForDuplicateTeam(team))
        return false;
    
    teams.push_back(team);
    
    return true;
}

std::string Faction::getFactionName() const
{
    return name;
}

std::string Faction::getCollisionRule() const
{
    return collisionRule;
}

std::string Faction::getColor() const
{
    return color;
}

std::string Faction::getDeathMessageVisibility() const
{
    return deathMessageVisibility;
}

std::string Faction::getDisplayName() const
{
    return displayName;
}

std::string Faction::getFriendlyFire() const
{
    return friendlyFire;
}

std::string Faction::getNametagVisibility() const
{
    return nametagVisibility;
}

std::string Faction::getPrefix() const
{
    return prefix;
}

std::string Faction::getFriendlyInvisibles() const
{
    return seeFriendlyInvisibles;
}

std::string Faction::getSuffix() const
{
    return suffix;
}

std::string Faction::getTeamsList(const bool verticalList) const
{
    std::string teamsList = "";
    
    for(unsigned int i = 0; i < teams.size(); i++)
    {
        teamsList += ((verticalList) ? " - " : " ")
                 + teams[i].getDisplayName() + "(" + teams[i].getName() + ")"
                 + ((verticalList) ? "\n" : ", ");
    }
    
    return teamsList;
}

std::string Faction::getTeamsList() const
{
    return getTeamsList(false);
}

std::vector<Team> Faction::getTeams() const
{
    return teams;
}
