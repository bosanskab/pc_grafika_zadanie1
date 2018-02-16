#pragma once

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QtWidgets>


class QtClass : public QWidget
{
	Q_OBJECT

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
public:
	QtClass(QWidget *parent = Q_NULLPTR); 
	~QtClass();
	void newImage(int x, int y);
	void osi(int vyska, int sirka);
	void zakladneDelenie(int vyska, int sirka);
	void noveDelenie(int pocet, int vyska, int sirka);
	QImage *obrazok;
	bool zapnutieKreslenia;
	QPoint beginPoint;
	void kresliSinus(int typ, int pocet, int vyska, int sirka,int n);
	void kresliKosinus(int typ,int pocet, int vyska, int sirka,int n);
	void SaveImg(QString menoSuboru);
};
