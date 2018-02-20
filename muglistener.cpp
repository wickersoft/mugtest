#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include "muglistener.h"
#include "qmugmessenger.h"

void (*image_add_callback) (QList<QString> *) = [] (QList<QString> *) -> void {};
void (*workspace_change_callback) (QString *) = [] (QString *) -> void {};

void muglistener::init()
{
    QMugMessenger *messenger = QMugMessenger::globalInstance();

    messenger->connect(messenger, &QMugMessenger::messageReceivedFull, [&](const MugMessage &msg) {

        if(msg.topic() == "addImagesToPhantom") {
            QJsonObject jsonObj = QJsonDocument::fromBinaryData(msg.content()).object();
            QList<QString> list;
            //QJsonArray array =
            foreach (const QJsonValue &value, jsonObj["uris"].toArray()) {
                list.append(value.toString());
            }
            image_add_callback(&list);
        } else if (msg.topic() == "setActiveTask") {
            QJsonObject jsonObj = QJsonDocument::fromBinaryData(msg.content()).object();
            QList<QString> list;
            foreach (const QJsonValue &value, jsonObj["uris"].toArray()) {
                list.append(value.toString());
            }
        } else {
    }});
}

void muglistener::on_image_added( void (*callback)(QList<QString> *)) {
    image_add_callback = callback;
}

void muglistener::on_workspace_changed( void (*callback)(QString *)) {
    workspace_change_callback = callback;
}
