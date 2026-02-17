#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: SVG_Export_main_fnc_3denExport
Description:
    Exports the current terrain to an SVG file and displays a notification in the 3DEN Editor with an option to copy the file path to the clipboard.

Parameters:
    - _worldName <STRING> : The name of the world/terrain to export (defaults to current worldName).

Returns:
    <NONE>

Examples
    (begin example)
        ["MyWorld"] call SVG_Export_main_fnc_3denExport
    (end)

Author:
    Aaren
---------------------------------------------------------------------------- */

params [["_worldName", worldName]];
TRACE_1("fnc_3denExport",_this);

private _content = "";
private _result = [
  _worldName,
  [true,false,true,false,true,true]
] call SVG_Export_main_fnc_createMapSVG;

if (_result == "") then {
  _content = localize LSTRING(Fail);
} else {
  _content = format [
    "<t size='1.2'>%1</t> :<br/>%2",
    localize LSTRING(Success),
    _result
  ];
};

//- Show 3den notification
[
  _content,
  localize LSTRING(Title),
  ["Copy", compile format ["copyToClipboard ""%1""", _result]],
  nil,
  "a3\modules_f\data\portraitstrategicmapimage_ca.paa"
] call BIS_fnc_3DENShowMessage;

nil
