#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAndroidExtras/QAndroidJniObject>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QAndroidJniObject androidJniMethodTest = QAndroidJniObject::fromString("test");
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/test/AndroidJniMethod",
                                              "test",
                                              "(Ljava/lang/String;)V",
                                              androidJniMethodTest.object<jstring>());

    return app.exec();
}
