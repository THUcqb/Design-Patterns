# Introduction

-   需求：商户有一写生产衣服、裤子的请求，只给出大小描述，工厂应生产正确型号的衣服、裤子。
-   思路：使用工厂方法设计模式，首先给出服装工厂的接口类；接下来实现 My服装工厂，size 作为用户的输入，根据 size 的大小决定生产 LargeShirt 还是 SmallShirt。用户需求变化时，比如对适中的 size 要求生产 MediumShirt，此时实现了 Your服装工厂，这里运用了工厂方法。同时服装工厂不仅能生产 shirt，还能生产 pants，所以整体运用了抽象工厂模式。

---

# Class

## Shirt

*   衣服的抽象类，作为 Product。

#### LargeShirt, MediumShirt, SmallShirt

*   衣服的实现类。

## Pants

-   裤子的抽象类，作为 Product。

#### LargeShirt, SmallShirt

*   裤子的实现类。

## ClothesFactory

#### Abstract

*   服装工厂的抽象类。

#### Public

*   CreateShirt

    -   ```c++
        virtual Shirt *CreateShirt(int size) = 0;
        ```

* CreatePants

    *   ```c++
        virtual Pants *CreatePants(int size) = 0;
        ```


## YourClothesFactory

#### Abstract

*   服装工厂的一个实现类

#### Public

*   CreateShirt

    *   ```c++
        Shirt *CreateShirt(int size)
        {
        //	MyClothesFactory::CreateShirt
        	if (size > 20)
        		return new LargeShirt;
        	if (size > 10)
        		return new MediumShirt;
        	else
        		return new SmallShirt;
        }
        ```

* CreatePants

    *   ```c++
        Pants *CreatePants(int size)
        {
        //	MyClothesFactory::CreatePants
        	if (size > 10)
        		return new LongPants;
        	else
        		return new ShortPants;
        }
        ```


## MyClothesFactory

#### Abstract

*   实现类似，不再赘述

---

# Example

#### Test

```c++
ClothesFactory *factory = new MyClothesFactory;

Shirt *shirt = factory->CreateShirt(12);
shirt->Show();
delete shirt;

Pants *pants = factory->CreatePants(5);
pants->Show();
delete pants;

delete factory;

factory = new YourClothesFactory;
shirt = factory->CreateShirt(12);
shirt->Show();
delete shirt;
shirt = factory->CreateShirt(22);
shirt->Show();
delete shirt;

delete factory;
```
#### Output

>   MyClothesFactory::CreateShirt
>   This is a LARGE Shirt
>   MyClothesFactory::CreatePants
>   This is a pair of SHORT Pants
>   YourClothesFactory::CreateShirt
>   This is a MEDIUM Shirt
>   YourClothesFactory::CreateShirt
>   This is a LARGE Shirt

---

# PS

*   那工厂方法的例子当然是工厂了。。
*   假设我们要生产衣服（抽象类），有不同颜色、不同大小的（实现类）。
*   思考简单工厂方法：有这样一个工厂，商户不需要知道衣服的型号（即实现类的名称），只需给出衣服的描述，工厂就能返回相应的衣服。
*   不过这样的话，工厂只有一定的型号（描述工厂的代码已经写好），很难应对商户不断变化的需求（如商户给出了新的描述，但工厂没有对应的型号）。这时候就需要建立新的工厂了，但是，他们生产的产品没有变（衣服），因此不妨定义一个抽象的工厂（接口类），每次你可以指定一个具体的工厂来生产衣服。这有点类似于建造者模式中的餐厅。而工厂方法中这些餐厅（工厂）没有直接的并列、竞争关系，可能只是历史上的先后顺序，只是因为他们生产的东西相同，才拥有共同的基类。这称为工厂方法。
*   接下来，一个工厂只生产衣服就有点不够充分利用了，能生产衣服、裤子等等的工厂（即把几个生产衣服、裤子的工厂集成到一个服装工厂），这就称为抽象工厂。
*   不是很懂这几个命名。。。