#include "stdafx.h"
#include "Map.h"

const QSize Map::def_mapSize = { 10, 10 };

Map::Map(QPoint pos, QSize size): _pos(pos) {
	_map.assign(size.height(), std::vector<Cell *>());
	for (auto i = 0; i < size.height(); i++) {
		_map[i].reserve(size.width());
		for (auto j = 0; j < size.width(); j++) {
			_map[i].push_back(new Cell({ i, j }, this));
		}
	}	
}

Map::~Map() {
	for (auto rows : _map) {
		for (auto cell : rows) {
			delete cell;
		}
	}
}

std::vector<Cell*> &Map::operator[](int idx) {
	return _map[idx];
}
