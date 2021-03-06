#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget"
#include "QWizard"
#include "deleteparsedreferences.h"
#include "QWizardPage"
#include "QWidget"
#include "classwizard.h"
#include "editreference.h"
#include "QLabel"
#include "viewparsedreferences.h"
#include "QLineEdit"
#include "QTextEdit"
#include "QtWidgets"
#include "QtGui"
#include "QtSql"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*  Put widget in center */
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());

    /*     Setup for toolButton for viewing parsed references         */
    ui->toolButton->setIcon(QIcon(QPixmap(":images/viewicon.png")));
    ui->toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButton->setIconSize(QSize(175,175));
    ui->toolButton->setText("View Parsed References");

    /*     Setup for toolButton for erasing parsed references         */
    ui->toolButton_4->setIcon(QIcon(QPixmap(":images/eraser.png")));
    ui->toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButton_4->setIconSize(QSize(175,175));
    ui->toolButton_4->setText("Delete Parsed Reference");


    /*     Setup for toolButton for parsing references         */
    ui->toolButton_2->setIcon(QIcon(QPixmap(":images/newicon.png")));
    ui->toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButton_2->setIconSize(QSize(175,175));
    ui->toolButton_2->setText("    Parse Reference Text   ");

    /*     Setup for toolButton for Exporting references         */
    ui->toolButton_3->setIcon(QIcon(QPixmap(":images/editicon.png")));
    ui->toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButton_3->setIconSize(QSize(175,175));
    ui->toolButton_3->setText("     Edit Reference Text   ");


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbpath = QCoreApplication::applicationDirPath().append("/db/refdb.db");
    db.setDatabaseName(dbpath);

    db.open();

    //ui->tableView->resizeColumnsToContents();
//   QHeaderView* header = ui->tableView->horizontalHeader();

   // header->setStretchLastSection(true);
  //  ui->tableView->setHorizontalHeader(header);

    qDebug()<< db.lastError();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_2_clicked()
{
        ClassWizard *test=new ClassWizard;
        test->exec();

        connect(test,SIGNAL(destroyed()),test,SLOT(deleteLater()));
}

void MainWindow::on_toolButton_clicked()
{
    ViewParsedReferences *vpr=new ViewParsedReferences;
    vpr->exec();

    connect(vpr,SIGNAL(destroyed()),vpr,SLOT(deleteLater()));
}

void MainWindow::on_toolButton_4_clicked()
{
    DeleteParsedReferences *dpr = new DeleteParsedReferences;

   // dpr->setWindowTitle("Delete Parsed References");
    dpr->exec();

    connect(dpr,SIGNAL(destroyed()),dpr,SLOT(deleteLater()));
}

void MainWindow::on_toolButton_3_clicked()
{
    editreference *editwidget = new editreference;
    editwidget->exec();

    connect(editwidget,SIGNAL(destroyed()),editwidget,SLOT(deleteLater()));
}
