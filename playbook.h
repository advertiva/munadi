#ifndef PLAYBOOK_H
#define PLAYBOOK_H

#include <QWidget>

namespace Ui {
    class Playbook;
}

class Playbook : public QWidget
{
    Q_OBJECT

public:
    explicit Playbook(QWidget *parent = 0);
    ~Playbook();

private:
    Ui::Playbook *ui;
};

#endif // PLAYBOOK_H
