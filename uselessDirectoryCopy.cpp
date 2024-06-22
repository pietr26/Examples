// Copies all directories (and subdirectories) without content

#include <QApplication>
#include <QDirIterator>

void main()
{
    QString from = "";
    QString to = "";

    int cutCount = from.size() + 1;
    QDirIterator makePaths(from, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (makePaths.hasNext())
        QDir().mkpath(to + makePaths.next().remove(0, cutCount));
}

