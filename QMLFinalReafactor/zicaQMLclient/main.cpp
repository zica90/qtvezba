#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend.h>
#include <QQmlContext>
#include <QSharedPointer>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    BackEnd backEnd;
    engine.rootContext()->setContextProperty("backEnd", &backEnd);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QSharedPointer<QObject> rootObject(engine.rootObjects().first());
    backEnd.setQObject(rootObject);
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
