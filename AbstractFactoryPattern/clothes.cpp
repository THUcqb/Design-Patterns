//
// Created by Qibin Chen on 31/05/2017.
//

#include "clothes.h"
#include <iostream>

void LargeShirt::Show()
{
	std::cout << "This is a LARGE Shirt" << std::endl;
}


void MediumShirt::Show()
{
	std::cout << "This is a MEDIUM Shirt" << std::endl;
}

void SmallShirt::Show()
{
	std::cout << "This is a SMALL Shirt" << std::endl;
}

void LongPants::Show()
{
	std::cout << "This is a pair of LONG Pants" << std::endl;
}

void ShortPants::Show()
{
	std::cout << "This is a pair of SHORT Pants" << std::endl;
}

Shirt::~Shirt()
{

}

Pants::~Pants()
{

}
