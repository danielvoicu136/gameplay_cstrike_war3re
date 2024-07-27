/* 
#define SKILL_DARKFLIGHT              40
#define SKILL_SAVAGEREND              41
#define SKILL_BLOODHUNT               42
#define ULTIMATE_WORGENFRENZY         43

SKILL_40 = MultiJumper
SKILL_41 = Enemy Skin 
SKILL_42 = Healing on Kill  
SKILL_43 = Enemy Swap Position  
*/ 

public WO_ULT_Frenzy( iCaster, iTarget )
{
	if(is_user_alive(iCaster) && is_user_alive(iTarget)) {
	
	new vOriginCaster[3];
	get_user_origin( iCaster, vOriginCaster );
	
	new vOriginTarget[3];
	get_user_origin( iTarget, vOriginTarget );
	
	Create_TE_SPRITE( vOriginCaster, g_iSprites[SPR_BANISH], 10, 255 );
	Create_TE_SPRITE( vOriginTarget, g_iSprites[SPR_BANISH], 10, 255 );
	
	new vOriginTemp[3]; 
	vOriginTemp[0] = vOriginTarget[0];
	vOriginTemp[1] = vOriginTarget[1];
	vOriginTemp[2] = vOriginTarget[2] - 2000;
	
	Create_ScreenFade( iTarget, 2, (1<<10), (1<<12), 0, 0, 0, 255 );
	
	set_user_health(iCaster, get_user_maxhealth(iCaster));
	set_user_health(iTarget, 50);
	
	set_user_origin( iTarget, vOriginTemp );
		
	
	SHARED_Teleport( iCaster, vOriginTarget );
	SHARED_Teleport( iTarget, vOriginCaster );
	
	
	/*
	vOriginTarget[2] += 15;
	vOriginCaster[2] += 15;	
	set_user_origin( iCaster, vOriginTarget );
	set_user_origin( iTarget, vOriginCaster );
	*/
		
	Create_ScreenFade( iTarget, 0, 0, 0, 0, 0, 0, 0 );
	
	emit_sound( iCaster, CHAN_STATIC, g_szSounds[SOUND_BANISH], 1.0, ATTN_NORM, 0, PITCH_NORM );
	emit_sound( iTarget, CHAN_STATIC, g_szSounds[SOUND_BANISH], 1.0, ATTN_NORM, 0, PITCH_NORM );
	
	Create_ScreenShake( iCaster, (10<<12), (2<<12), (5<<12) );
	Create_ScreenShake( iTarget, (10<<12), (2<<12), (5<<12) );
	
}

	return PLUGIN_HANDLED;
}