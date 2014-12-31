#include "imgtest.h"
#include <QLabel>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QScrollArea>
#include <QScrollBar>

imgtest::imgtest(QWidget *parent)
    : QMainWindow(parent),
      openBtn(new QPushButton("&Open?")),
      closeBtn(new QPushButton("&Close.")),
      imgLabel1(new QLabel),
      imgLabel2(new QLabel),
      scrollArea(new QScrollArea),
      scrollBar(new QScrollBar)

{
    imgForm();
    szWids();
    connectSl();

}



imgtest::~imgtest()
{
    
}
void imgtest::imgForm()
{
    scrollArea->setWidget(imgLabel1);

    // QHBoxLayout *imgLayout = new QHBoxLayout;
    //imgLayout->addWidget(imgLabel1);
    //imgLayout->addWidget(imgLabel2);

    QVBoxLayout *vrLayout = new QVBoxLayout;
    vrLayout->addWidget(openBtn);
    vrLayout->addWidget(closeBtn);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    // mainLayout->addLayout(imgLayout);
    mainLayout->addLayout(vrLayout);
    mainLayout->addWidget(scrollArea);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);

    setWindowTitle(tr("imgtest"));
}

void imgtest::szWids()
{
    openBtn->setFixedSize(70,20);
    closeBtn->setFixedSize(70,20);

    imgLabel1->setMinimumSize(500,400);
    imgLabel1->setBackgroundRole(QPalette::Base);
    imgLabel1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //imgLabel1->setScaledContents(true);//autoscale

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imgLabel1);
    scrollArea->horizontalScrollBar();
    scrollArea->verticalScrollBar();

}

void imgtest::openSl()
{
    openImg = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if
            (!openImg.isEmpty()) {
        QImage image(openImg);
        if        (openImg.isEmpty()) return;
        imgLabel1->setPixmap(QPixmap::fromImage(image));
        imgLabel1->adjustSize();
    }
}

void imgtest::connectSl()
{
    connect(openBtn, SIGNAL(clicked()), this, SLOT(openSl()));
    connect(closeBtn, SIGNAL(clicked()),this, SLOT(close()));
}



