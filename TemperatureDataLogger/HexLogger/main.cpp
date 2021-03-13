#include <QObject>
#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:///MainScreen.qml"));
    return app.exec();
}
