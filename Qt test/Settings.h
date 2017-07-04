#pragma once
class Settings {

public:
	static const QSize def_mapSize;
	static const QPoint def_mapPos;
	static const int def_nBombs;

	static const Settings novice;
	static const Settings experienced;
	static const Settings expert;

	explicit Settings(QSize mapSize = def_mapSize, int bombs = def_nBombs);

	int		bombs;
	QSize	fieldSize;

};

