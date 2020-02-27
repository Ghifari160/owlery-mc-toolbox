// Faction.h
//
// Owlery Community Server Toolbox
// Faction Generator
//
// Copyright © 2020 GHIFARI160.

#ifndef Faction_h
#define Faction_h

#include <string>
#include <vector>

#include "Team.h"

/**
 * @class Faction
 * @author GHIFARI160
 * @copyright Copyright © 2020 GHIFARI160
 *
 * Represents a faction
 *
 * This class represents a faction. The configuration of this faction will translate to the configuration of its member teams.
 */
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
    
    /**
     * @private
     * Checks if a team is a duplicate of a member team
     *
     * @param[in] team team to be compared against all member teams
     * @return duplicate state
     */
    bool checkForDuplicateTeam(const Team &team);
    
public:
    /// Constructs the Faction class
    Faction();
    
    /**
     * Constructs the Faction class
     *
     * @param factionName name of the faction. Must be all lowercase and may not include spaces
     */
    Faction(std::string factionName);
    
    /**
     * Constructs the Faction class
     *
     * @param factionName name of the faction. Must be all lowercase and may not include spaces
     * @param factionDisplayName display name of the faction. Must be a valid JSON string
     */
    Faction(std::string factionName, std::string factionDisplayName);
    
    /**
     * Sets the name of the faction
     *
     * The faction name will be set as the prefix of the team name of all member teams
     *
     * @param factionName name of the faction. Must be all lowercase and may not include spaces
     * @return success state
     */
    bool setName(std::string factionName);
    /**
     * Sets the collisionRule of the faction
     *
     * @param rule collisionRule value
     * @return success state
     */
    bool setCollisionRule(std::string rule);
    /**
     * Sets the color of the faction
     *
     * @param teamColor color of the faction and all member teams. Must be a valid team color
     * @return success state
     */
    bool setColor(std::string teamColor);
    /**
     * Sets the deathMessageVisibility rule of the faction
     *
     * @param rule deathMessageVisibility value
     * @return success state
     */
    bool setDeathMessageVisibility(std::string rule);
    /**
     * Sets the display name of the faction
     *
     * The faction display name will be set as the prefix of the display name of all member teams
     *
     * @param factionDisplayName display name of the faction. Must be a valid JSON string.
     * @return success state
     */
    bool setDisplayName(std::string factionDisplayName);
    /**
     * Sets the friendlyFire rule of the faction
     *
     * @param rule friendlyFire value
     * @return success state
     */
    bool setFriendlyFire(std::string rule);
    /**
     * Sets the nametagVisibility rule of the faction
     *
     * @param rule nametagVisibility value
     * @return success state
     */
    bool setNametagVisibility(std::string rule);
    /**
     * Sets the prefix of the faction
     *
     * The faction prefix will be prepended to the prefix of all member teams. The prefix is shown before the player name.
     *
     * @param teamPrefix prefix of the faction. Must be a valid JSON string
     * @return sucess state
     */
    bool setPrefix(std::string teamPrefix);
    /**
     * Sets the seeFriendlyInvisibles rule fo the faction
     *
     * @param rule seeFriendlyInvisibles value
     * @return success state
     */
    bool setFriendlyInvisibles(std::string rule);
    /**
     * Sets the suffix of the faction
     *
     * The faction suffix will be prepended to the suffix of all member teams. The suffix is shown after the player name.
     *
     * @param teamSuffix suffix of the faction. Must be a valid JSON string
     * @return success state
     */
    bool setSuffix(std::string teamSuffix);
    
    /**
     * Initiates a member team
     *
     * The configuration of the faction will be applied to the member team.
     *
     * @param[in,out] team member team to be initiated
     * @return success state
     */
    bool initTeam(Team &team);
    
    
    /**
     * Adds a member team
     *
     * The member team will not be initiated.
     *
     * @param team member team to be added
     * @return success state
     */
    bool addTeam(Team team);
    
    /**
     * Returns the faction name
     *
     * @return faction name
     */
    std::string getFactionName() const;
    /**
     * Returns the collisionRule of the faction
     *
     * @return collisionRule value
     */
    std::string getCollisionRule() const;
    /**
     * Returns the color of the faction
     *
     * @return color of the faction and all member teams
     */
    std::string getColor() const;
    /**
     * Returns the deathMessageVisibility rule of the faction
     *
     * @return deathMessageVisibility value
     */
    std::string getDeathMessageVisibility() const;
    /**
     * Returns the display name of the faction
     *
     * @return faction display name
     */
    std::string getDisplayName() const;
    /**
     * Returns the friendlyFire rule of the faction
     *
     * @return friendlyFire value
     */
    std::string getFriendlyFire() const;
    /**
     * Returns the nametagVisibility rule of the faction
     *
     * @return nametagVisibility value
     */
    std::string getNametagVisibility() const;
    /**
     * Returns the prefix of the faction
     *
     * @return faction prefix
     */
    std::string getPrefix() const;
    /**
     * Returns the seeFriendlyInvisibles rule of the faction
     *
     * @return seeFriendlyInvisibles value
     */
    std::string getFriendlyInvisibles() const;
    /**
     * Returns the suffix of the faction
     *
     * @return faction suffix
     */
    std::string getSuffix() const;
    
    /**
     * Returns a list of member teams
     *
     * @return list of member teams, separated by a comma and a space
     */
    std::string getTeamsList() const;
    /**
     * Returns a list of member teams
     *
     * If `verticalList` is true, the list entries will be separated by a new line. Each entry will
     * be prepended with a ` - `. Otherwise, the list entries will be separated by a comma
     * and a space (`, `).
     *
     * @param verticalList whether the list should be vertical
     * @return list of member teams
     */
    std::string getTeamsList(const bool verticalList) const;
    
    /**
     * Returns a vector of member teams
     *
     * @return vector of member teams
     */
    std::vector<Team> getTeams() const;
};

#endif /* Faction_h */
