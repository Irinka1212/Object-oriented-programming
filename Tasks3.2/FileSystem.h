#pragma once

#include "Folder.h"

class FileSystem
{
public:
    FileSystem();
    FileSystem(const std::string& rootFolderName);
    
    void addFile(const std::string& destinationFolderName, const File& file);
    void addFiles(const std::string& destionationFolderName, const std::vector<File>& files);
    
    void addFolder(const std::string& destionationFolderName, const Folder& folder);
    void addFolders(const std::string& destionationFolderName, const std::vector<Folder>& folders);
    
    const File* findFile(const std::string& name) const;
    const Folder* findFolder(const std::string& name) const;
    
private:
    Folder root;
};
