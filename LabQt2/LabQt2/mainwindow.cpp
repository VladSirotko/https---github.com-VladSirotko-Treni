#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(trans()));
    connect(ui->action1, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->action2, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trans()
{

    QString temp = ui->textEdit->toPlainText();
    int n=sqrt(temp.split(",", QString::SkipEmptyParts).length());
    int x[n][n];
     QString str[n][n];
     QString y;
     for (int i=0;i<n;i++)
       for (int j=0;j<n;j++)
      {
        x[i][j]= temp.split(",", QString::SkipEmptyParts)[i*n+j].toInt();
      }
       for (int i=0;i<n;i++)
         for(int j=0;j<n;j++)
           {
             str[i][j] = QString("%1").arg(x[j][i]);
           }
       for (int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              {if ((i==n-1)&&(j==n-1)) {y += str[i][j]+";";}
                 else if (j==n-1){ y += str[i][j]+";\n";}
                 else y += str[i][j]+",";
              }
    ui->textBrowser_2->setText(y);
}


