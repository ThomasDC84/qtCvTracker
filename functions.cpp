#include "functions.h"
#include <QCamera>
#include <QSettings>

QStringList getAvailableDevices()
{
    QList<QByteArray> cameras;
    QStringList CameraNames;

    cameras << QCamera::availableDevices();

    for(int i=0; i<cameras.size(); i++)
    {

        QString regpath;

        QString camera0(cameras.at(i));

        camera0 = camera0.replace("@device:pnp:\\\\\?\\", "");

        QRegExp tp;
        tp.setPattern("usb_*#");
        tp.setPatternSyntax(QRegExp::Wildcard);
        tp.indexIn(camera0);

        camera0.replace(tp.cap(0), tp.cap(0).toUpper());

        QRegExp rx;
        rx.setPattern("(\\{[^}]+\\})");
        rx.indexIn(camera0);

        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(camera0, pos)) != -1) {
            list << rx.cap(1);
            pos += rx.matchedLength();
        }

        if(list.size() == 2)
        {
            camera0 = camera0.replace(list[1], "#"+list[1].toUpper());
        }
        else
        {
            camera0 = camera0.replace("global", "#GLOBAL");
        }

        regpath.append("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\DeviceClasses\\");
        regpath.append(list.at(0));
        regpath.append("\\##?#");
        regpath.append(camera0);
        regpath.append("\\Device Parameters\\");

        QSettings camName(regpath, QSettings::NativeFormat);
        CameraNames.append(camName.value("FriendlyName", "WebCam").toString());
        regpath.clear();
    }

    return CameraNames;
}
