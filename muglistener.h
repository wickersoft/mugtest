#ifndef MUGLISTENER_H
#define MUGLISTENER_H

#include<QList>
#include<QString>

namespace muglistener {
void init();
void on_image_added( void (*)(QList<QString> *));
void on_workspace_changed(void (*)(QString *));
}
#endif // MUGLISTENER_H
