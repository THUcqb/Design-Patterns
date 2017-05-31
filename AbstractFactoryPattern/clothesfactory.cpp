//
// Created by Qibin Chen on 31/05/2017.
//

#include "clothesfactory.h"
#include <iostream>

ClothesFactory::~ClothesFactory()
{

}

Shirt *MyClothesFactory::CreateShirt(int size)
{
	std::cout << "MyClothesFactory::CreateShirt" << std::endl;
	if (size > 10)
		return new LargeShirt;
	else
		return new SmallShirt;
}

Pants *MyClothesFactory::CreatePants(int size)
{
	std::cout << "MyClothesFactory::CreatePants" << std::endl;
	if (size > 10)
		return new LongPants;
	else
		return new ShortPants;
}

Shirt *YourClothesFactory::CreateShirt(int size)
{
	std::cout << "YourClothesFactory::CreateShirt" << std::endl;
	if (size > 20)
		return new LargeShirt;
	if (size > 10)
		return new MediumShirt;
	else
		return new SmallShirt;
}

Pants *YourClothesFactory::CreatePants(int size)
{
	std::cout << "YourClothesFactory::CreatePants" << std::endl;
	if (size > 10)
		return new LongPants;
	else
		return new ShortPants;
}

