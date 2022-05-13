// Example taken from 
// https://doc.qt.io/archives/3.3/tutorial1-01.html
// slightly changed to make it work with QT5

/****************************************************************
**
** Qt tutorial 1
**
****************************************************************/

#include <qapplication.h>
#include <qpushbutton.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QPushButton hello( "Hello from CMake Best Practices!", 0 );
    hello.resize( 250, 30 );
    hello.show();
    return a.exec();
}