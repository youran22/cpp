#ifndef QTDEMO_H
#define QTDEMO_H

#include <QtGui/QMainWindow>
#include "ui_qtdemo.h"

class QtDemo : public QMainWindow
{
	Q_OBJECT

public:
	QtDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtDemo();

private:
	Ui::QtDemoClass ui;
};

#endif // QTDEMO_H
