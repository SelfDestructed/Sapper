#include "stdafx.h"
#include "Settings.h"

const QSize		Settings::def_mapSize = { 20, 20 };
const QPoint	Settings::def_mapPos = { 200, 36 };
const int		Settings::def_nBombs = { def_mapSize.width() * def_mapSize.height() / 10 };

const Settings Settings::novice{ {9, 9}, 10 };
const Settings Settings::experienced{ {	16, 16}, 40 };
const Settings Settings::expert{ {16, 30}, 99 };

Settings::Settings(QSize mapSize, int bombs) : bombs(bombs), fieldSize(mapSize) { }
