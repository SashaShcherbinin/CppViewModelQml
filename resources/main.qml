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
            Text { text: model.firstName; width: 200 }
            Text { text: model.lastName; width: 200 }
            Text { text: model.phoneNumber; width: 200 }
        }

        ScrollBar.vertical: ScrollBar { }
    }
}