#define ULT_SEARCHTIME		50			// Translates to 5 seconds

// This isn't actually called when they join spectator :/
public cmd_Teamselect( id, key )
{
	if ( !WC3_Check() )
	{
		return;
	}

	p_data_b[id][PB_CHANGINGTEAM] = true;
}

public cmd_Jointeam( id )
{
	if ( !WC3_Check() )
	{
		return;
	}

	p_data_b[id][PB_CHANGINGTEAM] = true;
}

// This is here to prevent the user from forcing a ResetHUD event
public cmd_fullupdate()
{
	if ( !WC3_Check() )
	{
		return PLUGIN_CONTINUE;
	}

	return PLUGIN_HANDLED;
}

// Called when the user buys a he grenade
public cmd_hegren( id )
{ 
	if ( !WC3_Check() )
	{
		return PLUGIN_CONTINUE;
	}

	// Make sure we even have grenade protection on
	if ( !get_pcvar_num( CVAR_wc3_grenade_protection ) )
	{
		return PLUGIN_CONTINUE;
	}

	// Then they shouldn't be buying a grenade anyway
	if ( !cs_get_user_buyzone( id ) )
	{
		return PLUGIN_HANDLED;
	}


	// User can only buy one grenade per round
	if ( p_data[id][P_HECOUNT] > 0 )
	{ 
		client_print( id, print_center, "%L", id, "ONLY_ONE_GRENADE_PER_ROUND" );

		return PLUGIN_HANDLED;
	}
	
	// Increment since they bought their grenade
	else
	{
		++p_data[id][P_HECOUNT];

		return PLUGIN_CONTINUE;
	}

	return PLUGIN_CONTINUE;
} 

public cmd_Ultimate(id)
{

	if ( !WC3_Check( id ) )
	{
		return PLUGIN_HANDLED;
	}

	// User can't use ultimate when dead
	if ( !is_user_alive( id ) )
	{
		return PLUGIN_HANDLED;
	}

	new iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE );
	new iSkillLevel = SM_GetSkillLevel( id, iSkillID, 3 );

	// User can't use their ultimate when they're hexed
	if ( p_data_b[id][PB_HEXED] )
	{
		WC3_StatusText( id, TXT_ULTIMATE, "%L", id, "HEX_NO_ABILITY" );

		client_cmd( id, "speak %s", g_szSounds[SOUND_ERROR] );

		return PLUGIN_HANDLED;
	}
	
	// User has no ultimate!
	else if ( iSkillLevel == 0 )
	{
		WC3_StatusText( id, TXT_ULTIMATE, "%L", id, "ULTIMATE_NOT_FOUND" );

		client_cmd( id, "speak %s", g_szSounds[SOUND_ERROR] );

		return PLUGIN_HANDLED;
	}
	
	// We're still in the global delay :/
	else if ( g_iUltimateDelay > 0 )
	{
		WC3_StatusText( id, TXT_ULTIMATE, "%L", id, "ULTIMATE_NOT_READY", g_iUltimateDelay );
		
		client_cmd( id, "speak %s", g_szSounds[SOUND_ERROR] );

		return PLUGIN_HANDLED;
	}

	// Ultimate is used or not ready yet
	else if ( p_data[id][P_ULTIMATEDELAY] > 0 )
	{
		WC3_StatusText( id, TXT_ULTIMATE, "%L", id, "ULTIMATE_NOT_READY", p_data[id][P_ULTIMATEDELAY] );

		client_cmd( id, "speak %s", g_szSounds[SOUND_ERROR] );

		return PLUGIN_HANDLED;
	}

	// If we got here, then we can cast the user's ultimate
	switch ( iSkillID )
	{
		
		// UNDEAD - Suicide Bomber
		case ULTIMATE_SUICIDE:
		{
			// User has already had their warning - kill them!
			if ( p_data_b[id][PB_SUICIDEATTEMPT] )
			{
				WC3_KillUser( id, 0, 0 );
			
				p_data_b[id][PB_SUICIDEATTEMPT] = false
			}

			// Give the user his/her warning
			else
			{
				// Flash the user's ultimate icon
				ULT_Icon( id, ICON_FLASH );

				p_data_b[id][PB_SUICIDEATTEMPT] = true

				WC3_StatusText( id, TXT_BLINK_CENTER, "%L", id, "SUICIDE_BOMB_ARMED" );
			}
		}

		// HUMAN ALLIANCE - Blink
		case ULTIMATE_BLINK:
		{
			HU_ULT_Blink( id );
		}

		// ORCISH HORDE - Chain Lightning
		case ULTIMATE_CHAINLIGHTNING:
		{
			if ( !p_data_b[id][PB_ISSEARCHING] )
			{
				p_data_b[id][PB_ISSEARCHING] = true;

				// Don't continue if task already exists...
				if ( !task_exists( TASK_ULTPING + id ) )
				{
					new parm[2];
					parm[0] = id;
					parm[1] = 5;
					_ULT_Ping( parm );
				}
			}
		}

		// NIGHT ELF - Entangling Roots
		case ULTIMATE_ENTANGLE:
		{
			if ( !p_data_b[id][PB_ISSEARCHING] )
			{
				p_data_b[id][PB_ISSEARCHING] = true;

				// Don't continue if task already exists...
				if ( !task_exists( TASK_ULTPING + id ) )
				{
					new parm[2];
					parm[0] = id;
					parm[1] = 5;
					_ULT_Ping( parm );
				}
			}
		}

		// BLOOD MAGE - Immolate
		case ULTIMATE_IMMOLATE:
		{
			p_data_b[id][PB_ISSEARCHING] = true;

			// Don't continue if task already exists...
			if ( !task_exists( TASK_ULTPING + id ) )
			{
				new parm[2];
				parm[0] = id;
				parm[1] = 5;
				_ULT_Ping( parm );
			}
		}

		// SHADOW HUNTER - Big Bad Voodoo
		case ULTIMATE_BIGBADVOODOO:
		{
			SH_Ult_BigBadVoodoo( id );
		}

		// WARDEN - Vengeance
		case ULTIMATE_VENGEANCE:
		{
			WA_ULT_Vengeance( id );
		}

		// CRYPT LORD - Locust Swarm
		case ULTIMATE_LOCUSTSWARM:
		{

			if ( get_pcvar_num( CVAR_wc3_psychostats ) )
			{
				new WEAPON = CSW_LOCUSTS - CSW_WAR3_MIN;

				iStatsShots[id][WEAPON]++;
			}

			CL_ULT_LocustSwarm( id );
		}
	}

	return PLUGIN_HANDLED;
}


public CMD_Handler( id )
{

	new szCmd[32];

	read_argv( 0, szCmd, 31 );

	CMD_Handle( id, szCmd, false );

	return PLUGIN_HANDLED;
}

public cmd_Say( id )
{
	
	new szSaid[32];
	read_args( szSaid, 31 );

	remove_quotes( szSaid );

	CMD_Handle( id, szSaid, true );

	return;
}

// Command handler
CMD_Handle( id, szCmd[], bool:bThroughSay )
{
	// Change the user's race
	if ( CMD_Equal( id,  szCmd, "changerace" ) || CMD_Equal( id,  szCmd, "selectrace" ) || CMD_Equal( id,  szCmd, "race" ) || CMD_Equal( id,  szCmd, "hero" )|| CMD_Equal( id,  szCmd, "changehero" ) || CMD_Equal( id,  szCmd, "selecthero" ))
	{
		WC3_ChangeRaceStart( id );
	}
	
	// Display select skill menu
	else if ( CMD_Equal( id,  szCmd, "selectskills" ) || CMD_Equal( id,  szCmd, "selectskill" ) )
	{
		MENU_SelectSkill( id );
	}

	else if ( CMD_Equal( id,  szCmd, "playerskills" ) || CMD_Equal( id,  szCmd, "playerskill" ) || CMD_Equal( id,  szCmd, "player" ) || CMD_Equal( id,  szCmd, "playerinfo" ) || CMD_Equal( id,  szCmd, "playersinfo" ))
	{
		//MOTD_PlayerSkills( id, bThroughSay );

		// We changed the playerskills table so we need this command just to avoid combilator warning 
		if(bThroughSay) bThroughSay = false;

		MOTD_PlayersInfo( id );
	}

	else if ( CMD_Equal( id,  szCmd, "ms" ) || CMD_Equal( id,  szCmd, "movespeed" ) )
	{
		client_print( id, print_chat, "Move Speed: %0.0f", get_user_maxspeed( id ) );
	}

	else if ( CMD_Equal( id,  szCmd, "skillsinfo" ) || CMD_Equal( id,  szCmd, "skillinfo" ) || CMD_Equal( id,  szCmd, "ultimateinfo" ) || CMD_Equal( id,  szCmd, "raceinfo" ) || CMD_Equal( id,  szCmd, "ultiinfo" ))
	{
		//MOTD_SkillsInfo( id );
		MOTD_RaceInfo( id );
	}

	else if ( CMD_Equal( id,  szCmd, "war3help" ) || CMD_Equal( id,  szCmd, "help" ) || CMD_Equal( id,  szCmd, "info" ))
	{
		//MOTD_War3help(id)
		MOTD_TutorialInfo( id );
	}

	else if ( CMD_Equal( id,  szCmd, "admin" ) || CMD_Equal( id,  szCmd, "admins" ) || CMD_Equal( id,  szCmd, "who" )|| CMD_Equal( id,  szCmd, "admin_who" ) || CMD_Equal( id,  szCmd, "adminwho" ))
	{
		//MOTD_AdminInfo( id );
	}

	else if ( CMD_Equal( id,  szCmd, "iconssetxyz" ) )
	{

		// Sprites not enabled or icons are disabled
		if ( !g_bExtraSpritesEnabled || ( !get_pcvar_num( CVAR_wc3_race_icon ) && !get_pcvar_num( CVAR_wc3_level_icon ) ) )
		{
			client_print( id, print_center, "%L", id, "ICONS_ARE_DISABLED" );
		}
		
		// We at least have one of the icon options enabled (race or level)
		else
		{

			// Allow user to see icons
			if ( p_data[id][P_SHOWICONS] )
			{
				p_data[id][P_SHOWICONS] = false;

				client_print( id, print_center, "%L", id, "NO_LONGER_SEE_ICONS" );
			}

			// User no longer wnats to see icons
			else
			{
				p_data[id][P_SHOWICONS] = true;

				client_print( id, print_center, "%L", id, "NOW_SEE_ICONS" );
			}

			CS_SetIcon( id );
		}
	}

	else if ( CMD_Equal( id, szCmd, "debug" ) )
	{
		client_print( id, print_chat, "%s Ultimate Cooldowns - Global:%d  Player:%d", g_MODclient, g_iUltimateDelay, p_data[id][P_ULTIMATEDELAY] );
	}

	else if ( CMD_Equal( id, szCmd, "levitation" ) )
	{
		if ( SM_GetSkillLevel( id, SKILL_LEVITATION ) <= 0 )
		{
			client_print( id, print_chat, "%s You do not have levitation!", g_MODclient );

			return;
		}

		if ( g_bLevitation[id] )
		{
			g_bLevitation[id] = false;
			
			client_print( id, print_chat, "%s Levitation disabled, type /levitation to re-enable", g_MODclient );
		}
		else
		{
			g_bLevitation[id] = true;
			
			client_print( id, print_chat, "%s Levitation enabled, type /levitation to disable", g_MODclient );
		}

		SHARED_SetGravity( id );
	}

	else if ( CMD_Equal( id,  szCmd, "level" ) )
	{
		WC3_ShowRaceInfo( id );
		WC3_ShowBar( id );
	}

	else if ( CMD_Equal( id,  szCmd, "shopmenu" ) || CMD_Equal( id,  szCmd, "shop" )  )
	{
		//MENU_Shopmenu( id, 0 );
		MENU_Shop( id );
	}

	else if ( CMD_Equal( id,  szCmd, "resetxp" ) )
	{
		MENU_ResetXP( id );
	}

	else if ( CMD_Equal( id,  szCmd, "itemsinfo" ) )
	{
		//MOTD_ItemsInfo( id, 0 )
		MENU_Shop( id );
	}
	else if ( CMD_Equal( id,  szCmd, "war3menu" ) || CMD_Equal( id,  szCmd, "menu" ) || CMD_Equal( id,  szCmd, "war3" ) || CMD_Equal( id,  szCmd, "server" ) || CMD_Equal( id,  szCmd, "servermenu" )    )
	{
		//MENU_War3Menu( id );
		MENU_GameMainMenu( id );
	}
	else if ( CMD_Equal( id,  szCmd, "savexp" ) )
	{
       client_print( id, print_chat, "%s XP is saved automatically, you do not need to type this command", g_MODclient );
	}

	else if ( CMD_Equal( id,  szCmd, "resetskills" ) )
	{
		// Special message for csdm
		if ( CVAR_csdm_active > 0 && get_pcvar_num( CVAR_csdm_active ) == 1 )
		{
			client_print( id, print_center, "Your skills will be reset when you respawn" );
			client_print( id, print_chat, "%s Your skills will be reset when you respawn.", g_MODclient );
		}
		else
		{
			client_print( id, print_center, "%L", id, "SKILLS_RESET_NEXT_ROUND" );
			client_print( id, print_chat, "%L", id, "SKILLS_RESET_NEXT_ROUND", g_MODclient );
		}
		
		p_data_b[id][PB_RESETSKILLS] = true;
		SentSoundSelect(id);
	}

	else if ( CMD_Equal( id,  szCmd, "devs" ) || CMD_Equal( id,  szCmd, "dev" )|| CMD_Equal( id,  szCmd, "developers" ) || CMD_Equal( id,  szCmd, "geesu" ) || CMD_Equal( id,  szCmd, "avanderik" ) || CMD_Equal( id,  szCmd, "ootoaoo" ) || CMD_Equal( id,  szCmd, "pimpdaddy" ) || CMD_Equal( id,  szCmd, "xreforged" ))
	{
		WC3_CheckDev(id)
	}

	// Cheat command if it's enabled
	else if ( get_pcvar_num( CVAR_wc3_cheats ) && ( CMD_Equal( id,  szCmd, "levelmax" ) || CMD_Equal( id,  szCmd, "lvlmax" ) ) )
	{
		new iRaceID = p_data[id][P_RACE];

		// They haven't been given free XP for this race yet
		if ( !g_bGivenLevel10[id][iRaceID] )
		{
			
			// Save their XP now, b/c we're not going to later
			DB_SaveXP( id, true );
	
			// OK give them level 10
			p_data[id][P_XP] = XP_GetByLevel( MAX_LEVELS );

			XP_Check( id );
			
			// Make sure we set that we've given them XP already!
			g_bGivenLevel10[id][iRaceID] = true;

			client_print( id, print_chat, "%s You have level maximum on this race !", g_MODclient );
		}
		// We've already given them XP!!!
		else
		{
			client_print( id, print_chat, "%s You already have level maximum on this race !", g_MODclient );
		}
	}
	
	// Ability to buy items through console commands
	else if ( CMD_Equal( id, szCmd, "ankh" ) || CMD_Equal( id,  szCmd, "guns" ) || CMD_Equal( id,  szCmd, "saveguns" ) )
	{
		if ( ITEM_MenuCanBuyCheck(id) )ITEM_Buy( id, ITEM_ANKH );
	}

	else if ( CMD_Equal( id, szCmd, "boots" ) || CMD_Equal( id,  szCmd, "speed" ))
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_BOOTS );
	}

	else if ( CMD_Equal( id, szCmd, "claws" ) || CMD_Equal( id,  szCmd, "claw" ) || CMD_Equal( id,  szCmd, "damage" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_CLAWS );
	}

	else if ( CMD_Equal( id, szCmd, "cloak" ) || CMD_Equal( id,  szCmd, "invis" ) || CMD_Equal( id,  szCmd, "invisibility" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_CLOAK );
	}

	else if ( CMD_Equal( id, szCmd, "mask" ) || CMD_Equal( id,  szCmd, "lifesteal" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_MASK );
	}

	else if ( CMD_Equal( id, szCmd, "necklace" ) || CMD_Equal( id,  szCmd, "block" ) || CMD_Equal( id,  szCmd, "neck" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_NECKLACE );
	}

	else if ( CMD_Equal( id, szCmd, "frost" ) || CMD_Equal( id,  szCmd, "slow" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_FROST );
	}

	else if ( CMD_Equal( id, szCmd, "health" ) || CMD_Equal( id,  szCmd, "vitality" ) || CMD_Equal( id,  szCmd, "life" ) )
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_HEALTH );
	}

	else if ( CMD_Equal( id, szCmd, "tome" ) || CMD_Equal( id,  szCmd, "exp" ) || CMD_Equal( id,  szCmd, "experience" ) || CMD_Equal( id,  szCmd, "buyxp" )|| CMD_Equal( id,  szCmd, "buyexp" ))
	{
		if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_TOME );
	}

	if ( get_pcvar_num( CVAR_wc3_races ) > 4 )
	{

		if ( CMD_Equal( id,  szCmd, "itemsinfo2" ) )
		{
			// MOTD_ItemsInfo( id, 9 );
			MENU_Shop( id );
		}
		else if ( CMD_Equal( id, szCmd, "scroll" ) || CMD_Equal( id,  szCmd, "respawn" ) || CMD_Equal( id,  szCmd, "revive" ) )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_SCROLL );
		}

		else if ( CMD_Equal( id, szCmd, "helm" ) || CMD_Equal( id,  szCmd, "headshot" ) || CMD_Equal( id,  szCmd, "hs" )  )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_HELM );
		}

		else if ( CMD_Equal( id, szCmd, "amulet" ) || CMD_Equal( id,  szCmd, "silent" ) || CMD_Equal( id,  szCmd, "silence" ) )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_AMULET );
		}

		else if ( CMD_Equal( id, szCmd, "socks" ) || CMD_Equal( id,  szCmd, "gravity" ) || CMD_Equal( id,  szCmd, "sock" ))
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_SOCK );
		}

		else if ( CMD_Equal( id, szCmd, "gloves" ) || CMD_Equal( id,  szCmd, "grenade" ) || CMD_Equal( id,  szCmd, "glove" ) )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_GLOVES );
		}

		else if ( CMD_Equal( id,  szCmd, "rings" ) || CMD_Equal( id,  szCmd, "ring" ) || CMD_Equal( id,  szCmd, "regen" ) || CMD_Equal( id,  szCmd, "regeneration" ) || CMD_Equal( id,  szCmd, "heal" ) || CMD_Equal( id,  szCmd, "healing" )  )
		{
			if ( ITEM_MenuCanBuyCheck( id ) ) ITEM_BuyRings( id );
		}

		else if ( CMD_Equal( id, szCmd, "chameleon" ) || CMD_Equal( id,  szCmd, "skin" ) )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_CHAMELEON );
		}

		else if ( CMD_Equal( id, szCmd, "guard" ) || CMD_Equal( id,  szCmd, "protectant" ) || CMD_Equal( id,  szCmd, "scan" ) || CMD_Equal( id,  szCmd, "scanner" )  )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_PROTECTANT );
		}

		else if ( CMD_Equal( id, szCmd, "mole" ) || CMD_Equal( id,  szCmd, "traitor" ) )
		{
			if (ITEM_MenuCanBuyCheck(id)) ITEM_Buy( id, ITEM_MOLE );
		}

		else if ( CMD_Equal( id,  szCmd, "ability" ) || CMD_Equal( id,  szCmd, "ward" ) )
		{
			SH_PlaceSerpentWard( id );
		}

		else if ( CMD_Equal( id,  szCmd, "shopmenu2" ) || CMD_Equal( id,  szCmd, "shop2" )  )
		{
			//MENU_Shopmenu( id, 9 );
			MENU_Shop( id );
		}

	}
	
	return;
}

// Function will check if the first string is equal to the second (checks for NAME or /NAME)
CMD_Equal( id,  szCmd[], szCorrectCmd[] )
{

	new szTmp[64];
	formatex( szTmp, 63, "/%s", szCorrectCmd );

	new bool:bValid = equali( szCmd, szTmp ) || equali( szCmd, szCorrectCmd );
	
	if ( !WC3_Check() )
	{
		
		// Only print a message if the command was valid
		if ( bValid )
		{
			WC3_Check( id );
		}
	
		return false;
	}


	return bValid;
}

public bindOpenShop(id)
{
	MENU_Shop( id );

    return PLUGIN_HANDLED
}


public bindSetWard(id)
{
	SH_PlaceSerpentWard( id );

    return PLUGIN_HANDLED
}


public FWD_CmdStart(id, uc_handle, seed)
{
	static Impulse;
	Impulse = get_uc(uc_handle, UC_Impulse);
	
	if(Impulse == FLASHLIGHT)
	{
		
		cmd_Ultimate(id);
	
		set_uc(uc_handle, UC_Impulse, 0);
		
		return FMRES_SUPERCEDE;
	}
	return FMRES_IGNORED;
}
