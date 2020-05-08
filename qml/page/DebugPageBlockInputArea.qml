﻿import QtQuick 2.12
import QtQuick.Controls 2.12

import "qrc:/qml/base"

DebugPageBlock {
    id: root
    sakIcon: "qrc:/resources/icons/输入 (1).png"
    sakTitle: qsTr("数据输入")

    contentItem: Item{
        SAKTextArea {
            height: 58
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: 5
                leftMargin: 5
                rightMargin: 5
            }
        }

        Row {
            id: buttonRow
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            rightPadding: 5
            bottomPadding: 5
            spacing: 5

            Repeater {
                model: [qsTr("清空输入"), qsTr("数据预设"), qsTr("发送预设"), qsTr("发送数据")]

                SAKButton {
                    height: 25
                    text: modelData

                    onClicked: {
                        console.info(modelData)
                    }
                }
            }
        }

        Row {
            anchors.verticalCenter: buttonRow.verticalCenter
            anchors.left: parent.left
            leftPadding: 5
            spacing: 5

            Repeater {
                model: [qsTr("追加CRC"), qsTr("大端CRC")]
                SAKCheckBox {
                    anchors.verticalCenter: parent.verticalCenter
                    text: modelData
                }
            }
        }
    }
}