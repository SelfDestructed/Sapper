#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "Settings.h"

class Cell;
class Map;

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);

	Settings getSettingsFromUi() const;

public slots:

	void startClicked();
	void stopClicked();

	void noviceHandler();
	void experiencedHandler();
	void expertHandler();
	void customHandler();

private:
	Map						*_map;
	Ui::MainWindowClass		_ui;
};
