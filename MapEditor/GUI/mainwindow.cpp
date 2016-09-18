#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstringitemmodel.h"
#include <vector>
#include <QGraphicsPixmapItem>
#include <cstdio>

MainWindow::MainWindow(QWidget *parent)
    :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    renderScale(2.0)
{
    ui->setupUi(this);

    QStringItemModel *stringItemModel = new QStringItemModel(QString("asdf"));
    ui->descriptorsListView->setModel(stringItemModel);

    ui->propertyEditWidget->setColumnCount(2);
    ui->propertyEditWidget->setRowCount(0);

//    item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
//    item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
//    ui->propertyEditWidget->setItem(0, 0, item1);
//    ui->propertyEditWidget->setItem(0, 1, item2);
//    ui->propertyEditWidget->setItem(1, 0, item3);
//    ui->propertyEditWidget->setItem(1, 1, item4);
//    ui->propertyEditWidget->horizontalHeader()->setStretchLastSection(true);

    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::renderSprite(std::string filename, int x, int y, int tx, int ty, int w, int h)
{
    QPixmap texturePixmap;
    texturePixmap.load(QString(filename.c_str()));
    QPixmap pixmap = texturePixmap.copy(tx, ty, w, h).scaled(w * SCALE, h * SCALE);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
    item->setOffset(x * SCALE, y * SCALE);
    ui->graphicsView->scene()->addItem(item);
}

void MainWindow::fillColor(int x, int y, int w, int h, unsigned int color)
{
    int r = (color >> 16) & 0xFF, g = (color >> 8) & 0xFF, b = (color) & 0xFF;
    QPixmap pixmap(w * SCALE, h * SCALE);
    pixmap.fill(QColor(r, g, b));
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
    item->setOffset(x * SCALE, y * SCALE);
    ui->graphicsView->scene()->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAssetDescriptors(vector<AssetDescriptor> descriptors)
{
    // TODO: Implement
}

vector<AssetDescriptor> MainWindow::getAssetDescriptors()
{
    // TODO: Implement
}

void MainWindow::renderLevel()
{
    // TODO: Implement level render
}

void MainWindow::cellChanged(int row, int column)
{
//    printf("Cell %d/%d changed\n", row, column);
}
