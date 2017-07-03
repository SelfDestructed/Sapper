#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"


class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);

public slots:
	void open();

private:
	Ui::MainWindowClass ui;
};
