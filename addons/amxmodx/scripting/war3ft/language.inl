/*
*	Language Functions
*/

#define TOTAL_MENUS 13


// This is the list of menu titles that are in war3ft.txt
new const MENU_NAMES[TOTAL_MENUS][] = 
{
	"MENU_BUY_ITEM",
	"MENU_BUY_ITEM2",
	"MENU_SELECT_SKILL",
	"MENU_SELECT_RACE",
	"MENU_WAR3MENU",
	"MENU_SKILLS_OPTIONS",
	"MENU_ITEM_OPTIONS",
	"MENU_RACE_OPTIONS",
	"MENU_ADMIN_MENU",
	"MENU_GIVE_PLAYERS_XP",
	"MENU_TEAM_XP",
	"MENU_RESET_XP",
	"MENU_REPLACE_ITEM"
};

// Callback functions for the above menu names
new const MENU_CALLBACK[TOTAL_MENUS][] = 
{
	"_MENU_Shopmenu1",
	"_MENU_Shopmenu2",
	"_MENU_SelectSkill",
	"_MENU_ChangeRace",
	"_MENU_War3Menu",
	"_menu_Skill_Options",
	"_menu_Item_Options",
	"_menu_Race_Options",
	"_menu_Admin_Options",
	"_menu_PlayerXP_Options",
	"_menu_TeamXP_Options",
	"_MENU_ResetXP",
	"_menu_ReplaceItem"
};

/*
	Description: Function will register all menus for all languages
*/
public LANG_SetMenus()
{
	new iTotalLanguages = get_langsnum();
	new lang[3], menu[128];
	new curMenuId = -1, highestMenuId = -1;
	new iLang, iMenu;


	// Loop through every menu

	for ( iMenu = 0; iMenu < TOTAL_MENUS; iMenu++ )
	{
		// Register the menu names for each language

		for ( iLang = 0; iLang < iTotalLanguages; iLang++ )
		{
			get_lang ( iLang, lang );

			if ( lang_exists( lang ) )
			{
				formatex ( menu, 127, "%L", lang, MENU_NAMES[iMenu] );
				curMenuId = register_menuid ( menu );

				if ( curMenuId > highestMenuId )
				{
					register_menucmd ( curMenuId, 1023, MENU_CALLBACK[iMenu] );
					highestMenuId = curMenuId;
				}
			}
		}// End language loop
	}// End menu loop
}

//Function will return the race name based on the race id and the language of the user
lang_GetRaceName ( race_id, id, race_name[], len, bool:shortLookup = false )
{

	new szRaceHelper[64];
	
	if ( shortLookup == true )
	{
		formatex( szRaceHelper, 63, "RACE_S_%d", race_id );
	}
	else
	{
		formatex( szRaceHelper, 63, "RACE_%d", race_id );
	}

	// Lookup the race name
	formatex( race_name, len-1, "%L", id, szRaceHelper );
}

/*

//Function will return the race name based on the race id and the language of the user
lang_customGetRaceName ( race_id, id, race_name[], len, bool:shortLookup = false )
{

	new szRaceHelper[64];
	
	if ( shortLookup == true )
	{
		formatex( szRaceHelper, 63, "RACE_H_%d", race_id );
	}
	else
	{
		formatex( szRaceHelper, 63, "RACE_H_%d", race_id );
	}

	// Lookup the race name
	formatex( race_name, len-1, "%L", id, szRaceHelper );
}

*/

//Description: Function will return the shopmenu item name based on the item id and the language of the user
LANG_GetItemName ( item_id, id, item_name[], len, bool:shortLookup = false )
{
	
	if ( item_id < 0 )
	{
		return;
	}

	new szItemHelper[64];

	if ( shortLookup == true )
	{
		formatex( szItemHelper, 63, "ITEM_S_%d", item_id );
	}
	else
	{
		formatex( szItemHelper, 63, "ITEM_%d", item_id );
	}

	// Lookup the item name
	formatex( item_name, len, "%L", id, szItemHelper );
}

LANG_GetItemInfo( item_id, id, item_description[], len )
{
	switch ( item_id )
	{
		case ITEM_ANKH:			formatex ( item_description, len, "%L", id, ( (g_MOD == GAME_DOD) ? "ITEM_I_0_DOD" : "ITEM_I_0" ) );
		case ITEM_BOOTS:		formatex ( item_description, len, "%L", id, ( (g_MOD == GAME_DOD) ? "ITEM_I_1_DOD" : "ITEM_I_1" ) );
		case ITEM_CLAWS:		formatex ( item_description, len, "%L", id, "ITEM_I_2", get_pcvar_num( CVAR_wc3_claw ), get_pcvar_num( CVAR_wc3_claw ) );
		case ITEM_CLOAK:		formatex ( item_description, len, "%L", id, "ITEM_I_3" );
		case ITEM_MASK:			formatex ( item_description, len, "%L", id, "ITEM_I_4" );
		case ITEM_NECKLACE:		formatex ( item_description, len, "%L", id, "ITEM_I_5" );
		case ITEM_FROST:		formatex ( item_description, len, "%L", id, "ITEM_I_6" );
		case ITEM_HEALTH:		formatex ( item_description, len, "%L", id, "ITEM_I_7" );
		case ITEM_TOME:			formatex ( item_description, len, "%L", id, "ITEM_I_8" );
		case ITEM_SCROLL:		formatex ( item_description, len, "%L", id, "ITEM_I_9" );
		case ITEM_PROTECTANT:	formatex ( item_description, len, "%L", id, "ITEM_I_10" );
		case ITEM_HELM:			formatex ( item_description, len, "%L", id, "ITEM_I_11" );
		case ITEM_AMULET:		formatex ( item_description, len, "%L", id, "ITEM_I_12" );
		case ITEM_SOCK:			formatex ( item_description, len, "%L", id, "ITEM_I_13" );
		case ITEM_GLOVES:		formatex ( item_description, len, "%L", id, "ITEM_I_14", get_pcvar_num( CVAR_wc3_glove_timer ) );
		case ITEM_RING:			formatex ( item_description, len, "%L", id, "ITEM_I_15" );
		case ITEM_CHAMELEON:	formatex ( item_description, len, "%L", id, "ITEM_I_16" );
		case ITEM_MOLE:			formatex ( item_description, len, "%L", id, "ITEM_I_17" );

		default:				formatex ( item_description, len, " " );
	}
}

//Description: Function will return the skill name based on the race id, skill id and the language of the user
LANG_GetSkillName( skill_id, id, skill_name[], len, func_id )
{	

	// Handle any game-specific instructions first
	if ( g_MOD == GAME_DOD )
	{
		// Reincarnation
		if ( skill_id == SKILL_REINCARNATION )
		{
			formatex ( skill_name, len-1, "%L", id, "SKILL_10_DOD" );
			return;
		}
	}

	// Handle everything else
	if ( skill_id < 0 || skill_id >= MAX_SKILLS )
	{
		WC3_Log( true, "[%d] Invalid skill: %d", func_id, skill_id );
		return;
	}

	new szSkillHelper[64];

	formatex ( szSkillHelper, 63, "SKILL_%d", skill_id );
	formatex ( skill_name, len-1, "%L", id, szSkillHelper );
}

LANG_GetSkillInfo( skill_id, id, skill_description[], len )
{
	switch ( skill_id )
	{
		// Undead Scourge
		case SKILL_VAMPIRICAURA:		formatex ( skill_description, len, "%L", id, "SKILL_I_0" );
		case SKILL_UNHOLYAURA:			formatex ( skill_description, len, "%L", id, ( (g_MOD == GAME_DOD) ? "SKILL_I_1_DOD" : "SKILL_I_1" ) );
		case SKILL_LEVITATION:			formatex ( skill_description, len, "%L", id, "SKILL_I_2" );
		case ULTIMATE_SUICIDE:			formatex ( skill_description, len, "%L", id, "SKILL_I_3" );

		// Human Alliance
		case SKILL_INVISIBILITY:		formatex ( skill_description, len, "%L", id, "SKILL_I_4" );
		case SKILL_DEVOTION:			formatex ( skill_description, len, "%L", id, "SKILL_I_5" );
		case SKILL_BASH:				formatex ( skill_description, len, "%L", id, "SKILL_I_6" );
		case ULTIMATE_BLINK:			formatex ( skill_description, len, "%L", id, "SKILL_I_7" );

		// Orcish Horde
		case SKILL_CRITICALSTRIKE:		formatex ( skill_description, len, "%L", id, "SKILL_I_8" );
		case SKILL_CRITICALGRENADE:		formatex ( skill_description, len, "%L", id, "SKILL_I_9" );
		case SKILL_REINCARNATION:		formatex ( skill_description, len, "%L", id, "SKILL_I_10" );
		case ULTIMATE_CHAINLIGHTNING:	formatex ( skill_description, len, "%L", id, "SKILL_I_11" );

		// Night Elf
		case SKILL_EVASION:				formatex ( skill_description, len, "%L", id, "SKILL_I_12" );
		case SKILL_THORNS:				formatex ( skill_description, len, "%L", id, "SKILL_I_13" );
		case SKILL_TRUESHOT:			formatex ( skill_description, len, "%L", id, "SKILL_I_14" );
		case ULTIMATE_ENTANGLE:			formatex ( skill_description, len, "%L", id, "SKILL_I_15" );

		// Blood Mage
		case SKILL_PHOENIX:				formatex ( skill_description, len, "%L", id, ( (g_MOD == GAME_DOD) ? "SKILL_I_16_DOD" : "SKILL_I_16" ) );
		case SKILL_BANISH:				formatex ( skill_description, len, "%L", id, "SKILL_I_17" );
		case SKILL_SIPHONMANA:			formatex ( skill_description, len, "%L", id, "SKILL_I_18" );
		case ULTIMATE_IMMOLATE:			formatex ( skill_description, len, "%L", id, "SKILL_I_19" );
		case PASS_RESISTANTSKIN:		formatex ( skill_description, len, "%L", id, "SKILL_I_20" );

		// Shadow Hunter
		case SKILL_HEALINGWAVE:			formatex ( skill_description, len, "%L", id, "SKILL_I_21" );
		case SKILL_HEX:					formatex ( skill_description, len, "%L", id, "SKILL_I_22" );
		case SKILL_SERPENTWARD:			formatex ( skill_description, len, "%L", id, "SKILL_I_23" );
		case ULTIMATE_BIGBADVOODOO:		formatex ( skill_description, len, "%L", id, "SKILL_I_24" );
		case PASS_UNSTABLECONCOCTION:	formatex ( skill_description, len, "%L", id, "SKILL_I_25" );

		// Warden
		case SKILL_FANOFKNIVES:			formatex ( skill_description, len, "%L", id, "SKILL_I_26" );
		case SKILL_BLINK:				formatex ( skill_description, len, "%L", id, "SKILL_I_27" );
		case SKILL_SHADOWSTRIKE:		formatex ( skill_description, len, "%L", id, "SKILL_I_28" );
		case ULTIMATE_VENGEANCE:		formatex ( skill_description, len, "%L", id, "SKILL_I_29" );
		case PASS_HARDENEDSKIN:			formatex ( skill_description, len, "%L", id, "SKILL_I_30" );

		// Crypt Lord
		case SKILL_IMPALE:				formatex ( skill_description, len, "%L", id, "SKILL_I_31" );
		case SKILL_SPIKEDCARAPACE:		formatex ( skill_description, len, "%L", id, "SKILL_I_32" );
		case SKILL_CARRIONBEETLES:		formatex ( skill_description, len, "%L", id, "SKILL_I_33" );
		case ULTIMATE_LOCUSTSWARM:		formatex ( skill_description, len, "%L", id, "SKILL_I_34" );
		case PASS_ORB:					formatex ( skill_description, len, "%L", id, "SKILL_I_35" );
		
		// Draenei
case SKILL_GIFTOFNAARU:            formatex(skill_description, len, "%L", id, "SKILL_I_36");
case SKILL_VINDICATORSHIELD:       formatex(skill_description, len, "%L", id, "SKILL_I_37");
case SKILL_HOLYSMITE:              formatex(skill_description, len, "%L", id, "SKILL_I_38");
case ULTIMATE_LIGHTWRATH:          formatex(skill_description, len, "%L", id, "SKILL_I_39");

// Worgen
case SKILL_DARKFLIGHT:             formatex(skill_description, len, "%L", id, "SKILL_I_40");
case SKILL_SAVAGEREND:             formatex(skill_description, len, "%L", id, "SKILL_I_41");
case SKILL_BLOODHUNT:              formatex(skill_description, len, "%L", id, "SKILL_I_42");
case ULTIMATE_WORGENFRENZY:        formatex(skill_description, len, "%L", id, "SKILL_I_43");

// Goblin
case SKILL_ROCKETBARRAGE:          formatex(skill_description, len, "%L", id, "SKILL_I_44");
case SKILL_TIMEISMONEY:            formatex(skill_description, len, "%L", id, "SKILL_I_45");
case SKILL_EXPLOSIVETRAP:          formatex(skill_description, len, "%L", id, "SKILL_I_46");
case ULTIMATE_BIGBOOM:             formatex(skill_description, len, "%L", id, "SKILL_I_47");

// Tauren
case SKILL_WARSTOMP:               formatex(skill_description, len, "%L", id, "SKILL_I_48");
case SKILL_ENDURANCEAURA:          formatex(skill_description, len, "%L", id, "SKILL_I_49");
case SKILL_EARTHSHOCK:             formatex(skill_description, len, "%L", id, "SKILL_I_50");
case ULTIMATE_REINCARNATION:       formatex(skill_description, len, "%L", id, "SKILL_I_51");

// Wisp
case SKILL_DETONATE:               formatex(skill_description, len, "%L", id, "SKILL_I_52");
case SKILL_HARVESTENERGY:          formatex(skill_description, len, "%L", id, "SKILL_I_53");
case SKILL_FADE:                   formatex(skill_description, len, "%L", id, "SKILL_I_54");
case ULTIMATE_SPIRITOFTHEFOREST:   formatex(skill_description, len, "%L", id, "SKILL_I_55");

// Troll
case SKILL_BERSERKING:             formatex(skill_description, len, "%L", id, "SKILL_I_56");
case SKILL_REGENERATION:           formatex(skill_description, len, "%L", id, "SKILL_I_57");
case SKILL_VOODOOHEX:              formatex(skill_description, len, "%L", id, "SKILL_I_58");
case ULTIMATE_TROLLRAGE:           formatex(skill_description, len, "%L", id, "SKILL_I_59");

// Pandaren
case SKILL_DRUNKENHAZE:            formatex(skill_description, len, "%L", id, "SKILL_I_60");
case SKILL_BREATHOFFIRE:           formatex(skill_description, len, "%L", id, "SKILL_I_61");
case SKILL_ROLL:                   formatex(skill_description, len, "%L", id, "SKILL_I_62");
case ULTIMATE_STORMEARTHANDFIRE:   formatex(skill_description, len, "%L", id, "SKILL_I_63");

// Demon
case SKILL_FELFLAME:               formatex(skill_description, len, "%L", id, "SKILL_I_64");
case SKILL_DEMONICLEAP:            formatex(skill_description, len, "%L", id, "SKILL_I_65");
case SKILL_SHADOWCLEAVE:           formatex(skill_description, len, "%L", id, "SKILL_I_66");
case ULTIMATE_METAMORPHOSIS:       formatex(skill_description, len, "%L", id, "SKILL_I_67");

// Furbolg
case SKILL_HIBERNATE:              formatex(skill_description, len, "%L", id, "SKILL_I_68");
case SKILL_MIGHTYROAR:             formatex(skill_description, len, "%L", id, "SKILL_I_69");
case SKILL_TOTEMSLAM:              formatex(skill_description, len, "%L", id, "SKILL_I_70");
case ULTIMATE_BEARFORM:            formatex(skill_description, len, "%L", id, "SKILL_I_71");

// Gnome
case SKILL_ENGINEERINGMASTERY:     formatex(skill_description, len, "%L", id, "SKILL_I_72");
case SKILL_ESCAPEARTIST:           formatex(skill_description, len, "%L", id, "SKILL_I_73");
case SKILL_GADGETRY:               formatex(skill_description, len, "%L", id, "SKILL_I_74");
case ULTIMATE_MECHANICALGENIUS:    formatex(skill_description, len, "%L", id, "SKILL_I_75");

// Naga
case SKILL_FROSTNOVA:              formatex(skill_description, len, "%L", id, "SKILL_I_76");
case SKILL_FORKEDLIGHTNING:        formatex(skill_description, len, "%L", id, "SKILL_I_77");
case SKILL_ENSNARE:                formatex(skill_description, len, "%L", id, "SKILL_I_78");
case ULTIMATE_WAVE:           		formatex(skill_description, len, "%L", id, "SKILL_I_79");

// Ogre
case SKILL_TWOHEADEDSTRIKE:        formatex(skill_description, len, "%L", id, "SKILL_I_80");
case SKILL_OGRESTRENGTH:           formatex(skill_description, len, "%L", id, "SKILL_I_81");
case SKILL_CRUSHINGBLOW:           formatex(skill_description, len, "%L", id, "SKILL_I_82");
case ULTIMATE_OGREMAGI:            formatex(skill_description, len, "%L", id, "SKILL_I_83");

// Murloc
case SKILL_MURLOCRUSH:             formatex(skill_description, len, "%L", id, "SKILL_I_84");
case SKILL_AQUATICESCAPE:          formatex(skill_description, len, "%L", id, "SKILL_I_85");
case SKILL_SLIPPERYSKIN:           formatex(skill_description, len, "%L", id, "SKILL_I_86");
case ULTIMATE_CALLOFTHEDEEP:       formatex(skill_description, len, "%L", id, "SKILL_I_87");

// Centaur
case SKILL_STAMPEDE:               formatex(skill_description, len, "%L", id, "SKILL_I_88");
case SKILL_TRAMPLE:                formatex(skill_description, len, "%L", id, "SKILL_I_89");
case SKILL_HARPOONTOOSS:           formatex(skill_description, len, "%L", id, "SKILL_I_90");
case ULTIMATE_CENTAURCHARGE:       formatex(skill_description, len, "%L", id, "SKILL_I_91");

// Satyr
case SKILL_CORRUPTION:             formatex(skill_description, len, "%L", id, "SKILL_I_92");
case SKILL_CURSEOFWEAKNESS:        formatex(skill_description, len, "%L", id, "SKILL_I_93");
case SKILL_SHADOWSTEP:             formatex(skill_description, len, "%L", id, "SKILL_I_94");
case ULTIMATE_DARKRITUAL:          formatex(skill_description, len, "%L", id, "SKILL_I_95");

// Titan
case SKILL_TITANSGRIP:             formatex(skill_description, len, "%L", id, "SKILL_I_96");
case SKILL_EARTHSHAKER:            formatex(skill_description, len, "%L", id, "SKILL_I_97");
case SKILL_COSMICBEAM:             formatex(skill_description, len, "%L", id, "SKILL_I_98");
case ULTIMATE_WRATHOFTHETITANS:    formatex(skill_description, len, "%L", id, "SKILL_I_99");

// Naaru
case SKILL_HOLYNOVA:               formatex(skill_description, len, "%L", id, "SKILL_I_100");
case SKILL_LIGHTOFDAWN:            formatex(skill_description, len, "%L", id, "SKILL_I_101");
case SKILL_PURIFY:                 formatex(skill_description, len, "%L", id, "SKILL_I_102");
case ULTIMATE_BLESSINGOFTHENAARU:  formatex(skill_description, len, "%L", id, "SKILL_I_103");

// Dwarf
case SKILL_STONEFORM:              formatex(skill_description, len, "%L", id, "SKILL_I_104");
case SKILL_GUNMASTERY:             formatex(skill_description, len, "%L", id, "SKILL_I_105");
case SKILL_EXPLORERSBOUNTY:        formatex(skill_description, len, "%L", id, "SKILL_I_106");
case ULTIMATE_AVATAR:              formatex(skill_description, len, "%L", id, "SKILL_I_107");

// Forsaken
case SKILL_TOUCHOFTHEGRAVE:        formatex(skill_description, len, "%L", id, "SKILL_I_108");
case SKILL_WILLOFTHEFORSAKEN:      formatex(skill_description, len, "%L", id, "SKILL_I_109");
case SKILL_BLIGHTSPRAY:            formatex(skill_description, len, "%L", id, "SKILL_I_110");
case ULTIMATE_PLAGUEOFUNDEATH:     formatex(skill_description, len, "%L", id, "SKILL_I_111");

// Earthen
case SKILL_STONESKIN:              formatex(skill_description, len, "%L", id, "SKILL_I_112");
case SKILL_GROUNDSLAM:             formatex(skill_description, len, "%L", id, "SKILL_I_113");
case SKILL_HARDENEDRESOLVE:        formatex(skill_description, len, "%L", id, "SKILL_I_114");
case ULTIMATE_LIVINGSTONE:         formatex(skill_description, len, "%L", id, "SKILL_I_115");

// Mechagnome
case SKILL_HYPERCHARGE:            formatex(skill_description, len, "%L", id, "SKILL_I_116");
case SKILL_COMBATANALYSIS:         formatex(skill_description, len, "%L", id, "SKILL_I_117");
case SKILL_EMERGENCYREPAIRS:       formatex(skill_description, len, "%L", id, "SKILL_I_118");
case ULTIMATE_MECHAOVERDRIVE:      formatex(skill_description, len, "%L", id, "SKILL_I_119");

// Highborne
case SKILL_ARCANEBLAST:            formatex(skill_description, len, "%L", id, "SKILL_I_120");
case SKILL_MANASHIELD:             formatex(skill_description, len, "%L", id, "SKILL_I_121");
case SKILL_ANCIENTKNOWLEDGE:       formatex(skill_description, len, "%L", id, "SKILL_I_122");
case ULTIMATE_ARCANEASCENDANCY:    formatex(skill_description, len, "%L", id, "SKILL_I_123");

// Tuskarr
case SKILL_FISHINGNET:             formatex(skill_description, len, "%L", id, "SKILL_I_124");
case SKILL_ICEARMOR:               formatex(skill_description, len, "%L", id, "SKILL_I_125");
case SKILL_TUSKSTRIKE:             formatex(skill_description, len, "%L", id, "SKILL_I_126");
case ULTIMATE_CALLOFTHETIDES:      formatex(skill_description, len, "%L", id, "SKILL_I_127");

// Vrykul
case SKILL_RUNICEMPOWERMENT:       formatex(skill_description, len, "%L", id, "SKILL_I_128");
case SKILL_DRAGONSROAR:            formatex(skill_description, len, "%L", id, "SKILL_I_129");
case SKILL_BATTLEHARDENED:         formatex(skill_description, len, "%L", id, "SKILL_I_130");
case ULTIMATE_VRYKULSWRATH:        formatex(skill_description, len, "%L", id, "SKILL_I_131");

// Giant
case SKILL_GIANTSSTOMP:            formatex(skill_description, len, "%L", id, "SKILL_I_132");
case SKILL_MOUNTAINSTRENGTH:       formatex(skill_description, len, "%L", id, "SKILL_I_133");
case SKILL_BOULDERTHROW:           formatex(skill_description, len, "%L", id, "SKILL_I_134");
case ULTIMATE_COLOSSALSMASH:       formatex(skill_description, len, "%L", id, "SKILL_I_135");

// Vulpera
case SKILL_BAGOFTRICKS:            formatex(skill_description, len, "%L", id, "SKILL_I_136");
case SKILL_SCAVENGERSCUNNING:      formatex(skill_description, len, "%L", id, "SKILL_I_137");
case SKILL_DUSTCLOUD:              formatex(skill_description, len, "%L", id, "SKILL_I_138");
case ULTIMATE_NOMADICSPIRIT:       formatex(skill_description, len, "%L", id, "SKILL_I_139");

// Mogu
case SKILL_LIGHTNINGLASH:          formatex(skill_description, len, "%L", id, "SKILL_I_140");
case SKILL_STONEGUARD:             formatex(skill_description, len, "%L", id, "SKILL_I_141");
case SKILL_SPIRITLINK:             formatex(skill_description, len, "%L", id, "SKILL_I_142");
case ULTIMATE_TITANSWILL:          formatex(skill_description, len, "%L", id, "SKILL_I_143");

// Treant
case SKILL_ROOTSTRIKE:             formatex(skill_description, len, "%L", id, "SKILL_I_144");
case SKILL_NATURESEMBRACE:         formatex(skill_description, len, "%L", id, "SKILL_I_145");
case SKILL_BARKSKIN:               formatex(skill_description, len, "%L", id, "SKILL_I_146");
case ULTIMATE_ANCIENTAWAKENING:    formatex(skill_description, len, "%L", id, "SKILL_I_147");

// Broken
case SKILL_FELRESISTANCE:          formatex(skill_description, len, "%L", id, "SKILL_I_148");
case SKILL_CHAINHEAL:              formatex(skill_description, len, "%L", id, "SKILL_I_149");
case SKILL_DARKSTRIKE:             formatex(skill_description, len, "%L", id, "SKILL_I_150");
case ULTIMATE_FERALSPIRIT:         formatex(skill_description, len, "%L", id, "SKILL_I_151");

// Dryad
case SKILL_NATURESWRATH:           formatex(skill_description, len, "%L", id, "SKILL_I_152");
case SKILL_FORESTSGRACE:           formatex(skill_description, len, "%L", id, "SKILL_I_153");
case SKILL_HEALINGTOUCH:           formatex(skill_description, len, "%L", id, "SKILL_I_154");
case ULTIMATE_WRATHOFTHEWILDS:     formatex(skill_description, len, "%L", id, "SKILL_I_155");

// Yaungol
case SKILL_FIREBRAND:              formatex(skill_description, len, "%L", id, "SKILL_I_156");
case SKILL_WILDCHARGE:             formatex(skill_description, len, "%L", id, "SKILL_I_157");
case SKILL_BURNINGRAGE:            formatex(skill_description, len, "%L", id, "SKILL_I_158");
case ULTIMATE_INFERNOCHARGE:       formatex(skill_description, len, "%L", id, "SKILL_I_159");

// Mantid
case SKILL_BLADEDDANCE:            formatex(skill_description, len, "%L", id, "SKILL_I_160");
case SKILL_AMBERPRISON:            formatex(skill_description, len, "%L", id, "SKILL_I_161");
case SKILL_QUICKSTRIKE:            formatex(skill_description, len, "%L", id, "SKILL_I_162");
case ULTIMATE_SWARMSFURY:          formatex(skill_description, len, "%L", id, "SKILL_I_163");

// Saurok
case SKILL_POISONSPIT:             formatex(skill_description, len, "%L", id, "SKILL_I_164");
case SKILL_CLAWFRENZY:             formatex(skill_description, len, "%L", id, "SKILL_I_165");
case SKILL_CAMOUFLAGE:             formatex(skill_description, len, "%L", id, "SKILL_I_166");
case ULTIMATE_PRIMALRAGE:          formatex(skill_description, len, "%L", id, "SKILL_I_167");

// Ethereal
case SKILL_DIMENSIONALSHIFT:       formatex(skill_description, len, "%L", id, "SKILL_I_168");
case SKILL_MANADRAIN:              formatex(skill_description, len, "%L", id, "SKILL_I_169");
case SKILL_ARCANECLOAK:            formatex(skill_description, len, "%L", id, "SKILL_I_170");
case ULTIMATE_NETHERSTORM:         formatex(skill_description, len, "%L", id, "SKILL_I_171");

// Stoneborn
case SKILL_PETRIFY:                formatex(skill_description, len, "%L", id, "SKILL_I_172");
case SKILL_EARTHQUAKE:             formatex(skill_description, len, "%L", id, "SKILL_I_173");
case SKILL_ROCKARMOR:              formatex(skill_description, len, "%L", id, "SKILL_I_174");
case ULTIMATE_STONETITAN:          formatex(skill_description, len, "%L", id, "SKILL_I_175");

// Jinyu
case SKILL_WATERJET:               formatex(skill_description, len, "%L", id, "SKILL_I_176");
case SKILL_HEALINGRAIN:            formatex(skill_description, len, "%L", id, "SKILL_I_177");
case SKILL_TIDALSURGE:             formatex(skill_description, len, "%L", id, "SKILL_I_178");
case ULTIMATE_WATERSPOUT:          formatex(skill_description, len, "%L", id, "SKILL_I_179");

// Hozen
case SKILL_BANANATOSS:             formatex(skill_description, len, "%L", id, "SKILL_I_180");
case SKILL_AGILITYBOOST:           formatex(skill_description, len, "%L", id, "SKILL_I_181");
case SKILL_FRENZIEDDANCE:          formatex(skill_description, len, "%L", id, "SKILL_I_182");
case ULTIMATE_PRIMALHOWL:          formatex(skill_description, len, "%L", id, "SKILL_I_183");

// Arakkoa
case SKILL_DARKTALON:              formatex(skill_description, len, "%L", id, "SKILL_I_184");
case SKILL_SOLARBEAM:              formatex(skill_description, len, "%L", id, "SKILL_I_185");
case SKILL_CURSEOFSETHE:           formatex(skill_description, len, "%L", id, "SKILL_I_186");
case ULTIMATE_SHADOWNOVA:          formatex(skill_description, len, "%L", id, "SKILL_I_187");

// Sporeling
case SKILL_SPOREBUST:              formatex(skill_description, len, "%L", id, "SKILL_I_188");
case SKILL_REGROWTH:               formatex(skill_description, len, "%L", id, "SKILL_I_189");
case SKILL_FUNGUSSHIELD:           formatex(skill_description, len, "%L", id, "SKILL_I_190");
case ULTIMATE_SPOREEXPLOSION:      formatex(skill_description, len, "%L", id, "SKILL_I_191");

// Quilboar
case SKILL_RAZORQUILLS:            formatex(skill_description, len, "%L", id, "SKILL_I_192");
case SKILL_CHARGE:                 formatex(skill_description, len, "%L", id, "SKILL_I_193");
case SKILL_EARTHSPIKE:             formatex(skill_description, len, "%L", id, "SKILL_I_194");
case ULTIMATE_STAMPEDE:            formatex(skill_description, len, "%L", id, "SKILL_I_195");

// Drakonid
case SKILL_DRAGONSBREATH:          formatex(skill_description, len, "%L", id, "SKILL_I_196");
case SKILL_WINGBUFFET:             formatex(skill_description, len, "%L", id, "SKILL_I_197");
case SKILL_TAILSWIPE:              formatex(skill_description, len, "%L", id, "SKILL_I_198");
case ULTIMATE_DRAGONFURY:          formatex(skill_description, len, "%L", id, "SKILL_I_199");

// Gnoll
case SKILL_VICIOUSBITE:            formatex(skill_description, len, "%L", id, "SKILL_I_200");
case SKILL_GNOLLHOWL:              formatex(skill_description, len, "%L", id, "SKILL_I_201");
case SKILL_SCAVENGERSINSTINCT:     formatex(skill_description, len, "%L", id, "SKILL_I_202");
case ULTIMATE_PACKLEADER:          formatex(skill_description, len, "%L", id, "SKILL_I_203");

// Harpy
case SKILL_SCREECH:                formatex(skill_description, len, "%L", id, "SKILL_I_204");
case SKILL_TALONSTRIKE:            formatex(skill_description, len, "%L", id, "SKILL_I_205");
case SKILL_WINDGUST:               formatex(skill_description, len, "%L", id, "SKILL_I_206");
case ULTIMATE_TEMPEST:             formatex(skill_description, len, "%L", id, "SKILL_I_207");

// Kobold
case SKILL_CANDLESASH:             formatex(skill_description, len, "%L", id, "SKILL_I_208");
case SKILL_TUNNELING:              formatex(skill_description, len, "%L", id, "SKILL_I_209");
case SKILL_SCURRY:                 formatex(skill_description, len, "%L", id, "SKILL_I_210");
case ULTIMATE_CAVEIN:              formatex(skill_description, len, "%L", id, "SKILL_I_211");

// Tol'vir
case SKILL_SANDBLAST:              formatex(skill_description, len, "%L", id, "SKILL_I_212");
case SKILL_OBSIDIANSKIN:           formatex(skill_description, len, "%L", id, "SKILL_I_213");
case SKILL_DUSTSTORM:              formatex(skill_description, len, "%L", id, "SKILL_I_214");
case ULTIMATE_GUARDIANOFTHESANDS:  formatex(skill_description, len, "%L", id, "SKILL_I_215");

// Wolvar
case SKILL_FIERCESLASH:            formatex(skill_description, len, "%L", id, "SKILL_I_216");
case SKILL_HUNTERSMARK:            formatex(skill_description, len, "%L", id, "SKILL_I_217");
case SKILL_PACKTACTICS:            formatex(skill_description, len, "%L", id, "SKILL_I_218");
case ULTIMATE_WOLVARSWRATH:        formatex(skill_description, len, "%L", id, "SKILL_I_219");

// Kvaldir
case SKILL_SEAMIST:                formatex(skill_description, len, "%L", id, "SKILL_I_220");
case SKILL_GHOSTLYSTRIKE:          formatex(skill_description, len, "%L", id, "SKILL_I_221");
case SKILL_UNDYINGWILL:            formatex(skill_description, len, "%L", id, "SKILL_I_222");
case ULTIMATE_WRATHOFTHEKVALDIR:   formatex(skill_description, len, "%L", id, "SKILL_I_223");

// Anubisath
case SKILL_SCARABSWARM:            formatex(skill_description, len, "%L", id, "SKILL_I_224");
case SKILL_SANDSTORM:              formatex(skill_description, len, "%L", id, "SKILL_I_225");
case SKILL_GUARDIANSSHIELD:        formatex(skill_description, len, "%L", id, "SKILL_I_226");
case ULTIMATE_ANUBISATHREBIRTH:    formatex(skill_description, len, "%L", id, "SKILL_I_227");

// Magnataur
case SKILL_FROSTBREATH:            formatex(skill_description, len, "%L", id, "SKILL_I_228");
case SKILL_SLAM:             	   formatex(skill_description, len, "%L", id, "SKILL_I_229");
case SKILL_MASSIVECHARGE:          formatex(skill_description, len, "%L", id, "SKILL_I_230");
case ULTIMATE_GLACIALCRUSH:        formatex(skill_description, len, "%L", id, "SKILL_I_231");

// Grummle
case SKILL_LUCKYDO:                formatex(skill_description, len, "%L", id, "SKILL_I_232");
case SKILL_PACKMENTALITY:          formatex(skill_description, len, "%L", id, "SKILL_I_233");
case SKILL_NIMBLEFINGERS:          formatex(skill_description, len, "%L", id, "SKILL_I_234");
case ULTIMATE_GRUMMLEFORTUNE:      formatex(skill_description, len, "%L", id, "SKILL_I_235");

// Tortollan
case SKILL_SHELLSHIELD:            formatex(skill_description, len, "%L", id, "SKILL_I_236");
case SKILL_TIDALWAVE:              formatex(skill_description, len, "%L", id, "SKILL_I_237");
case SKILL_WISDOMOFTHEAGES:        formatex(skill_description, len, "%L", id, "SKILL_I_238");
case ULTIMATE_TORTOISEGUARDIAN:    formatex(skill_description, len, "%L", id, "SKILL_I_239");

// Sethrak
case SKILL_LIGHTNINGCOIL:          formatex(skill_description, len, "%L", id, "SKILL_I_240");
case SKILL_VENOMSPIT:              formatex(skill_description, len, "%L", id, "SKILL_I_241");
case SKILL_CONSTRICT:              formatex(skill_description, len, "%L", id, "SKILL_I_242");
case ULTIMATE_SERPENTSRAGE:        formatex(skill_description, len, "%L", id, "SKILL_I_243");

// Qiraji
case SKILL_PSYCHICSCREAM:          formatex(skill_description, len, "%L", id, "SKILL_I_244");
case SKILL_SANDTRAP:               formatex(skill_description, len, "%L", id, "SKILL_I_245");
case SKILL_HIVEMIND:               formatex(skill_description, len, "%L", id, "SKILL_I_246");
case ULTIMATE_SWARMCALL:           formatex(skill_description, len, "%L", id, "SKILL_I_247");

// Voidwalker
case SKILL_VOIDBOLT:               formatex(skill_description, len, "%L", id, "SKILL_I_248");
case SKILL_SHADOWSHIELD:           formatex(skill_description, len, "%L", id, "SKILL_I_249");
case SKILL_SIPHONLIFE:             formatex(skill_description, len, "%L", id, "SKILL_I_250");
case ULTIMATE_VOIDERUPTION:        formatex(skill_description, len, "%L", id, "SKILL_I_251");

// Felguard
case SKILL_FELCLEAVE:              formatex(skill_description, len, "%L", id, "SKILL_I_252");
case SKILL_DEMONICROAR:            formatex(skill_description, len, "%L", id, "SKILL_I_253");
case SKILL_HELLFIRE:               formatex(skill_description, len, "%L", id, "SKILL_I_254");
case ULTIMATE_FELSTORM:            formatex(skill_description, len, "%L", id, "SKILL_I_255");

// Gilblin
case SKILL_TOXICSPRAY:             formatex(skill_description, len, "%L", id, "SKILL_I_256");
case SKILL_AQUATICDASH:            formatex(skill_description, len, "%L", id, "SKILL_I_257");
case SKILL_SLIPPERYESCAPE:         formatex(skill_description, len, "%L", id, "SKILL_I_258");
case ULTIMATE_GILBLINFRENZY:       formatex(skill_description, len, "%L", id, "SKILL_I_259");

// Nymph
case SKILL_NATURESCHARM:           formatex(skill_description, len, "%L", id, "SKILL_I_260");
case SKILL_ENTANGLINGROOTS:        formatex(skill_description, len, "%L", id, "SKILL_I_261");
case SKILL_HEALINGWATERS:          formatex(skill_description, len, "%L", id, "SKILL_I_262");
case ULTIMATE_FORESTSBLESSING:     formatex(skill_description, len, "%L", id, "SKILL_I_263");

// Elemental
case SKILL_FLAMEBURST:             formatex(skill_description, len, "%L", id, "SKILL_I_264");
case SKILL_WATERSPIKE:             formatex(skill_description, len, "%L", id, "SKILL_I_265");
case SKILL_QUAKE:                  formatex(skill_description, len, "%L", id, "SKILL_I_266");
case ULTIMATE_ELEMENTALOVERLOAD:   formatex(skill_description, len, "%L", id, "SKILL_I_267");

// Flamewaker
case SKILL_FIRELASH:               formatex(skill_description, len, "%L", id, "SKILL_I_268");
case SKILL_MOLTENARMOR:            formatex(skill_description, len, "%L", id, "SKILL_I_269");
case SKILL_INFERNOCHARGE:          formatex(skill_description, len, "%L", id, "SKILL_I_270");
case ULTIMATE_LAVABURST:           formatex(skill_description, len, "%L", id, "SKILL_I_271");

// Faceless
case SKILL_MINDFLAY:               formatex(skill_description, len, "%L", id, "SKILL_I_272");
case SKILL_SHADOWEMBRACE:          formatex(skill_description, len, "%L", id, "SKILL_I_273");
case SKILL_CORRUPTINGTOUCH:        formatex(skill_description, len, "%L", id, "SKILL_I_274");
case ULTIMATE_VOIDCONSUMPTION:     formatex(skill_description, len, "%L", id, "SKILL_I_275");

// Taunka
case SKILL_BATTLEROAR:             formatex(skill_description, len, "%L", id, "SKILL_I_276");
case SKILL_ICESHIELD:              formatex(skill_description, len, "%L", id, "SKILL_I_277");
case SKILL_SPIRITBOND:             formatex(skill_description, len, "%L", id, "SKILL_I_278");
case ULTIMATE_TAUNKASRESOLVE:      formatex(skill_description, len, "%L", id, "SKILL_I_279");

// Kaldorei
case SKILL_MOONFIRE:               formatex(skill_description, len, "%L", id, "SKILL_I_280");
case SKILL_STARFALL:               formatex(skill_description, len, "%L", id, "SKILL_I_281");
case SKILL_NATURESTOUCH:           formatex(skill_description, len, "%L", id, "SKILL_I_282");
case ULTIMATE_WRATHOFELUNE:        formatex(skill_description, len, "%L", id, "SKILL_I_283");

// Unshackled
case SKILL_SEABLAST:               formatex(skill_description, len, "%L", id, "SKILL_I_284");
case SKILL_FREEDOMCALL:            formatex(skill_description, len, "%L", id, "SKILL_I_285");
case SKILL_TIDALSTRIKE:            formatex(skill_description, len, "%L", id, "SKILL_I_286");
case ULTIMATE_UNSHACKLEDSFURY:     formatex(skill_description, len, "%L", id, "SKILL_I_287");

// Ankoan
case SKILL_WATERWHIP:              formatex(skill_description, len, "%L", id, "SKILL_I_288");
case SKILL_HEALINGTIDES:           formatex(skill_description, len, "%L", id, "SKILL_I_289");
case SKILL_DEEPSEASTRIKE:          formatex(skill_description, len, "%L", id, "SKILL_I_290");
case ULTIMATE_TIDALWAVE:           formatex(skill_description, len, "%L", id, "SKILL_I_291");

		
		
		
	}
}