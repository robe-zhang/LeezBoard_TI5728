#include <qglobal.h>
#include <QApplication>
#include <QLabel>

#if QT_VERSION < 0x050000
#include <QWSServer>
#endif


#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	bool use_cmem = false;

	if(argc > 3){
		use_cmem = atoi(argv[3]);
	}
	else{
		printf("USAGE: -platform linuxfb <use_cmem flag>\n\n");
		printf("Set the ""use_cmem"" flag to 1 to allocate memory from CMEM driver. By default it is set to 0\n\n\n");
	}

	QApplication a(argc, argv);

	MainWindow w(NULL, use_cmem);

#if QT_VERSION < 0x050000
	QWSServer::setBackground(QBrush(QColor(0, 0, 0, 0)));
#endif

	w.show();
	return a.exec();
}

