#include "CalculateAreaOfCircle.h"
#include "qgridlayout.h"
#include "qdebug.h"
#include "qdatetime.h"
#include "qtimer.h"
const static double PI = 3.1416;

//CalculateAreaOfCircle::CalculateAreaOfCircle(QWidget* parent)
//	: QDialog(parent)
//{
//	ui.setupUi(this);	
//}
//
//void CalculateAreaOfCircle::on_countButton_clicked() {
//	bool ok;
//	QString tempStr;
//	QString valueStr = ui.radiusLineEdit->text();
//	int valueInt = valueStr.toInt(&ok);
//	double area = valueInt * valueInt * PI;
//	ui.areaLabel_2->setText(tempStr.setNum(area));
//}
//
//void CalculateAreaOfCircle::on_radiusLineEdit_textChanged(const QString& arg1)
//{
//	bool ok;
//	QString tempStr;
//	QString valueStr = ui.radiusLineEdit->text();
//	int valueInt = valueStr.toInt(&ok);
//	double area = valueInt * valueInt * PI;
//	ui.areaLabel_2->setText(tempStr.setNum(area));
//}

CalculateAreaOfCircle::CalculateAreaOfCircle(QWidget* parent)
	: QDialog(parent)
{
	label1 = new QLabel(this);
	label1->setText(QStringLiteral("请输入圆的半径: "));
	lineEdit = new QLineEdit(this);
	label2 = new QLabel(this);
	button = new QPushButton(this);
	button->setText(QStringLiteral("显示对应圆的面积: "));
	label3 = new QLabel(this);
	time = new QDateTime(QDateTime::currentDateTime());
	label3->setText(time->date().toString() + "  " + time->time().toString());
	QGridLayout* mainLayout = new QGridLayout(this);
	mainLayout->addWidget(label1, 0, 0);
	mainLayout->addWidget(lineEdit, 0, 1);
	mainLayout->addWidget(label2, 1, 1);
	mainLayout->addWidget(button, 1, 0);
	mainLayout->addWidget(label3, 2, 0);
	connect(button, SIGNAL(clicked()), this, SLOT(showArea()));
	QTimer* clock = new QTimer(parent);
	connect(clock, SIGNAL(timeout()), this, SLOT(updateTime()));
	clock->start(1000);
}

void CalculateAreaOfCircle::showArea()
{
	QList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.insert(list.end(), i);
	}
	QList<int>::iterator j;
	for (j = list.begin(); j != list.end(); j++)
	{
		qDebug() << (*j);
	}

	bool ok;
	QString tempStr;
	QString valueStr = lineEdit->text();
	int valueInt = valueStr.toInt(&ok);
	double area = valueInt * valueInt * PI;
	label2->setText(tempStr.setNum(area));
}

void CalculateAreaOfCircle::updateTime()
{
	label3->setText(time->date().toString() + "  " + time->time().toString());
}
