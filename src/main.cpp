#include <QApplication>
#include <QTableView>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "contact/ContactTableModel.h"

int runWithWidget(int argc, char *argv[]);

int runWithQml(int argc, char *argv[]);

std::unique_ptr<ContactTableModel> createViewModel();

int main(int argc, char *argv[]) {
    return runWithQml(argc, argv);
}

int runWithWidget(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::unique_ptr<ContactTableModel> model = createViewModel();
    QTableView view;
    view.setModel(model.get());
    view.show();
    return QApplication::exec();
}

int runWithQml(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    std::unique_ptr<ContactTableModel> model = createViewModel();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("contactTableModel", model.get());
    engine.load(QUrl(QStringLiteral("qrc:/resources/main.qml")));
    return QGuiApplication::exec();
}

std::unique_ptr<ContactTableModel> createViewModel() {
    auto model = std::make_unique<ContactTableModel>();
    model->addContact("John", "Doe", "123456789");
    model->addContact("Jane", "Smith", "987654321");
    model->addContact("James", "Brown", "456123789");
    model->addContact("Jessica", "Davis", "321654987");
    model->addContact("Jack", "Wilson", "789123456");
    model->addContact("Jill", "Taylor", "654987321");
    model->addContact("Jeremy", "Clark", "147258369");
    model->addContact("Jenny", "Evans", "963852741");
    model->addContact("Josh", "Moore", "258369147");
    model->addContact("Julia", "Parker", "852741963");
    model->addContact("Justin", "Wright", "369147258");
    model->addContact("Judy", "Collins", "741963852");
    return model;
}
