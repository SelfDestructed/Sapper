#include "Cell.h"
#include "stdafx.h"
#include "Map.h"
const QSize Cell::def_cellSize = { 20, 20 };

Cell::Cell(QPoint mapPos, Map *map, QWidget *parent, QSize size) :
	QPushButton(parent),
	_opened(false),
	_hasBomb(false),
	_mapPos(mapPos), 
	_map(map) {

	_pos.setX(mapPos.x() * size.height() + map->pos().x());
	_pos.setY(mapPos.y() * size.width() + map->pos().y());
	move(_pos);

	_label.move(_pos);
	_label.setFixedSize(size);
	_label.setHidden(true);
	_label.setAlignment(Qt::AlignCenter);
	setFixedSize(size);
	showNormal();
	//_button = new QToolButton();
	//_button->setIconSize(size);
	//_button->move(_pos);
	//_button->setFixedSize(size);
	//_button->setFrameRect({_pos, size});
	//_button->setLineWidth(2);
	//_button->showNormal();
	// map->mainLayout->addWidget(_button);
	// QObject::connect(_button, &QWidget::event, this, &Cell::open);
}

bool Cell::hasBomb() const {
	return _hasBomb;
}

int Cell::getBombsAround() const {
	auto bombs = 0;
	// top row
	if (_mapPos.y() != 0) {
		if (_mapPos.x() != 0) {
			if ((*_map)[_mapPos.x() - 1][_mapPos.y() - 1]->hasBomb()) {
				bombs++;
			}
		}

		if ((*_map)[_mapPos.x()][_mapPos.y() - 1]->hasBomb()) {
			bombs++;
		}

		if (_mapPos.x() + 1 != _map->raw().size()) {
			if ((*_map)[_mapPos.x() + 1][_mapPos.y() - 1]->hasBomb()) {
				bombs++;
			}
		}
	}

	// middle
	if (_mapPos.x() != 0) {
		if ((*_map)[_mapPos.x() - 1][_mapPos.y()]->hasBomb()) {
			bombs++;
		}
	}
	if (_mapPos.x() + 1 != _map->raw().size()) {
		if ((*_map)[_mapPos.x() + 1][_mapPos.y()]->hasBomb()) {
			bombs++;
		}
	}

	// bottom row
	if (_mapPos.y() + 1 != (*_map)[0].size()) {
		if (_mapPos.x() != 0) {
			if ((*_map)[_mapPos.x() - 1][_mapPos.y() + 1]->hasBomb()) {
				bombs++;
			}
		}
		if ((*_map)[_mapPos.x()][_mapPos.y() + 1]->hasBomb()) {
			bombs++;
		}
		if (_mapPos.x() + 1 != _map->raw().size()) {
			if ((*_map)[_mapPos.x() + 1][_mapPos.y() + 1]->hasBomb()) {
				bombs++;
			}
		}
	}
	return bombs;
}

void Cell::setBomb() {
	_label.setText("#");	// TODO rmv dbg
	_hasBomb = true;
}

void Cell::mouseReleaseEvent(QMouseEvent* event) {
	if(_opened) {
		return;
	} 
	_opened = true;
	_label.setHidden(false);
	close();
	if (_hasBomb) {
		MessageBoxA(nullptr, "Game over!", "BOOM!", MB_OK);
		main_window->stopClicked();
	}
	else {
		auto bombs = getBombsAround();
		if (bombs) {
			_label.setText(std::to_string(getBombsAround()).c_str());
		}
		else {
			if (_mapPos.y() != 0) {
				if (_mapPos.x() != 0) {
					(*_map)[_mapPos.x() - 1][_mapPos.y() - 1]->mouseReleaseEvent(event);
				}
				(*_map)[_mapPos.x()][_mapPos.y() - 1]->mouseReleaseEvent(event);

				if (_mapPos.x() + 1 != _map->raw().size()) {
					(*_map)[_mapPos.x() + 1][_mapPos.y() - 1]->mouseReleaseEvent(event);
				}
			}

			// middle
			if (_mapPos.x() != 0) {
				(*_map)[_mapPos.x() - 1][_mapPos.y()]->mouseReleaseEvent(event);
			}
			if (_mapPos.x() + 1 != _map->raw().size()) {
				(*_map)[_mapPos.x() + 1][_mapPos.y()]->mouseReleaseEvent(event);
			}

			// bottom row
			if (_mapPos.y() + 1 != _map->raw().front().size()) {
				if (_mapPos.x() != 0) {
					(*_map)[_mapPos.x() - 1][_mapPos.y() + 1]->mouseReleaseEvent(event);
				}
				(*_map)[_mapPos.x()][_mapPos.y() + 1]->mouseReleaseEvent(event);
				if (_mapPos.x() + 1 != _map->raw().size()) {
					(*_map)[_mapPos.x() + 1][_mapPos.y() + 1]->mouseReleaseEvent(event);
				}
			}
		}
		_map->succesMove();
	}
}