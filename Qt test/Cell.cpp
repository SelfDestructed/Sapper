#include "Cell.h"
#include "stdafx.h"
#include "Map.h"
const QSize Cell::def_cellSize = { 20, 20 };

Cell::Cell(QPoint mapPos, Map *map, QSize size) :
	_hasBomb(false),
	_mapPos(mapPos),
	_map(map) {
	_pos.setX(mapPos.x() * size.height());
	_pos.setY(mapPos.y() * size.width());

	_button = new QPushButton(window);
	_button->setFixedSize(size);
	_button->move(_pos);
	_button->showNormal();
}

bool Cell::hasBomb() const {
	return _hasBomb;
}

int Cell::getBombsAround() const {
	auto bombs = 0;
	// top row
	if ((*_map)[_mapPos.x() - 1][_mapPos.y() - 1]->hasBomb()) {
		bombs++;
	}
	if ((*_map)[_mapPos.x()    ][_mapPos.y() - 1]->hasBomb()) {
		bombs++;
	}
	if ((*_map)[_mapPos.x() + 1][_mapPos.y() - 1]->hasBomb()) {
		bombs++;
	}

	// middle
	if ((*_map)[_mapPos.x() - 1][_mapPos.y()]->hasBomb()) {
		bombs++;
	}
	if ((*_map)[_mapPos.x() + 1][_mapPos.y()]->hasBomb()) {
		bombs++;
	}

	// bottom row
	if ((*_map)[_mapPos.x() - 1][_mapPos.y() + 1]->hasBomb()) {
		bombs++;
	}
	if ((*_map)[_mapPos.x()    ][_mapPos.y() + 1]->hasBomb()) {
		bombs++;
	}
	if ((*_map)[_mapPos.x() + 1][_mapPos.y() + 1]->hasBomb()) {
		bombs++;
	}
	return bombs;
}

void Cell::setBomb() {
	_hasBomb = true;
}
