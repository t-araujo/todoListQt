import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToDo 1.0

ColumnLayout {
    Row {
        TextField {
            id: descriptionField
            placeholderText: "New note"
//            anchors.horizontalCenter: parent.horizontalCenter
            width: 150
        }
        Button {
            text: qsTr("Add new note")
            onClicked: {
                test.setItem(descriptionField.text)
                descriptionField.clear()
            }
        }
    }
    GridLayout {
        id: grid
        columns: 3
        Column {
            Frame {
                Layout.fillWidth: true
                ListView {
                    id: listView
                    implicitWidth: 250
                    implicitHeight: 250
                    clip: true
                    anchors.fill: parent

                    model: test.items

                    delegate:
                        RowLayout {

                        width: parent.width
                        CheckBox {
                            id: noteCheck
                            checked: modelData.done
                            onCheckStateChanged: modelData.done = !modelData.done
//                                note.text != "" ? modelData.done = true : modelData.done = false
                            onCheckedChanged: console.log(modelData.done)
                        }
                        TextField {
                            id: note
                            font.strikeout : noteCheck.data
                            text: modelData.description
                            onEditingFinished: modelData.description = text
                            Layout.fillWidth: true
                        }
                    }
                }
            }
        }
        Column {

        }

    }
    Row {
        Button {
            text: qsTr("delete last note")
            onClicked: test.removeLast()
        }
        Button {
            text: qsTr("Delete First note")
            onClicked: test.removeFirst()
        }
        Button {
            text: qsTr("Delete all notes")
            onClicked: test.removeAll()
        }
    }
}

