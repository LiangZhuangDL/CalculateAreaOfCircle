#pragma once

#include <QtWidgets/QDialog>
#include "ui_CalculateAreaOfCircle.h"

class CalculateAreaOfCircle : public QDialog
{
	Q_OBJECT

public:
	CalculateAreaOfCircle(QWidget* parent = Q_NULLPTR);

private slots:

	void showArea();

	void updateTime();

	/*void on_countButton_clicked();

	void on_radiusLineEdit_textChanged(const QString& arg1);*/

private:
	/*Ui::CalculateAreaOfCircleClass ui;*/
	QLabel* label1, * label2, * label3;
	QLineEdit* lineEdit;
	QPushButton* button;
	QDateTime* time;
};
