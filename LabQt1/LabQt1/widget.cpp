#include "widget.h"
#include <QtWidgets>


Widget::Widget(QWidget *parent)
    : QWidget(parent),
      exitButton(nullptr),
      arrayButton(nullptr),
      answer(nullptr),
      outText(nullptr)
{

    QVBoxLayout *mainLayout=nullptr;
    mainLayout = new QVBoxLayout();

    setLayout(mainLayout);

    auto arrayInputer = new QLineEdit();

    auto buttonLayout = new QHBoxLayout();



    outText=new QLabel();


    mainLayout->addWidget(arrayInputer);
    mainLayout->addWidget(outText);
    mainLayout->addSpacerItem(new QSpacerItem(1,50,QSizePolicy::Maximum, QSizePolicy::MinimumExpanding));
    mainLayout->addLayout(buttonLayout);

    exitButton = new QPushButton(tr("Выход"));
    arrayButton = new QPushButton(tr("array"));
    answer = new QPushButton(tr("Произведение"));

    buttonLayout->addWidget(exitButton);
    buttonLayout->addSpacerItem(new QSpacerItem(30,1,QSizePolicy::MinimumExpanding));
    buttonLayout->addWidget(arrayButton);

    buttonLayout->addWidget(answer);

    connect(exitButton,SIGNAL(clicked()), this, SLOT(close()));
    //connect(arrayInputer,SIGNAL(textChanged(QString)),this,SLOT(setText(QString)));
    connect(answer,SIGNAL(clicked()),this, SLOT(swap()));

}


Widget::~Widget()
{

}



void Widget::swap()
{
    QString temp(arrayButton->text());
    temp.split(",", QString::SkipEmptyParts).length();

    int x[temp.split(",", QString::SkipEmptyParts).length()];
    for (int i=0;i<temp.split(",", QString::SkipEmptyParts).length();i++)
    {
         x[i]= temp.split(",", QString::SkipEmptyParts)[i].toInt();
    }
    int min=x[0],max=x[0],st=0,end=0,Multy=1,k;
            for (int i = 1; i < temp.split(",", QString::SkipEmptyParts).length(); i++)
            {  if (abs(x[i])<abs(min)) {min=x[i]; st=i;}
                else if (abs(x[i])>abs(max)) {max=x[i]; end=i;};
            }


            if (end<st)
            {k=st; st=end;end=k;
                for (int j = st+1; j <end; j++)
                {Multy*=x[j];}}
            else
            for (int j = st+1; j <end; j++)
             {Multy*=x[j];}
           if ((st+1==end) ||( st==end-1)) {Multy=-666666;}
            QString s1 = "Произведение элементов между Min и Max: %1";
            outText->setText(s1.arg(Multy));}



void Widget::setText(const QString &txt)
{
    arrayButton->setText(txt);
}
