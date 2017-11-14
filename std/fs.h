#ifndef ASKELIB_STD_FS_H
#define ASKELIB_STD_FS_H

#include <QFile>

namespace aske {

bool isBinary(QFile &f);


void createFile(const QString &fileName);
QString readFile(const QString &fileName);
bool copyFileForced(const QString &from, const QString &to);
bool copyRecursively(const QString &srcDir, const QString &dstDir);

bool isPicture(const QString &fileName);
QString binaryToText(const QByteArray &data, bool caps = true);

} // namespace aske

#endif //ASKELIB_STD_FS_H
