class ctrlMenuStrip;
class display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
      class Items
      {

        class File
        {
          items[] += {"Export_Map_SVG"};
        };

        class Export_Map_SVG
        {
          action = "[worldName] call SVG_Export_main_fnc_3denExport;";
          picture = "\a3\modules_f\data\portraitstrategicmapimage_ca.paa";
          text = CSTRING(Title);
          opensNewWindow = 0;
        };
      };
    };
  };
};
