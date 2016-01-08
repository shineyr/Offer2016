/*
* 面试题8.3.7 有家动物收容所只收猫和狗，且严格遵守“先进先出的原则”。
* 在收养该收容所的动物时，只能选择最老的（根据进入时间长短）；或者，
* 可以挑选猫或狗（最老的）。
* 设计数据结构，实现各种操作方法，比如enqueue，dequeueAny，dequeueDog
* dequeueCat等。
*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <string>

using namespace std;

class Animal{
public:
	Animal(string name) :name(name){}

	void setOrder(int ord)
	{
		this->order = ord;
	}

	int getOrder()
	{
		return this->order;
	}

	bool isOlderThan(Animal a)
	{
		return this->order < a.getOrder();
	}
private:
	int order;
	string name;
};

class Dog : Animal{
public:
	Dog(string n) :Animal(n){}
};

class Cat :Animal{
public:
	Cat(string n) :Animal(n){}
};

class AnimalQueue{
public:
	queue<Dog> dogs;
	queue<Cat> cats;

	void enqueue(Animal a)
	{
		a.setOrder(order);
		++order;

		if (a instanceof Dog)
			dogs.push((Dog)a);
		else if (a instanceof Cat)
			cats.push((Cat)a);
	}

	Animal dequeueAny()
	{
		if (dogs.empty())
			return dequeueCats();
		else if (cats.empty())
			return dequeueDogs();

		Dog dog = dogs.front();
		Cat cat = cats.front();
		if (dog.isOlderThan(cat))
			return dequeueDogs();
		else
			return dequeueCats();
	}

	Dog dequeueDogs()
	{
		Dog dog = dogs.front();
		dogs.pop();
		return dog;
	}

	Cat dequeueCats()
	{
		Cat cat = cats.front();
		cats.pop();
		return cat;
	}

private:
	int order = 0;
};