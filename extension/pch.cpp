// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

#include <string>
#include <filesystem>

void* GetArmaHostProcAddress(std::string name) {
    auto data = name.data();
    return GetProcAddress(GetModuleHandleA(nullptr), data);
}

std::filesystem::path GetCurrentArmaPath() {
    char path[MAX_PATH];
    HMODULE hm = NULL;

    if (GetModuleFileName(hm, path, sizeof(path)) == 0)
    {
        int ret = GetLastError();
        fprintf(stderr, "GetModuleFileName failed, error = %d\n", ret);
        // Return or however you want to handle an error.
    }

    return std::filesystem::path(path);
}

//std::filesystem::path GetCurrentDLLPath() {
//    char path[MAX_PATH];
//    HMODULE hm = NULL;
//    
//    if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
//        GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
//        (LPCSTR)&GetCurrentDLLPath, &hm) == 0)
//    {
//        int ret = GetLastError();
//        fprintf(stderr, "GetModuleHandle failed, error = %d\n", ret);
//        // Return or however you want to handle an error.
//    }
//
//    return std::filesystem::path(path);
//}

std::filesystem::path ExportTerrainSvg(
    const char* fileName,
    bool drawLocationNames,
    bool drawGrid,
    bool drawCountlines,
    bool drawTreeObjects,
    bool drawMountainHeightpoints,
    bool simpleRoads)
{
    const std::string procName = "?ExportSVG@@YAXPEBD_N11111@Z";
    auto exportPtr = GetArmaHostProcAddress(procName);

    // The function itself
    auto exportFunc = static_cast<void(*)(
        const char* name,
        bool drawLocationNames,
        bool drawGrid,
        bool drawCountlines,
        bool drawTreeObjects,
        bool drawMountainHeightpoints,
        bool simpleRoads
        )>(exportPtr);

    if (!exportFunc) {
        throw "ExportSVG function is not found on Arma ProcAddress.";
    }

    auto myDirectory = GetCurrentArmaPath().parent_path();
    if (!std::filesystem::exists(myDirectory / "Maps"))
        std::filesystem::create_directory(myDirectory / "Maps");
    
    auto svgPath = myDirectory / "Maps" / fileName;
    auto path = svgPath.string();

    // 4. Call the function directly
    exportFunc(
        path.data(),
        drawLocationNames,
        drawGrid,
        drawCountlines,
        drawTreeObjects,
        drawMountainHeightpoints,
        simpleRoads
    );

    return svgPath;
}

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
