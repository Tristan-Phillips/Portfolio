//Local Includes
#include "mainclient.h"

//External Includes
#include <QApplication>
//Used purely for the 'splash screen'
#include <QMovie>
#include <QTimer>
#include <QLabel>
#include <QSplashScreen>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClient w;

    /* Allows for a .GIF to be used similarly 
     * to how a splash screen would work.*/
        QMovie *movie = new QMovie(":/images/splash.gif");
        QLabel *process = new QLabel{nullptr};
        process->resize(500,500);
        process->setMovie(movie);
        process->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        process->setAlignment(Qt::AlignCenter);
        movie->start();
        process->show();
    
    //Splash screen of cats included because I dont know if a QMovie will be counted for points as a splash screen
        QPixmap pixmap(":/images/catsplash.png");

        QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
        splash.move(((process->width())+process->width())-((pixmap.width()/2)+8) ,((process->height()/2))-(((pixmap.height())/4))+6);
        splash.show();

    //Timer to allow the 'splash screen' to be displayed for 3 seconds
        QTimer::singleShot(3000, &splash, SLOT(close()));
        QTimer::singleShot(3000, process, SLOT(close()));
        QTimer::singleShot(3000, &w, SLOT(show()));

    return a.exec();
}
