public ShowInfoMessage(id)
{
	//WC3_CheckDev(id);
	//ColorChat(id, "!t%s!g Press!t M!g to open !tWarcraft Server Menu!g.",GAME_NAME);
	//ColorChat(id, "!t%s!g Type in chat!t /help!g to open !tHelp Info!g.",GAME_NAME);

	client_print( id, print_chat, "%s Press M to open Warcraft 3 Menu", g_MODclient );
	client_print( id, print_chat, "%s /shop /race /help /player /admin", g_MODclient );
	
}

public SentSoundSelect(id) 
{ 
	if(is_user_connected(id))
	{
		emit_sound( id, CHAN_STATIC, g_szSounds[SOUND_MENU_SELECT], 1.0, ATTN_NORM, 0, PITCH_NORM );
	}
}
	

public ChooseTeam(id)
{
	if (bChooseTeamOverrideActive[id])
	{
		MENU_GameMainMenu(id);
		return PLUGIN_HANDLED;
	}
	
	bChooseTeamOverrideActive[id] = true;
	return PLUGIN_CONTINUE;
}

public MENU_GameMainMenu(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\yWarcraft 3 Reforged \d(2024) \y");
		
		Menu = menu_create(Title, "_MENU_GameMainMenu");
		
		new szItem1[256];
		formatex(szItem1,sizeof(szItem1)-1,"Shop \yItem^n")
		menu_additem(Menu, szItem1, "1", 0); 

		new szItem2[256];
		formatex(szItem2,sizeof(szItem2)-1,"Select \yRace");
		menu_additem(Menu, szItem2, "2", 0); 

		new szItem3[256];
		formatex(szItem3,sizeof(szItem3)-1,"Select \ySkills");
		menu_additem(Menu, szItem3, "3", 0); 
		
		new szItem4[256];
		formatex(szItem4,sizeof(szItem4)-1,"\yReset Skills^n");
		menu_additem(Menu, szItem4, "4", 0); 

		new szItem5[256];
		formatex(szItem5,sizeof(szItem5)-1,"Skills \yInfo");
		menu_additem(Menu, szItem5, "5", 0); 

		new szItem6[256];
		formatex(szItem6,sizeof(szItem6)-1,"Players \yInfo^n");
		menu_additem(Menu, szItem6, "6", 0); 

		new szItem7[256];
		formatex(szItem7,sizeof(szItem7)-1,"\yChoose Team");
		menu_additem(Menu, szItem7, "7", 0); 

		new szItem8[256];
		formatex(szItem8,sizeof(szItem8)-1,"Help \yInfo");
		menu_additem(Menu, szItem8, "8", 0); 

		new szItem9[256];
		formatex(szItem9,sizeof(szItem9)-1,"Admin \yInfo^n");
		menu_additem(Menu, szItem9, "9", 0); 

		new szItem10[256];
		formatex(szItem10,sizeof(szItem10)-1,"\rAdmin Only");
		menu_additem(Menu, szItem10, "10", 0); 

		
	/*	
		new szItem12[256];
		formatex(szItem12,sizeof(szItem2)-1,"%s", g_bAutoBuy[id] ? "Auto Buy Items: \yEnabled" : "Auto Buy Items: \rDisabled");
		menu_additem(Menu, szItem12, "8", 0); 
	
		new szItem8[256];
		formatex(szItem8,sizeof(szItem8)-1,"%s", g_bExchange[id] ? "Auto Exchange Gold: \yEnabled" : "Auto Exchange Gold: \rDisabled");
		menu_additem(Menu, szItem8, "9", 0); 
		
		new szItem11[256];
		formatex(szItem11,sizeof(szItem11)-1,"\yBONUS \wAdd Level:\y %d", get_user_levelbank(id));
		menu_additem(Menu, szItem11, "12", 0); 
	*/	
		
		
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);

		SentSoundSelect(id);
	}
}

public _MENU_GameMainMenu(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	new Data[6], Name[64];
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	switch(Key)
	{
		
		case 1: 
		{
			MENU_Shop( id ); 
		}

		case 2: 
		{
			WC3_ChangeRaceStart( id );
		}

		case 3: 
		{
			MENU_SelectSkill( id );
		}

		case 4: 
		{
			CMD_Handle( id, "resetskills", true );
			SentSoundSelect(id);
		}

		case 5: 
		{
			MOTD_RaceInfo( id );
		}

		case 6: 
		{
			MOTD_PlayersInfo( id );
		}

		case 7:
		{
			bChooseTeamOverrideActive[id] = false;
			client_cmd(id, "chooseteam");
			SentSoundSelect(id);
		}

		case 8: 
		{
			MOTD_TutorialInfo( id );
		}
		
		case 9: 
		{
			//MOTD_AdminInfo( id );
			client_print( id, print_chat, "%s Admin Info is in work ...", g_MODclient );
		}

		case 10: 
		{
			menu_Admin_Options( id );
		}

		default: return PLUGIN_HANDLED;
		
	/*
		
		case 5:
		{
			if ( CVAR_csdm_active > 0 && get_pcvar_num( CVAR_csdm_active ) == 1 )
			{
				client_print( id, print_center, "Your skills will be reset when you respawn." );
				client_print( id, print_chat, "%s Your skills will be reset when you respawn.", GAME_NAME );
				
			}
			else
			{
				client_print( id, print_center, "Your skills will be reset next round.");
				client_print( id, print_chat, "%s Your skills will be reset next round.", GAME_NAME );
			}
		
				p_data_b[id][PB_RESETSKILLS] = true;
		
		}

		case 6: MENU_Shop( id );
		
		case 7: MOTD_ShopInfo( id );
		
		case 8: MENU_ShopAutoBuy(id);
		
		case 9: Exchange_Think(id);
		
		case 10: MOTD_PlayersInfo( id );
		
		case 11: MOTD_TutorialInfo( id );

		case 12: LevelBank( id );	
	*/
		
		
			
		
	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}

// Display the current race information 

public MOTD_RaceInfo( id )
{
	static iSkillID, bool:bHeaderShown;
	new szTitle[128], szContent[2048];
	new iPos = 0;

	new szTmpDesc[256], szSkillName[128], szRaceName[64];
	
		switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}
			
	if ( SM_IsValidRace( p_data[id][P_RACE] ) )
	{

		// Get the Race Name
		lang_GetRaceName( p_data[id][P_RACE], id, szRaceName, 63 );
		formatex( szTitle, 127, "%s Information", szRaceName);
	}
	else
	{
		formatex( szTitle, 127, "No Race" );
		iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>You have no race please use /changerace")
	}

	bHeaderShown = false;
	iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_TRAINABLE );
	while ( iSkillID != -1 )
	{
		if ( !bHeaderShown )
		{
			iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>Type<th>Name<th>Description")
			iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Race<td>%s<td> ",szRaceName)
			bHeaderShown = true;
		}

		LANG_GetSkillName( iSkillID, id, szSkillName, 127, 2 )
		LANG_GetSkillInfo( iSkillID, id, szTmpDesc, 255 );

		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Skill<td>%s<td>%s", szSkillName, szTmpDesc)

		iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_TRAINABLE, iSkillID + 1 );
	}

	iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE );
	while ( iSkillID != -1 )
	{
	
		LANG_GetSkillName( iSkillID, id, szSkillName, 127, 3 )
		LANG_GetSkillInfo( iSkillID, id, szTmpDesc, 255 );

		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Ultimate<td>%s<td>%s", szSkillName, szTmpDesc)

		iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_ULTIMATE, iSkillID + 1 );
	}
	
	iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_PASSIVE );
	while ( iSkillID != -1 )
	{
		LANG_GetSkillName( iSkillID, id, szSkillName, 127, 4 )
		LANG_GetSkillInfo( iSkillID, id, szTmpDesc, 255 );

		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Passive<td>%s<td>%s", szSkillName, szTmpDesc)

		iSkillID = SM_GetSkillOfType( id, SKILL_TYPE_PASSIVE, iSkillID + 1 );
	}

	show_motd( id, szContent, szTitle );
	SentSoundSelect(id);

	return;
}

// Display the all players information

public MOTD_PlayersInfo(id)
{
	new szContent[2048], szName[64], szPlayersName[64], szRaceName[64];
	new iPos = 0;
		
	get_user_name(id, szName, 63);
		
		switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}
		
		iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>Name<th>VIP<th>Race<th>Level")
		
		for(new i = 1; i < get_maxplayers(); i++)
		{	
			if(is_user_connected(i))
			{
				get_user_name(i, szPlayersName, 63);
				lang_GetRaceName( p_data[i][P_RACE], i, szRaceName, 63 );

				if(equal(szName, szPlayersName)) 
					iPos += format(szContent[iPos], 2047 - iPos, "<tr id=c><td>%s<td>%s<td>%s<td>%d", szPlayersName, is_user_vip(i) ? "VIP" : " ", szRaceName, p_data[i][P_LEVEL])
				else 
					iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>%s<td>%s<td>%s<td>%d", szPlayersName, is_user_vip(i) ? "VIP" : " ", szRaceName, p_data[i][P_LEVEL])
				
			}		
		}
		
		show_motd(id, szContent, "Players Information");
		SentSoundSelect(id);
}	

// Display the shop information

/*
public MOTD_ShopInfo(id)
{
		new szContent[2048];
		new iPos = 0;
		
		switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)	
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)	
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)	
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)	
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)	
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)	
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)	
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}
		
		iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>Name<th>Short<th>Description")
		
		for(new i = 0; i < MAX_SHOPMENU_ITEMS; i++)
		{	
			iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>%s<td>%s<td>%s", Lang_ItemDatabase[i][0], Lang_ItemDatabase[i][1], Lang_ItemDatabase[i][2])		
		}
		
		show_motd(id, szContent, "Shop Information");	
}	

// Display user account information 

public MOTD_Account(id)
{
		new szContent[2048];
		new iPos = 0;
		
		switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)	
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)	
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)	
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)	
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)	
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)	
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)	
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}
		
		
		new szName[32];
		get_user_name( id, szName, 31 );
		
		new iGold = 0; 
		iGold = get_user_gold(id);
		
		new iGold_Value = 0;
		iGold_Value = iGold * VALUE_GOLD;
		
		new szLevel[256], iPosLevel = 0;
		if(p_data[id][P_LEVEL]<MAX_LEVELS)
		{
			iPosLevel += formatex( szLevel[iPosLevel], 255, "%d/%d", p_data[id][P_LEVEL], MAX_LEVELS );
		}
		else
		{
			iPosLevel += formatex( szLevel[iPosLevel], 255, "%d", p_data[id][P_LEVEL]);
		}
		
		
		new szXP[256], iPosXP = 0;
		if(p_data[id][P_LEVEL]<MAX_LEVELS)
		{
			iPosXP += formatex( szXP[iPosXP], 255, "%d/%d", p_data[id][P_XP], XP_GetByLevel( p_data[id][P_LEVEL]+1) );
		}
		else
		{
			iPosXP += formatex( szXP[iPosXP], 255, "%d", p_data[id][P_XP]);
		}
		
		
		new szItems[256], iPosItems = 0;
		
		new bool:ItemSlotOne = false;
	
		if( g_iShopMenuItems[id][ITEM_SLOT_ONE] <= ITEM_NONE && g_iShopMenuItems[id][ITEM_SLOT_TWO] <= ITEM_NONE)
		{
			iPosItems += formatex( szItems[iPosItems], 255, "None" );
		}
		else 
		{
			if ( g_iShopMenuItems[id][ITEM_SLOT_ONE] > ITEM_NONE )
			{
				iPosItems += formatex( szItems[iPosItems], 255, "%s", Lang_ItemDatabase[g_iShopMenuItems[id][ITEM_SLOT_ONE]][ITEM_NAME_SHORT] );
				ItemSlotOne = true;
			}
			
			if ( g_iShopMenuItems[id][ITEM_SLOT_TWO] > ITEM_NONE )
			{
			
				if ( ItemSlotOne )
				{
					iPosItems += formatex( szItems[iPosItems], 255, ", %s", Lang_ItemDatabase[g_iShopMenuItems[id][ITEM_SLOT_TWO]][ITEM_NAME_SHORT] );
				}
				else
				{
					iPosItems += formatex( szItems[iPosItems], 255, "%s", Lang_ItemDatabase[g_iShopMenuItems[id][ITEM_SLOT_TWO]][ITEM_NAME_SHORT] );
				}
				
			}
		}	
		
		
		
		
		iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>Account<th>Information")
		
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Name<td>%s", szName)
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Account<td>%s", is_user_vip(id) ? "VIP" : "Player")
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Gold<td>%i",iGold)
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Gold Value<td>%i $", iGold_Value)
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Race<td>%s", Lang_RaceName[p_data[id][P_RACE]])
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Level<td>%s", szLevel)
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>XP<td>%s", szXP)
		iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>Items<td>%s", szItems)
		
		
		show_motd(id, szContent, "Account Information");	
}	

*/

// Display the tutorial info 

public MOTD_TutorialInfo(id)
{
	new szContent[2048];
		new iPos = 0;
		
		switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)	
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)	
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)	
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)	
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)	
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)	
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)	
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}
		
		iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>About<th>Description")
		
		for(new i = 0; i < MAX_HELP; i++)
		{	
			iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>%s<td>%s", Lang_TutorialDatabase[i][0], Lang_TutorialDatabase[i][1])		
		}
		
		show_motd(id, szContent, "Help Information");
		SentSoundSelect(id);

}

/*
public MOTD_AdminInfo(id)
{
   new szContent[2048], playerName[33], playerFlags[33], rank[33];
   new iPos = 0;

   

   switch(SELECT_DESIGN) 
		{
			case 1: iPos = format(szContent, 2047, DESIGN1_STYLE)
			case 2: iPos = format(szContent, 2047, DESIGN2_STYLE)
			case 3: iPos = format(szContent, 2047, DESIGN3_STYLE)
			case 4: iPos = format(szContent, 2047, DESIGN4_STYLE)
			case 5: iPos = format(szContent, 2047, DESIGN5_STYLE)
			case 6: iPos = format(szContent, 2047, DESIGN6_STYLE)
			case 7: iPos = format(szContent, 2047, DESIGN7_STYLE)
			case 8: iPos = format(szContent, 2047, DESIGN8_STYLE)
			case 9: iPos = format(szContent, 2047, DESIGN9_STYLE)
			case 10: iPos = format(szContent, 2047, DESIGN10_STYLE)
			case 11: iPos = format(szContent, 2047, DESIGN11_STYLE)
			case 12: iPos = format(szContent, 2047, DESIGN12_STYLE)
			case 13: iPos = format(szContent, 2047, DESIGN13_STYLE)
			default: iPos = format(szContent, 2047, DEFAULT_STYLE)
		}

   iPos += format(szContent[iPos], 2047 - iPos, "<body><center><table border=0 width=75%%><th>Name<th>Type<th>Access");


    for (new i = 0; i < get_maxplayers(); i++) {
        if (!is_user_connected(i)) continue;
        get_user_name(i, playerName, 32);
		
        if (get_user_flags(id) & ADMIN_USER) continue; // Skip players with 'Z' flag

        new bool:rankFound = false;
        for (new j = 0; j < sizeof Rang; j++) {

			if(get_user_flags(i) == read_flags(Rang[j][1])) {
				copy(rank, sizeof(rank), Rang[j][0]);
           	 	rankFound = true;
            	break;
           	 }
        }

        if (rankFound) 
		{
			new accessFlags = get_user_flags(i);
    		new flagsString[32];
    		//BuildFlagsString(accessFlags, flagsString, charsmax(flagsString));

			iPos += format(szContent[iPos], 2047 - iPos, "<tr><td>%s<td>%s<td>%s", playerName, rank, accessFlags);
        }
    }

    show_motd(id, szContent, "Admins Information");
    SentSoundSelect(id); 
}
*/

public MENU_War3Menu( id )
{
	static pos, szMenu[256], keys;
	keys = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<9);
	pos = 0;

	// Add the title
	pos += formatex( szMenu[pos], 255-pos, "%L^n^n", id, "MENU_WAR3MENU" );

	// Add the actual options to the menu
	pos += formatex( szMenu[pos], 255-pos, "\w1. %L^n", id, "SKILLS_MENU" );
	pos += formatex( szMenu[pos], 255-pos, "\w2. %L^n", id, "RACE_MENU" );
	pos += formatex( szMenu[pos], 255-pos, "\w3. %L^n", id, "ITEM_MENU" );
	pos += formatex( szMenu[pos], 255-pos, "\w4. %L^n", id, "HELP" );
	pos += formatex( szMenu[pos], 255-pos, "\w5. %L^n", id, "ADMIN_MENU_TITLE" );
	pos += formatex( szMenu[pos], 255-pos, "^n\w0. %L", id, "WORD_EXIT" );

	// Display the menu
	show_menu( id, keys, szMenu, -1 );
	SentSoundSelect(id);

	return;
}

public _MENU_War3Menu( id, key )
{

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch ( key )
	{
		case 0:	menu_Skill_Options( id );
		case 1:	menu_Race_Options( id );
		case 2:	menu_Item_Options( id );
		case 3:	MOTD_War3help( id );
		case 4:	menu_Admin_Options( id );
	}
	
	return PLUGIN_HANDLED;
}

public menu_Skill_Options( id )
{

	new pos = 0, i, menu_body[512], menuitems[3][32]
	new keys = (1<<0)|(1<<1)|(1<<2)|(1<<8)|(1<<9)


	format(menuitems[0],31,"%L",id,"SELECT_SKILLS")
	format(menuitems[1],31,"%L",id,"SKILLS_INFORMATION")
	format(menuitems[2],31,"%L",id,"RESELECT_SKILLS")

	pos += format(menu_body[pos], 511-pos, "%L^n^n",id,"MENU_SKILLS_OPTIONS")
	for (i = 0; i<3; i++){
		pos += format(menu_body[pos], 511-pos, "\w%d. %s^n",i+1,menuitems[i])
	}
	pos += format(menu_body[pos], 511-pos, "^n^n\w9. %L",id,"BACK_STRING")
	pos += format(menu_body[pos], 511-pos, "^n\w0. %L",id,"WORD_EXIT")
	show_menu(id,keys,menu_body,-1)
	SentSoundSelect(id);
	return PLUGIN_CONTINUE
}

public _menu_Skill_Options(id,key){
	
	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch (key){
		case 0:	MENU_SelectSkill( id );
		case 1:	MOTD_SkillsInfo( id );
		case 2:	CMD_Handle( id, "resetskills", true );
		case 8: MENU_War3Menu(id)
		default: return PLUGIN_HANDLED;
	}

	return PLUGIN_HANDLED;
}

public menu_Race_Options(id){

	new pos = 0, i, menu_body[512], menuitems[4][32]
	new keys = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<8)|(1<<9)

	format(menuitems[0],31,"%L",id,"CHANGE_RACE")
	format(menuitems[1],31,"%L",id,"SHOW_LEVEL")
	format(menuitems[2],31,"%L",id,"RESET_XP")
	format(menuitems[3],31,"%L",id,"SHOW_PLAYER_SKILLS")

	pos += format(menu_body[pos], 511-pos, "%L^n^n",id,"MENU_RACE_OPTIONS")
	for (i = 0; i<4; i++){
		pos += format(menu_body[pos], 511-pos, "\w%d. %s^n",i+1,menuitems[i])
	}
	pos += format(menu_body[pos], 511-pos, "^n^n\w9. %L",id,"BACK_STRING")
	pos += format(menu_body[pos], 511-pos, "^n\w0. %L",id,"WORD_EXIT")
	show_menu(id,keys,menu_body,-1)
	SentSoundSelect(id);

	return PLUGIN_CONTINUE
}

public _menu_Race_Options(id,key){

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch (key){
		case 0:	WC3_ChangeRaceStart( id );
		case 1:	WC3_ShowRaceInfo( id );
		case 2:	MENU_ResetXP( id );
		case 3:	MOTD_PlayerSkills( id, true );
		case 8: MENU_War3Menu(id)
		default: return PLUGIN_HANDLED;
	}

	return PLUGIN_HANDLED;
}

public menu_Item_Options(id){

	new pos = 0, i, menu_body[512], menuitems[4][32]
	new keys = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<8)|(1<<9)

	format(menuitems[0],31,"%L",id,"SHOPMENU1_OPTION")
	format(menuitems[1],31,"%L",id,"SHOPMENU2_OPTION")
	format(menuitems[2],31,"%L",id,"SHOW_SHOPMENU1_INFO")
	format(menuitems[3],31,"%L",id,"SHOW_SHOPMENU2_INFO")

	pos += format(menu_body[pos], 511-pos, "%L^n^n",id,"MENU_ITEM_OPTIONS")
	for (i = 0; i<4; i++){
		pos += format(menu_body[pos], 511-pos, "\w%d. %s^n",i+1,menuitems[i])
	}
	pos += format(menu_body[pos], 511-pos, "^n^n\w9. %L",id,"BACK_STRING")
	pos += format(menu_body[pos], 511-pos, "^n\w0. %L",id,"WORD_EXIT")
	show_menu(id,keys,menu_body,-1)
	SentSoundSelect(id);

	return PLUGIN_CONTINUE
}

public _menu_Item_Options(id,key){

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch (key){
		case 0:	MENU_Shopmenu( id, 0 );
		case 1:	MENU_Shopmenu( id, 9 );
		case 2:	MOTD_ItemsInfo( id, 0 );
		case 3:	MOTD_ItemsInfo( id, 9 );
		case 8: MENU_War3Menu(id);
		default: return PLUGIN_HANDLED;
	}

	return PLUGIN_HANDLED;
}

public menu_Admin_Options(id){

    if ( id && !( get_user_flags( id ) & XP_GetAdminFlag() ) )
	{
			client_print(id,print_center,"%s %L",g_MODclient, id,"YOU_HAVE_NO_ACCESS")
			return PLUGIN_HANDLED
	}

	new pos = 0, i, menu_body[512], menuitems[3][32]
	new keys = (1<<0)|(1<<1)|(1<<2)|(1<<8)|(1<<9)

	format(menuitems[0],31,"%L",id,"GIVE_IND_XP")
	format(menuitems[1],31,"%L",id,"GIVE_MULT_XP")
	format(menuitems[2],31,"%L",id,"SAVE_ALL_XP")

	pos += format(menu_body[pos], 511-pos, "%L^n^n",id,"MENU_ADMIN_MENU")
	for (i = 0; i<3; i++){
		pos += format(menu_body[pos], 511-pos, "\w%d. %s^n",i+1,menuitems[i])
	}
	pos += format(menu_body[pos], 511-pos, "^n^n\w9. %L",id,"BACK_STRING")
	pos += format(menu_body[pos], 511-pos, "^n\w0. %L",id,"WORD_EXIT")
	show_menu(id,keys,menu_body,-1)
	SentSoundSelect(id);

	return PLUGIN_CONTINUE
}

public _menu_Admin_Options(id,key){

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch (key){
		case 0:{
			g_menuOption[id] = 1
			g_menuSettings[id] = 50
			menu_PlayerXP_Options(id,g_menuPosition[id] = 0)
		}
		case 1:{
			g_menuOption[id] = 1
			g_menuSettings[id] = 50
			menu_TeamXP_Options(id)
		}
		case 2: DB_SaveAll( false );
		case 8: MENU_War3Menu(id)
	}

	return PLUGIN_HANDLED;
}

public menu_PlayerXP_Options(id,pos){

	if (pos < 0){
		menu_Admin_Options(id)
		return PLUGIN_CONTINUE
	}

	get_players(g_menuPlayers[id],g_menuPlayersNum[id])
	new menuBody[512]
	new b = 0
	new i
	new name[32], team[4], title[128], back[16], exitstring[16]
	new start = pos * 7
	if (start >= g_menuPlayersNum[id])
		start = pos = g_menuPosition[id] = 0
	format(title,127,"%L",id,"MENU_GIVE_PLAYERS_XP")
	new len = format(menuBody,511, "%s\R%d/%d^n\w^n",title,pos+1,(g_menuPlayersNum[id] / 7 + ((g_menuPlayersNum[id] % 7) ? 1 : 0 )))
	new end = start + 7
	new keys = (1<<9)|(1<<7)

	if (end > g_menuPlayersNum[id])
		end = g_menuPlayersNum[id]

	for(new a = start; a < end; ++a){
		i = g_menuPlayers[id][a]
		get_user_name(i,name,31)
		get_user_team(i,team,3)
		keys |= (1<<b)
		len += format(menuBody[len],511-len,"\w%d. %s^n\w",++b,name)
	}

	format(title,127,"%L",id,"GIVE")
	len += format(menuBody[len],511-len,"^n8. %s  %d XP^n",title,g_menuSettings[id])

	format(back,15,"%L",id,"BACK_STRING")

	if (end != g_menuPlayersNum[id]){
		format(menuBody[len],511-len,"^n9. %L...^n0. %s", id,"MORE_STRING", pos ? back : back)
		keys |= (1<<8)
	}
	else{
		format(exitstring,15,"%L",id,"WORD_EXIT")
		format(menuBody[len],511-len,"^n0. %s", pos ? back : exitstring)
	}


	show_menu(id,keys,menuBody,-1)
	return PLUGIN_CONTINUE

}

public _menu_PlayerXP_Options(id,key){

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch(key){
		case 7:{
			++g_menuOption[id]
			if (g_menuOption[id]>6){
				g_menuOption[id]=1
			}
			switch(g_menuOption[id]){
				case 1: g_menuSettings[id] = 25
				case 2: g_menuSettings[id] = 50
				case 3: g_menuSettings[id] = 100
				case 4: g_menuSettings[id] = 200
				case 5: g_menuSettings[id] = 300
				case 6: g_menuSettings[id] = 500
			}
			menu_PlayerXP_Options(id,g_menuPosition[id])
		}
		case 8: menu_PlayerXP_Options(id,++g_menuPosition[id])
		case 9: return PLUGIN_HANDLED;
		default:{
			new player = g_menuPlayers[id][g_menuPosition[id] * 7 + key]
			client_print(player,print_chat,"%s %L",g_MODclient, id,"THE_ADMIN_JUST_GAVE_YOU_XP",g_menuSettings[id])
			p_data[player][P_XP] += g_menuSettings[id]

			XP_Check( player );

			menu_PlayerXP_Options(id,g_menuPosition[id])
		}
	}

	return PLUGIN_HANDLED;
}

public menu_TeamXP_Options(id){

	new pos = 0, i, menu_body[512], menuitems[3][32], give[16]
	new keys = (1<<0)|(1<<1)|(1<<2)|(1<<7)|(1<<8)|(1<<9)

	format(menuitems[0],31,"%L",id,"TERRORISTS")
	format(menuitems[1],31,"%L",id,"CT")
	format(menuitems[2],31,"%L",id,"EVERYONE")

	pos += format(menu_body[pos], 511-pos, "%L^n^n",id,"MENU_TEAM_XP")
	for (i = 0; i<3; i++){
		pos += format(menu_body[pos], 511-pos, "\w%d. %s^n",i+1,menuitems[i])
	}
	format(give,15,"%L",id,"GIVE")
	pos += format(menu_body[pos], 511-pos,"^n8. %s  %d XP^n",give,g_menuSettings[id])
	pos += format(menu_body[pos], 511-pos, "^n^n\w9. %L",id,"BACK_STRING")
	pos += format(menu_body[pos], 511-pos, "^n\w0. %L",id,"WORD_EXIT")
	show_menu(id,keys,menu_body,-1)

	return PLUGIN_CONTINUE
}

public _menu_TeamXP_Options(id,key){

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	switch(key){
		case 0:
		{
			ADMIN_GiveXP( id, "@T", g_menuSettings[id] );
			menu_TeamXP_Options(id)
		}
		case 1:{
			ADMIN_GiveXP( id, "@CT", g_menuSettings[id] );
			menu_TeamXP_Options(id)
		}
		case 2:{
			ADMIN_GiveXP( id, "@ALL", g_menuSettings[id] );
			menu_TeamXP_Options(id)
		}
		case 7:{
			++g_menuOption[id]
			if (g_menuOption[id]>6){
				g_menuOption[id]=1
			}
			switch(g_menuOption[id]){
				case 1: g_menuSettings[id] = 25
				case 2: g_menuSettings[id] = 50
				case 3: g_menuSettings[id] = 100
				case 4: g_menuSettings[id] = 200
				case 5: g_menuSettings[id] = 300
				case 6: g_menuSettings[id] = 500
			}
			menu_TeamXP_Options(id)
		}
		case 8: menu_Admin_Options(id)
	}

	return PLUGIN_HANDLED;
}

public MENU_ResetXP(id)
{

	static szMenu[128];
	new keys = (1<<0)|(1<<1)|(1<<9);
	
	formatex( szMenu, 127, "%L^n^n\w1. Yes^n\w2. No", id, "MENU_RESET_XP" );

	show_menu( id, keys, szMenu, -1 );

	return;
}

public _MENU_ResetXP( id, key )
{
	
	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}

	// User selected yes
	if ( key == 0 )
	{
		XP_Reset( id );
	}
	
	return PLUGIN_HANDLED;
}

// Function will display the changerace menu
public MENU_ChangeRace( id, iRaceXP[MAX_RACES] )
{
	
	new szRaceName[MAX_RACES+1][64], i, pos, iKeys = 0, szMenu[1024], szXP[16];

	// Get our race names
	for ( i = 0; i < get_pcvar_num( CVAR_wc3_races ); i++ )
	{
		lang_customGetRaceName( i + 1, id, szRaceName[i], 63 );
	}

	pos += formatex( szMenu[pos], 1024-pos, "%L", id, "MENU_SELECT_RACE" );
	//pos += formatex( szMenu[pos], 1024-pos, "\ySelect Race" );


	// Then add the experience column
	if ( get_pcvar_num( CVAR_wc3_save_xp ) )
	{
		//pos += formatex( szMenu[pos], 1024-pos, "\R%L^n^n", id, "MENU_WORD_EXPERIENCE" );
		pos += formatex( szMenu[pos], 1024-pos, "\RLeve l^n^n");
	}
	else
	{
		pos += formatex( szMenu[pos], 1024-pos, "^n^n" );
	}

	// Build the changerace menu (for every race)
	for ( i = 0; i < get_pcvar_num( CVAR_wc3_races ); i++ )
	{

		XP_GetLevelByXP( iRaceXP[i])

		//num_to_str( iRaceXP[i], szXP, 15 );
		num_to_str( XP_GetLevelByXP(iRaceXP[i]), szXP, 15 );
		
		// Add the "Select a Hero" message if necessary
		if ( i == 4 )
		{
			//pos += format( szMenu[pos], 512-pos, "%L", id, "SELECT_HERO" );
			  pos += formatex( szMenu[pos], 1024-pos, "^n" );
		}

		if ( i == 8 )
		{
			//pos += format( szMenu[pos], 512-pos, "%L", id, "SELECT_HERO" );
			  pos += formatex( szMenu[pos], 1024-pos, "^n" );
		}
		
		// User's current race
		if ( i == p_data[id][P_RACE] - 1 )
		{
			pos += formatex( szMenu[pos], 1024-pos, "\y%d. %s\d\R%s^n", i + 1, szRaceName[i], ( (get_pcvar_num( CVAR_wc3_save_xp )) ? szXP : " " ) );

			iKeys |= (1<<i);
		}

		// Race the user wants to change to
		else if ( i == p_data[id][P_CHANGERACE] - 1 )
		{
			pos += formatex( szMenu[pos], 1024-pos, "\r%d. %s\r\R%s^n", i + 1, szRaceName[i], ( (get_pcvar_num( CVAR_wc3_save_xp )) ? szXP : " " ) );

			iKeys |= (1<<i);
		}

		// All other cases
		else
		{
			/*
			new iRaceLimit = get_pcvar_num( CVAR_wc3_race_limit );
			new bool:bAllowRace = true;

			if ( iRaceLimit > 0 )
			{
				new iTotal[MAX_RACES];

				// Get how many people are using each race
				new iPlayers[32], iNumPlayers, i, iTarget;
				get_players( iPlayers, iNumPlayers );

				for ( i = 0; i < iNumPlayers; i++ )
				{
					iTarget = iPlayers[i];

					if ( iTarget != id && p_data[iTarget][P_RACE] > 0 && p_data[iTarget][P_RACE] <= get_pcvar_num( CVAR_wc3_races ) )
					{
						iTotal[p_data[iTarget][P_RACE]]++;
					}
				}
				
				// Now if we have more races selected than iRaceLimit provides us with, then we need to increase iRaceLimit
				while ( HLPR_TotalUsingRaces( iTotal ) > iRaceLimit * get_playersnum() )
				{
					iRaceLimit++;
				}

				// Check to see if there was an increase that was necessary
				if ( iRaceLimit > get_pcvar_num( CVAR_wc3_race_limit ) )
				{
					WC3_Log( true, "Error, increase wc3_race_limit to at least %d", iRaceLimit );
				}

				if ( iTotal[i+1] >= iRaceLimit )
				{
					bAllowRace = false;

				}
			}*/

			new bool:bAllowRace = true;

			// Check to see if the user can choose this race (are there too many of this race?)
			if ( bAllowRace )
			{
				pos += formatex( szMenu[pos], 1024-pos, "\w%d. %s\y\R%s^n", i + 1, szRaceName[i], ( (get_pcvar_num( CVAR_wc3_save_xp )) ? szXP : " " ) );

				iKeys |= (1<<i);
			}

			// If not, display the race, but don't give them a key to press
			else
			{
				pos += formatex( szMenu[pos], 1024-pos, "\d%d. %s\y\R%s^n", i + 1, szRaceName[i], ( (get_pcvar_num( CVAR_wc3_save_xp )) ? szXP : " " ) );
			}
		}

	}

	iKeys |= (1<<i);
	
	// This is needed so we can make the Auto-Select option "0" if the number of races is 9
	if ( get_pcvar_num( CVAR_wc3_races ) == 9 )
	{
		i = -1;
	}

	pos += format( szMenu[pos], 1024-pos, "%L", id, "SELECT_RACE_FOOTER", i + 1 );
	
	// Add a cancel button to the bottom
	if ( get_pcvar_num( CVAR_wc3_races ) != 9 )
	{
		iKeys |= (1<<9);

		pos += format( szMenu[pos], 1024-pos, "^n\w0. %L", id, "WORD_CANCEL" );
	}
	
	// Show the menu to the user!
	show_menu( id, iKeys, szMenu, -1 );
	SentSoundSelect(id);

	return;
}

/*HLPR_TotalUsingRaces( iTotalRaces[MAX_RACES] )
{
	new iTotal = 0;
	for ( new i = 1; i <= get_pcvar_num( CVAR_wc3_races ); i++ )
	{
		WC3_Log( true, "%d", i );
		iTotal += iTotalRaces[i];
	}

	return iTotal;
}*/


public _MENU_ChangeRace( id, key )
{

	if ( !WC3_Check() )
	{
		return PLUGIN_HANDLED;
	}
	
	// User pressed 0 (cancel)
	if ( get_pcvar_num( CVAR_wc3_races ) < 9 && key - 1 == get_pcvar_num( CVAR_wc3_races ) )
	{
		return PLUGIN_HANDLED;
	}

	// Save the current race data before we change
	DB_SaveXP( id, false );

	new iRace, iAutoSelectKey = KEY_0;
	
	if ( get_pcvar_num( CVAR_wc3_races ) != 9 )
	{
		iAutoSelectKey = get_pcvar_num( CVAR_wc3_races )
	}
	
	// Auto select a race
	if ( key == iAutoSelectKey )
	{
		iRace = random_num( 1, get_pcvar_num( CVAR_wc3_races ) );
	}

	// Otherwise race is set
	else
	{
		iRace = key + 1;
	}

	// User currently has a race
	if ( p_data[id][P_RACE] != 0 )
	{

		// Change the user's race at the start of next round
		if ( iRace != p_data[id][P_RACE] )
		{
			
			// Special message for csdm
			if ( CVAR_csdm_active > 0 && get_pcvar_num( CVAR_csdm_active ) == 1 )
			{
				client_print( id, print_center, "Your race will be changed when you respawn" );
			}	
			else
			{
				client_print( id, print_center, "%L", id, "CENTER_CHANGED_NEXT" );
			}

			p_data[id][P_CHANGERACE] = iRace;
		}

		// Do nothing
		else
		{
			p_data[id][P_CHANGERACE] = 0;
		}
	}

	// User doesn't have a race so give it to him!!!
	else
	{
		WC3_SetRace( id, iRace );
	}

	return PLUGIN_HANDLED;
}

public MENU_ReplaceItem( id )
{

	new szMenu[512] = "", pos = 0;
	new iKeys = (1<<9)|(1<<0)|(1<<1);

	// Add the menu header
	pos += format( szMenu[pos], 511-pos, "%L^n^n", id, "MENU_REPLACE_ITEM" );

	new szItemName[64], szItemName2[64];
	LANG_GetItemName( g_iShopMenuItems[id][ITEM_SLOT_ONE], id, szItemName, 63 );
	LANG_GetItemName( g_iShopMenuItems[id][ITEM_SLOT_TWO], id, szItemName2, 63 );

	// Add the items
	pos += format( szMenu[pos], 511-pos, "\w1. %s^n", szItemName );
	pos += format( szMenu[pos], 511-pos, "\w2. %s^n", szItemName2 );

	// Add the exit option
	pos += format( szMenu[pos], 511-pos, "^n\w0. %L", id, "WORD_EXIT" );

	// Show the menu
	show_menu( id, iKeys, szMenu, -1 );
	SentSoundSelect(id);

	return;
}

public _menu_ReplaceItem( id, iKey )
{
	if ( !WC3_Check() || iKey == 9 )
	{
		return PLUGIN_HANDLED;
	}

	// Remove item from item slot one
	if ( iKey == 0 )
	{
		ITEM_Remove( id, ITEM_SLOT_ONE )
	}

	// Remove item from itemslot two
	else if ( iKey == 1 )
	{
		ITEM_Remove( id, ITEM_SLOT_TWO )
	}

	// Then the user typed "rings"
	if ( g_iFutureItem[id] == -3 )
	{
		ITEM_BuyRings( id );
	}
	else
	{
		ITEM_Buy( id, g_iFutureItem[id] );
	}

	return PLUGIN_HANDLED;
}


public MENU_Shopmenu( id, iStart )
{

	if ( !ITEM_MenuCanBuyCheck( id ) )
	{
		return;
	}

	// Shopmenu2 can't display if we don't have the correct number of races!
	if ( iStart == MAX_PAGE_ITEMS && get_pcvar_num( CVAR_wc3_races ) <= 4 )
	{
		return;
	}

	new szMenu[512], szItemName[64], pos = 0, i, iItemID;
	new iKeys = (1<<9);

	// Add the header
	if ( iStart == 0 )
	{
		pos += format( szMenu[pos], 511-pos, "%L", id, "MENU_BUY_ITEM" );
	}

	// "Shopmenu 2"
	else if ( iStart == MAX_PAGE_ITEMS )
	{
		pos += format( szMenu[pos], 511-pos, "%L", id, "MENU_BUY_ITEM2" );
	}

	// Lets add the items to the menu!
	for ( i = 0; i < MAX_PAGE_ITEMS; i++ )
	{
		iItemID = iStart + i;

		LANG_GetItemName( iItemID, id, szItemName, 63 );

		// These items don't exist in DOD
		if ( g_MOD == GAME_DOD && ( iItemID == ITEM_SCROLL ) )
		{
			pos += format( szMenu[pos], 511-pos, "\d%d. %s\y\R%d^n", i + 1, szItemName, ITEM_Cost( id, iItemID ) );
		}

		// Everything else is allowed!
		else
		{
			pos += format( szMenu[pos], 511-pos, "\w%d. %s\y\R%d^n", i + 1, szItemName, ITEM_Cost( id, iItemID ) );
			iKeys |= (1<<i);
		}

	}

	pos += format( szMenu[pos], 511-pos, "^n\w0. %L", id, "WORD_EXIT" );

	show_menu( id, iKeys, szMenu, -1 );
	SentSoundSelect(id);
}

public _MENU_Shopmenu1( id, iKey )
{
	if ( !WC3_Check() || iKey == 9 )
	{
		return PLUGIN_HANDLED;
	}

	ITEM_Buy( id, iKey );

	return PLUGIN_HANDLED;
}

public _MENU_Shopmenu2( id, iKey )
{
	if ( !WC3_Check() || iKey == 9 )
	{
		return PLUGIN_HANDLED;
	}

	iKey += MAX_PAGE_ITEMS;
	
	ITEM_Buy( id, iKey );

	return PLUGIN_HANDLED;
}



public MENU_Shop(id) 
{ 
	if(is_user_connected(id)) 
	{
		new Title[256];
		formatex(Title,sizeof(Title)-1,"\yShopmenu \d(quick buy /item) \R\yCo st $^nPage:");
		
		Menu = menu_create(Title, "_MENU_Shop");
		
		new i, szItem[256], szKey[256], szItemName[64];
	
		for ( i = 0; i < MAX_SHOPMENU_ITEMS; i++ ) 
		{ 
				
			LANG_GetItemName( i, id, szItemName, 63 );

			if(ITEM_CanBuyCheckSilent( id, i ))
			formatex(szItem,sizeof(szItem)-1,"%s \R\y%d $",szItemName,ITEM_Cost( id, i ));
			else
			formatex(szItem,sizeof(szItem)-1,"\d%s \R%d $",szItemName,ITEM_Cost( id, i )); 
				
			num_to_str(i+1,szKey,255);
			
			menu_additem(Menu, szItem, szKey, 0); 
		}
  
		menu_setprop(Menu, MPROP_NUMBER_COLOR, "\y") 
		menu_setprop(Menu, MPROP_EXIT, MEXIT_ALL);
		menu_display(id, Menu, 0);
		SentSoundSelect(id);
	}
}

public _MENU_Shop(id, menu, item) 
{
	
	if(item == MENU_EXIT) 
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	new Data[6], Name[64];
	new Access, CallBack;
	menu_item_getinfo(menu, item, Access, Data,5, Name, 63, CallBack);
	new Key = str_to_num(Data);
	switch(Key)
	{
		case 1: ITEM_Buy( id, 0 );
		case 2: ITEM_Buy( id, 1 );
		case 3: ITEM_Buy( id, 2 );
		case 4: ITEM_Buy( id, 3 );
		case 5: ITEM_Buy( id, 4 );
		case 6: ITEM_Buy( id, 5 );
		case 7: ITEM_Buy( id, 6 );	
		case 8: ITEM_Buy( id, 7 );
		case 9: ITEM_Buy( id, 8 );	
		case 10: ITEM_Buy( id, 9 );	
		case 11: ITEM_Buy( id, 10 );	
		case 12: ITEM_Buy( id, 11 );	
		case 13: ITEM_Buy( id, 12 );	
		case 14: ITEM_Buy( id, 13 );
		case 15: ITEM_Buy( id, 14 );	
		case 16: ITEM_Buy( id, 15 );
		case 17: ITEM_Buy( id, 16 );
		case 18: ITEM_Buy( id, 17 );
		case 19: ITEM_Buy( id, 18 );
			
		default: return PLUGIN_HANDLED;
	}
	
	menu_destroy(menu);
	return PLUGIN_HANDLED;
}






public MENU_SelectSkill( id )
{

	// User has no race, how can we select skills?!?
	if ( p_data[id][P_RACE] == 0 )
	{
		//set_hudmessage(200, 100, 0, -1.0, 0.3, 0, 1.0, 5.0, 0.1, 0.2, 2)
		WC3_StatusText( id, TXT_TOP_CENTER, "%L", id, "SELECT_RACE_BEFORE_SKILLS" );

		return;
	}

	// They don't choose skills when it's random
	else if ( p_data[id][P_RACE] == RACE_CHAMELEON && get_pcvar_num( CVAR_wc3_cham_random ) )
	{
		//WC3_StatusText( id, TXT_TOP_CENTER, "%s", "Chameleons can't select skills!" );
		CHAM_ConfigureSkills( id );

		return;
	}

	// Lets make sure the user has some available skill points
	new iSkillsUsed = SM_TotalSkillPointsUsed( id );
	if ( iSkillsUsed >= p_data[id][P_LEVEL] )
	{

		//set_hudmessage(200, 100, 0, -1.0, 0.3, 0, 1.0, 5.0, 0.1, 0.2, 2)
		WC3_StatusText( id, TXT_TOP_CENTER, "%L", id, "ALREADY_SELECTED_SKILL_POINTS" );

		return;
	}

	// Bots don't need a menu now do they??
	if ( is_user_bot( id ) )
	{
		// No race has been selected yet!!
		if ( !SM_SkillAvailable( id ) )
		{
			return;
		}
		
		// Keep giving the bot a random ID until we are full!
		while ( iSkillsUsed < p_data[id][P_LEVEL] )
		{
			SM_GiveRandomSkillPoint( id );

			iSkillsUsed = SM_TotalSkillPointsUsed( id );
		}

		return;
	}

	// OK set up a menu!!!

	new szMsg[512], pos = 0, szSkillName[64];
	new iSkillCounter = 0, iSkillID = 0, iKeys = (1<<9), iSkillLevel;

	// Add the menu header
	pos += formatex( szMsg[pos], 512-pos, "%L", id, "MENU_SELECT_SKILL" );

	iSkillID = SM_GetSkillByPos( id, iSkillCounter );

	while ( iSkillID != -1 )
	{
		iSkillLevel = SM_GetSkillLevel( id, iSkillID, 4 );

		LANG_GetSkillName( iSkillID , id, szSkillName, 63, 1 );
		
		// Add the trainable skills to the menu
		if ( SM_GetSkillType( iSkillID ) == SKILL_TYPE_TRAINABLE )
		{

			// Only add it to the menu if they don't have level 3 already!
			if ( iSkillLevel < MAX_SKILL_LEVEL )
			{

				// User isn't high enough of a level to select this skill yet
				if ( p_data[id][P_LEVEL] <= 2 * iSkillLevel )
				{
					pos += formatex( szMsg[pos], 512-pos, "\d" );
				}

				// Then the user can choose it!
				else
				{
					iKeys |= (1<<iSkillCounter);
				}

				pos += formatex( szMsg[pos], 512-pos, "^n%d. %s (%L %d)\w", iSkillCounter+1, szSkillName, id, "WORD_LEVEL", iSkillLevel + 1 );
			}
		}
		
		// Add the ultimate to the menu
		else if ( SM_GetSkillType( iSkillID ) == SKILL_TYPE_ULTIMATE )
		{

			if ( iSkillLevel < MAX_ULTIMATE_LEVEL )
			{
				// User can't choose ultimate yet :/ p_ultimateunlock[]
	
			/*
				if ( p_data[id][P_LEVEL] <= MIN_ULT_LEVEL - 1 )
				{
					pos += formatex( szMsg[pos], 512-pos, "\d" );
				}
			*/
				// level 0 ultimate [6]    level 1 ultimate [12]    level 2 ultimate [18]   level 3 ultimate [24]
				if ( p_data[id][P_LEVEL] < p_ultimateunlock[iSkillLevel])		
				{
					pos += formatex( szMsg[pos], 512-pos, "\d" );
				}

				// Then the user is level 6 or above and can select their ultimate!
				else
				{
					iKeys |= (1<<iSkillCounter);
				}

				pos += formatex( szMsg[pos], 512-pos, "^n%d. %L: %s (%L %d)\w", iSkillCounter+1, id, "WORD_ULTIMATE", szSkillName, id, "WORD_LEVEL", iSkillLevel + 1);

			}
		}

		iSkillCounter++;
		iSkillID = SM_GetSkillByPos( id, iSkillCounter );
	}

	// Add the cancel button to the menu
	pos += formatex( szMsg[pos], 512-pos, "^n^n0. %L", id, "WORD_CANCEL" );

	// Show the menu!
	show_menu( id, iKeys, szMsg, -1 );
	SentSoundSelect(id);

	return;
}



public _MENU_SelectSkill( id, iKey )
{

	if ( !WC3_Check() || iKey == 9 )
	{
		return PLUGIN_HANDLED;
	}

	// Determine which key was just selected
	new iSkillID = SM_GetSkillByPos( id, iKey );

	// Set up the skill!
	SM_SetSkill( id, iSkillID );
	
	new iSkillsUsed = SM_TotalSkillPointsUsed( id );
	
	// Then they have another skill to select!!
	if ( iSkillsUsed < p_data[id][P_LEVEL] )
	{
		MENU_SelectSkill( id );
	}

	// No more, lets show them their latest level/XP
	else
	{
		WC3_ShowBar( id );
	}

	return PLUGIN_HANDLED;
}
