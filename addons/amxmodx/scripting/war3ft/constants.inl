// ***************************************************************************
// Author: B. Josh Becker
// Description: This page contains defines as well as the variables used
// in this plugin
// ***************************************************************************

#define TASK_ITEMS			0		// Showing items in the HUD
#define TASK_SPAWN			32		// Respawning from revive
#define TASK_IMPALE			64		// Crypt Lord's Impale
#define TASK_BANISH			96		// Used to set the user's origin back to normal
#define TASK_SPAWNREMOVEGOD	128		// Gives the user godmode for a brief period after they respawn
#define TASK_EXPLOSION		160		// From Suicide Bomber
#define TASK_BEAMCYLINDER	192		// From Suicide Bomber
#define	TASK_GETINPUT		224		// Calls getuserinput function
#define TASK_COOLDOWN		256		// Ultimate Cooldown function
#define TASK_TRANSPORT		288		// Transport function for ITEM_MOLE
#define TASK_MOLE			320		// Used for mole + fan of knives
#define	TASK_WAVE			352		// Healing Wave
#define	TASK_REINCARNATION	384		// Weapon Reincarnation
#define	TASK_GLOW			416		// Calls glow_change
#define	TASK_REMOVEBUYZONE	448		// This will remove a buyzone
#define	TASK_HEX			480		// Jumper task (goomba)
#define	TASK_RESETSPEED		512		// Reset maxspeed (bash)
#define	TASK_ITEM_GLOVES	544		// Nade timer (gloves)
#define	TASK_UNHOLYSPEED	576		// Unholyspeed timer
#define	TASK_RESETGOD		608		// Reset god mode
#define	TASK_BLINKCHECK		640		// Check to see if the player teleported into an invalid location
#define	TASK_BLINKSTUCK		672		// Checks to see if a user is stuck after blinking
#define	TASK_BIGBADATTACKER	704		// _SH_ResetBigBadAttacker
#define	TASK_TELEPORT		736		// For teleporting someone w00t
//#define	TASK_TELEPORT		768		// Teleports the player
//#define	TASK_TELEFADEIN		800		// Calls telefadein function
//#define	TASK_UNSTICK		832		// "Unsticks" a stuck teleported player
#define	TASK_SEARCHTARGET	864		// Used by some ultimates
//#define TASK_WALKER			896		// Walker process
#define	TASK_ENTANGLEWAIT	928		// Used for entangling roots
#define	TASK_LIGHTNING		960		// Used for chain lightning
//#define	TASK_LIGHTSEARCH	992		// Used for chain lightning
#define	TASK_LIGHTNINGNEXT	1024	// Used for chain lightning
#define TASK_SPAWNPLAYER	1056	// Used to spawn a player (final spawn call)
#define TASK_GIVEITEMS		1088	// Used to give a player his items after spawning
#define	TASK_ITEM_RING	1120	// Used with rings of regeneration
#define	TASK_SILENCEBURST	1152
//#define	TASK_ONFIRE			1184	// Used with flamethrower
//#define	TASK_HEALNOW		1226	// Used with Healing Waves
#define	TASK_HEALNEXT		1258	// Used with Healing Waves
#define	TASK_LIGHT			1290	// Used with serpant wards
#define	TASK_SHIELD			1322	// Used to check for shield
#define	TASK_FUNNELS		1354	// Used with Swarming Locusts
#define	TASK_HETHROWEVENT	1386	// Used for nade trails
#define	TASK_MONEYLOOP		1428	// Used for displaying the money for DOD
#define TASK_TEMPENTITY		1460
#define TASK_ANKHGIVEITEMS	1492
#define TASK_HELM			1524
#define	TASK_REINCCHECK		1556
#define TASK_SAVE			1588	// Used for saving XP
//#define TASK_UDELAY			1620	// Ultimate Delay Function
//#define TASK_BURN           1652
#define TASK_BURNING		1684	// Used for Blood Mage Ultimate
#define TASK_FINDTARGET		1706	// Used for finding a target
#define TASK_ULTPING		1738	// Used to play the "ping" sound every second


#define TASK_BUYTIME		2000	// Checks for buytime
#define	TASK_CHECKVOTES		2002	// Used for checking the votes
#define	TASK_FTCONTROLLER	2003	// Used for automatic start/stop
#define	TASK_CHECKWAR3		2004
#define	TASK_EXECUTECONFIG	2005
#define	TASK_AFTERCONFIG	2006
#define	TASK_SETSQL			2007
//#define	TASK_SETLANGUAGE	2008
#define	TASK_SETVARIABLES	2009
#define	TASK_CLONETHINK		2010
//#define	TASK_CHECKMAP		2011
#define TASK_BOIDTHINK		2012
#define TASK_TARGETBOMBED	2013
//#define TASK_BOMBTIMER		2014
//#define TASK_WAR3CHECK		2015	// Checks the value of sv_warcraft3 every 5 seconds (better than checking it on every function call)
#define TASK_SIPHON			2016
#define TASK_ENDULTIMATE	2017
//#define TASK_BEFORE_ROUND_START		2018
#define TASK_MOLEFIX		3000
#define TASK_RESETSPAWNS	3001
#define TASK_UDELAY			3002		// Ultimate delay function

// From ../multiplayer source/dlls/player.cpp
#define ARMOR_RATIO	 0.7	// Armor Takes 30% of the damage (was .2 in the SDK)
#define ARMOR_BONUS  0.5	// Each Point of Armor is work 1/x points of health

#define TE_BEAMPOINTS		0
#define TE_EXPLOSION		3
#define	TE_TAREXPLOSION		4
#define TE_SMOKE			5
#define TE_BEAMENTS			8
#define	TE_LAVASPLASH		10
#define	TE_TELEPORT			11
#define TE_IMPLOSION		14
#define TE_SPRITETRAIL		15
#define TE_SPRITE			17
#define TE_BEAMCYLINDER		21
#define TE_BEAMFOLLOW		22
#define TE_STREAK_SPLASH	25
#define TE_ELIGHT			28
#define TE_LARGEFUNNEL		100
#define TE_FIZZ				105		// create alpha sprites inside of entity, float upwards
#define TE_BUBBLES			113		// create alpha sprites inside of box, float upwards
#define TE_SPRAY			120
#define TE_PLAYERATTACHMENT 124

#define	EF_BRIGHTFIELD		1

#define TE_EXPLFLAG_NONE	0

#define MAX_NAME_LENGTH 32
#define MAX_VAR_LENGTH 64 
#define RACE_SKILL_LENGTH 64
#define RACE_SKILL_LENGTH_F 63
#define RACE_NAME_LENGTH 64
#define RACE_NAME_LENGTH_F 63
#define ITEM_NAME_LENGTH 64
#define ITEM_NAME_LENGTH_F 63
#define SHORT_RACE_NAME_LENGTH 16
#define SHORT_RACE_NAME_LENGTH_F 15
#define SHORT_ITEM_NAME_LENGTH 32
#define SHORT_ITEM_NAME_LENGTH_F 31

#define TELEPORT_RADIUS			50
#define LIGHTNING_RANGE			500
#define ORB_DAMAGE				10			// Damage done by Orb of Annihilation

// CS AmmoX Types
#define AMMOX_338MAGNUM			1     // AWP
#define AMMOX_762NATO			2     // AK47, SCOUT, G3SG1
#define AMMOX_556NATOBOX		3     // MG
#define AMMOX_556NATO			4     // SG552, GALI, FAMAS, M4A1, AUG, SG550
#define AMMOX_BUCKSHOT			5     // M3, XM1014
#define AMMOX_45ACP				6     // MAC10, UMP45, USP
#define AMMOX_57MM				7     // P90, FIVESEVEN
#define AMMOX_50AE				8     // DEAGLE
#define AMMOX_357SIG			9     // P228
#define AMMOX_9MM				10     // MP5NAVY, TMP, GLOCK18, ELITE
#define AMMOX_FLASHBANG			11     // Flashbang
#define AMMOX_HEGRENADE			12     // HE Grenade
#define AMMOX_SMOKEGRENADE		13     // Smoke Grenade


#define HITGROUP_GENERIC		0 // none
#define HITGROUP_HEAD			1 // 1 << 1 = 2
#define HITGROUP_CHEST			2 // 1 << 2 = 4
#define HITGROUP_STOMACH		3 // 8
#define HITGROUP_LEFTARM		4 // 16
#define HITGROUP_RIGHTARM		5 // 32
#define HITGROUP_LEFTLEG		6 // 64
#define HITGROUP_RIGHTLEG		7 // 128

/*	 Weapon IDs	 */
#define CSW_WORLDSPAWN			0 

#if !defined CSW_GALIL
	#define CSW_GALIL			14
#endif
#if !defined CSW_FAMAS
	#define CSW_FAMAS			15
#endif

#define CSW_WAR3_MIN			51

#define	CSW_LIGHTNING			51
#define	CSW_SUICIDE				52
#define	CSW_IMMOLATE			53
#define	CSW_LOCUSTS				54
#define	CSW_SERPENTWARD			55
#define CSW_SHADOW				56
#define	CSW_THORNS				57
#define	CSW_CARAPACE			58
#define CSW_CARRION				59
#define CSW_ORB					60
#define CSW_CONCOCTION			61
#define CSW_BANISH				62

#define CSW_WAR3_MAX			62

// Should be equal to (CSW_WAR3_MIN - CSW_WAR3_MAX) + 1
#define MAX_CSW_S				12

// Race numbers
#define RACE_NONE				0
#define RACE_UNDEAD				1
#define RACE_HUMAN				2
#define RACE_ORC				3
#define RACE_ELF				4
#define RACE_BLOOD				5
#define RACE_SHADOW				6
#define RACE_WARDEN				7
#define RACE_CRYPT				8
#define RACE_CHAMELEON			9

#define MAX_RACES				9

// team ids 
#define UNASSIGNED 0 
#define TS 1 
#define CTS 2 
#define AUTO_TEAM 5 

// New team ID defines
#define TEAM_T		1
#define TEAM_CT		2

// To determine what game is running
#define GAME_CSTRIKE		1
#define GAME_CZERO			2
#define GAME_DOD			3

// Used with PB_SKINSWITCHED
#define SKIN_RESET					0
#define SKIN_SWITCH					1

#define KEY_1						0
#define KEY_2						1
#define KEY_3						2
#define KEY_4						3
#define KEY_5						4
#define KEY_6						5
#define KEY_7						6
#define KEY_8						7
#define KEY_9						8
#define KEY_0						9

#define XPOS						0
#define YPOS						1
#define ZPOS						2

#define DISPLAYLEVEL_NONE			0
#define DISPLAYLEVEL_SHOWRACE		1
#define DISPLAYLEVEL_SHOWGAINED		2
//#define DISPLAYLEVEL_SHOWBOTH		3
#define	DISPLAYLEVEL_SHOWRACECHAT	4


// General configuration 
//#define MAX_LEVELS					25

// ***************************************************************************
// The following section contains defines for the player_data array, it pretty much
// stores everything.  
//		P_ is within player_data
//		PB_ is within player_data_bool array
// ***************************************************************************
	// ***************************
	//		Start of info for player_data
	// ***************************

	#define P_RACE                  0		// Race
	//#define P_SKILL1                1		// Skill 1 level
	//#define P_SKILL2                2		// Skill 2 level
	//#define P_SKILL3                3		// Skill 4 level
	//#define P_ULTIMATE              4		// Ultimate level
	#define P_LEVEL					5		// Player Level
	#define P_XP                    6		// Current XP

	// Miscellaneous options
	#define P_SPECMODE				7		// Used to determine if the player is spectating or not
	#define P_SHOWRACEMENU			8		// Should we show the race menu when the player respawns?
	#define P_SHOWICONS				9		// Show player icons/levels for this player?
	#define P_CHANGERACE			10		// Holds the value of what race to change to when the following round starts

	// Used for weapon Reincarnation
	#define P_FLASHCOUNT			11		// Number of flash grenades bought that round
	#define	P_HECOUNT				12		// Number of HE's bought that round
	#define P_SMOKECOUNT			13		// Number of smoke grenades bought that round
	#define P_ARMORONDEATH			14		// Amount of armor the player had when he/she died
	#define P_LASTARMOR				15		// This will contain the previous value of P_ARMORONDEATH

	// Used by various ultimates/abilities
	#define P_TELEMENU				16		// Used by teleport
	#define P_TEAM					17		// Stores the player's team ID
	//#define P_SHADOWCOUNT			18		// Number of shadow strikes the player has left
	#define P_SERPENTCOUNT			19		// Number of serpent wards the player has left
	#define P_RINGS					20
	#define P_ULTIMATEDELAY			21
	#define P_RESPAWNBY				22		// Stores how the user is going to respawn

	// Used for DOD
	#define P_MONEY					23		// Amount of money the player has

	#define P_LAST					24
	// ***************************
	//		End of info for player_data
	// ***************************


	// ***************************
	//		Start of info for player_data_bool
	// ***************************

	// Miscellaneous
	#define PB_SKINSWITCHED			0		// Set if the user's skin has been changed
	#define PB_RESETSKILLS			1		// Does the player want to reset their skills in the next round?
	#define PB_CHANGINGTEAM			2		// Is the user currently changing his/her team?
	#define PB_DIEDLASTROUND		3		// Did the user died during the previous round?

	// Used for weapon Reincarnation
	#define PB_DEFUSE				4		// Player had a defuse kit when he/she died?
	#define PB_SHIELD				5		// Player had a shield when he/she died?
	#define PB_NIGHTVISION			6		// Player had nightvision when he/she died?
	#define PB_USP_SILENCED			28		// USP silenced on death?
	#define PB_M4A1_SILENCED		29		// M4A1 silenced on death?
	#define PB_GLOCK_BURST			30		// Glock in burst mode on death?
	#define PB_FAMAS_BURST			31		// Famas in burst mode on death?


	// Used by various ultimates/abilities
	#define PB_GIVEITEMS			7		// Tells weapon controller function to give the player his items after respawning
	#define PB_NADEJUSTRECEIVED		8		// Used with flaming gloves... (removable?)
	#define PB_MOLE					9		// Is the player a mole?
	#define PB_PHOENIX				10		// Will this player have phoenix?
	#define PB_WARDENBLINK			11		// Does this player have blink enabled?
	#define PB_SUICIDEATTEMPT		12		// Has this player made a suicide attempt for undead's ultimate?
	#define PB_ISBURNING			13		// Is the player burning from the immolate ultimate?
	#define PB_STUNNED				14
	#define PB_SLOWED				15
	#define PB_ISSEARCHING			16
	#define PB_LIGHTNINGHIT			17
	#define PB_INVIS				18
	#define PB_HEXED				19		// Is the player hexed? (All abilities are disabled)
	#define PB_JUSTJOINED			20
	#define PB_ISCONNECTED			21
	#define PB_GODMODE				22

	#define PB_HAS_SPAWNED			23		// Has the player previously spawned this round?
	#define PB_CAN_RENDER			24

	#define PB_NO_DAMAGE			25
	#define PB_BIGBAD_ATTACKER		26		// This user is allowed to attack a user running big bad voodoo!

	#define PB_ISPLANTING			27		// Set to true if the user is planting the bomb

//	#define PB_CHAM_CONFIGURED		28		// Has chameleon been configured?

	#define PB_LAST					32
	// ***************************
	//		End of info for player_data_bool
	// ***************************
// ***************************************************************************
//	End player array information
// ***************************************************************************


// What is the user going to respawn by?
#define RESPAWN_ITEM			1
#define RESPAWN_PHOENIX			2
#define RESPAWN_VENGEANCE		3

// Enemies who have immunity w/in this radius will cause blink to fail 
#define IMMUNITY_RADIUS		500

#define SPAWN_DELAY			0.2

// ***************************************************************************
//  Start of variables
// ***************************************************************************

// Use this everywhere instead of declaring it in each function (compiles faster)
new szTmpMsg[2048];

// This keeps track of which races were given "free" XP - we don't want to save this XP to the database
new bool:g_bGivenLevel10[33][MAX_RACES+1];	// Stores if we gave them level 10

new g_GlowLevel[33][4];

// Used for Chameleon
new g_ChamSkills[5];

new p_data[33][P_LAST]					// Contains player data
new bool:p_data_b[33][PB_LAST]			// Contains player data of type boolean

// Used for advanced statistics
new iStatsHead[33][MAX_CSW_S]
new iStatsChest[33][MAX_CSW_S]
new iStatsStomach[33][MAX_CSW_S]
new iStatsLeftArm[33][MAX_CSW_S]
new iStatsRightArm[33][MAX_CSW_S]
new iStatsLeftLeg[33][MAX_CSW_S]
new iStatsRightLeg[33][MAX_CSW_S]
new iStatsKills[33][MAX_CSW_S]
new iStatsDeaths[33][MAX_CSW_S]
new iStatsHS[33][MAX_CSW_S]
new iStatsTKS[33][MAX_CSW_S]
new iStatsShots[33][MAX_CSW_S]
new iStatsHits[33][MAX_CSW_S]
new iStatsDamage[33][MAX_CSW_S]

new MAXPLAYERS

// Used by admin menu
new g_menuPosition[33]
new g_menuPlayers[33][32]
new g_menuPlayersNum[33]
new g_menuOption[33]
new g_menuSettings[33]

new gmsgStatusText
new gmsgBarTime

// Used with SHARED_SetUserSpeed
new bool:g_bPlayerZoomed[33];

new szSpawnEnt[2][32];

/*  START - CSTRIKE VARIABLES */
new bool:g_freezeTime	= false;
new bool:g_buyTime

// Counter-Strike/Condition Zero Skins
new SKIN_CT[5][]		= { "sas"		, "gsg9"	, "urban"		, "gign"	, "spetsnaz" };
new SKIN_T[5][]			= { "arctic"	, "leet"	, "guerilla"	, "terror"	, "militia" };
	
// Day of Defeat Player skins
new SKIN_AXIS[2][]		= { "axis-inf"	, "axis-para" };
new SKIN_ALLIES[2][]	= { "us-inf"	, "us-para" };
new SKIN_BRIT[1][]		= { "brit-inf" };

new CsArmorType:g_ArmorType[33];

/*  END - CSTRIKE VARIABLES */

/*  START - DOD VARIABLES */
new gmsgHudText

new iReincarnation[33][3];
/*  END - DOD VARIABLES */

// Used to keep track of how much dmg one player does to another
new g_iDamageDealt[33][33];

// Used with helm
new Float:fLastShotFired[33];

// Used to determine if the ultimatedelay is valid
new g_iUltimateDelay;

// Captured Messages
new gmsgDeathMsg
new gmsgScreenFade
new gmsgScreenShake
new gmsgScoreInfo
new gmsgStatusIcon

new bool:g_GameRestarting = false;

new bool:bIgnoreArmorSet[33];

new g_MODclient[15] = "* [WAR3FT]"

new bool:warcraft3 = true
new bool:g_EndRound

// Used to make sure a spawn point isn't used for another player
#define TOTAL_SPAWNS	64
new g_iSpawnReserved[TOTAL_SPAWNS];
new g_iSpawnInc = 0;

new g_PlayerWeapons[33][32];			// Stores player weapons after they have been purchased
new g_PlayerLastWeapons[33][32];		// Stores player weapons after they have been purchased

new g_MOD = 0;

// thanks twistedeuphoria - from objective proximity warning
#define MAX_OBJECTIVES			11
#define OBJENT_VIP_ESCAPE		0
#define OBJENT_HOSTAGE			1
#define OBJENT_BOMBSITE			2
#define OBJENT_HOSTAGE_ESCAPE	3

new g_iObjectiveEnt[MAX_OBJECTIVES];
new g_iObjectiveEntType[MAX_OBJECTIVES];
new Float:g_fObjectiveOrigin[MAX_OBJECTIVES][3]
new g_iTotalObjectiveEnts = 0;

new bool:g_bLevitation[33];

new bool:g_bOrcNadesDisabled = false;
new bool:g_bGlovesDisabled = false;

// ***************************
// Skill Information
// ***************************

#define SKILL_1						1
#define SKILL_2						2
#define SKILL_3						3
#define SKILL_ULTIMATE				4
#define SKILL_PASSIVE				5

#define MAX_PLAYER_SKILLS			6

// SKILL DEFINES
#define SKILL_NONE				-1

#define SKILL_VAMPIRICAURA		0
#define SKILL_UNHOLYAURA		1
#define SKILL_LEVITATION		2
#define ULTIMATE_SUICIDE		3

#define SKILL_INVISIBILITY		4
#define SKILL_DEVOTION			5
#define SKILL_BASH				6
#define ULTIMATE_BLINK			7

#define SKILL_CRITICALSTRIKE	8
#define SKILL_CRITICALGRENADE	9
#define SKILL_REINCARNATION		10
#define ULTIMATE_CHAINLIGHTNING	11

#define SKILL_EVASION			12
#define SKILL_THORNS			13
#define SKILL_TRUESHOT			14
#define ULTIMATE_ENTANGLE		15

#define SKILL_PHOENIX			16
#define SKILL_BANISH			17
#define SKILL_SIPHONMANA		18
#define ULTIMATE_IMMOLATE		19
#define PASS_RESISTANTSKIN		20

#define SKILL_HEALINGWAVE		21
#define SKILL_HEX				22
#define SKILL_SERPENTWARD		23
#define ULTIMATE_BIGBADVOODOO	24
#define PASS_UNSTABLECONCOCTION	25

#define SKILL_FANOFKNIVES		26
#define SKILL_BLINK				27
#define SKILL_SHADOWSTRIKE		28
#define ULTIMATE_VENGEANCE		29
#define PASS_HARDENEDSKIN		30

#define SKILL_IMPALE			31
#define SKILL_SPIKEDCARAPACE	32
#define SKILL_CARRIONBEETLES	33
#define ULTIMATE_LOCUSTSWARM	34
#define PASS_ORB				35

#define MAX_SKILLS				36


#define MAX_RACE_SKILLS         3

// Character Configuration 
#define MAX_SKILL_LEVEL			7
#define MAX_ULTIMATE_LEVEL		4
#define MAX_LEVELS				25
#define MIN_ULT_LEVEL           6

// Increased Cooldown by Ultimate Level
new const p_ultimatereduce[MAX_ULTIMATE_LEVEL] =		{15, 10, 5, 0};
new const p_ultimateunlock[MAX_ULTIMATE_LEVEL] =		{6, 12, 18, 24};	
#define ULTIMATE_SECURITY_TIME 7	// set a value to prevent instant ultimate ready


// Used with g_SkillType
#define SKILL_TYPE_TRAINABLE	1
#define SKILL_TYPE_PASSIVE		2
#define SKILL_TYPE_ULTIMATE		3

// Used with g_SkillOrder
#define SKILL_POS_NONE			-1
#define SKILL_POS_1				0
#define SKILL_POS_2				1
#define SKILL_POS_3				2
#define SKILL_POS_4				3

new g_SkillOwner[MAX_SKILLS	];	// For each skill, says who the owning race is
new g_SkillType[MAX_SKILLS	];	// For each skill, says what type of skill it is (trainable/ultimate/passive)
new g_SkillOrder[MAX_SKILLS	];	// For each skill, lists what order it should appear in /level and /selectskill (and how it should save)

// Used to store what level each skill is for the players
new g_PlayerSkillLevel[33][MAX_SKILLS];			// Stores what level each skill is
new bool:g_bPlayerSkills[33][MAX_SKILLS];		// Stores what skills the player has available (set on race selection)

// Constants for Abilities

new const Float:p_vampiric[MAX_SKILL_LEVEL] =			{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Vampiric Aura			(skill 1)


new Float:p_unholy[MAX_SKILL_LEVEL] =					{265.0, 267.0, 270.0, 273.0, 275.0, 280.0, 285.0}			// Unholy Aura				(skill 2)
new Float:p_unholy_dod[MAX_SKILL_LEVEL] =				{10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 100.0}					// Unholy Aura				(skill 2)



new const Float:p_levitation[MAX_SKILL_LEVEL] =			{0.8, 0.7, 0.6, 0.5, 0.45, 0.4, 0.35}						// Levitation				(skill 3)

new const p_invisibility[MAX_SKILL_LEVEL] =				{200, 190, 180, 170, 160, 150, 135}							// Invisibility				(skill 1)
new const p_devotion[MAX_SKILL_LEVEL] =					{10, 15, 20, 25, 30, 35, 45}								// Devotion Aura			(skill 2)
new const Float:p_bash[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15} 					// Bash						(skill 3)

new const Float:p_critical[MAX_SKILL_LEVEL] =			{0.25, 0.30, 0.35, 0.40, 0.45, 0.50, 0.75}					// Critical Strike			(skill 1)
new const Float:p_grenade[MAX_SKILL_LEVEL] =			{1.2, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0}							// Critical Grenade			(skill 2)
new const Float:p_ankh[MAX_SKILL_LEVEL] =				{0.400, 0.500, 0.600, 0.700, 0.800, 0.900, 1.0}				// Equipment reincarnation	(skill 3)

new const Float:p_evasion[MAX_SKILL_LEVEL] =			{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Evasion					(skill 1)
new const Float:p_thorns[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Thorns Aura				(skill 2)
new const Float:p_trueshot[MAX_SKILL_LEVEL] =			{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Trueshot Aura			(skill 3)

new const Float:p_phoenix[MAX_SKILL_LEVEL] =			{0.400, 0.500, 0.600, 0.700, 0.800, 0.900, 1.0}				// Phoenix					(skill 1)
new const p_phoenix_dod[MAX_SKILL_LEVEL] =				{100, 200, 300, 400, 500, 600, 900}							// Phoenix - DOD			(skill 1)
new const Float:p_banish[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Banish					(skill 2)
new const Float:p_mana[MAX_SKILL_LEVEL] =				{0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07}					// Siphon Mana				(skill 3)
new const Float:p_resistant[MAX_LEVELS+1] =				{0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05}						// Resistant Skin		(Skill 4)

new const Float:p_heal[MAX_SKILL_LEVEL] =				{2.5, 2.3, 2.0, 1.7, 1.5, 1.3, 1.0}							// Healing Wave				(skill 1)
new const Float:p_hex[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Hex						(skill 2)
new const p_serpent[MAX_SKILL_LEVEL] =					{3, 3, 3, 3, 3, 3, 3}										// Serpent Ward	Count		(skill 3)
new const p_serpent_damage[MAX_SKILL_LEVEL] =			{1, 3, 5, 7, 9, 11, 13}										// Serpent Ward	Damage		(skill 3)						


new const Float:p_concoction[MAX_LEVELS+1] =			{0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05}						// Unstable Concoction	(Skill 4)

new const Float:p_fan[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Fan of Knives			(skill 1)
new const Float:p_blink[MAX_SKILL_LEVEL] =				{0.400, 0.500, 0.600, 0.700, 0.800, 0.900, 1.0}				// Blink					(skill 2)
new const Float:p_shadow[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Shadow Strike			(skill 3)
new const Float:p_harden[MAX_LEVELS+1] =				{0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05}						// Hardened Skin		(Skill 4)

new const Float:p_impale[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}		    		// Impale					(skill 1)
new const Float:p_spiked[MAX_SKILL_LEVEL] =				{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Spiked Carapace			(skill 2)
new const Float:p_carrion[MAX_SKILL_LEVEL] =			{0.09, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15}					// Carrion Beetle			(skill 3)
new const Float:p_orb[MAX_LEVELS+1] =					{0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05,
														 0.05, 0.05, 0.05, 0.05, 0.05, 0.05}						// Orb of Annihilation	(Skill 4)



new MOTD_header[] = "<html><head><LINK REL=^"StyleSheet^" HREF=^"wc3.css^" TYPE=^"text/css^"></head><body>";


// SOUNDS
#define MAX_SOUNDS	32  // +1

new g_szSounds[MAX_SOUNDS][64];

#define SOUND_VENGEANCE			0
#define SOUND_SUICIDE			1
#define SOUND_BANISH			2
#define SOUND_LOCUSTSWARM		3
#define SOUND_SHADOWSTRIKE		4
#define SOUND_CARRION			5
#define SOUND_IMPALE			6
#define SOUND_VOODOO			7
#define SOUND_FLAMESTRIKE		8
#define SOUND_ENTANGLING		9
#define SOUND_LIGHTNING			10
#define SOUND_TELEPORT			11
#define SOUND_BLINK				12
#define SOUND_ANNIHILATION		13
#define SOUND_CONCOCTION_CAST	14
#define SOUND_CONCOCTION_HIT	15
#define SOUND_HEX				16
#define SOUND_IMMOLATE			17
#define SOUND_IMMOLATE_BURNING	18
#define SOUND_LEVELUP			19
#define SOUND_PICKUPITEM		20
#define SOUND_TOME				21
#define SOUND_ULTIMATESCAN		22
#define SOUND_ULTIMATEREADY		23
#define SOUND_REINCARNATION		24
#define SOUND_ANTEND			25
#define SOUND_ERROR				26
#define SOUND_DISPELL			27
#define SOUND_SPELLSHIELD		28   //
#define SOUND_ITEM_BUY			29
#define SOUND_ITEM_BUY_FAIL		30
#define	SOUND_MENU_SELECT		31

// SPRITES
#define MAX_SPRITES	15

new g_szSprites[MAX_SPRITES][64];
new g_szRaceSprites[MAX_RACES + 1][64];
//new g_szLevelSprites[MAX_LEVELS + 1][64];

new g_iRaceSprites[MAX_RACES + 1];
//new g_iLevelSprites[MAX_LEVELS + 1];
new g_iSprites[MAX_SPRITES] = {0};

new bool:g_bExtraSpritesEnabled = false

#define SPR_BANISH			0
#define SPR_SHADOWSTRIKE	1
#define SPR_SNOW			2
#define SPR_FIRE			3
#define SPR_BURNING			4
#define SPR_BEETLE			5
#define SPR_FIREBALL		6
#define SPR_BEAM			7
#define SPR_TRAIL			8
#define SPR_SHOCKWAVE		9
#define SPR_LIGHTNING		10
#define SPR_FLARE			11
#define SPR_WAVE			12
#define SPR_SMOKE			13
#define SPR_IMMOLATE		14

// HUD Channels
#define HUD_SPEC_INFO			1	// Info displayed in bottom corner of player being spectated
#define HUD_SHOWSTATUS			4	// Information shown on enemies/teammates when looking at them
#define HUD_DOD_MONEY			4	// Money Displayed at top center of screen in DOD
#define HUD_RACE_INFO			2	// /level command
#define HUD_ULTIMATE			1	// Ultimate messages (i.e. you have _ seconds remaining)
#define HUD_SKILL				3	// i.e. "you have evaded a shot"
#define HUD_XP					3	// Used to show the user their xp/items when dead
#define HUD_AUTO				-1	// Automatically choose one!
#define HUD_TIMER				1	// Timer

#define FADE_OUT                0x0000          // Fade out from max alpha
#define FADE_IN                 0x0001          // Fade in to max alpha
#define FADE_MODULATE_OUT       0x0002          // Modulate, fade out from max alpha
#define FADE_MODULATE_IN        0x0003      // Modulate, fade in to max alpha
#define FADE_ONLYONE_OUT        0x0004      // Start at max Alpha, no fade out
#define FADE_ONLYONE_IN         0x0005      // Fade in to max Alpha, no fade out
#define FADE_MODONE_OUT         0x0006      // Modulate, Start at max Alpha, no fade
#define FADE_MODONE_IN          0x0007      // Modulate, Fade in to max Alpha, no fade out

#define HUDMESSAGE_FX_FADEIN    0           // hudmessage effect types
#define HUDMESSAGE_FX_FLICKER   1
#define HUDMESSAGE_FX_WRITEOUT  2

// Used for spectating info
#define SPEC_HOLDTIME		10.0
new g_iSpectatingID[33];
new Float:g_fLastSpecDisplay[33];

// Lets keep track of what team the player is on!
new g_iPlayerTeam[33];

#define BOT_CAST_ULT_CHANCE		0.10

new bool:g_bCZBotRegisterHam

// Extra by xReforged
new Menu;
new bChooseTeamOverrideActive[33];
#define	INFO_FREQ					180.0
#define VIP_LEVEL		ADMIN_LEVEL_H
//#define	GAME_NAME	"* [WAR3FT]"

// Used by Clean Binds 
#define SPRAY				201 			
#define FLASHLIGHT 			100

// MOTD DESIGN

#define SELECT_DESIGN		10

#define DESIGN1_STYLE "<meta charset=UTF-8><style>body{background:#112233;font-family:Arial}th{background:#558866;color:#FFF;padding:10px 2px;text-align:left}td{padding:4px 3px}table{background:#EEEECC;font-size:12px;font-family:Arial}h2,h3{color:#FFF;font-family:Verdana}#c{background:#E2E2BC}img{height:10px;background:#09F;margin:0 3px}#r{height:10px;background:#B6423C}#clr{background:none;color:#FFF;font-size:20px}</style>"
#define DESIGN2_STYLE "<meta charset=UTF-8><style>body{font-family:Arial}th{background:#575757;color:#FFF;padding:5px;border-bottom:2px #BCE27F solid;text-align:left}td{padding:3px;border-bottom:1px #E7F0D0 solid}table{color:#3C9B4A;background:#FFF;font-size:12px}h2,h3{color:#333;font-family:Verdana}#c{background:#F0F7E2}img{height:10px;background:#62B054;margin:0 3px}#r{height:10px;background:#717171}#clr{background:none;color:#575757;font-size:20px}</style>"
#define DESIGN3_STYLE "<meta charset=UTF-8><style>body{background:#E6E6E6;font-family:Verdana}th{background:#F5F5F5;color:#A70000;padding:6px;text-align:left}td{padding:2px 6px}table{color:#333;background:#E6E6E6;font-size:10px;font-family:Georgia;border:2px solid #D9D9D9}h2,h3{color:#333;}#c{background:#FFF}img{height:10px;background:#14CC00;margin:0 3px}#r{height:10px;background:#CC8A00}#clr{background:none;color:#A70000;font-size:20px;border:0}</style>"
#define DESIGN4_STYLE "<meta charset=UTF-8><style>body{background:#E8EEF7;margin:2px;font-family:Tahoma}th{color:#0000CC;padding:3px}tr{text-align:left;background:#E8EEF7}td{padding:3px}table{background:#CCC;font-size:11px}h2,h3{font-family:Verdana}img{height:10px;background:#09F;margin:0 3px}#r{height:10px;background:#B6423C}#clr{background:none;color:#000;font-size:20px}</style>"
#define DESIGN5_STYLE "<meta charset=UTF-8><style>body{background:#555;font-family:Arial}th{border-left:1px solid #ADADAD;border-top:1px solid #ADADAD}table{background:#3C3C3C;font-size:11px;color:#FFF;border-right:1px solid #ADADAD;border-bottom:1px solid #ADADAD;padding:3px}h2,h3{color:#FFF}#c{background:#FF9B00;color:#000}img{height:10px;background:#00E930;margin:0 3px}#r{height:10px;background:#B6423C}#clr{background:none;color:#FFF;font-size:20px;border:0}</style>"
#define DESIGN6_STYLE "<meta charset=UTF-8><style>body{background:#FFF;font-family:Tahoma}th{background:#303B4A;color:#FFF}table{padding:6px 2px;background:#EFF1F3;font-size:12px;color:#222;border:1px solid #CCC}h2,h3{color:#222}#c{background:#E9EBEE}img{height:7px;background:#F8931F;margin:0 3px}#r{height:7px;background:#D2232A}#clr{background:none;color:#303B4A;font-size:20px;border:0}</style>"
#define DESIGN7_STYLE "<meta charset=UTF-8><style>body{background:#FFF;font-family:Verdana}th{background:#2E2E2E;color:#FFF;text-align:left}table{padding:6px 2px;background:#FFF;font-size:11px;color:#333;border:1px solid #CCC}h2,h3{color:#333}#c{background:#F0F0F0}img{height:7px;background:#444;margin:0 3px}#r{height:7px;background:#999}#clr{background:none;color:#2E2E2E;font-size:20px;border:0}</style>"
#define DESIGN8_STYLE "<meta charset=UTF-8><style>body{background:#242424;margin:20px;font-family:Tahoma}th{background:#2F3034;color:#BDB670;text-align:left} table{padding:4px;background:#4A4945;font-size:10px;color:#FFF}h2,h3{color:#D2D1CF}#c{background:#3B3C37}img{height:12px;background:#99CC00;margin:0 3px}#r{height:12px;background:#999900}#clr{background:none;color:#FFF;font-size:20px}</style>"
#define DESIGN9_STYLE "<meta charset=UTF-8><style>body{background:#FFF;font-family:Tahoma}th{background:#056B9E;color:#FFF;padding:3px;text-align:left;border-top:4px solid #3986AC}td{padding:2px 6px}table{color:#006699;background:#FFF;font-size:12px;border:2px solid #006699}h2,h3{color:#F69F1C;}#c{background:#EFEFEF}img{height:5px;background:#1578D3;margin:0 3px}#r{height:5px;background:#F49F1E}#clr{background:none;color:#056B9E;font-size:20px;border:0}</style>"
#define DESIGN10_STYLE "<meta charset=UTF-8><style>body{background:#4C5844;font-family:Tahoma}th{background:#1E1E1E;color:#C0C0C0;padding:2px;text-align:left;}td{padding:2px 10px}table{color:#AAC0AA;background:#424242;font-size:13px}h2,h3{color:#C2C2C2;font-family:Tahoma}#c{background:#323232}img{height:3px;background:#B4DA45;margin:0 3px}#r{height:3px;background:#6F9FC8}#clr{background:none;color:#FFF;font-size:20px}</style>"
#define DESIGN11_STYLE "<meta charset=UTF-8><style>body{background:#F2F2F2;font-family:Arial}th{background:#175D8B;color:#FFF;padding:7px;text-align:left}td{padding:3px;border-bottom:1px #BFBDBD solid}table{color:#153B7C;background:#F4F4F4;font-size:11px;border:1px solid #BFBDBD}h2,h3{color:#153B7C}#c{background:#ECECEC}img{height:8px;background:#54D143;margin:0 3px}#r{height:8px;background:#C80B0F}#clr{background:none;color:#175D8B;font-size:20px;border:0}</style>"
#define DESIGN12_STYLE "<meta charset=UTF-8><style>body{background:#283136;font-family:Arial}th{background:#323B40;color:#6ED5FF;padding:10px 2px;text-align:left}td{padding:4px 3px;border-bottom:1px solid #DCDCDC}table{background:#EDF1F2;font-size:10px;border:2px solid #505A62}h2,h3{color:#FFF}img{height:10px;background:#A7CC00;margin:0 3px}#r{height:10px;background:#CC3D00}#clr{background:none;color:#6ED5FF;font-size:20px;border:0}</style>"
#define DESIGN13_STYLE "<meta charset=UTF-8><style>body{background:#220000;font-family:Tahoma}th{background:#3E0909;color:#FFF;padding:5px 2px;text-align:left;border-bottom:1px solid #DEDEDE}td{padding:2px 2px;}table{background:#FFF;font-size:11px;border:1px solid #791616}h2,h3{color:#FFF}#c{background:#F4F4F4;color:#7B0000}img{height:7px;background:#a00000;margin:0 3px}#r{height:7px;background:#181818}#clr{background:none;color:#CFCFCF;font-size:20px;border:0}</style>"
#define DEFAULT_STYLE "<meta charset=UTF-8><style>body{background:#000}tr{text-align:left}table{font-size:13px;color:#FFB000;padding:2px}h2,h3{color:#FFF;font-family:Verdana}img{height:5px;background:#0000FF;margin:0 3px}#r{height:5px;background:#FF0000}</style>"

#define MAX_HELP	18

new Lang_TutorialDatabase[][][] =
{
	{"Race",						"Each race has separate race level and different powers"										},	
	{"Race Level",					"Each race level, upgrade the race powers level"												},	
	{"Race Experience",				"Earn XP (win, kill, plant, defuse) to increase the race level"									},
	{" ",							" "																								},
	{" ",							" "																								},	
	{"Race Skills",					"Auto active by chance percent, each skill level increase the chance" 							},
	{"Race Ultimate",				"MANUAL PRESS F (type in console bind f ultimate), each level decrease ultimate cooldown"		},	
	{"Race Passive",				"Auto active by chance percent, each race level increase the chance"							},	
	{" ",							" "																								},
	{"/war3menu",					"Server game menu"																				},
	{"/changerace",					"Select other race with different powers"														},	
	{"/resetskills",				"Reselect your race skills again, you can choose the upgrades again"							},	
	{"/ability",					"(Race Shaman Wards) MANUAL PRESS V (type in console bind v ability)"							},	
	{"/shopmenu",					"Buy powers with money"																			},			
	{" ",							" "																								},
	{" ",							" "																								},
	{"Developer ?",					"xReforged"																						},	
	{"Questions ?",					"Visit DAEVA.RO"																				}	
					
}

// auto set race for users 3 spawn
#define AUTO_SET_RACE_SPAWN 3

new iUserSpawnNumber[33];
new bool:bUserHasAutoRace[33]; 

