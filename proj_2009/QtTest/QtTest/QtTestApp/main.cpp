#include "qttestapp.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtTestApp w;
	w.show();
	return a.exec();
}
