#ifndef QTTESTAPP_H
#define QTTESTAPP_H

#include <QtGui/QMainWindow>
#include "ui_qttestapp.h"

class QtTestApp : public QMainWindow
{
	Q_OBJECT

public:
	QtTestApp(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtTestApp();

private:
	Ui::QtTestAppClass ui;
};

#endif // QTTESTAPP_H
