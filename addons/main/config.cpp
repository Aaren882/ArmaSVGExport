#include "script_component.hpp"

class CfgPatches
{
	class ADDON
	{
		authors[] = {"Aaren"};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"A3_3DEN"};
		units[] = {};
		weapons[] = {};
		VERSION_CONFIG;
	};
};

class Extended_PreInit_EventHandlers 
{
	class ADDON
	{
		init = QUOTE(call COMPILE_FILE(XEH_PreInit));
	};
};

#include "UI/3den.hpp"
