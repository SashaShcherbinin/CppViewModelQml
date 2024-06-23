#ifndef CONTACT_MODEL_H
#define CONTACT_MODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class ContactTableModel : public QAbstractTableModel {

Q_OBJECT

public:
    explicit ContactTableModel(QObject *parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

    [[nodiscard]] int columnCount(const QModelIndex &parent) const override;

    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    [[nodiscard]] Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addContact(const QString &firstName, const QString &lastName, const QString &phoneNumber);

private:
    struct Contact {
        QString firstName;
        QString lastName;
        QString phoneNumber;
    };

    QList<Contact> contacts;
};

#endif // CONTACT_MODEL_H