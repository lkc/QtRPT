#include "exampledlg4.h"
#include "ui_exampledlg4.h"

ExampleDlg4::ExampleDlg4(QWidget *parent) : QDialog(parent), ui(new Ui::ExampleDlg4) {
    ui->setupUi(this);

    ui->tableWidget->setRowCount(45);
    QObject::connect(ui->btnPrint, SIGNAL(clicked()), this, SLOT(print()));

    QTableWidgetItem *newItem;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        // name, cat, price, sw, sh, panel, cpu, Mem

        if (i % 2) {
            newItem = new QTableWidgetItem("PC "+QString::number(i/2));
            ui->tableWidget->setItem(i,0,newItem);

            newItem = new QTableWidgetItem("PC");
            ui->tableWidget->setItem(i,1,newItem);

            newItem = new QTableWidgetItem(QString::number(399 + (i%10) * 50));
            ui->tableWidget->setItem(i,2,newItem);

            newItem = new QTableWidgetItem(QString());
            ui->tableWidget->setItem(i,3,newItem);

            newItem = new QTableWidgetItem(QString());
            ui->tableWidget->setItem(i,4,newItem);

            newItem = new QTableWidgetItem(QString());
            ui->tableWidget->setItem(i,5,newItem);

            newItem = new QTableWidgetItem(i % 3 ? QString("Intel") : QString("AMD"));
            ui->tableWidget->setItem(i,6,newItem);

            newItem = new QTableWidgetItem(QString::number(i%8));
            ui->tableWidget->setItem(i,7,newItem);

        } else {
            newItem = new QTableWidgetItem("Display "+QString::number(i/2));
            ui->tableWidget->setItem(i,0,newItem);

            newItem = new QTableWidgetItem("Display");
            ui->tableWidget->setItem(i,1,newItem);

            newItem = new QTableWidgetItem(QString::number(199 + (i%15) * 30));
            ui->tableWidget->setItem(i,2,newItem);

            newItem = new QTableWidgetItem(QString::number(800 + (i % 6) * 100));
            ui->tableWidget->setItem(i,3,newItem);

            newItem = new QTableWidgetItem(QString::number(600 + (i % 6) * 100));
            ui->tableWidget->setItem(i,4,newItem);

            newItem = new QTableWidgetItem(i % 4 ? QString("LED") : QString("LCD"));
            ui->tableWidget->setItem(i,5,newItem);

            newItem = new QTableWidgetItem(QString());
            ui->tableWidget->setItem(i,6,newItem);

            newItem = new QTableWidgetItem(QString());
            ui->tableWidget->setItem(i,7,newItem);

        }
    }
}

void ExampleDlg4::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage) {
    if (paramName == "Name") {
        if (ui->tableWidget->item(recNo,0) == 0) return;
        paramValue = ui->tableWidget->item(recNo,0)->text();
    }
    if (paramName == "Category") {
        if (ui->tableWidget->item(recNo,1) == 0) return;
        paramValue = ui->tableWidget->item(recNo,1)->text();
    }
    if (paramName == "Price") {
        if (ui->tableWidget->item(recNo,2) == 0) return;
        paramValue = ui->tableWidget->item(recNo,2)->text();
    }
    if (paramName == "ScreenWidth") {
        if (ui->tableWidget->item(recNo,3) == 0) return;
        paramValue = ui->tableWidget->item(recNo,3)->text();
    }
    if (paramName == "ScreenHeight") {
        if (ui->tableWidget->item(recNo,4) == 0) return;
        paramValue = ui->tableWidget->item(recNo,4)->text();
    }
    if (paramName == "PanelType") {
        if (ui->tableWidget->item(recNo,5) == 0) return;
        paramValue = ui->tableWidget->item(recNo,5)->text();
    }
    if (paramName == "CPU") {
        if (ui->tableWidget->item(recNo,6) == 0) return;
        paramValue = ui->tableWidget->item(recNo,6)->text();
    }
    if (paramName == "Memory") {
        if (ui->tableWidget->item(recNo,7) == 0) return;
        paramValue = ui->tableWidget->item(recNo,7)->text();
    }
}

void ExampleDlg4::setValueImage(int &recNo, QString &paramName, QImage &paramValue, int reportPage) {
}

void ExampleDlg4::print() {
    QString fileName = "./examples_report/example4.xml";
    report = new QtRPT(this);
    report->recordCount << ui->tableWidget->rowCount();
    if (report->loadReport(fileName) == false) {
        qDebug()<<"Report's file not found";
    }
    QObject::connect(report, SIGNAL(setValue(int&, QString&, QVariant&, int)),
                     this, SLOT(setValue(int&, QString&, QVariant&, int)));
    QObject::connect(report, SIGNAL(setValueImage(int&, QString&, QImage&, int)),
                     this, SLOT(setValueImage(int&, QString&, QImage&, int)));
    //report->setCallbackFunc(getReportValue);
    report->printExec();

}

ExampleDlg4::~ExampleDlg4() {
    delete ui;
}
