//
// Created by Qibin Chen on 28/05/2017.
//

#include "filemanager.h"
#include <iostream>

FileManager::FileManager()
{
	std::cout << "FileManager Constructor" << std::endl;
}

FileManager::~FileManager()
{
	std::cout << "FileManager Destructor" << std::endl;
}

void FileManager::NewFile(const char *filePathName)
{
	std::cout << "FileManager::New File @" << filePathName << std::endl;
}

void FileManager::DeleteFile(const char *filePathName)
{
	std::cout << "FileManager::Delete File @" << filePathName << std::endl;
}
