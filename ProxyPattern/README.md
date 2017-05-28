# Introduction

*   假定现已有一个写好的文件管理器，需求如下：对这个管理器中的一部分函数进行一些权限限制，以防在一些场景下创建的实例误用某些函数。

---

# Class

## FileManager

##### Abstract

*   文件管理器，在现成的类库中，作为模式中被代理的类。

##### Interface

*   NewFile

    *   ```c++
        void FileManager::NewFile(const char *filePathName)
        {
        	std::cout << "FileManager::New File @" << filePathName << std::endl;
        }
        ```
    * 在所给路径新建一个文件。


- DeleteFile

    -   ```c++
        void FileManager::DeleteFile(const char *filePathName)
        {
        	std::cout << "FileManager::Delete File @" << filePathName << std::endl;
        }
        ```

    - 删除所给路径的文件（如果存在的话）。


# FileManagerController

##### Abstract

-   对 FileManager 进行的代理。

##### Interface

-   Constructor

    -   ```c++
        FileManagerController(bool isAdmin = false) : isAdmin(isAdmin), fileManager(new FileManager)
        	{}
        ```

    - 构造函数，传入参数 isAdmin 表明是否具有所有权限。


-   Destructor

    -   ```c++
        virtual ~FileManagerController()
        	{
        		delete fileManager;
        	}
        ```

- NewFile

    -   ```c++
        void NewFile(const char *filePathName)
        {
          fileManager->NewFile(filePathName);
        }
        ```

    - NewFile 没有权限限制，直接调用

- DeleteFile

    - ```c++
        void DeleteFile(const char *filePathName)
        {
          if (isAdmin)
            fileManager->DeleteFile(filePathName);
          else
            std::cout << "Error: Delete file " << filePathName << " failed, Administrator privileges REQUIRED"<< std::endl;
        }
        ```

    - 仅当创建的这个文件管理器具有 “管理员权限”，即 isAdmin = true 时，才会调用 FileManager::DeleteFile()，否则会输出权限不足。

---

# Example

*   Test

    ```c++
    FileManagerController *manager = new FileManagerController(false);
    manager->NewFile("desktop/123.cpp");
    manager->DeleteFile("desktop/123.cpp");
    delete manager;
    ```
* Output

    >   FileManager Constructor
    >   FileManager::New File @desktop/123.cpp
    >   Error: Delete file desktop/123.cpp failed, Administrator privileges REQUIRED
    >   FileManager Destructor
    >
    >   Process finished with exit code 0