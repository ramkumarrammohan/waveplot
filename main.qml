import QtQuick 2.9
import QtQuick.Window 2.2
import Custom 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("waveplot")

//    StrikeLine {
//        id: strikeLineId
//        anchors.fill: parent
//        anchors.margins: 10
//    }

    Waveform {
        id: waveformId
        anchors.fill: parent
    }
}
