#pragma once
#include "Cell.h"

class Map {

public:
	static const QSize def_mapSize;

	explicit Map(QPoint pos = { 100, 100 }, QSize size = { def_mapSize });

	~Map();

	std::vector<Cell *> &operator[](int idx);

private:
	QGridLayout			_grid;
	QPoint				_pos;
	std::vector<std::vector<Cell *>> _map;
};
