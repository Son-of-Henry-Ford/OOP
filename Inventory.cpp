#include "Inventory.h"
#include "item.h"



Inventory::Inventory(int capacity, int currentSize) : capacity(capacity), currentSize(currentSize) {}


bool Inventory::addItemToInventory(Item* item) {
	if (currentSize == capacity || item == nullptr) {
		return 0;
	}
	for (auto& c : items) {
		if (c.first->getName() == item->getName()) {
			++c.second;
			++currentSize;
			return 1;
		}
	}
	Item* newItem = item->getCopy();
	items[newItem] = 1;
	return 1;
}

bool Inventory::useItem(const std::string& item, Player& player) {
	for (auto c : items) {
		if (c.first->getName() == item) {
			if (c.second == 0) {
				return 0;
			}
			--c.second;
			--currentSize;
			return 1;
		}
	}
	return 0;
}

int Inventory::getCurrentSize() {
	return currentSize;
}
int Inventory::getCapacity() {
	return capacity;
}

Inventory::~Inventory() {
	for (auto& c : items) {
		delete c.first;
	}
}