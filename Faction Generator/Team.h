// Team.hpp
//
// Owlery Community Server Toolbox
// Faction Generator v0.1.0
//
// Copyright © 2020 GHIFARI160.

#ifndef Team_h
#define Team_h

#include <string>

class Team
{
private:
    std::string name;
    std::string collisonRule;
    std::string color;
    std::string displayName;
    std::string deathMessageVisibility;
    std::string friendlyFire;
    std::string nametagVisibility;
    std::string prefix;
    std::string seeFriendlyInvisibles;
    std::string suffix;
    
public:
    Team(std::string teamName);
    Team(std::string teamName, std::string teamDisplayName);
    
    bool setCollisionRule(std::string rule);
    bool setColor(std::string teamColor);
    bool setDisplayName(std::string teamDisplayName);
    bool setDeathMessageVisibility(std::string rule);
    bool setFriendlyFire(std::string rule);
    bool setNametagVisibility(std::string rule);
    bool setPrefix(std::string teamPrefix);
    bool setFriendlyInvisibiles(std::string rule);
    bool setSuffix(std::string teamSuffix);
    
    std::string getName() const;
    std::string getCollisionRule() const;
    std::string getColor() const;
    std::string getDisplayName() const;
    std::string getDeathMessageVisibility() const;
    std::string getFriendlyFire() const;
    std::string getNametagVisibility() const;
    std::string getPrefix() const;
    std::string getFriendlyInvisibles() const;
    std::string getSuffix() const;
    
    std::string getTeamDetails() const;
    
    std::string getCommandBase() const;
    
    std::string getCommand_init() const;
    
    std::string getCommand_collisionRule() const;
    std::string getCommand_color() const;
    std::string getCommand_deathMessageVisibility() const;
    std::string getCommand_friendlyFire() const;
    std::string getCommand_nametagVisibility() const;
    std::string getCommand_prefix() const;
    std::string getCommand_seeFriendlyInvisibles() const;
    std::string getCommand_suffix() const;
};

#endif /* Team_h */
