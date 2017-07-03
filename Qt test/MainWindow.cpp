#include "stdafx.h"
#include "MainWindow.h"
#include "Map.h"
MainWindow *window;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	connect(ui.testButton, &QPushButton::clicked, this, &MainWindow::open);
	::window = this;
}

void MainWindow::open() {
	qDebug() << "Open slot executed";
	Map *map = new Map({100, 100});
}
