//
// Created by Qibin Chen on 31/05/2017.
//

#include "clothesfactory.h"

int main()
{
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
}
