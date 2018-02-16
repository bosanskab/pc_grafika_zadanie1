#include "Grafika.h"

Grafika::Grafika(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);
	ui.scrollArea->setWidget(&this->widgetNaKreslenie);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	

	widgetNaKreslenie.newImage(sirka,vyska);
	widgetNaKreslenie.osi(sirka,vyska);
	widgetNaKreslenie.zakladneDelenie(sirka,vyska);
}

void Grafika::on_vymaz_clicked() {
	widgetNaKreslenie.newImage(sirka,vyska);
	widgetNaKreslenie.osi(sirka, vyska);
	widgetNaKreslenie.zakladneDelenie(sirka,vyska);
}

void Grafika::on_pocet_valueChanged(int pocet){
	vymaz();
	widgetNaKreslenie.osi(sirka, vyska);
	widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
}

void Grafika::vymaz() {
	widgetNaKreslenie.newImage(sirka,vyska);
	widgetNaKreslenie.osi(sirka,vyska);
}

void Grafika::on_kresli_clicked() {
	int pocet = ui.pocet->value();
	int n = ui.n->value();

	if (ui.comboBox->currentIndex() == 0) {
		vymaz();
		widgetNaKreslenie.osi(sirka,vyska);
		if (ui.bodovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
			widgetNaKreslenie.kresliSinus(1, pocet, vyska, sirka,n);
		}
		if (ui.ciarovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska,  sirka);
			widgetNaKreslenie.kresliSinus(2, pocet, vyska, sirka,n);
		}
		if (ui.stlpcovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
			widgetNaKreslenie.kresliSinus(3, pocet, vyska, sirka,n);
		}
	}

	if (ui.comboBox->currentIndex() == 1) {
		vymaz();
		widgetNaKreslenie.osi(sirka, vyska);
		if (ui.bodovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
			widgetNaKreslenie.kresliKosinus(1, pocet, vyska, sirka,n);
		}
		if (ui.ciarovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
			widgetNaKreslenie.kresliKosinus(2, pocet, vyska, sirka,n);
		}
		if (ui.stlpcovy->isChecked()) {
			widgetNaKreslenie.noveDelenie(pocet, vyska, sirka);
			widgetNaKreslenie.kresliKosinus(3, pocet, vyska, sirka,n);
		}
	}
}


void Grafika::on_actionSave_triggered(){
	widgetNaKreslenie.SaveImg("Grafika.png");
}
