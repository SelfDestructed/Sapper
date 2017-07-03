#pragma once
#include "stdafx.h"
#include "MainWindow.h"

class Map;

extern MainWindow *window;

class Cell {

public:
	static const QSize def_cellSize;


	Cell(QPoint mapPos, QSize size, Map* map);

	Cell(QPoint mapPos, Map *map, QSize size = { def_cellSize });

	bool hasBomb() const;

	int getBombsAround() const;

	void setBomb();

private:
	bool		_hasBomb;
	QPoint		_pos;
	QPoint		_mapPos;
	Map			*_map;
	QPushButton *_button;
};
