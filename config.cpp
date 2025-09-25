class CfgPatches
{
	class MainMenu
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1; 		
			requiredAddons[]={"DZ_Data", "DZ_Gear_Consumables", "DZ_Vehicles_Wheeled", "DZ_Structures_Residential", "DZ_Sounds_Effects", "DZ_Sounds_Weapons"};
	};
};
class CfgMods
{
	class MainMenu
	{
	    dir = "Nightro_MainMenu";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Nightro_MainMenu";
		logoSmall = "";
		logo = "";
		logoOver = "Nightro_MainMenu";
		tooltip = "Nightro_MainMenu";
		overview = "Nightro_MainMenu";
	    credits = "STRNK";
	    author = "STRNK";
	    authorID = ;
	    version = "1.0";
	    extra = 0;
		
	    type = "mod";
		dependencies[]={"Mission","Game"}; 

	    class defs
	    {	
	    	class gameScriptModule
			{
				value="";
				files[]=
				{
					"Nightro_MainMenu/scripts/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]={"Nightro_MainMenu/scripts/5_Mission"};
			};			
        };
    };
};
