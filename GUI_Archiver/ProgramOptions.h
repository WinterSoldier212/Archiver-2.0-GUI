#pragma once

#include <vector>
#include "Archiver.h"
#include "Unarchiver.h"

using namespace std;

void zip(
    vector<string>& files,
    string& outputFileDirectory,
    string& outputFileName
) {
    if (outputFileDirectory.empty())
        outputFileDirectory = getCurrentDirectory();

    string pathForNewArchive = outputFileDirectory + "\\" + outputFileName;

    Archiver archive;
    archive.Create(pathForNewArchive);
    for (const auto& file : files) 
    {
        AddFileInArchive(archive, file);
    }
}

void unzip(
    vector<string>& archives,
    string& outputFileDirectory
) {
    if (outputFileDirectory.empty())
        outputFileDirectory = getCurrentDirectory();

    filesystem::create_directories(outputFileDirectory);

    for (auto archive : archives)
    {
        Unarchiver unarchiver;
        unarchiver.Open(archive);

        ExtractAllFilesFromArchive(unarchiver, outputFileDirectory);
    }
}