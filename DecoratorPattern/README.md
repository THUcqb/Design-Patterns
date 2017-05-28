# Introduction

-   假定现已有一个写好的照片展示窗口，需求是能对照片窗口的出现加上 3、2、1 倒数，再显示出来的特效。

---

# Class

## Widget

##### Abstract

-   窗口、部件等的接口类。

##### Interface

-   Show

    *   ```c++
        virtual void Show() = 0;
        ```
## PhotoWindow

##### Abstract

-   显示一张照片的窗口。基类为 Widget

##### Interface

-   Constructor

    -   ```c++
        PhotoWindow::PhotoWindow()
        {
        	std::cout << "PhotoWindow::PhotoWindow" << std::endl;
        }
        ```



-   Destructor

    -   ```c++
        PhotoWindow::~PhotoWindow()
        {
        	std::cout << "PhotoWindow::~PhotoWindow" << std::endl;
        }
        ```

- Show

    -   ```c++
        void PhotoWindow::Show()
        {
        	std::cout << "PhotoWindow::Show" << std::endl;
        }
        ```

    - 新建窗口展示一张照片。


## CountDownEffect

##### Abstract

*   倒数特效类，装饰一个 Widget，数三下特效后再予以显示。

##### Interface

-   Constructor

    -   ```c++
        CountDownEffect(Widget *widget) : widget(widget)
        {
        	std::cout << "CountDownEffects: Set Object PhotoWindow" << std::endl;
        }
        ```


-   Destructor

    -   ```c++
        virtual ~CountDownEffect()
        {
        	std::cout << "CountDownEffects::~CountDownEffects" << std::endl;
        }
        ```

- Show

    -   ```c++
        void Show()
        {
            std::cout << "CountDownEffects::Show" << std::endl;
            std::cout << "\tShowing Counting Down Effect" << std::endl;
            std::cout << "\t3" << std::endl;
            std::cout << "\t2" << std::endl;
            std::cout << "\t1" << std::endl;
            std::cout << "\tCome out!" << std::endl;
            widget->Show();
        }
        ```

    - 显示倒数特效，特效后显示窗口的功能。

---

# Example

*   Test

    ```c++
    Widget *photoWindow = new PhotoWindow;
    CountDownEffect *effects = new CountDownEffect(photoWindow);

    effects->Show();

    delete photoWindow;
    delete effects;
    ```


- Output

  >   PhotoWindow::PhotoWindow
  >   CountDownEffects: Set Object PhotoWindow
  >   CountDownEffects::Show
  >
  >   	Showing Counting Down Effect
  >   	3
  >   	2
  >   	1
  >   	Come out!
  >   PhotoWindow::Show
  >   PhotoWindow::~PhotoWindow
  >   CountDownEffects::~CountDownEffects