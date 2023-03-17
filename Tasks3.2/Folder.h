#pragma once

#include "File.h"
#include "Date.h"
#include "ContentStorage.h"

class Folder: public Content
{
    ContentStorage filesAndFolders;
        
public:
    Folder(const std::string& name) : Content(name)
    {}
    
    Folder* findFolder(const std::string& name) const
    {
        return dynamic_cast<Folder *>(filesAndFolders.get(name));
    }
    
    File* findFile(const std::string& name) const
    {
        return dynamic_cast<File *>(filesAndFolders.get(name));
    }
    
    void addFile(const File& file)
    {
        filesAndFolders.add(file);
    }
    
    void addFiles(const std::vector<File>& files)
    {
        for (size_t i = 0; i < files.size(); ++i)
            filesAndFolders.add(files[i]);
    }
    
    void addFolder(const Folder& folder)
    {
        filesAndFolders.add(folder);
    }
    
    void addFolders(const std::vector<Folder>& folders)
    {
        for (size_t i = 0; i < folders.size(); ++i)
            filesAndFolders.add(folders[i]);
    }
};
