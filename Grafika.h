#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Grafika.h"
#include <QDebug>
#include "QtClass.h"

class Grafika : public QMainWindow{
	Q_OBJECT

public:
	Grafika(QWidget *parent = Q_NULLPTR);
public slots:
	void on_actionSave_triggered();
	void on_kresli_clicked();
	void on_vymaz_clicked();
	void on_pocet_valueChanged(int pocet);
	void vymaz();
private:
	Ui::GrafikaClass ui;
	QtClass widgetNaKreslenie; 
	int vyska=360, sirka=480;
};
