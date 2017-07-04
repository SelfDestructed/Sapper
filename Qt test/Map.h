#pragma once
#include "Cell.h"
#include "Settings.h"

class Map {

public:
	explicit Map(Settings &settings, QPoint pos = { Settings::def_mapPos });

	~Map();

	QPoint pos() const;

	std::vector<Cell *> &operator[](int idx);

	void setBombs(int cnt);

	std::vector<std::vector<Cell *>> &raw();

	void succesMove() {
		if(--_closed == _bombs) {
			MessageBoxA(nullptr, "Success!", "You won!", MB_OK);
			main_window->stopClicked();
		}
	}

private:
	int								 _closed;
	int								 _bombs;
	QPoint							 _pos;
	std::vector<std::vector<Cell *>> _map;
};
