#ifndef INVENTORY
#define INVENTORY
#include <map>
#include <string>
#include "config.h"


class Player;
class Item;

class Inventory
{
public:
	Inventory(int capacity = INVENTORY_CAPACITY, int currentSize = 0);
	bool addItemToInventory(Item* item); ///��������� ������ ������!!!!!!!!!!!!"����������� �������� ����������� �����, ���� �������� �������� � ��� ������� ������� ������ ���� �������!!!" - ������������� �� ��������!!! ������� ������� ���-��
	bool useItem(const std::string& item, Player& player);
	int getCurrentSize();
	int getCapacity();
	~Inventory();
private:
	std::map<Item*, int> items;
	int capacity;
	int currentSize;
};

#endif