#include <QCoreApplication>
#include <QTextStream>
#include "muglistener.h"


QTextStream qin(stdin);
QTextStream qout(stdout);

void kek(QList<QString> * uris) {

    for(int i = 0; i < uris->length(); i++) {
        qout << uris->at(i) << endl;
    }
}

void top(QString * workspace) {
    qout << "Workspace is now: " << *workspace << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    muglistener::on_image_added(kek);
    muglistener::on_workspace_changed(top);
    muglistener::init();
}
