#include "ContactTableModel.h"

ContactTableModel::ContactTableModel(QObject *parent)
        : QAbstractTableModel(parent) {}

int ContactTableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return contacts.count();
}

int ContactTableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

QVariant ContactTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return {};

    const Contact &contact = contacts[index.row()];

    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case 0: return contact.firstName;
                case 1: return contact.lastName;
                case 2: return contact.phoneNumber;
                default: return {};
            }
        case Qt::UserRole: return contact.firstName;
        case Qt::UserRole + 1: return contact.lastName;
        case Qt::UserRole + 2: return contact.phoneNumber;
        default: return {};
    }
}

bool ContactTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        Contact &contact = contacts[index.row()];

        switch (index.column()) {
            case 0: contact.firstName = value.toString(); break;
            case 1: contact.lastName = value.toString(); break;
            case 2: contact.phoneNumber = value.toString(); break;
            default: return false;
        }

        emit dataChanged(index, index, {role});
        return true;
    }

    return false;
}

Qt::ItemFlags ContactTableModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

void ContactTableModel::addContact(const QString &firstName, const QString &lastName, const QString &phoneNumber) {
    beginInsertRows(QModelIndex(), contacts.count(), contacts.count());
    contacts.append({firstName, lastName, phoneNumber});
    endInsertRows();
}

QHash<int, QByteArray> ContactTableModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "firstName";
    roles[Qt::UserRole + 1] = "lastName";
    roles[Qt::UserRole + 2] = "phoneNumber";
    return roles;
}