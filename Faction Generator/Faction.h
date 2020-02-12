// Faction.hpp
//
// Owlery Community Server Toolbox
// Faction Generator v0.1.0
//
// Copyright © 2020 GHIFARI160.

#ifndef Faction_h
#define Faction_h

#include <string>
#include <vector>

#include "Team.h"

class Faction
{
private:
    std::string name;
    std::string displayName;
    
    std::string collisionRule;
    std::string color;
    std::string deathMessageVisibility;
    std::string friendlyFire;
    std::string nametagVisibility;
    std::string prefix;
    std::string seeFriendlyInvisibles;
    std::string suffix;
    
    std::vector<Team> teams;
    std::vector<Team>::iterator ti;
    
public:
    Faction();
    Faction(std::string factionName);
    Faction(std::string factionName, std::string factionDisplayName);
    
    bool setName(std::string factionName);
    bool setCollisionRule(std::string rule);
    bool setColor(std::string teamColor);
    bool setDeathMessageVisibility(std::string rule);
    bool setDisplayName(std::string factionDisplayName);
    bool setFriendlyFire(std::string rule);
    bool setNametagVisibility(std::string rule);
    bool setPrefix(std::string teamPrefix);
    bool setFriendlyInvisibles(std::string rule);
    bool setSuffix(std::string teamSuffix);
    
    bool initTeam(Team *team);
    
    bool addTeam(Team team);
    
    std::string getFactionName() const;
    std::string getCollisionRule() const;
    std::string getColor() const;
    std::string getDeathMessageVisibility() const;
    std::string getDisplayName() const;
    std::string getFriendlyFire() const;
    std::string getNametagVisibility() const;
    std::string getPrefix() const;
    std::string getFriendlyInvisibles() const;
    std::string getSuffix() const;
    
    std::string getTeamsList() const;
    
    std::vector<Team> getTeams() const;
};

#endif /* Faction_h */
