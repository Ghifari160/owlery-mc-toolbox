// Team.cpp
//
// Owlery Community Server Toolbox
// Faction Generator v0.1.0
//
// Copyright © 2020 GHIFARI160.

#include "Team.h"

Team::Team(std::string teamName)
: name{teamName}, displayName{teamName}
{}

Team::Team(std::string teamName, std::string teamDisplayName)
: name{teamName}, displayName{teamDisplayName}
{}

bool Team::setCollisionRule(std::string rule)
{
    collisonRule = rule;
    
    return true;
}

bool Team::setColor(std::string teamColor)
{
    color = teamColor;
    
    return true;
}

bool Team::setDisplayName(std::string teamDisplayName)
{
    displayName = teamDisplayName;
    
    return true;
}

bool Team::setDeathMessageVisibility(std::string rule)
{
    deathMessageVisibility = rule;
    
    return true;
}

bool Team::setFriendlyFire(std::string rule)
{
    friendlyFire = rule;
    
    return true;
}

bool Team::setNametagVisibility(std::string rule)
{
    nametagVisibility = rule;
    
    return true;
}

bool Team::setPrefix(std::string teamPrefix)
{
    prefix = teamPrefix;
    
    return true;
}

bool Team::setFriendlyInvisibiles(std::string rule)
{
    seeFriendlyInvisibles = rule;
    
    return true;
}

bool Team::setSuffix(std::string teamSuffix)
{
    suffix = teamSuffix;
    
    return true;
}

std::string Team::getName() const
{
    return name;
}

std::string Team::getCollisionRule() const
{
    return collisonRule;
}

std::string Team::getColor() const
{
    return color;
}

std::string Team::getDisplayName() const
{
    return displayName;
}

std::string Team::getDeathMessageVisibility() const
{
    return deathMessageVisibility;
}

std::string Team::getFriendlyFire() const
{
    return friendlyFire;
}

std::string Team::getNametagVisibility() const
{
    return nametagVisibility;
}

std::string Team::getPrefix() const
{
    return prefix;
}

std::string Team::getFriendlyInvisibles() const
{
    return seeFriendlyInvisibles;
}

std::string Team::getSuffix() const
{
    return suffix;
}

std::string Team::getTeamDetails() const
{
    return "Team Name: " + name
         + ((displayName != name) ? ("(" + displayName + ")") : "") + "\n"
         + "collisionRule: " + collisonRule + "\n"
         + "color: " + color + "\n"
         + "deathMessageVisibility: " + deathMessageVisibility + "\n"
         + "friendlyFire: " + friendlyFire + "\n"
         + "nametagVisibility: " + nametagVisibility + "\n"
         + "prefix: " + prefix + "\n"
         + "seeFriendlyInvisibles: " + seeFriendlyInvisibles + "\n"
         + "suffix: " + suffix + "\n";
}

std::string Team::getCommandBase() const
{
    return "/team modify " + getName() + " ";
}

std::string Team::getCommand_init() const
{
    return "/team add " + getName() + " \"" + getDisplayName() + "\"";
}

std::string Team::getCommand_collisionRule() const
{
    return getCommandBase() + "collisionRule " + getCollisionRule();
}

std::string Team::getCommand_color() const
{
    return getCommandBase() + "color " + getColor();
}

std::string Team::getCommand_deathMessageVisibility() const
{
    return getCommandBase() + "deathMessageVisibility " + getDeathMessageVisibility();
}

std::string Team::getCommand_friendlyFire() const
{
    return getCommandBase() + "friendlyFire " + getFriendlyFire();
}

std::string Team::getCommand_nametagVisibility() const
{
    return getCommandBase() + "nametagVisibility " + getNametagVisibility();
}

std::string Team::getCommand_prefix() const
{
    return getCommandBase() + "prefix \"" + getPrefix() + "\"";
}

std::string Team::getCommand_seeFriendlyInvisibles() const
{
    return getCommandBase() + "seeFriendlyInvisibles " + getFriendlyInvisibles();
}

std::string Team::getCommand_suffix() const
{
    return getCommandBase() + "suffix \"" + getSuffix() + "\"";
}
