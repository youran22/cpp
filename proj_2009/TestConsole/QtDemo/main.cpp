#include "qtdemo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDemo w;
	w.show();
	return a.exec();
}
