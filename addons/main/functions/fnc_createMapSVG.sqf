#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: SVG_Export_main_fnc_createMapSVG
Description:
  #NOTE - https://community.bistudio.com/wiki/diag_exportTerrainSVG?useskin=darkvector
  Exports the current map data to an SVG file using the ArmaSVGExport extension.

Parameters:
    - _fileName <string> : The name of the SVG file to be created (without extension) 
    - _exportFlags <ARRAY<BOOL>> : 
        An array of boolean values indicating which elements to include in the export: 
        - [0] : drawLocationNames
        - [1] : drawGrid
        - [2] : drawCountlines
        - [3] : drawTreeObjects
        - [4] : drawMountainHeightpoints
        - [5] : simpleRoads

Returns:
    String of SVG directory <STRING>

Examples
    (begin example)
        ["FileName",[true,false,true,false,true,true]] call SVG_Export_main_fnc_createMapSVG
    (end)

Author:
    Aaren
---------------------------------------------------------------------------- */

params [
  ["_fileName", ""],
  ["_exportFlags", [true,true,true,true,true,true]]
];
TRACE_1("fnc_createMapSVG",_this);

if (_fileName == "") exitWith {
  ERROR("value ""_fileName"" cannot be empty.");
  ""
};

private _result = "ArmaSVGExport" callExtension [_fileName + ".svg", _exportFlags];
_result params ["_outputPath"];

INFO_1("ArmaSVGExport successful = ""%1""",_outputPath);

_outputPath
