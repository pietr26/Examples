// Get suffixes from all files in a directory

#include <QApplication>
#include <QDirIterator>

void main()
{
    QString from = "";
    QString outputFile = "" + QString("suffixes.txt");

    QStringList list;
    QDirIterator dir(from, QDir::Files, QDirIterator::Subdirectories);

    while (dir.hasNext())
        list << QFileInfo(dir.next()).completeSuffix();

    list.removeDuplicates();
    list.sort();

    QFile suffixes(outputFile);
    suffixes.open(QFile::WriteOnly);
    QTextStream out(&suffixes);
    out << list.join("\n");
    suffixes.close();
}
