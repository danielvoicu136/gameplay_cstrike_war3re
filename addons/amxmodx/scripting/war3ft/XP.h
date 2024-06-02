/*
*	XP Header File
*/

// Increased 2X by xReforged 

// Objective Modifiers
#define DEFUSING_BOMB		40			// XP awarded when the user starts to defuse the bomb
#define DEFUSED_BOMB		80			// XP awarded when the user defuses the bomb
#define PLANTING_BOMB		40			// XP awarded when the user starts planting the bomb
#define PLANT_BOMB			80			// XP awarded when the user plants the bomb
#define SPAWN_BOMB			40			// XP awarded when the user spawns with the bomb
#define BOMB_PICKUP			40			// XP awarded when the user picks up the bomb
#define TOUCH_HOSTAGE		40			// XP awarded when the user touches a hostage
#define RESCUE_HOSTAGE		80			// XP awarded when the user rescues the hostage
#define KILL_HOSTAGE		40			// XP lost when killing a hostage
#define SPAWN_VIP			40			// XP awarded for spawning as the VIP
#define ESCAPE_VIP			80			// XP awarded for escaping as the VIP
#define OBJ_RADIUS			500			// Nearby radius to award XP for helping complete objectives

// Kill modifiers
#define KILL_HEADSHOT		20			// XP awarded for getting a headshot
#define KILL_HOSTAGE_SAVER	20			// XP awarded for killing the hostage saver
#define	KILL_DEFUSER		20			// XP awarded for killing the defuser
#define KILL_PLANTER		20			// XP awarded for killing the planter
#define KILL_BOMB_CARRIER	20			// XP awarded for killing the bomb carrier
#define KILL_VIP			40			// XP awarded for killing the VIP
#define KILL_RADIUS			250			// Nearby radius to award XP

#define WIN_ROUND			40			// XP awarded for winning the round


// Holds information about the player
enum
{
	PLR_BOMB_DEFUSER = 1,
	PLR_BOMB_PLANTER,
	PLR_HOSTAGE_RESCUER,
	PLR_VIP,
	PLR_BOMB_CARRIER,
};

new g_iPlayerRole[33];
new bool:bHasBegunPlantingOrDefusing[33];

// Holds the XP Multipliers per weapon
new Float:fWpnXPMultiplier[CSW_WAR3_MAX+1] =		{1.0};

// Short Term - Amount of XP needed to gain a level
//new iXPLevelShortTerm[MAX_LEVELS+1]				= {0,150,300,600,1000,1500,2100,2800,3400,4500,5500};

new iXPLevelShortTerm[MAX_LEVELS+1]				= {
	0,
	100,
	200,
	300,
	400,
	500,
	600,
	700,
	800,
	900,
	1000,
	1100,
	1200,
	1300,
	1400,
	1500,
	1600,
	1700,
	1800,
	1900,
	2000,
	2100,
	2200,
	2300,
	2400,
	2500
	};

// Short Term - Amount of XP awarded when killing a user of this level
// new iXPGivenShortTerm[MAX_LEVELS+1]				= {10,15,25,35,40,50,60,70,80,90,95};

new iXPGivenShortTerm[MAX_LEVELS+1]				= {
	10,
	10,
	20,
	30,
	40,
	50,
	60,
	70,
	80,
	90,
	100,
	110,
	120,
	130,
	140,
	150,
	160,
	170,
	180,
	190,
	200,
	210,
	220,
	230,
	240,
	250
	};

// Long Term - Amount of XP needed to gain a level

new iXPLevelSaved[MAX_LEVELS+1]					= {
	0,					// Level 0			0 
	250,				// Level 1			70 		
	500,				// Level 2 			80
	1000,				// Level 3			90
	2000,				// Level 4			110
	4000,				// Level 5			170
	10000,				// Level 6			210
	20000,				// Level 7			270
	30000,				// Level 8			390
	40000,				// Level 9			560
	50000,				// Level 10			780
	60000,				// Level 11			1120
	70000,				// Level 12 		1150
	80000,				// Level 13			1470
	90000,				// Level 14			1880
	100000,				// Level 15 		2550
	110000,				// Level 16 		3270
	120000,				// Level 17			4220
	130000,				// Level 18			4670
	140000,				// Level 19			5780
	150000,				// Level 20			7190
	160000,				// Level 21			8980
	170000,				// Level 22			11230
	180000,				// Level 23			13710
	190000,				// Level 24			16610
	200000				// Level 25 		23140
	};

// Long Term - Amount of XP awarded when killing a user of this level

new iXPGivenSaved[MAX_LEVELS+1]					= {
	6,	// Level 0
	8,	// Level 1
	10,	// Level 2
	12, // Level 3 
	14,	// Level 4
	16,	// Level 5
	18,	// Level 6 
	20,	// Level 7 
	24,	// Level 8
	28,	// Level 9
	32,	// Level 10 
	34,	// Level 11 
	36, // Level 12 
	38, // Level 13 
	40, // Level 14 
	42, // Level 15
	44, // Level 16
	46, // Level 17
	48, // Level 18 
	50, // Level 19 
	52, // Level 20 
	54, // Level 21
	56, // Level 22 
	58, // Level 23 
	60, // Level 24
	62	// Level 25  
	};