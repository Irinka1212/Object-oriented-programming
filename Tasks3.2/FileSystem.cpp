#include "FileSystem.h"

FileSystem::FileSystem() : root("root")
{}

FileSystem::FileSystem(const std::string& rootFolderName) : root(rootFolderName)
{}

void FileSystem::addFile(const std::string& destinationFolderName, const File& file)
{
    Folder* destination = root.findFolder(destinationFolderName);
    if (destination)
        destination->addFile(file);
}

void FileSystem::addFiles(const std::string& destionationFolderName,
                          const std::vector<File>& files)
{
    Folder* destination = root.findFolder(destionationFolderName);
    if (destination)
        destination->addFiles(files);
}

void FileSystem::addFolder(const std::string& destionationFolderName, const Folder& folder)
{
    Folder* destination = root.findFolder(destionationFolderName);
    if (destination)
        destination->addFolder(folder);
}

void FileSystem::addFolders(const std::string& destionationFolderName,
                            const std::vector<Folder>& folders)
{
    Folder* destination = root.findFolder(destionationFolderName);
    if (destination)
        destination->addFolders(folders);
}

const File* FileSystem::findFile(const std::string& name) const
{
    return root.findFile(name);
}

const Folder* FileSystem::findFolder(const std::string& name) const
{
    return root.findFolder(name);
}
