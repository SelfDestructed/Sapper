#pragma once
#include "stdafx.h"
#include "MainWindow.h"

class Map;

extern MainWindow *main_window;

class Cell : public QPushButton {	Q_OBJECT
	
public:
	static const QSize def_cellSize;

	Cell(QPoint mapPos, Map *map, QWidget *parent = nullptr, QSize size = { def_cellSize });

	bool hasBomb() const;

	int getBombsAround() const;

	void setBomb();

	void mouseReleaseEvent(QMouseEvent *event) override;

private:
	bool		_opened;
	bool		_hasBomb;
	QPoint		_pos;
	QPoint		_mapPos;
	Map			*_map;
	QLabel		_label{ main_window };
	// QToolButton	*_button;
};
