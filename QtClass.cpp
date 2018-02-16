#include "QtClass.h"
#include <QtMath>

QtClass::QtClass(QWidget *parent)
	: QWidget(parent){
	zapnutieKreslenia = 0;
}

QtClass::~QtClass() {
}

void QtClass::newImage(int x, int y){
	obrazok = new QImage(x, y, QImage::Format_RGB32);
	obrazok->fill(Qt::white);

	update(); 
}

void QtClass::osi(int sirka, int vyska) {
	QPainter painter(obrazok);
	zapnutieKreslenia = 0;

	painter.setPen(QPen(Qt::black, 1));
	painter.drawLine(10, vyska/2, sirka-10, vyska/2);
	painter.drawLine(sirka/2, 10, sirka/2, vyska-10);
	painter.drawText(sirka/2+10, 10, "y");
	painter.drawText(sirka-10, vyska/2-10, "x");
}

void QtClass::zakladneDelenie(int sirka, int vyska) {
	QPainter painter(obrazok);
	zapnutieKreslenia = 0;

	for (int i =0; i < 21; i++) {
		painter.drawPoint(10 + i * (sirka - 20) / 20, vyska / 2 + 1);
		painter.drawPoint(10 + i * (sirka - 20) / 20, vyska / 2 - 1);
		painter.drawPoint(sirka / 2 + 1, 10 + (vyska - 20) / 20 * i);
		painter.drawPoint(sirka / 2 - 1, 10 + (vyska - 20) / 20 * i);
	}
}

void QtClass::noveDelenie(int pocet, int vyska, int sirka) {
	QPainter painter(obrazok);

	for (int i = 0; i < pocet+ 1; i++) {
		painter.drawPoint(10 + i * (sirka - 20) / pocet, vyska / 2 + 1);
		painter.drawPoint(10 + i * (sirka - 20) / pocet, vyska / 2 - 1);
		painter.drawPoint(sirka / 2 + 1, 10 + (vyska - 20) / pocet * i);
		painter.drawPoint(sirka / 2 - 1, 10 + (vyska - 20) / pocet * i);
	}
	
}

void QtClass::kresliSinus(int typ,int pocet, int vyska, int sirka, int n) {
	QPainter painter(obrazok);
	double x, y;

	zapnutieKreslenia = 0;
	if (typ == 1) {
		painter.setPen(QPen(Qt::red, 3));
		double diel = (2*n* M_PI) / pocet;
		for (double i = (-n*M_PI); i <(n*M_PI)+diel; i = i +diel){
			y=qSin(-i)*(vyska-20)/M_PI+vyska/2;
			x = i * ((sirka - 20) /(2*n* M_PI))+ (sirka / 2);
			painter.drawPoint(x,y);
		}
	}
	if (typ == 2) {
		double x[101], y[101];
		int j=0;
		painter.setPen(QPen(Qt::yellow, 2));
		double diel = (2*n*M_PI) / pocet;
		for (double i = (-n*M_PI); i <(n*M_PI)+diel; i = i + diel) {
			y [j]= qSin(-i)*(vyska - 20) / M_PI + vyska/2;
			x[j] = i * ((sirka - 20) / (2*n* M_PI)) + (sirka / 2);
			if(j>0)
				painter.drawLine(x[j-1], y[j-1],x[j],y[j]);
			j++;
		}
	}
	if (typ == 3) {
		painter.setPen(QPen(Qt::green, 3));
		double y2;
		double diel = (2*n*M_PI) / pocet;
		double sirkaObdlznik = (sirka - 20) / pocet;
		for (double i = (-n*M_PI); i <(n*M_PI); i = i + diel) {
			y = (qSin(-i)*(vyska - 20) / M_PI) + (vyska/2);
			y2 =  vyska/2-y;
			x = i * ((sirka - 20) / (2*n * M_PI))+(sirka/2);
			painter.fillRect(x,y,sirkaObdlznik, y2, Qt::green);
		}
	}
}

void QtClass::kresliKosinus(int typ,int pocet,int vyska, int sirka,int n) {
	QPainter painter(obrazok);
	double x, y;

	zapnutieKreslenia = 0;
	if (typ == 1) {
		painter.setPen(QPen(Qt::red, 3));
		double diel = (2 * n* M_PI) / pocet;
		for (double i = (-n * M_PI); i <(n*M_PI) + diel; i = i + diel) {
			y = -qCos(i)*(vyska - 20) / M_PI + vyska / 2;
			x = i * ((sirka - 20) / (2 * n* M_PI)) + (sirka / 2);
			painter.drawPoint(x, y);
		}
	}
	if (typ == 2) {
		double x[101], y[101];
		int j = 0;
		painter.setPen(QPen(Qt::yellow, 2));
		double diel = (2 * n*M_PI) / pocet;
		for (double i = (-n * M_PI); i <(n*M_PI) + diel; i = i + diel) {
			y[j] = -qCos(i)*(vyska - 20) / M_PI + vyska / 2;
			x[j] = i * ((sirka - 20) / (2 * n* M_PI)) + (sirka / 2);
			if (j>0)
				painter.drawLine(x[j - 1], y[j - 1], x[j], y[j]);
			j++;
		}
	}
	if (typ == 3) {
		painter.setPen(QPen(Qt::green, 3));
		double y2;
		double diel = (2 * n*M_PI) / pocet;
		double sirkaObdlznik = (sirka - 20) / pocet;
		for (double i = (-n * M_PI); i <(n*M_PI); i = i + diel) {
			y = (-qCos(i)*(vyska - 20) / M_PI) + (vyska / 2);
			y2 = vyska / 2 - y;
			x = i * ((sirka - 20) / (2 * n * M_PI)) + (sirka / 2);
			painter.fillRect(x, y, sirkaObdlznik, y2, Qt::green);
		}
	}
}

void QtClass::paintEvent(QPaintEvent *event){
	QPainter painter(this);
	QRect area = event->rect(); 
	painter.drawImage(area, *obrazok, area);
}

void QtClass::SaveImg(QString menoSuboru){
	if (obrazok->save(menoSuboru, "png"))
		qDebug() << "Save";
	else
		qDebug() << "Error";
}