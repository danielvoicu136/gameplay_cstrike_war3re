// For Icon events
#define ICON_HIDE 0 
#define ICON_SHOW 1 
#define ICON_FLASH 2 

new g_UltimateIcons[MAX_RACES-1][32] = 
					{
						"dmg_rad",				// Undead
"item_longjump",		// Human Alliance
"dmg_shock",			// Orcish Horde
"item_healthkit",		// Night Elf
"dmg_heat",				// Blood Mage
"suit_full",			// Shadow Hunter
"cross",				// Warden
"dmg_gas",				// Crypt Lord
"dmg_rad",				// Draenei
"item_longjump",		// Worgen
"dmg_shock",			// Goblin
"item_healthkit",		// Tauren
"dmg_heat",				// Wisp
"suit_full",			// Troll
"cross",				// Pandaren
"dmg_gas",				// Demon
"dmg_rad",				// Furbolg
"item_longjump",		// Gnome
"dmg_shock",			// Naga
"item_healthkit",		// Ogre
"dmg_heat",				// Murloc
"suit_full",			// Centaur
"cross",				// Satyr
"dmg_gas",				// Titan
"dmg_rad",				// Naaru
"item_longjump",		// Dwarf
"dmg_shock",			// Forsaken
"item_healthkit",		// Earthen
"dmg_heat",				// Mechagnome
"suit_full",			// Highborne
"cross",				// Tuskarr
"dmg_gas",				// Vrykul
"dmg_rad",				// Giant
"item_longjump",		// Vulpera
"dmg_shock",			// Mogu
"item_healthkit",		// Treant
"dmg_heat",				// Broken
"suit_full",			// Dryad
"cross",				// Yaungol
"dmg_gas",				// Mantid
"dmg_rad",				// Saurok
"item_longjump",		// Ethereal
"dmg_shock",			// Stoneborn
"item_healthkit",		// Jinyu
"dmg_heat",				// Hozen
"suit_full",			// Arakkoa
"cross",				// Sporeling
"dmg_gas",				// Quilboar
"dmg_rad",				// Drakonid
"item_longjump",		// Gnoll
"dmg_shock",			// Harpy
"item_healthkit",		// Kobold
"suit_full",			// Tol'vir
"cross",				// Wolvar
"dmg_gas",				// Kvaldir
"dmg_rad",				// Anubisath
"item_longjump",		// Magnataur
"dmg_shock",			// Grummle
"item_healthkit",		// Tortollan
"dmg_heat",				// Sethrak
"suit_full",			// Qiraji
"cross",				// Voidwalker
"dmg_gas",				// Felguard
"dmg_rad",				// Gilblin
"item_longjump",		// Nymph
"dmg_shock",			// Elemental
"item_healthkit",		// Flamewaker
"dmg_heat",				// Faceless
"suit_full",			// Taunka
"cross",				// Kaldorei
"dmg_gas",				// Unshackled
"dmg_rad"				// Ankoan
					};

new g_ULT_iLastIconShown[33];				// Stores what the last icon shown was for each user (race #)

