//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_SHIRT_H
#define DESIGNPATTERNS_SHIRT_H

class Shirt
{
public:
	virtual ~Shirt();

	virtual void Show() = 0;
};

class LargeShirt : public Shirt
{
public:
	void Show() override;
};

class MediumShirt : public Shirt
{
public:
	void Show() override;
};

class SmallShirt : public Shirt
{
public:
	void Show() override;
};

class Pants
{
public:
	virtual ~Pants();

public:
	virtual void Show() = 0;
};

class LongPants : public Pants
{
public:
	void Show() override;
};

class ShortPants : public Pants
{
public:
	void Show() override;
};

#endif //DESIGNPATTERNS_SHIRT_H
