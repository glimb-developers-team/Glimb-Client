#include "OrderCustomerWindow.h"
#include "ui_OrderCustomerWindow.h"

OrderCustomerWindow::OrderCustomerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderCustomerWindow)
{
    ui->setupUi(this);

    QTreeWidgetItem *FirstLevel = new QTreeWidgetItem(ui->treeWidget);
        ui->treeWidget->addTopLevelItem(FirstLevel);
        FirstLevel->setText(0,"Закупка 1");
        QTreeWidgetItem *item = new QTreeWidgetItem(FirstLevel);
        item->setText(0,"Материалы");
    QTreeWidgetItem *SecondLevel = new QTreeWidgetItem(ui->treeWidget);
        ui->treeWidget->addTopLevelItem(SecondLevel);
        SecondLevel->setText(0,"Закупка 2");
        QTreeWidgetItem *item2 = new QTreeWidgetItem(SecondLevel);
        item2->setText(0,"Материалы");

}

OrderCustomerWindow::~OrderCustomerWindow()
{
    delete ui;
}
