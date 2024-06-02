/*
*	Common Ultimate Functions
*/

// This is ran every second...
public _ULT_Delay()
{

	fRunCalcRemoveLootItem();
	
	// Decrement the global counter
	g_iUltimateDelay--;
	
	// Now we need to loop through all players and decrement their ultimate delay
	new players[32], numplayers, i, id;
	get_players( players, numplayers );

	for ( i = 0; i < numplayers; i++ )
	{
		id = players[i];
		
		auto_buy_tome(id);

		// Reduce the user's ultimate delay
		p_data[id][P_ULTIMATEDELAY]--;

		// Then the user's ultimate is ready
		if ( p_data[id][P_ULTIMATEDELAY] == 0 )
		{
			ULT_IconHandler( id );
		}
	}
}

ULT_ResetCooldown( id, iTime, iHideIcon = true )
{

	static iSkillLevel;
	static iSkillID;
	
	iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE );
	iSkillLevel = SM_GetSkillLevel( id, iSkillID );

	// Check if the reset global is after succesfully use or after enemy blocked ultimate
	if( iTime == get_pcvar_num( CVAR_wc3_ult_cooldown ) )
	{

		switch(iSkillLevel)
		{
			case 1: iTime = iTime + p_ultimatereduce[iSkillLevel-1]; // increased by 15 
			case 2: iTime = iTime + p_ultimatereduce[iSkillLevel-1]; // increased by 10
			case 3: iTime = iTime + p_ultimatereduce[iSkillLevel-1]; // increased by 5 
			case 4: iTime = iTime + p_ultimatereduce[iSkillLevel-1]; // increased by 0 
			default: iTime = iTime + 0 
		}

		if(iTime <= 0)
		{
			iTime = ULTIMATE_SECURITY_TIME; // set a value to prevent instant ultimate ready
		}

		p_data[id][P_ULTIMATEDELAY] = iTime;

	}
	else  // We want a specific ultimate time
	{
		p_data[id][P_ULTIMATEDELAY] = iTime;
	}

	// Hide the user's ultimate icon
	if ( iHideIcon )
	{
		ULT_Icon( id, ICON_HIDE );
	}
}


// This function will handle ultimate icons - basically shows if appropriate or hides if appropriate
ULT_IconHandler( id )
{
	// WC3 isn't running... shux
	if ( !WC3_Check() )
	{
		return;
	}
	
	new bool:bShowIcon = true;

	// User has no ultimate!
	new iUltimateID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE );
	if ( iUltimateID > -1 && SM_GetSkillLevel( id, iUltimateID, 6 ) <= 0 )
	{
		bShowIcon = false;
	}

	// In global delay - can't show icon!
	else if ( g_iUltimateDelay > 0 )
	{
		bShowIcon = false;
	}

	// User's delay is longer!
	else if ( p_data[id][P_ULTIMATEDELAY] > 0 )
	{
		bShowIcon = false;
	}

	// User is dead - don't show icon!
	else if ( !is_user_alive( id ) )
	{
		bShowIcon = false;
	}

	// User isn't connected! - don't show icon!
	else if ( !p_data_b[id][PB_ISCONNECTED] )
	{
		bShowIcon = false;
	}


	// We need to hide the user's icon!
	if ( !bShowIcon )
	{
		// In theory I could remember what was displayed when - but easy way out is this
		ULT_ClearIcons( id );
	}

	// Show the user's icon!
	else
	{
		// Play the ultimate ready sound
		client_cmd( id, "speak %s", g_szSounds[SOUND_ULTIMATEREADY] )
		
		// Give the user a graphical message that their ultimate is ready
		WC3_StatusText( id, TXT_ULTIMATE, "%L", id, "ULTIMATE_READY" );
		
		// Show their ultimate icon
		ULT_Icon( id, ICON_SHOW );
	}
}

// This function will display/flash/hide the race's ultimate icon on the screen
ULT_Icon( id, flag )
{
	
	// DOD does not support ultimate icons :/
	if ( g_MOD == GAME_DOD )
	{
		return;
	}

	// If they mysteriously lost a level - we shouldn't display the icon (i.e. admin command)
	if ( p_data[id][P_LEVEL] < MIN_ULT_LEVEL && flag != ICON_HIDE )
	{
		flag = ICON_HIDE;
	}

	new iRaceID = p_data[id][P_RACE];
	
	// If we're chameleon we need to display the icon of the ultimate we have
	if ( p_data[id][P_RACE] == RACE_CHAMELEON )
	{
		new iChamUltimate = g_ChamSkills[3];

		iRaceID = g_SkillOwner[iChamUltimate];
	}
	
	// We should only do this if we have a valid race ID
	if ( iRaceID )
	{
		new r, g, b;

		// Each race has its on color for its icon...
		switch ( iRaceID )
		{
			case 1: r=255,	g=0,	b=0;		// Undead
			case 2: r=0,	g=120,	b=120;		// Human
			case 3: r=255,	g=255,	b=255;		// Orc
			case 4: r=0,	g=0,	b=255;		// Night Elf
			case 5: r=255,	g=0,	b=0;		// Blood Mage
			case 6: r=0,	g=200,	b=200;		// Shadow Hunter
			case 7: r=255, g=0, b=0;    // Warden
			case 8: r=0, g=255, b=0;    // Crypt Lord
			case 9: r=0, g=0, b=255;    // Draenei
			case 10: r=128, g=0, b=0;   // Worgen
			case 11: r=255, g=165, b=0; // Goblin
			case 12: r=139, g=69, b=19; // Tauren
			case 13: r=0, g=128, b=128; // Wisp
			case 14: r=34, g=139, b=34; // Troll
			case 15: r=0, g=0, b=139;   // Pandaren
			case 16: r=178, g=34, b=34; // Demon
			case 17: r=85, g=107, b=47; // Furbolg
			case 18: r=255, g=20, b=147; // Gnome
			case 19: r=0, g=206, b=209; // Naga
			case 20: r=210, g=105, b=30; // Ogre
			case 21: r=0, g=191, b=255; // Murloc
			case 22: r=165, g=42, b=42; // Centaur
			case 23: r=128, g=0, b=128; // Satyr
			case 24: r=112, g=128, b=144; // Titan
			case 25: r=255, g=215, b=0; // Naaru
			case 26: r=169, g=169, b=169; // Dwarf
			case 27: r=75, g=0, b=130; // Forsaken
			case 28: r=139, g=0, b=139; // Earthen
			case 29: r=105, g=105, b=105; // Mechagnome
			case 30: r=123, g=104, b=238; // Highborne
			case 31: r=70, g=130, b=180; // Tuskarr
			case 32: r=176, g=196, b=222; // Vrykul
			case 33: r=0, g=0, b=139; // Giant
			case 34: r=0, g=100, b=0; // Vulpera
			case 35: r=255, g=99, b=71; // Mogu
			case 36: r=46, g=139, b=87; // Treant
			case 37: r=160, g=82, b=45; // Broken
			case 38: r=32, g=178, b=170; // Dryad
			case 39: r=128, g=128, b=0; // Yaungol
			case 40: r=72, g=61, b=139; // Mantid
			case 41: r=60, g=179, b=113; // Saurok
			case 42: r=47, g=79, b=79; // Ethereal
			case 43: r=218, g=112, b=214; // Stoneborn
			case 44: r=199, g=21, b=133; // Jinyu
			case 45: r=95, g=158, b=160; // Hozen
			case 46: r=30, g=144, b=255; // Arakkoa
			case 47: r=255, g=69, b=0; // Sporeling
			case 48: r=75, g=0, b=130; // Quilboar
			case 49: r=100, g=149, b=237; // Drakonid
			case 50: r=255, g=140, b=0; // Gnoll
			case 51: r=106, g=90, b=205; // Harpy
			case 52: r=123, g=104, b=238; // Kobold
			case 53: r=144, g=238, b=144; // Tol'vir
			case 54: r=173, g=255, b=47; // Wolvar
			case 55: r=46, g=139, b=87; // Kvaldir
			case 56: r=255, g=105, b=180; // Anubisath
			case 57: r=255, g=127, b=80; // Magnataur
			case 58: r=100, g=149, b=237; // Grummle
			case 59: r=255, g=228, b=196; // Tortollan
			case 60: r=240, g=128, b=128; // Sethrak
			case 61: r=60, g=179, b=113; // Qiraji
			case 62: r=255, g=160, b=122; // Voidwalker
			case 63: r=72, g=61, b=139; // Felguard
			case 64: r=255, g=69, b=0; // Gilblin
			case 65: r=95, g=158, b=160; // Nymph
			case 66: r=32, g=178, b=170; // Elemental
			case 67: r=255, g=127, b=80; // Flamewaker
			case 68: r=199, g=21, b=133; // Faceless
			case 69: r=0, g=0, b=139; // Taunka
			case 70: r=255, g=99, b=71; // Kaldorei
			case 71: r=144, g=238, b=144; // Unshackled
			case 72: r=240, g=128, b=128; // Ankoan

		}
			
		// Special circumstances should be done here
		switch ( flag )
		{
			case ICON_FLASH:
			{

				// Change colors for Suicide Bomber or Immolate
				if ( SM_GetSkillLevel( id, ULTIMATE_SUICIDE ) > 0 || SM_GetSkillLevel( id, ULTIMATE_IMMOLATE ) > 0 )
				{
					r=255, g=255, b=255;
				}
			}
		}

		// Create the status icon
		Create_StatusIcon( id, flag, g_UltimateIcons[iRaceID - 1], r, g, b );

		// Remember what icon we displayed
		if ( flag == ICON_SHOW || flag == ICON_FLASH )
		{
			g_ULT_iLastIconShown[id] = iRaceID;
		}

		// No icon shown
		else if ( flag == ICON_HIDE )
		{
			g_ULT_iLastIconShown[id] = 0;
		}
	}
}

ULT_ClearIcons( id )
{
	// Only have icons for CS/CZ
	if ( g_MOD == GAME_CSTRIKE || g_MOD == GAME_CZERO )
	{
		// Remove the last icon that was shown!
		if ( g_ULT_iLastIconShown[id] > 0 )
		{
			Create_StatusIcon( id, ICON_HIDE, g_UltimateIcons[g_ULT_iLastIconShown[id]-1], 0, 0, 0 );
		}
		
		/*
		// Loop through all possible icons and remove them
		for ( new i = 0; i < MAX_RACES - 1; i++ )
		{
			Create_StatusIcon( id, ICON_HIDE, g_UltimateIcons[i], 0, 0, 0 )
		}*/
	}
}

ULT_Available( id )
{

	// User needs ult + can't have it used + can't have a delay + can't have a global delay
	if ( p_data[id][P_ULTIMATEDELAY] <= 0 && g_iUltimateDelay <= 0 )
	{
		new iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE );
		new iSkillLevel = SM_GetSkillLevel( id, iSkillID, 7 );
		
		if ( iSkillLevel > 0 )
		{
			return true;
		}
	}

	return false;
}

// This will simply CHECK if a user can block an ultimate!
bool:ULT_CanUserBlockUlt( id )
{
	new bool:bCanBlock = false;

	if ( p_data_b[id][PB_WARDENBLINK] && !p_data_b[id][PB_HEXED] )
	{
		bCanBlock = true;
	}

	else if ( ITEM_Has( id, ITEM_NECKLACE ) > ITEM_NONE )
	{
		bCanBlock = true;
	}

	return bCanBlock;
}

ULT_RemoveCharge( id, iFuncID )
{

	if ( ITEM_Has( id, ITEM_NECKLACE ) > ITEM_NONE )
	{
		ITEM_RemoveCharge( id, ITEM_NECKLACE );
	}
	else if ( p_data_b[id][PB_WARDENBLINK] )
	{}
	else
	{
		WC3_Log( true, "We should never be here!!! (%d)", iFuncID );
	}

	client_print( id, print_chat, "%s You have blocked an enemy's ultimate!", g_MODclient );

	// Play ultimate blocked sound
	emit_sound( id, CHAN_STATIC, g_szSounds[SOUND_SPELLSHIELD], 1.0, ATTN_NORM, 0, PITCH_NORM );
}

ULT_Blocked( id )
{
	// Maybe play a sound here instead?
	client_print( id, print_chat, "%s Your ultimate has been blocked", g_MODclient );

	// Play ultimate blocked sound
	emit_sound( id, CHAN_STATIC, g_szSounds[SOUND_DISPELL], 1.0, ATTN_NORM, 0, PITCH_NORM );
}

public _ULT_Ping( parm[] )
{
	new id = parm[0];
	new iTimeLeft = parm[1];
	
	// Decrement our timer
	parm[1]--;
	
	// User died or diconnected
	if ( !p_data_b[id][PB_ISCONNECTED] || !is_user_alive( id ) )
	{
		p_data_b[id][PB_ISSEARCHING] = false;
	}
	
	// This is the last "playing" of the sound, no target was found :/
	if ( iTimeLeft == 0 )
	{
		p_data_b[id][PB_ISSEARCHING] = false;
		
		if ( ULT_Available( id ) )
		{
			ULT_Icon( id, ICON_SHOW );
		}
	}
	
	// Then we need to play the sound + flash their icon!
	if ( p_data_b[id][PB_ISSEARCHING] )
	{
		// Flash their ultimate icon
		ULT_Icon( id, ICON_FLASH );

		// Play the ping sound
		emit_sound( id, CHAN_STATIC, g_szSounds[SOUND_ULTIMATESCAN], 1.0, ATTN_NORM, 0, PITCH_NORM );

		set_task( 1.0, "_ULT_Ping", TASK_ULTPING + id, parm, 2 );
	}

	return;
}

// Function called before user's spawn
ULT_Reset( id )
{
	// Remove any explosions that are occuring, we don't want them carried over to the next round
	task_exists( TASK_EXPLOSION + id )		? remove_task( TASK_EXPLOSION + id ) : 0;
	task_exists( TASK_BEAMCYLINDER + id )	? remove_task( TASK_BEAMCYLINDER + id ) : 0;

	// Stop Crypt Lord's Ultimate
	task_exists( TASK_FUNNELS + id )		? remove_task( TASK_FUNNELS + id ) : 0;

	// Stop the ultimate cooldowns since they will reset at round start
	task_exists( TASK_UDELAY + id )			? remove_task( TASK_UDELAY + id ) : 0;
	
	// Reset Big Bad Voodoo
	if ( task_exists( TASK_RESETGOD + id ) )
	{
		remove_task( TASK_RESETGOD + id );

		SH_Ult_Remove( id );
	}
	
	// Set this to false to stop searching ultimates (used by NE + ORC + BM ultimates)
	p_data_b[id][PB_ISSEARCHING] = false;

	// Hide their ultimate icon
	ULT_Icon( id, ICON_HIDE );
}
