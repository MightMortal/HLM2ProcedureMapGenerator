#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstringitemmodel.h"
#include "../Assets/Sprite.h"
#include "../Assets/Atlas.h"
#include <vector>
#include <QGraphicsPixmapItem>
#include <cstdio>
#include <QtWidgets/QFileDialog>

MainWindow::MainWindow(ObjectManager &om, QWidget *parent)
    :
    om(om),
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

void MainWindow::renderLevel(Level &level)
{
    renderTiles(level.tileMaps.begin()->tiles);
    renderWalls(level.wallMaps.begin()->walls);
    renderObjects(level.objectMaps.begin()->objects);
}

void MainWindow::cellChanged(int row, int column)
{
//    printf("Cell %d/%d changed\n", row, column);
}

void MainWindow::on_loadButton_clicked(bool checked)
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    "Open level directory",
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    Level level(dir.toStdString());
    fillColor(0, 0, LEVEL_VIEW_WIDTH, LEVEL_VIEW_HEIGHT, 0xFFFFFFFF);
    renderLevel(level);
}

void MainWindow::on_saveButton_clicked(bool checked)
{

}

void MainWindow::on_propertyEditWidget_cellChanged(int row, int column)
{

}

void MainWindow::on_descriptorsListView_doubleClicked(const QModelIndex &index)
{

}

template<typename T>
void MainWindow::renderObjects(vector<T> &objects)
{
    int tx, ty, w, h;
    for (auto editorObject : objects) {
        Sprite *sprite = om.get(editorObject.id).second;
        if (sprite == nullptr) {
            cout << "Object <" << editorObject.id << "> doesn't have sprite" << endl;
            sprite = om.getSprite(editorObject.spriteId);
        }
        if (sprite != nullptr) {
            string spriteName = sprite->SpritePath().substr(sprite->SpritePath().find_last_of('/') + 1);
            string atlasPath = SpritesIndex::getSpritePath(spriteName);
            string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
            Atlas atlas(atlasPath);
            tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
            ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
            w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
            h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
            renderSprite(spritePath + ".png", editorObject.x, editorObject.y, tx, ty, w, h);
        }
    }
}

void MainWindow::renderWalls(vector<EditorWall> &walls)
{
    int tx, ty, w, h;
    for (auto editorWall : walls) {
        Wall *wall = om.getWall(editorWall.id);
        string spriteName = wall->getName().substr(wall->getName().find_last_of('/') + 1);
        string atlasPath = SpritesIndex::getSpritePath(spriteName);
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
        ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
        w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
        h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
        renderSprite(spritePath + ".png", editorWall.x, editorWall.y, tx, ty, w, h);
    }
}

void MainWindow::renderTiles(vector<EditorTile> &tiles)
{
    int tx, ty, w, h;
    for (auto editorTile : tiles) {
        Tile *tile = om.getTile(editorTile.id);
        string atlasPath = SpritesIndex::getSpritePath(tile->getName());
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetX() + editorTile.textureX;
        ty = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetY() + editorTile.textureY;
        if (editorTile.id == 10)
            w = h = 8;
        else
            w = h = 16;
        renderSprite(spritePath + ".png", editorTile.x, editorTile.y, tx, ty, w, h);
    }
}
