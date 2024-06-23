import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Contacts"

    TableView {
        id: tableView
        anchors.fill: parent
        model: contactTableModel

        delegate: Row {
            spacing: 10
            Text { text: model.firstName; width: 100 }
            Text { text: model.lastName; width: 100 }
            Text { text: model.phoneNumber; width: 100 }
        }

        ScrollBar.vertical: ScrollBar { }
    }
}