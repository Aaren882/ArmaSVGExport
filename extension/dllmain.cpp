// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <cstring>
#include <string>

#pragma warning(disable : 4996)

extern "C"
{
    __declspec(dllexport) int __stdcall RVExtensionArgs(char* output, unsigned int outputSize, const char* function, const char** argv, unsigned int argc);
	__declspec(dllexport) void __stdcall RVExtensionVersion(char* output, unsigned int outputSize);
}


void __stdcall RVExtensionVersion(char* output, unsigned int outputSize)
{
    std::strncpy(output, "26.2.0", outputSize--);
}

/// <summary>
/// Parses up to six boolean arguments, calls ExportTerrainSvg with the parsed flags and the provided file name, and writes a formatted status/path string into the output buffer.
/// </summary>
/// <param name="output">Pointer to a writable char buffer that will receive a formatted C-string (the function uses sprintf to write "outputSize=%d, path=%s"). The caller must ensure the buffer is large enough.</param>
/// <param name="outputSize">Size of the output buffer in bytes. This value is included in the formatted output but is not enforced to prevent buffer overflow.</param>
/// <param name="fileName">C-string path or name passed to ExportTerrainSvg as the target file.</param>
/// <param name="argv">Array of C-strings representing arguments. Each entry is compared to "true" to produce a boolean flag. Up to six entries are read.</param>
/// <param name="argc">Number of entries in argv. The function reads argv[0]..argv[argc-1] (up to 6) into internal flags and then passes six flags to ExportTerrainSvg; if fewer than six arguments are provided, the remaining flags may be uninitialized.</param>
/// <returns>Always returns 0. Side effects: calls ExportTerrainSvg and writes a formatted string into the output buffer.</returns>
int __stdcall RVExtensionArgs(char* output, unsigned int outputSize, const char* fileName, const char** argv, unsigned int argc)
{
    bool args[6];
    for (int i = 0; i < argc; i++)
    {
        std::string s(argv[i]); //- convert into <string>
        args[i] = s == "true"; //- put bool(s) into "args"
    }
    
    auto exportPath = ExportTerrainSvg(
        fileName,
        args[0], args[1], args[2], args[3], args[4], args[5]);

    std::sprintf(output, "%s", exportPath.string().data());
    return 0;
}