# Quickstart

Quick introduction for a minimal working example see: https://gitlab.com/hpivw/mug/blob/master/mug-tools/mug-messenger/src/main.cpp

## Qt  

`#include "qmugmessaging.h"`

Does not require initialization/instantiation, a global instance can be accessed with `QMugMessenger::globalInstance`  
<br>
### Publishing a message

```cpp
QMugMessenger::globalInstance()->publish(QString topic, QString messageString)
```
<br>  
### Subscribing to messages

**Option 1 Qt Signals & Slots**

```cpp
QMugMessenger::globalInstance()->mugConnect("EXAMPLETOPIC", receiver, SLOT(receiveExampleTopic(QString)))
```


**Option 2 Lambdas**
```cpp
QMugMessenger::globalInstance()->mugConnect("EXAMPLETOPIC", [&](const &Qstring content) {
    // body
});
```
<br> 
## QML

### Install the mug-qml plugin

Copy libqmlmugplugin.dll (.so, .dylib), qmldir, plugin.qmltypes into `QTDIR/qml/Mug/` (QTDIR is ur qt installation directory)

On unix system you can use `make install` to isntall the plugin.

### Using the plugin

`IMPORTANT!` Use Connections to access the Messenger singletons signals.
using Messenger.onMessageReceived: {...} WONT work and will crash the qml runtime! (This is QT-BUG)

```qml
import Mug 1.0

// receiving messages
Connections {
    target: Messenger
    onMessageReceived: {
        // in qml you have to filter for the topic by hand
    }
}

// publish
Messenger.publish("topic", "message")
```

## Utiltiy classes

You can convert Json to Qt types by using the following classes:

* MugPoint <-> QPoint
* MugPointF <-> QPoint
* MugPolygon <-> QPolygonF + color + border
* MugLabel <-> QStaticText + font + color + positon
* MugFont <-> QFont
* MugTimeInterval <-> QDateTime (start, end)

Since those classes extend standard Qt classes you can use them directly in other Qt componenets (e.g: `QPainter.drawPolygon(MugPolygon)`)

You can construct those types from json by using the QJsonObject cosntructor `MugJsonType(QJsonObject)`or `MugJsonType::fromString(QString)`.

Each type provides a `MugJsonType.toJson()` method which converts the type back to a QJsonObject.

There are also some static methos in MugJsonType to convert strings to their respective Qt types.

`static QDateTime stringToTimeStamp(const QString &timestamp)`
`static QString colorToHexArgb(const QColor &color)`

**Example:**
```cpp
QPoint point(10, 20);
MugPoint mPoint(point);
QJsonObject resultObj = mPoint.toJson();
QMugMessenger::globalInstance()->publish("point_topic", mPoint.toString());


QJsonObject p1{{"x", 10}, {"y", 20}};
QJsonObject p2{{"x", 40}, {"y", 80}};
QRect rect(MugPoint(p1), MugPoint(p2));


QJsonObject p3{{"x", 20}, {"y", 20}};
MugPolygon somePoly;
somePoly.append(MugPoint(p3));
```

## MUGUDPM socket

If you want to interact with the messaging interface directly. Use `mugsocket.h` which serves as a Qt wrapper for messaging.
