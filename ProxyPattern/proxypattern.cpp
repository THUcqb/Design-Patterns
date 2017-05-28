//
// Created by Qibin Chen on 28/05/2017.
//

#include <iostream>
#include "filemanager.h"

class FileManagerController
{
	bool isAdmin;
	FileManager *fileManager;
public:
	FileManagerController(bool isAdmin = false) : isAdmin(isAdmin), fileManager(new FileManager)
	{}

	virtual ~FileManagerController()
	{
		delete fileManager;
	}

	void NewFile(const char *filePathName)
	{
		fileManager->NewFile(filePathName);
	}

	void DeleteFile(const char *filePathName)
	{
		if (isAdmin)
			fileManager->DeleteFile(filePathName);
		else
			std::cout << "Error: Delete file " << filePathName << " failed, Administrator privileges REQUIRED"<< std::endl;
	}
};

int main()
{
	FileManagerController *manager = new FileManagerController(false);
	manager->NewFile("desktop/123.cpp");
	manager->DeleteFile("desktop/123.cpp");
	delete manager;
	return 0;
}