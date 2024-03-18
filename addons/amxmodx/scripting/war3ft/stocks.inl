stock get_user_maxhealth( id )
{

	new maxHealth = 100

	static iSkillLevel;
	iSkillLevel = SM_GetSkillLevel( id, SKILL_DEVOTION );

	// Human Devotion Skill
	if ( iSkillLevel > 0 )
	{
		maxHealth += p_devotion[iSkillLevel-1];
	}


	// Player has a health bonus from the Periapt of Health

	if ( ITEM_Has( id, ITEM_HEALTH ) > ITEM_NONE )
		maxHealth += get_pcvar_num( CVAR_wc3_health );

	return maxHealth
}

// Check the vip 
stock is_user_vip(id)
{
   
   if(get_user_flags(id) & VIP_LEVEL) return true
   else return false
   
   return PLUGIN_CONTINUE
}

// Function checks to see if the weapon is a pistol
stock SHARED_IsSecondaryWeapon( iWeaponID )
{
	// Check for Counter-Strike or Condition Zero
	if ( g_MOD == GAME_CSTRIKE || g_MOD == GAME_CZERO )
	{
		if ( iWeaponID == CSW_ELITE || iWeaponID == CSW_FIVESEVEN || iWeaponID == CSW_USP || iWeaponID == CSW_GLOCK18 || iWeaponID == CSW_DEAGLE || iWeaponID == CSW_P90 )
		{
			return true;
		}
	}
	
	// Check for Day of Defeat
	else if ( g_MOD == GAME_DOD )
	{

	}


	return false;
}

// ColorChat
stock ColorChat(const id, const input[], any:...) {
	new count = 1, players[32];
	static msg[191];
	vformat(msg, 190, input, 3);
	
	replace_all(msg, 190, "!g", "^4");
	replace_all(msg, 190, "!y", "^1");
	replace_all(msg, 190, "!t", "^3");
	
	if(id) players[0] = id;
	else get_players(players, count, "ch"); {
		for(new i = 0; i < count; i++) {
			if(is_user_connected(players[i])) {
				message_begin(MSG_ONE_UNRELIABLE, get_user_msgid("SayText"), _, players[i]);
				write_byte(players[i]);
				write_string(msg);
				message_end();
			}
		}
	} 
}
