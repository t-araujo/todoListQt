import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Todo List")

    ToDoList {
        anchors.centerIn: parent
    }

//        Test {

//        }


//    Component.onCompleted: test.setName("sjdkksjdksjdkj")

//    ColumnLayout {
//        Row {
//            Repeater{
//                model: test.names
//                Text {
//                    padding: 10
//                    text: modelData
//                }
//            }
//        }

//        Row {
//            leftPadding: 10
//            TextField {
//                placeholderText: qsTr("Enter name")
//                id: inputString
//            }
//        }

//        Row {

//            Button {
//                text : qsTr("Remove First")
//                Layout.fillWidth: true
//                onClicked: test.removeFirst()
//            }
//            Button {
//                Text {
//                    text: qsTr("Remove Last")
//                    anchors.centerIn: parent
//                }
//                Layout.fillWidth: true
//                onClicked: test.removeLast()
//            }
//            Button {
//                Text {
//                    id: removeAllButton
//                    text: qsTr("Remove All")
//                    anchors.centerIn: parent
//                }
//                onClicked: test.removeAll()
//            }
//            Button {
//                Text {
//                    id: addOneButton
//                    text: qsTr("Add one")
//                    anchors.centerIn: parent
//                }
//                onClicked: test.setName(inputString.displayText)
//            }
//        }
//    }

}
