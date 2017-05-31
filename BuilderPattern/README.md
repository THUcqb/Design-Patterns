# Introduction

-   需求：根据使用者的需求构建各种场景（室内外、颜色等）。
-   思路：可使用建造者模式
    -   SceneBuilder 类提供统一的构建借口，如：CreateSky()；用户只需知道具体的建造者的名称，如：SceneBuilder2D（表示2D的场景构造），以及 Director 的指挥命令，即可使用 Director 建造一套场景。

---

# Class

## Scene

#### Abstract

*   场景类，作为 Product。

#### Public

*   AddComponent

    *   ```c++
        void AddComponent(std::string newComponent);
        ```

    * 增加一个场景中的元素，以此建造 Product。

* Show

    *   ```c++
        void Show();
        ```

    * Product 的展现方式。

## SceneBuilder

#### Abstract

-   接口类，抽象建造者。

#### Interface

*   CreateInit

    -   ```c++
        virtual void CreateInit() final { mainScene = new Scene; }
        ```

    - Builder 开始建造前的初始化。

* CreateWall, CreateSky, CreateFurniture, CreateLuminaire

    *   ```c++
        virtual void CreateWall(std::string color) = 0;
        virtual void CreateSky() = 0;
        virtual void CreateFurniture(std::string type) = 0;
        virtual void CreateLuminaire(std::string color) = 0;
        ```

    * 实现类需要提供的建造方法。

* GetScene

    * ```c++
        virtual Scene* GetScene() final { return mainScene; }
        ```

    * 返回建造的 Product。

### SceneBuilder2D

-   concrete builder，提供 2D 场景元素的建造方法。

## Director

#### Abstract

*   指挥者，提供完整成套的场景，用户无需知道建造的过程。

#### Private

*   SceneBuilder *builder
    *   用户需指定的具体建造者。

#### Public

*   Director

    *   ```c++
        Director(SceneBuilder *builder) : builder(builder);
        ```

* Construct

    *   ```c++
        Scene* Construct(std::string environment);
        ```

    * 为输入的不同命令提供成套的场景，如 "Blue Inside"，"Outside"。

---

# Example

#### Test

```c++
SceneBuilder *builder = new SceneBuilder2D;
Director director(builder);

Scene *scene = director.Construct("Blue Inside");
scene->Show();

delete scene;
delete builder;
```
#### Output

>   2D Wall, color: blue
>   2D Furniture, type:desk
>   2D Luminaire, color: white

---

# PS

*   下面这个例子很好的说明了建造者模式：
*   builder 视为抽象的餐厅，建造 Product 的场所，规定了一家餐厅应该提供烧哪些菜的方法；concretebuilder 视为具体的某一家餐厅。
*   director 视为一个服务员，手上的菜单有一些套餐任你选择。注：该服务员不属于某一家具体的餐厅，可认为是你的管家。
*   告诉服务员你需要的套餐。当然，你只需告诉他套餐的名称（儿童套餐：-），就会获得这个 Product。
*   思考以下几点：
    *   你无需知道套餐包含哪些菜（由服务员的菜单提供，他向餐厅请求其中的菜）
    *   你无需知道餐厅如何烧菜。
    *   告诉服务员你想吃哪家餐厅，而不是自己跑去一家餐厅一个个点菜。