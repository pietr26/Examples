// Sorts a list of classes with an unknown structure.

#include <QApplication>

class Test
{
public:
    Test(QString bla, float blubb)
    {
        this->bla = bla;
        this->blubb = blubb;
    }

    QString bla;
    float blubb;
};

bool operator<(const Test& a, const Test& b) {
    return a.blubb < b.blubb;
}


void main()
{
    QList<Test> test;
    test.append(Test("test3", 3));
    test.append(Test("test4", 4));
    test.append(Test("test2", 2));
    test.append(Test("test1", 1));

    qInfo() << "unsort:";
    for (const auto& obj : test) {
        qInfo() << obj.bla << obj.blubb;
    }

    std::sort(test.begin(), test.end());

    qInfo() << "sort:";
    for (const auto& obj : test) {
        qInfo() << obj.bla << obj.blubb;
    }
}

/* OUTPUT:
    unsort:
    "test3" 3
    "test4" 4
    "test2" 2
    "test1" 1
    sort:
    "test1" 1
    "test2" 2
    "test3" 3
    "test4" 4
*/
