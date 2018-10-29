#include "qttestapp.h"

QtTestApp::QtTestApp(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

QtTestApp::~QtTestApp()
{

}
