#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "strikeline.h"
#include "waveform.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // QML Registers
    qmlRegisterType<Waveform>("Custom", 1, 0, "Waveform");
    qmlRegisterType<StrikeLine>("Custom", 1, 0, "StrikeLine");

    // QML Engine
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
