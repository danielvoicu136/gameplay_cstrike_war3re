/*
SKILL_36 = Money Wave
SKILL_37 = Medical Armor Wave 
SKILL_38 = Cleave to Armor Wave 
SKILL_39 = Recovery Wave 

#define SKILL_GIFTOFNAARU             36
#define SKILL_VINDICATORSHIELD        37
#define SKILL_HOLYSMITE               38
#define ULTIMATE_LIGHTWRATH           39
*/

#define DR_MONEY_WAVE_FREQ 1.5
#define DR_MONEY_WAVE_RANGE 750

#define DR_MEDICAL_ARMOR_RANGE 750
#define DR_CLEAVE_WAVE_RANGE 750

#define DR_LIGHTWRATH_HP 50 
#define DR_LIGHTWRATH_AR 50 
#define DR_LIGHTWRATH_MONEY 500 
#define DR_LIGHTWRATH_RANGE 750	

// ****************************************
// Draenei's Money Wave
// ****************************************

// Helper function to start the money process
public DR_MoneyWave(id)
{
	if (!task_exists(id + TASK_WAVE_MONEY))
	{
		_DR_MoneyWave(id);
	}
}

// We don't need to ever actually "turn this off" since this task will take care of itself
public _DR_MoneyWave(id)
{

	if (id >= TASK_WAVE_MONEY)
	{
		id -= TASK_WAVE_MONEY;
	}

	// User is no longer connected :/
	if (!p_data_b[id][PB_ISCONNECTED])
	{
		return;
	}

	static iSkillLevel;
	iSkillLevel = SM_GetSkillLevel(id, SKILL_GIFTOFNAARU);

	// User doesn't have this skill, so lets return
	//  - Also return if this was called twice
	if (iSkillLevel <= 0)
	{
		return;
	}

	// Continue money ...
	if (is_user_alive(id))
	{

		set_task(DR_MONEY_WAVE_FREQ, "_DR_MoneyWave", TASK_WAVE_MONEY + id);
	}

	// Prevent healing if this player is hexed
	if (p_data_b[id][PB_HEXED])
	{
		return;
	}

	new players[32], numberofplayers, targetid, targetorigin[3], origin[3];
	new iTeam = get_user_team(id);

	get_user_origin(id, origin);
	get_players(players, numberofplayers, "a");

	// Loop through each player and check to see if one is close enough to be healed
	for (new i = 0; i < numberofplayers; i++)
	{
		targetid = players[i];

		// User is on the caster's team
		if (p_data_b[targetid][PB_ISCONNECTED] && get_user_team(targetid) == iTeam)
		{
			get_user_origin(targetid, targetorigin);

			// User is close enough
			if (get_distance(origin, targetorigin) < DR_MONEY_WAVE_RANGE)
			{
				
				new iBonus = cs_get_user_money(targetid) + p_moneywave_damage[iSkillLevel - 1];
				new iMaxMoney = 16000; 
				
				cs_set_user_money(targetid, clamp(iBonus,0,iMaxMoney));	

			}
		}
	}

	return;
}


// ****************************************
// Draenei's Medical Armor Wave
// ****************************************

// Helper function to start the healing process
public DR_MedicalArmorWave(id)
{
	if (!task_exists(id + TASK_WAVE_MEDICAL_ARMOR))
	{
		_DR_MedicalArmorWave(id);
	}
}

// We don't need to ever actually "turn this off" since this task will take care of itself
public _DR_MedicalArmorWave(id)
{

	if (id >= TASK_WAVE_MEDICAL_ARMOR)
	{
		id -= TASK_WAVE_MEDICAL_ARMOR;
	}

	// User is no longer connected :/
	if (!p_data_b[id][PB_ISCONNECTED])
	{
		return;
	}

	static iSkillLevel;
	iSkillLevel = SM_GetSkillLevel(id, SKILL_VINDICATORSHIELD);

	// User doesn't have this skill, so lets return
	//  - Also return if this was called twice
	if (iSkillLevel <= 0)
	{
		return;
	}

	// Continue medical armor ...
	if (is_user_alive(id))
	{
		set_task(p_medical_armor[iSkillLevel-1], "_DR_MedicalArmorWave", TASK_WAVE_MEDICAL_ARMOR + id);
	}

	// Prevent healing if this player is hexed
	if (p_data_b[id][PB_HEXED])
	{
		return;
	}

	new players[32], numberofplayers, targetid, targetorigin[3], origin[3];
	new iTeam = get_user_team(id);

	get_user_origin(id, origin);
	get_players(players, numberofplayers, "a");

	// Loop through each player and check to see if one is close enough to be healed
	for (new i = 0; i < numberofplayers; i++)
	{
		targetid = players[i];

		// User is on the caster's team
		if (p_data_b[targetid][PB_ISCONNECTED] && get_user_team(targetid) == iTeam)
		{
			get_user_origin(targetid, targetorigin);

			// User is close enough
			if (get_distance(origin, targetorigin) < DR_MEDICAL_ARMOR_RANGE)
			{
				new CsArmorType:ArmorType;
				new iCurArmor = cs_get_user_armor( targetid, ArmorType );
				new iMaxHealth = get_user_maxhealth( targetid );
				new iCurHealth = get_user_health( targetid );
				new iTemp = 1;  
				
				if( iCurArmor > 0 && iCurHealth < iMaxHealth ) {	
					cs_set_user_armor( targetid, iCurArmor - iTemp, ArmorType );
					set_user_health( targetid, get_user_health( targetid ) + iTemp );
				}
			}
		}
	}

	return;
}


// ****************************************
// Draenei's Cleave to Armor  
// ****************************************

DR_SkillsOffensive( iAttacker, iVictim )
{
	static iSkillLevel;

	// Cleave Damage to Armor Wave 
	iSkillLevel = SM_GetSkillLevel( iAttacker, SKILL_HOLYSMITE );
	if ( iSkillLevel > 0 )
	{

	new cleaveEnemy = 0; 
	new players[32], numberofplayers, targetid, targetorigin[3], origin[3];
	new iTeam = get_user_team( iAttacker );

	get_user_origin( iVictim, origin );
	get_players( players, numberofplayers, "a" );
	
	// Loop through each player and check to see if one is close enough 
	for ( new i = 0; i < numberofplayers; i++ )
	{
		targetid = players[i];
		
		// User is on the caster's team
		if ( p_data_b[targetid][PB_ISCONNECTED] && get_user_team( targetid ) != iTeam )
		{
			get_user_origin( targetid, targetorigin );
			
			// User is close enough
			if ( get_distance(origin, targetorigin) < DR_CLEAVE_WAVE_RANGE )
			{
				cleaveEnemy++;
			}
		}
	}
	
		get_user_origin( iAttacker, origin );
		// Loop through each player and check to see if one is close enough 
		for ( new i = 0; i < numberofplayers; i++ )
		{
			targetid = players[i];
			
			// User is on the caster's team
			if ( p_data_b[targetid][PB_ISCONNECTED] && get_user_team( targetid ) == iTeam )
			{
				get_user_origin( targetid, targetorigin );
				
				// User is close enough
				if ( get_distance(origin, targetorigin) < DR_CLEAVE_WAVE_RANGE )
				{
					new CsArmorType:ArmorType;
					new iCurArmor = cs_get_user_armor( targetid, ArmorType );
					new iMaxArmor = SHARED_GetMaxArmor( targetid );
					
					if( iCurArmor < iMaxArmor) 
					{	
						new iBonus = iCurArmor + cleaveEnemy + p_cleave_armor[iSkillLevel-1];
						cs_set_user_armor( targetid, clamp(iBonus,0,iMaxArmor),  ArmorType );
					}
		
				}
			}
		}

	}
}


DR_ULT_LightWrath( id )
{
	
	// User can't use ultimate while planting or defusing!
	if ( p_data_b[id][PB_ISPLANTING] )
	{
		client_print( id, print_center, "You cannot use your ultimate while planting the bomb!" );
		return;
	}

	// If the user's ultimate is not available, then why are we here?
	if ( !ULT_Available( id ) )
	{		
		return;
	}

	// User is alive 
	if ( is_user_alive( id ) )
	{
		new players[32], numberofplayers, targetid, targetorigin[3], origin[3];
		new iTeam = get_user_team(id);

		get_user_origin(id, origin);
		get_players(players, numberofplayers, "a");

		// Loop through each player and check to see if one is close enough to be healed
		for (new i = 0; i < numberofplayers; i++)
		{
			targetid = players[i];

			// User is on the caster's team
			if (p_data_b[targetid][PB_ISCONNECTED] && get_user_team(targetid) == iTeam)
			{
				get_user_origin(targetid, targetorigin);

				// User is close enough
				if (get_distance(origin, targetorigin) < DR_LIGHTWRATH_RANGE)
				{
				
					cs_set_user_money(targetid, cs_get_user_money(targetid) + DR_LIGHTWRATH_MONEY);
					
					new iMaxHealth = get_user_maxhealth( targetid );
					if(get_user_health(targetid) < iMaxHealth) { 
						set_user_health( targetid, clamp(get_user_health( targetid ) + DR_LIGHTWRATH_HP,0,iMaxHealth));
					} 
					
					new CsArmorType:ArmorType;
					new iCurArmor = cs_get_user_armor( targetid, ArmorType );
					new iMaxArmor = SHARED_GetMaxArmor( targetid );
					if( iCurArmor < iMaxArmor) { 
						cs_set_user_armor( targetid, clamp(iCurArmor+DR_LIGHTWRATH_AR,0,iMaxArmor),  ArmorType );
					} 
					
					new iLineWidth = 10;
					Create_TE_BEAMENTS( id, targetid, g_iSprites[SPR_LIGHTNING], 0, 15, 10, iLineWidth, 10, 0, 255, 0, 255, 0 );
					Create_TE_ELIGHT( targetid, targetorigin, 100, 0, 255, 0, 10, 0 );
					emit_sound( targetid, CHAN_STATIC, g_szSounds[SOUND_LIGHTNING], 1.0, ATTN_NORM, 0, PITCH_NORM );
				}
			}
		}
		
		// Set up a new ultimate delay
		ULT_ResetCooldown( id, get_pcvar_num( CVAR_wc3_ult_cooldown ) );
	}
	
	return;
}
