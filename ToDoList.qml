import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import ToDo 1.0

ColumnLayout {

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
                Component.onCompleted: {
                    console.log(modelData)
                }
                width: parent.width
                CheckBox {
                    id: noteCheck
                    checked: modelData.done
//                    onCheckStateChanged: note.text != "" ? noteCheck.data = true : noteCheck.data = false
                    onClicked: note.text != "" ? model.done = checked: ""
                }
                TextField {
                    id: note
                    text: modelData.description
                    onEditingFinished: modelData.description = text
                    Layout.fillWidth: true
                }
            }
        }
    }
    Row{
        Button {
            text: qsTr("Add new note")
            onClicked: test.setItem("temporário 2")
        }
        Button {
            text: qsTr("delete last note")
        }
        Button {
            text: qsTr("Delete First note")
        }
        Button {
            text: qsTr("Delete all notes")
        }
    }
}
