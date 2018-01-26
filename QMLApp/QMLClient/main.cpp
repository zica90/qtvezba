#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend.h>
#include <QScopedPointer>
#include <QTcpSocket>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    BackEnd* backEnd =new BackEnd();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("backEnd", backEnd);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *rootObject = engine.rootObjects().first();
    backEnd->setSendButton(rootObject);
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
