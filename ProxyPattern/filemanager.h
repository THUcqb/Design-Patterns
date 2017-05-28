//
// Created by Qibin Chen on 28/05/2017.
//

#ifndef DESIGN_PATTERNS_FILEMANAGER_H
#define DESIGN_PATTERNS_FILEMANAGER_H

class FileManager
{
public:
	FileManager();

	virtual ~FileManager();

	void NewFile(const char *filePathName);

	void DeleteFile(const char *filePathName);
};


#endif //DESIGN_PATTERNS_FILEMANAGER_H
