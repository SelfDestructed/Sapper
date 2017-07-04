#include "stdafx.h"
#include "Map.h"

Map::Map(Settings &settings, QPoint pos) : _closed(settings.fieldSize.height() * settings.fieldSize.width()), _bombs(settings.bombs), _pos(pos) {
	_map.assign(settings.fieldSize.height(), std::vector<Cell *>());
	for (auto i = 0; i < settings.fieldSize.height(); i++) {
		_map[i].reserve(settings.fieldSize.width());
		for (auto j = 0; j < settings.fieldSize.width(); j++) {
			_map[i].push_back(new Cell({ i, j }, this, main_window));
		}
	}

	main_window->resize({ pos.x() + settings.fieldSize.height() * Cell::def_cellSize.width() + 100,
						  pos.y() + settings.fieldSize.width() * Cell::def_cellSize.height() + 30 });
	setBombs(_bombs);
}

Map::~Map() {
	for (auto rows : _map) {
		for (auto cell : rows) {
			delete cell;
		}
	}
}

QPoint Map::pos() const {
	return _pos;
}

std::vector<Cell*> &Map::operator[](int idx) {
	if (idx < 0 || idx > _map.size()) throw std::exception("out of bounds");
	return _map[idx];
}

void Map::setBombs(int cnt) {
	for (auto i = 0; i < cnt; i++) {
		_map[rand() % _map.size()][rand() % _map.front().size()]->setBomb();
	}
}

std::vector<std::vector<Cell*>> &Map::raw() {
	return _map;
}
