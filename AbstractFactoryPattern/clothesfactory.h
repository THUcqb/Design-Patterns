//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_CLOTHESFACTORY_H
#define DESIGNPATTERNS_CLOTHESFACTORY_H

#include "clothes.h"

class ClothesFactory
{
public:
	virtual ~ClothesFactory();

	virtual Shirt *CreateShirt(int size) = 0;

	virtual Pants *CreatePants(int size) = 0;
};

class MyClothesFactory : public ClothesFactory
{
public:
	Shirt *CreateShirt(int size) override ;

	Pants *CreatePants(int size) override ;
};

class YourClothesFactory : public ClothesFactory
{
public:
	Shirt *CreateShirt(int size) override ;

	Pants *CreatePants(int size) override ;
};

#endif //DESIGNPATTERNS_CLOTHESFACTORY_H
