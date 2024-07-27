
new fwd_ReportKill = -1;

public FWD_Register()
{
	//reportKill(killer, victim, weaponIndex, weaponName); 
	//iKiller, iVictim, iWeapon, szWpnName
	fwd_ReportKill = CreateMultiForward( "wc3_reportkill", ET_IGNORE, FP_CELL, FP_CELL, FP_CELL, FP_STRING );
}

public FWD_Destroy()
{
	DestroyForward( fwd_ReportKill );
}

/*
public FWD_PreThink(id) {

	if(is_user_connected(id) && is_user_alive(id) && get_user_weapon(id) == CSW_KNIFE ) 
	{ 
	
					if(SM_GetSkillLevel( id, SKILL_INVISIBILITY ) > 0 || ITEM_Has(id, ITEM_CLOAK ) > ITEM_NONE ) 
					{
						set_pev(id, pev_viewmodel2, szInvisKnife);
						set_pev(id, pev_weaponmodel2, "");
					}
					
	}
}
*/

/*
public Ham_Knife_Deploy_Pre(const iWeaponEnt)
{
    new const iOwner = pev(iWeaponEnt, pev_owner)

    if(!is_user_alive(iOwner))
        return HAM_IGNORED

	if(SM_GetSkillLevel( iOwner, SKILL_INVISIBILITY ) > 0 || ITEM_Has(iOwner, ITEM_CLOAK ) > ITEM_NONE ) 
	{
		set_pev(iOwner, pev_viewmodel2, szInvisKnife);
		set_pev(iOwner, pev_weaponmodel2, "");
	}

    return HAM_IGNORED
}
*/