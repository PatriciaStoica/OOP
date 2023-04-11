#pragma once

#include "DynamicArray.h"
#include "Tutorial.h"

class Repository {
	DynamicArray<Tutorial> repo;

public:
	Repository();
	void add(Tutorial tutorial);
	void remove(Tutorial tutorial);
	Tutorial findTutorial(int index);
	void update(string Title, int newNumberLikes);
	int size();
	DynamicArray<Tutorial> getAll();
};