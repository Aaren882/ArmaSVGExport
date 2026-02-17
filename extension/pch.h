// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <string>
#include <filesystem>

/// <summary>
/// Retrieves the address of a host procedure by name from the Arma host.
/// </summary>
/// <param name="name">The name of the procedure or symbol to look up.</param>
/// <returns>A pointer to the requested procedure (void*). Returns nullptr if the procedure is not found.</returns>
void* GetArmaHostProcAddress(std::string name);

/// <summary>
/// Retrieves the filesystem path of the current Arma application/installation.
/// </summary>
/// <returns>A std::filesystem::path representing the current Arma application or installation path.</returns>
std::filesystem::path GetCurrentArmaPath();

/// <summary>
/// Generates an SVG image of the terrain and saves it to the specified file.
/// </summary>
/// <param name="fileName">The output SVG file name.</param>
/// <param name="drawLocationNames">If true, render location names on the map.</param>
/// <param name="drawGrid">If true, overlay a grid on the terrain.</param>
/// <param name="drawCountlines">If true, draw contour/count lines representing elevation.</param>
/// <param name="drawTreeObjects">If true, include tree objects in the rendering.</param>
/// <param name="drawMountainHeightpoints">If true, mark mountain height points on the map.</param>
/// <param name="simpleRoads">If true, render roads using a simplified representation.</param>
/// <returns>A std::filesystem::path to the generated SVG file.</returns>
std::filesystem::path ExportTerrainSvg(
    const char* fileName,
    bool drawLocationNames,
    bool drawGrid,
    bool drawCountlines,
    bool drawTreeObjects,
    bool drawMountainHeightpoints,
    bool simpleRoads);

#endif //PCH_H
