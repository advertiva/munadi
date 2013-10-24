#include "playbook.h"
#include "ui_playbook.h"

Playbook::Playbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playbook)
{
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("app/native/res/background.png")));
    this->setPalette(palette);

    ui->setupUi(this);


}

Playbook::~Playbook()
{
    delete ui;
}
