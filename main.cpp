#include "Grafika.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	Grafika w; 
	w.show();
	return a.exec();
}
