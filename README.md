## About ArmaSVGExport

**ArmaSVGExport** is a simple tool allows you to generate map SVG without diagnostic mode enabled.

### Check [diag_exportTerrainSVG](https://community.bistudio.com/wiki/diag_exportTerrainSVG) for more details.

## Quick Example
  * ### In Editor
    <img width="496" height="499" alt="image" src="https://github.com/user-attachments/assets/6b198ed5-00fb-4b76-956b-30ab9c581c24" />
    <img width="437" height="290" alt="image" src="https://github.com/user-attachments/assets/a23ff4f1-f309-4f4e-bd22-685614a39c51" />
    <img width="482" height="350" alt="image" src="https://github.com/user-attachments/assets/0f0e8464-0365-4875-b1c0-3cd79e0e40a6" />
    
  * ### Script
    1. Open a world in Editor.
    2. 
    ```sqf 
    private _output_Dir = [
      "myWorld",
      [
        true, // - [0] : drawLocationNames
        true, // - [1] : drawGrid
        true, // - [2] : drawCountlines
        true, // - [3] : drawTreeObjects
        true, // - [4] : drawMountainHeightpoints
        true, // - [5] : simpleRoads
      ]
    ] call SVG_Export_main_fnc_createMapSVG;

    _output_Dir //- ...My_Arma3_Directory/Maps/myWorld.svg
    ```

## Disclaimer
This mod is inspired by [TacControl](https://github.com/WolfCorps/TacControl/blob/fdafd470b10209e49cf6cabfcff21418af6a5115/src/ArmaExt/src/Modules/ModuleImageDirectory.cpp#L206-L227) (__Dedmen__ and __Dahlgren__)
