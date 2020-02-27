// Team.h
//
// Owlery Community Server Toolbox
// Faction Generator
//
// Copyright © 2020 GHIFARI160.

#ifndef Team_h
#define Team_h

#include <string>

/**
 * @class Team
 * @author GHIFARI160
 * @copyright Copyright © 2020 GHIFARI160.
 *
 * Represents a team
 *
 * This class represents a member team of a faction.
 */
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
    
    /**
     * @private
     * Gets the base of team modification commands
     *
     * This method will generate the base command for team modification in the format of
     * `/team modify <team name>`
     *
     * @return team modification command base
     */
    std::string getCommandBase() const;
    
public:
    /// Constructs the team class
    Team();
    /**
     * Constructs the team class
     *
     * @param teamName name of the team. Must be all lowercase and may not include spaces
     */
    Team(std::string teamName);
    /**
     * Constructs the team class
     *
     * @param teamName name of the team. Must be all lowercase and may not include spaces
     * @param teamDisplayName display name of the name. Must be a valid JSON string
     */
    Team(std::string teamName, std::string teamDisplayName);
    
    /**
     * Sets the team collisionRule
     *
     * @param rule collisionRule value
     * @return succes state
     */
    bool setCollisionRule(std::string rule);
    /**
     * Sets the color of the team
     *
     * @param teamColor color of the team. Must be a valid team color.
     * @return success state
     */
    bool setColor(std::string teamColor);
    /**
     * Sets the display name of the team
     *
     * @param teamDisplayName display name of the team. Must be a valid JSON string
     * @return success state
     */
    bool setDisplayName(std::string teamDisplayName);
    /**
     * Sets the deathMessageVisibility rule of the team
     *
     * @param rule deathMessageVisibility value
     * @return success state
     */
    bool setDeathMessageVisibility(std::string rule);
    /**
     * Sets the friendlyFire rule of the team
     *
     * @param rule friendlyFire value
     * @return success state
     */
    bool setFriendlyFire(std::string rule);
    /**
     * Sets the nametagVisibility rule of the team
     *
     * @param rule nametagVisibility value
     * @return success state
     */
    bool setNametagVisibility(std::string rule);
    /**
     * Sets the prefix of the team
     *
     * @param teamPrefix prefix of the team. Must be a valid JSON string
     * @return success state
     */
    bool setPrefix(std::string teamPrefix);
    /**
     * Sets the seeFriendlyInvisibles rule of the team
     *
     * @param rule seeFriendlyInvisibles value
     * @return success state
     */
    bool setFriendlyInvisibiles(std::string rule);
    /**
     * Sets the suffix of the team
     *
     * @param teamSuffix suffix of the team. Must be a valid JSON string
     * @return success state
     */
    bool setSuffix(std::string teamSuffix);
    
    /**
     * Gets the name of the team
     *
     * @return team name
     */
    std::string getName() const;
    /**
     * Gets the collisionRule of the team
     *
     * @return collisionRule value
     */
    std::string getCollisionRule() const;
    /**
     * Gets the color of the team
     *
     * @return team color
     */
    std::string getColor() const;
    /**
     * Gets the display name of the team
     *
     * @return team display team
     */
    std::string getDisplayName() const;
    /**
     * Gets the deathMessageVisibility rule of the team
     *
     * @return deathMessageVisibility value
     */
    std::string getDeathMessageVisibility() const;
    /**
     * Gets the friendlyFire rule of the team
     *
     * @return friendlyFire value
     */
    std::string getFriendlyFire() const;
    /**
     * Gets the nametagVisibility rule of the team
     *
     * @return nametagVisibility value
     */
    std::string getNametagVisibility() const;
    /**
     * Gets the prefix of the team
     *
     * @return team prefix
     */
    std::string getPrefix() const;
    /**
     * Gets the seeFriendlyInvisibles rule of the team
     *
     * @return seeFriendlyInvisibles value
     */
    std::string getFriendlyInvisibles() const;
    /**
     * Gets the suffix of the team
     *
     * @return team suffix
     */
    std::string getSuffix() const;
    
    /**
     * Gets the details of the team
     *
     * @return full configuration of the team
     */
    std::string getTeamDetails() const;
    
    /**
     * Gets the creation command for the team
     *
     * This function returns the full configuration of the team. Each configuration is returned in a
     * new line.
     *
     * @return team creation command
     */
    std::string getCommand_init() const;
    
    /**
     * Gets the collisionRule modification command for the team
     *
     * @return team collisionRule modification command. Returns empty string for default value
     */
    std::string getCommand_collisionRule() const;
    /**
     * Gets the color modification command for the team
     *
     * @return team color modification command
     */
    std::string getCommand_color() const;
    /**
     * Gets the deathMessageVisibility modification command for the team
     *
     * @return team deathMessageVisibility modification command. Returns empty string for default value
     */
    std::string getCommand_deathMessageVisibility() const;
    /**
     * Gets the friendlyFire modification command for the team
     *
     * @return team friendlyFire modification command. Returns empty string for default value
     */
    std::string getCommand_friendlyFire() const;
    /**
     * Gets the nametagVisibility modification command for the team
     *
     * @return team nametagVisbility modification command. Returns empty string for default value
     */
    std::string getCommand_nametagVisibility() const;
    /**
     * Gets the prefix modification command for the team
     *
     * @return team prefix modification command
     */
    std::string getCommand_prefix() const;
    /**
     * Gets the seeFriendlyInvisibles modifcation command for the team
     *
     * @return team seeFriendlyInvisibles modification command
     */
    std::string getCommand_seeFriendlyInvisibles() const;
    /**
     * Gets the suffix modification command for the team
     *
     * @return team suffix modification command
     */
    std::string getCommand_suffix() const;
};

#endif /* Team_h */
