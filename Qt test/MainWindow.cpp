#include "stdafx.h"
#include "MainWindow.h"
#include "Map.h"

MainWindow *main_window;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	_ui.setupUi(this);
	::main_window = this;

	_ui.spinRows->setMinimum(4);
	_ui.spinRows->setMaximum(50);

	_ui.spinCols->setMinimum(4);
	_ui.spinCols->setMaximum(50);

	_ui.spinBombs->setMinimum(1);

	_ui.radioCustom->setChecked(true);

	_ui.buttonStop->setDisabled(true);

	setMinimumSize(200, 250);
	resize(200, 250);

	connect(_ui.buttonStart, &QPushButton::clicked, this, &MainWindow::startClicked);
	connect(_ui.buttonStop, &QPushButton::clicked, this, &MainWindow::stopClicked);

	connect(_ui.radioNovice, &QRadioButton::clicked, this, &MainWindow::noviceHandler);
	connect(_ui.radioExperienced, &QRadioButton::clicked, this, &MainWindow::experiencedHandler);
	connect(_ui.radioExpert, &QRadioButton::clicked, this, &MainWindow::expertHandler);
	connect(_ui.radioCustom, &QRadioButton::clicked, this, &MainWindow::customHandler);
}

Settings MainWindow::getSettingsFromUi() const {
	return Settings{ {_ui.spinRows->text().toInt(), _ui.spinCols->text().toInt() }, _ui.spinBombs->text().toInt() };
}

void MainWindow::startClicked() {
	_map = new Map(getSettingsFromUi());
	_ui.buttonStop->setDisabled(false);
	_ui.buttonStart->setDisabled(true);

	_ui.spinCols->setDisabled(true);
	_ui.spinRows->setDisabled(true);
	_ui.spinBombs->setDisabled(true);
}

void MainWindow::stopClicked() {
	delete _map;
	_ui.buttonStop->setDisabled(true);
	_ui.buttonStart->setDisabled(false);
	if (_ui.radioCustom->isChecked()) {
		_ui.spinCols->setDisabled(false);
		_ui.spinRows->setDisabled(false);
		_ui.spinBombs->setDisabled(false);
	}
	resize(200, 250);
}

void MainWindow::noviceHandler() {
	_ui.spinCols->setValue(Settings::novice.fieldSize.height());
	_ui.spinRows->setValue(Settings::novice.fieldSize.width());
	_ui.spinBombs->setValue(Settings::novice.bombs);

	_ui.spinCols->setDisabled(true);
	_ui.spinRows->setDisabled(true);
	_ui.spinBombs->setDisabled(true);
}

void MainWindow::experiencedHandler() {
	_ui.spinCols->setValue(Settings::experienced.fieldSize.height());
	_ui.spinRows->setValue(Settings::experienced.fieldSize.width());
	_ui.spinBombs->setValue(Settings::experienced.bombs);

	_ui.spinCols->setDisabled(true);
	_ui.spinRows->setDisabled(true);
	_ui.spinBombs->setDisabled(true);

}

void MainWindow::expertHandler() {
	_ui.spinCols->setValue(Settings::expert.fieldSize.height());
	_ui.spinRows->setValue(Settings::expert.fieldSize.width());
	_ui.spinBombs->setValue(Settings::expert.bombs);

	_ui.spinCols->setDisabled(true);
	_ui.spinRows->setDisabled(true);
	_ui.spinBombs->setDisabled(true);
}

void MainWindow::customHandler() {
	_ui.spinCols->setValue(Settings::novice.fieldSize.height());
	_ui.spinRows->setValue(Settings::novice.fieldSize.width());
	_ui.spinBombs->setValue(Settings::novice.bombs);

	_ui.spinCols->setDisabled(false);
	_ui.spinRows->setDisabled(false);
	_ui.spinBombs->setDisabled(false);
}