#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <databasemanager.h>
#include <QScopedPointer>
#include <QQmlContext>
#include <backend.h>
#include <QObject>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    BackEnd *be=new BackEnd();
    engine.rootContext()->setContextProperty("db", be->getDBManager().data());
    engine.rootContext()->setContextProperty("be", be);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *rootObject = engine.rootObjects().first();
    be->setSendButton(rootObject);


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();


}
